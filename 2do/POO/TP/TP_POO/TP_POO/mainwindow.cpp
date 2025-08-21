#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "juego.h"
#include <QMessageBox>
#include "arranque.h"

//Constructor
MainWindow::MainWindow(int numJugadores, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/img/fondo.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);


    crearTableroUI();

    // Conectar la lógica del juego
    connect(&miJuego, &Juego::juegoIniciado, this, &MainWindow::configurarPanelesJugadores);
    connect(&miJuego, &Juego::dadoLanzado, this, &MainWindow::actualizarDado);
    connect(&miJuego, &Juego::jugadorMovido, this, &MainWindow::moverFichaUI);
    connect(&miJuego, &Juego::mensajeParaMostrar, this, &MainWindow::mostrarMensajePopUp);
    connect(this, &MainWindow::continuarTurno, &miJuego, &Juego::continuarTurno);
    connect(&miJuego, &Juego::juegoGanado, this, &MainWindow::mostrarGanador);

    connect(&miJuego, &Juego::turnoRepetido, this, [=]() {
        ui->BotonTirarDado->setEnabled(true);
    });


    miJuego.iniciar(numJugadores); // Iniciar la partida
    inicializarPeones(numJugadores);
    jugadoresUI = miJuego.obtenerJugadores(); // Obtener la lista de jugadores

    actualizarPanelesJugadores ();
}

//Destructor
// Limpia los recursos y elimina los widgets de casillas y peones
MainWindow::~MainWindow()
{
    qDeleteAll(vectorCasillas);
    qDeleteAll(peonesLabels);
    delete ui;
}

// Mostrar mensajes emergentes
void MainWindow::mostrarGanador(const QString &nombreGanador) {
//    QMessageBox::information(this, "¡Fin del juego!", nombreGanador + " ha ganado el juego 🎉");
    QMessageBox msg;
    msg.setWindowTitle("¡Fin del juego!");
    msg.setText(nombreGanador + " ha ganado el juego 🎉\n\n¿Cómo desea continuar?");

    QPushButton *btnMenu = msg.addButton("Volver al menú", QMessageBox::DestructiveRole);
    QPushButton *btnSalir = msg.addButton("Salir", QMessageBox::RejectRole);

    msg.exec();
    if (msg.clickedButton() == btnMenu) {
        // Volver al menú
        Inicio *menu = new Inicio();
        menu->show();
        this->close();
    }
    //Salir del juego
    else if (msg.clickedButton() == btnSalir) {
        QApplication::quit();
    }
}

