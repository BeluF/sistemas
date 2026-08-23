erDiagram
    ORGANISMO ||--o{ PERICIA : "solicita"
    TIPO_PERICIA ||--o{ PERICIA : "clasifica"
    ESTADO ||--o{ PERICIA : "estado_actual"
    
    PERICIA ||--o{ PARTICIPACION_PERICIA : "involucra"
    PERSONA ||--o{ PARTICIPACION_PERICIA : "participa_en"
    
    PERSONA ||--o{ PERITO_ESPECIALIDAD : "acredita"
    ESPECIALIDAD ||--o{ PERITO_ESPECIALIDAD : "agrupa"
    ESPECIALIDAD ||--o{ PARTICIPACION_PERICIA : "actua_con"
    
    PERSONA |o--o| USUARIO : "autentica"
    
    PERICIA ||--o{ MOVIMIENTO_PERICIA : "registra"
    TIPO_MOVIMIENTO ||--o{ MOVIMIENTO_PERICIA : "clasifica"
    USUARIO ||--o{ MOVIMIENTO_PERICIA : "carga"
    
    PERICIA ||--o{ HISTORIAL_ESTADO_PERICIA : "audita_estados"
    ESTADO ||--o{ HISTORIAL_ESTADO_PERICIA : "registra_estado"
    USUARIO ||--o{ HISTORIAL_ESTADO_PERICIA : "autoriza"
    
    PERICIA ||--o{ ACTIVIDAD_PROGRAMADA : "planifica"
    PERSONA ||--o{ ACTIVIDAD_PROGRAMADA : "responsable_tecnico"
    MOVIMIENTO_PERICIA |o--o| ACTIVIDAD_PROGRAMADA : "origina"
    
    ACTIVIDAD_PROGRAMADA ||--o{ CONVOCATORIA_ACTIVIDAD : "convoca"
    PERSONA ||--o{ CONVOCATORIA_ACTIVIDAD : "asiste"

    ORGANISMO {
        int id_organismo PK
        string nombre_organismo
        string tipo_organismo
        string contacto
    }

    TIPO_PERICIA {
        int id_tipo_pericia PK
        string nombre
        string descripcion
        string area_profesional
    }

    ESTADO {
        int id_estado PK
        string nombre_estado
        string descripcion
    }

    PERICIA {
        int id_pericia PK
        int id_organismo FK
        string numero_pericia_organismo
        int id_tipo_pericia FK
        int id_estado_actual FK
        string expediente_judicial
        string area_tecnica_responsable
        date fecha_solicitud
        text descripcion_caso
    }

    PERSONA {
        int id_persona PK
        string tipo_documento
        string numero_documento
        string nombre
        string apellido
        date fecha_nacimiento
        string telefono
        string correo_electronico
    }

    ESPECIALIDAD {
        int id_especialidad PK
        string nombre_especialidad
    }

    PERITO_ESPECIALIDAD {
        int id_persona PK,FK
        int id_especialidad PK,FK
        string numero_matricula
        string organismo_colegiado
    }

    PARTICIPACION_PERICIA {
        int id_participacion PK
        int id_pericia FK
        int id_persona FK
        string rol_en_pericia
        string tipo_perito
        int id_especialidad_actuacion FK
        string motivo_evaluacion
        text hallazgos_tecnicos
    }

    USUARIO {
        int id_usuario PK
        int id_persona FK
        string nombre_usuario
        string password_hash
        string rol_usuario
        boolean activo
    }

    TIPO_MOVIMIENTO {
        int id_tipo_movimiento PK
        string nombre
        string descripcion
    }

    MOVIMIENTO_PERICIA {
        int id_movimiento PK
        int id_pericia FK
        int id_tipo_movimiento FK
        int id_usuario_carga FK
        int numero_orden
        datetime fecha_registro
        text descripcion_actuacion
    }

    HISTORIAL_ESTADO_PERICIA {
        int id_historial PK
        int id_pericia FK
        int id_estado FK
        int id_usuario FK
        datetime fecha_cambio
        string observaciones
    }

    ACTIVIDAD_PROGRAMADA {
        int id_actividad PK
        int id_pericia FK
        int id_perito_responsable FK
        int id_movimiento_generado FK
        date fecha
        time hora
        string lugar
        string estado_actividad
        text descripcion
    }

    CONVOCATORIA_ACTIVIDAD {
        int id_actividad PK,FK
        int id_persona PK,FK
        boolean asistio
        string observaciones
    }
