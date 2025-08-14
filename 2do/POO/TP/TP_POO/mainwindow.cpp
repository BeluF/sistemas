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

        QList <QString> BgColors ={
            "#CFD8DC", // Gris
            "#B2EBF2", // Cian claro
            "#FFCDD2", // Rojo claro
            "#D1C4E9", // Púrpura claro
            "#C8E6C9", // Verde claro
            "#FFF9C4"  // Amarillo claro
        };

        switch (i){
        case 9:
        case 18:
        case 27:
        case 36:
        case 45:
        case 54:
            //Oca
            setBackgroundImage(casilla, "oca", TAMANO_CASILLA);
            break;

        case 6:
            //Puente
            setBackgroundImage(casilla, "puente", TAMANO_CASILLA);
            break;

        case 19:
            //Posada
            setBackgroundImage(casilla, "posada", TAMANO_CASILLA);
            break;

        case 31:
            //Pozo
            setBackgroundImage(casilla, "pozo", TAMANO_CASILLA);
            break;

        case 42:
            //Laberinto
            setBackgroundImage(casilla, "laberinto", TAMANO_CASILLA);
            break;

        case 56:
            //Cárcel
            setBackgroundImage(casilla, "carcel", TAMANO_CASILLA);
            break;

        case 58:
            //Calavera
            setBackgroundImage(casilla, "calavera", TAMANO_CASILLA);
            break;

        case 63:
            //Meta
            setBackgroundImage(casilla, "meta", TAMANO_CASILLA);
            break;

        default:{
            //Determinar grupos de a 10 casillas (contando las especiales)
            int grupo = (i - 1) / 10;

            //
            int indiceColor = grupo % BgColors.size();
            QString colorFondo = BgColors.at(indiceColor);
            QString estilo = QString("QLabel {"
                                     "    background-color: %1;"
                                     "    border: 2px solid #455A64;"
                                     "    font-weight: bold;"
                                     "    border-radius: 8px;"
                                     "    color: #37474F;"
                                     "}");

            // 3. Aplicar el estilo, reemplazando %1 con el color correcto
            casilla->setStyleSheet(estilo.arg(colorFondo));
            break;

        }

        }



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


void MainWindow::setBackgroundImage(QLabel* casilla, const QString& nameBg, const int TAMANO_CASILLA){
    //Casilla inexistente
    if (!casilla) {
        return;
    }

    //Establecer un estilo base transparente para que la imagen sea visible.
    casilla->setStyleSheet("QLabel {"
                           "    background-color: transparent;"
                           "    border: 2px solid #455A64;"
                           "    font-weight: bold;"
                           "    border-radius: 8px;"
                           "    color: #01579B;"
                           "}");


    // Construir la ruta de la imagen dinámicamente usando la variable nameBg.
    QString imagePath = ":/img/" + nameBg + ".png";

    // Cargar la imagen en un QPixmap usando la ruta construida.
    QPixmap bgPixmap(imagePath);

    // Verificar si la imagen se cargó correctamente.
    if (bgPixmap.isNull()) {
        qDebug() << "Error: No se pudo cargar la imagen en la ruta:" << imagePath;
        return; // Salir si la imagen no existe.
    }


    //Escalar la imagen para que quepa dentro de la casilla, manteniendo su proporción.
    // Qt::KeepAspectRatio asegura que no se deforme.
    // Qt::SmoothTransformation hace que el escalado se vea de alta calidad.
    int tamanoImagen = TAMANO_CASILLA - 10; //Margen
    QPixmap imgEscalada = bgPixmap.scaled(tamanoImagen, tamanoImagen,
                                          Qt::KeepAspectRatio,
                                          Qt::SmoothTransformation);

    casilla->setPixmap(imgEscalada);

    casilla->setAlignment(Qt::AlignCenter);

}