// Crear tablero de forma dinámica 
//Tabler caracol
void MainWindow::crearTableroUI() {
    const int TAMANO_CASILLA = 70;
    const int ESPACIADO = 4;
    const int TAMANO_TOTAL_CASILLA = TAMANO_CASILLA + ESPACIADO;

    QPoint coordenadas[64];
    int n = 8;
    int dx[] = {1, 0, -1, 0}; // derecha, abajo, izquierda, arriba
    int dy[] = {0, 1, 0, -1};
    bool ocupado[8][8] = {{false}};

    int x = 0, y = 0, dir = 0;
    for (int i = 1; i <= 63; ++i) {
        coordenadas[i] = QPoint(x, y);
        ocupado[y][x] = true;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || ocupado[ny][nx]) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx;
        y = ny;
    }

    // Limpieza de widgets antiguos por si se redibuja
    if (!vectorCasillas.isEmpty()) {
        qDeleteAll(vectorCasillas);
        vectorCasillas.clear();
    }
    vectorCasillas.resize(64, nullptr);

    // Bucle para crear y posicionar cada casilla
    for (int i = 1; i <= 63; ++i) {
        QLabel* casilla = new QLabel(ui->boardContainer);
        casilla->setText(QString::number(i));
        casilla->setAlignment(Qt::AlignCenter);
        casilla->setObjectName("casilla" + QString::number(i));

        QString estiloBase = "border: 2px solid #455A64; font-weight: bold; border-radius: 8px;";
        QString colorFondo = "background-color: #CFD8DC;";
        QString colorTexto = "color: #37474F;";

        QString estiloFinal;

        if (i == 9 || i == 18 || i == 27 || i == 36 || i == 45 || i == 54) { // Oca
            // 'background-color: transparent;' para asegurar de que el fondo
            // no tape la imagen que va arriba
            casilla->setStyleSheet("QLabel {"
                                   "    background-color: transparent;"
                                   "    border: 2px solid #455A64;"
                                   "    font-weight: bold;"
                                   "    border-radius: 8px;"
                                   "    color: #01579B;"
                                   "}");

            // Cargarr la imagen de la oca en un QPixmap.
            QPixmap ocaPixmap(":/img/oca.png");

            //Escalar la imagen para que quepa dentro de la casilla, manteniendo su proporción.
            // Qt::KeepAspectRatio asegura que no se deforme.
            // Qt::SmoothTransformation hace que el escalado se vea de alta calidad.
            int tamanoImagen = TAMANO_CASILLA - 10;
            QPixmap ocaEscalada = ocaPixmap.scaled(tamanoImagen, tamanoImagen,
                                                   Qt::KeepAspectRatio,
                                                   Qt::SmoothTransformation);

            casilla->setPixmap(ocaEscalada);

            casilla->setAlignment(Qt::AlignCenter);
        } else if (i == 6) { // Puente

            // 'background-color: transparent;' para asegurar de que el fondo
            // no tape la imagen que va arriba
            casilla->setStyleSheet("QLabel {"
                                   "    background-color: transparent;"
                                   "    border: 2px solid #455A64;"
                                   "    font-weight: bold;"
                                   "    border-radius: 8px;"
                                   "    color: #01579B;"
                                   "}");

            // Cargarr la imagen de la oca en un QPixmap.
            QPixmap puentePixmap(":/img/puente.png");

            //Escalar la imagen para que quepa dentro de la casilla, manteniendo su proporción.
            // Qt::KeepAspectRatio asegura que no se deforme.
            // Qt::SmoothTransformation hace que el escalado se vea de alta calidad.
            int tamanoImagen = TAMANO_CASILLA - 10;
            QPixmap puenteEscalado= puentePixmap.scaled(tamanoImagen, tamanoImagen,
                                                   Qt::KeepAspectRatio,
                                                   Qt::SmoothTransformation);

            casilla->setPixmap(puenteEscalado);

            casilla->setAlignment(Qt::AlignCenter);

        } else if (i == 19) { // Posada
            // 'background-color: transparent;' para asegurar de que el fondo
            // no tape la imagen que va arriba
            casilla->setStyleSheet("QLabel {"
                                   "    background-color: transparent;"
                                   "    border: 2px solid #455A64;"
                                   "    font-weight: bold;"
                                   "    border-radius: 8px;"
                                   "    color: #01579B;"
                                   "}");

            // Cargarr la imagen de la oca en un QPixmap.
            QPixmap posadaPixmap(":/img/posada.png");

            //Escalar la imagen para que quepa dentro de la casilla, manteniendo su proporción.
            // Qt::KeepAspectRatio asegura que no se deforme.
            // Qt::SmoothTransformation hace que el escalado se vea de alta calidad.
            int tamanoImagen = TAMANO_CASILLA - 10;
            QPixmap posadaEscalada= posadaPixmap.scaled(tamanoImagen, tamanoImagen,
                                                         Qt::KeepAspectRatio,
                                                         Qt::SmoothTransformation);

            casilla->setPixmap(posadaEscalada);
            casilla->setAlignment(Qt::AlignCenter);

        } else if (i == 31) { // Pozo
            // 'background-color: transparent;' para asegurar de que el fondo
            // no tape la imagen que va arriba
            casilla->setStyleSheet("QLabel {"
                                   "    background-color: transparent;"
                                   "    border: 2px solid #455A64;"
                                   "    font-weight: bold;"
                                   "    border-radius: 8px;"
                                   "    color: #01579B;"
                                   "}");

            // Cargarr la imagen de la oca en un QPixmap.
            QPixmap pozoPixmap(":/img/pozo.png");

            //Escalar la imagen para que quepa dentro de la casilla, manteniendo su proporción.
            // Qt::KeepAspectRatio asegura que no se deforme.
            // Qt::SmoothTransformation hace que el escalado se vea de alta calidad.
            int tamanoImagen = TAMANO_CASILLA - 10;
            QPixmap pozoEscalado= pozoPixmap.scaled(tamanoImagen, tamanoImagen,
                                                             Qt::KeepAspectRatio,
                                                             Qt::SmoothTransformation);

            casilla->setPixmap(pozoEscalado);
            casilla->setAlignment(Qt::AlignCenter);
        } else if (i == 63) { // Meta
            // 'background-color: transparent;' para asegurar de que el fondo
            // no tape la imagen que va arriba
            casilla->setStyleSheet("QLabel {"
                                   "    background-color: transparent;"
                                   "    border: 2px solid #455A64;"
                                   "    font-weight: bold;"
                                   "    border-radius: 8px;"
                                   "    color: #01579B;"
                                   "}");

            // Cargarr la imagen de la oca en un QPixmap.
            QPixmap metaPixmap(":/img/meta.png");

            //Escalar la imagen para que quepa dentro de la casilla, manteniendo su proporción.
            // Qt::KeepAspectRatio asegura que no se deforme.
            // Qt::SmoothTransformation hace que el escalado se vea de alta calidad.
            int tamanoImagen = TAMANO_CASILLA - 10;
            QPixmap metaEscalada = metaPixmap.scaled(tamanoImagen, tamanoImagen,
                                                         Qt::KeepAspectRatio,
                                                         Qt::SmoothTransformation);

            casilla->setPixmap(metaEscalada);
            casilla->setAlignment(Qt::AlignCenter);
        } else if (i == 42) { // Laberinto
            // 'background-color: transparent;' para asegurar de que el fondo
            // no tape la imagen que va arriba
            casilla->setStyleSheet("QLabel {"
                                   "    background-color: transparent;"
                                   "    border: 2px solid #455A64;"
                                   "    font-weight: bold;"
                                   "    border-radius: 8px;"
                                   "    color: #01579B;"
                                   "}");

            // Cargarr la imagen de la oca en un QPixmap.
            QPixmap laberintoPixmap(":/img/laberinto.png");

            //Escalar la imagen para que quepa dentro de la casilla, manteniendo su proporción.
            // Qt::KeepAspectRatio asegura que no se deforme.
            // Qt::SmoothTransformation hace que el escalado se vea de alta calidad.
            int tamanoImagen = TAMANO_CASILLA - 10;
            QPixmap laberintoEscalado= laberintoPixmap.scaled(tamanoImagen, tamanoImagen,
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation);

            casilla->setPixmap(laberintoEscalado);
            casilla->setAlignment(Qt::AlignCenter);
        } else if (i == 56) { // Cárcel
            // 'background-color: transparent;' para asegurar de que el fondo
            // no tape la imagen que va arriba
            casilla->setStyleSheet("QLabel {"
                                   "    background-color: transparent;"
                                   "    border: 2px solid #455A64;"
                                   "    font-weight: bold;"
                                   "    border-radius: 8px;"
                                   "    color: #01579B;"
                                   "}");

            // Cargarr la imagen de la oca en un QPixmap.
            QPixmap carcelPixmap(":/img/carcel.png");

            //Escalar la imagen para que quepa dentro de la casilla, manteniendo su proporción.
            // Qt::KeepAspectRatio asegura que no se deforme.
            // Qt::SmoothTransformation hace que el escalado se vea de alta calidad.
            int tamanoImagen = TAMANO_CASILLA - 10;
            QPixmap carcelEscalada = carcelPixmap.scaled(tamanoImagen, tamanoImagen,
                                                               Qt::KeepAspectRatio,
                                                               Qt::SmoothTransformation);

            casilla->setPixmap(carcelEscalada);
            casilla->setAlignment(Qt::AlignCenter);

        } else if (i == 58) { // Calavera
            // 'background-color: transparent;' para asegurar de que el fondo
            // no tape la imagen que va arriba
            casilla->setStyleSheet("QLabel {"
                                   "    background-color: transparent;"
                                   "    border: 2px solid #455A64;"
                                   "    font-weight: bold;"
                                   "    border-radius: 8px;"
                                   "    color: #01579B;"
                                   "}");

            // Cargarr la imagen de la oca en un QPixmap.
            QPixmap calaveraPixmap(":/img/calavera.png");

            //Escalar la imagen para que quepa dentro de la casilla, manteniendo su proporción.
            // Qt::KeepAspectRatio asegura que no se deforme.
            // Qt::SmoothTransformation hace que el escalado se vea de alta calidad.
            int tamanoImagen = TAMANO_CASILLA - 10;
            QPixmap calaveraEscalada= calaveraPixmap.scaled(tamanoImagen, tamanoImagen,
                                                         Qt::KeepAspectRatio,
                                                         Qt::SmoothTransformation);

            casilla->setPixmap(calaveraEscalada);
            casilla->setAlignment(Qt::AlignCenter);        } else if (i == 63) { // Meta
            colorFondo = "background-color: #A5D6A7;"; colorTexto = "color: #1B5E20;";
            estiloBase = "border: 4px solid #388E3C; font-weight: bold; border-radius: 8px;";
        }
        else         estiloFinal = colorFondo + colorTexto + estiloBase;


        casilla->setStyleSheet(estiloFinal);

        // Posicionamiento
        int posX = coordenadas[i].x() * TAMANO_TOTAL_CASILLA;
        int posY = coordenadas[i].y() * TAMANO_TOTAL_CASILLA;
        casilla->setGeometry(posX, posY, TAMANO_CASILLA, TAMANO_CASILLA);
        vectorCasillas[i] = casilla;
    }
    qDebug() << "Se han creado 63 casillas con el diseño de caracol.";
}

