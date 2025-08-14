/****************************************************************************
** Meta object code from reading C++ file 'juego.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../juego.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'juego.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN5JuegoE_t {};
} // unnamed namespace

template <> constexpr inline auto Juego::qt_create_metaobjectdata<qt_meta_tag_ZN5JuegoE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Juego",
        "juegoIniciado",
        "",
        "numJugadoresActivos",
        "dadoLanzado",
        "valorDado",
        "turnoCambiado",
        "nombreSiguienteJugador",
        "jugadorCastigado",
        "nombreJugador",
        "turnosRestantes",
        "juegoGanado",
        "nombreGanador",
        "mensajeEstado",
        "mensaje",
        "turnoRepetido",
        "jugadorMovido",
        "jugadorIndex",
        "casillaOrigen",
        "casillaDestino",
        "mensajeParaMostrar",
        "jugarTurno",
        "continuarTurno"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'juegoIniciado'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'dadoLanzado'
        QtMocHelpers::SignalData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Signal 'turnoCambiado'
        QtMocHelpers::SignalData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Signal 'jugadorCastigado'
        QtMocHelpers::SignalData<void(const QString &, int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 }, { QMetaType::Int, 10 },
        }}),
        // Signal 'juegoGanado'
        QtMocHelpers::SignalData<void(const QString &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 12 },
        }}),
        // Signal 'mensajeEstado'
        QtMocHelpers::SignalData<void(const QString &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Signal 'turnoRepetido'
        QtMocHelpers::SignalData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'jugadorMovido'
        QtMocHelpers::SignalData<void(int, int, int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 }, { QMetaType::Int, 18 }, { QMetaType::Int, 19 },
        }}),
        // Signal 'mensajeParaMostrar'
        QtMocHelpers::SignalData<void(const QString &)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Slot 'jugarTurno'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'continuarTurno'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Juego, qt_meta_tag_ZN5JuegoE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Juego::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5JuegoE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5JuegoE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN5JuegoE_t>.metaTypes,
    nullptr
} };

void Juego::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Juego *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->juegoIniciado((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->dadoLanzado((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->turnoCambiado((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->jugadorCastigado((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->juegoGanado((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->mensajeEstado((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->turnoRepetido(); break;
        case 7: _t->jugadorMovido((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 8: _t->mensajeParaMostrar((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->jugarTurno(); break;
        case 10: _t->continuarTurno(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Juego::*)(int )>(_a, &Juego::juegoIniciado, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Juego::*)(int )>(_a, &Juego::dadoLanzado, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Juego::*)(const QString & )>(_a, &Juego::turnoCambiado, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Juego::*)(const QString & , int )>(_a, &Juego::jugadorCastigado, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Juego::*)(const QString & )>(_a, &Juego::juegoGanado, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Juego::*)(const QString & )>(_a, &Juego::mensajeEstado, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (Juego::*)()>(_a, &Juego::turnoRepetido, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (Juego::*)(int , int , int )>(_a, &Juego::jugadorMovido, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (Juego::*)(const QString & )>(_a, &Juego::mensajeParaMostrar, 8))
            return;
    }
}

const QMetaObject *Juego::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Juego::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5JuegoE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Juego::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Juego::juegoIniciado(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void Juego::dadoLanzado(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Juego::turnoCambiado(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void Juego::jugadorCastigado(const QString & _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void Juego::juegoGanado(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void Juego::mensajeEstado(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void Juego::turnoRepetido()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Juego::jugadorMovido(int _t1, int _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2, _t3);
}

// SIGNAL 8
void Juego::mensajeParaMostrar(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}
QT_WARNING_POP