// Inicializar los peones en la UI
void MainWindow::inicializarPeones(int numJugadores) {
    QList<QPixmap> fichasJugadores;
    fichasJugadores.append(QPixmap(":/img/rojo.png"));
    fichasJugadores.append(QPixmap(":/img/azul.png"));
    fichasJugadores.append(QPixmap(":/img/verde.png"));
    fichasJugadores.append(QPixmap(":/img/amarillo.png"));

    qDeleteAll(peonesLabels);
    peonesLabels.clear();

    for (int i = 0; i < numJugadores; ++i) {
        QLabel* peon = new QLabel(ui->boardContainer);
        peon->setPixmap(fichasJugadores[i % fichasJugadores.size()]);
        peon->setScaledContents(true);
        peon->setFixedSize(30, 30);

        peon->show();

        peonesLabels.append(peon);
    }
    qDebug() << "Se han creado" << peonesLabels.size() << "peones.";
}

void MainWindow::moverFichaUI(int jugadorIndex, int casillaOrigen, int casillaDestino)
{
    if (jugadorIndex < 0 || jugadorIndex >= peonesLabels.size() || casillaDestino <= 0 || casillaDestino >= vectorCasillas.size()) {
        qCritical() << "moverFichaUI: Índice inválido.";
        return;
    }

    QLabel* peonAMover = peonesLabels[jugadorIndex];
    QLabel* casillaDestinoLabel = vectorCasillas[casillaDestino];

    if (!peonAMover || !casillaDestinoLabel) {
        qCritical() << "moverFichaUI: El puntero del peón o la casilla son nulos.";
        return;
    }

    QPoint destinoPosBase = casillaDestinoLabel->pos();
    int peonOffsetX = (casillaDestinoLabel->width() - peonAMover->width()) / 2;
    int peonOffsetY = (casillaDestinoLabel->height() - peonAMover->height()) / 2;
    int offsetIndividual = 4 * jugadorIndex;

    QPoint posicionFinalPeon(destinoPosBase.x() + peonOffsetX + offsetIndividual,
                             destinoPosBase.y() + peonOffsetY);

    peonAMover->move(posicionFinalPeon);
    peonAMover->raise();

    qDebug() << "Moviendo peón del jugador" << jugadorIndex << "a la casilla" << casillaDestino
             << "en la posición" << posicionFinalPeon;
}

void MainWindow::on_BotonTirarDado_clicked()
{
    miJuego.jugarTurno();
    actualizarPanelesJugadores();
}


// Actualizar los paneles de jugadores según el turno actual
// Este método se llama después de cada turno para reflejar quién está jugando.
void MainWindow::actualizarPanelesJugadores()
{
    int turnoActual = miJuego.getTurno();
    qDebug() << "Actualizando UI para el turno del jugador:" << turnoActual;
    ui->groupBox_j1->setVisible(0==turnoActual);
    ui->groupBox_j2->setVisible(1==turnoActual);
    ui->groupBox_j3->setVisible(2==turnoActual);
    ui->groupBox_j4->setVisible(3==turnoActual);
}

// Configurar los paneles de jugadores según el número de jugadores
void MainWindow::configurarPanelesJugadores(int numJugadores) {
    ui->groupBox_j1->setVisible(true);
}

// Actualizar el valor del dado en la UI
void MainWindow::actualizarDado(int valorDado) {
    ui->lcd_dado->display(valorDado);
}
