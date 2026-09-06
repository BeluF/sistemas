// ==========================================
// JUSTIDATA SOLUTIONS S.A. - MODELO RELACIONAL
// ==========================================

Table Organismo {
  id_organismo int [pk, increment]
  nombre_organismo varchar [not null]
  tipo_organismo varchar [not null]
  contacto varchar
  direccion varchar
}

Table Tipo_Pericia {
  id_tipo_pericia int [pk, increment]
  nombre varchar [not null]
  descripcion text
  area_profesional varchar [not null]
  arancel_base decimal(12,2) [not null]
}

Table Estado {
  id_estado int [pk, increment]
  nombre_estado varchar [not null]
  descripcion text
}

Table Especialidad {
  id_especialidad int [pk, increment]
  nombre_especialidad varchar [not null]
}

Table Persona {
  id_persona int [pk, increment]
  tipo_documento varchar [not null]
  numero_documento varchar [not null, unique]
  nombre varchar [not null]
  apellido varchar [not null]
  fecha_nacimiento date
  telefono varchar
  correo_electronico varchar
  direccion varchar
}

Table Usuario {
  id_usuario int [pk, increment]
  id_persona int [ref: - Persona.id_persona]
  nombre_usuario varchar [not null, unique]
  password_hash varchar [not null]
  rol_usuario varchar [not null]
  activo boolean [default: true]
}

Table Perito_Especialidad {
  id_persona int [ref: > Persona.id_persona]
  id_especialidad int [ref: > Especialidad.id_especialidad]
  numero_matricula varchar [not null]
  organismo_colegiado varchar
  indexes {
    (id_persona, id_especialidad) [pk]
  }
}

Table Pericia {
  id_pericia int [pk, increment]
  id_organismo int [ref: > Organismo.id_organismo, not null]
  numero_pericia_organismo varchar [not null]
  id_tipo_pericia int [ref: > Tipo_Pericia.id_tipo_pericia, not null]
  id_estado_actual int [ref: > Estado.id_estado, not null]
  expediente_judicial varchar [not null]
  area_tecnica_responsable varchar [not null]
  fecha_solicitud date [not null]
  descripcion_caso text
}

Table Participacion_Pericia {
  id_participacion int [pk, increment]
  id_pericia int [ref: > Pericia.id_pericia, not null]
  id_persona int [ref: > Persona.id_persona, not null]
  rol_en_pericia varchar [not null]
  tipo_perito varchar
  motivo_evaluacion varchar
  hallazgos_tecnicos text
}

Table Tipo_Movimiento {
  id_tipo_movimiento int [pk, increment]
  nombre varchar [not null]
  descripcion text
}

Table Movimiento_Pericia {
  id_movimiento int [pk, increment]
  id_pericia int [ref: > Pericia.id_pericia, not null]
  id_tipo_movimiento int [ref: > Tipo_Movimiento.id_tipo_movimiento, not null]
  id_usuario_carga int [ref: > Usuario.id_usuario, not null]
  numero_orden int [not null]
  fecha_registro datetime [not null]
  descripcion_actuacion text [not null]
}

Table Historial_Estado_Pericia {
  id_historial int [pk, increment]
  id_pericia int [ref: > Pericia.id_pericia, not null]
  id_estado int [ref: > Estado.id_estado, not null]
  id_usuario int [ref: > Usuario.id_usuario, not null]
  fecha_cambio datetime [not null]
  observaciones text
}

Table Actividad_Programada {
  id_actividad int [pk, increment]
  id_pericia int [ref: > Pericia.id_pericia, not null]
  fecha date [not null]
  hora time [not null]
  lugar varchar [not null]
  estado_actividad varchar [not null]
  descripcion text
}

Table Convocatoria_Actividad {
  id_actividad int [ref: > Actividad_Programada.id_actividad]
  id_persona int [ref: > Persona.id_persona]
  asistio boolean [default: false]
  observaciones text
  indexes {
    (id_actividad, id_persona) [pk]
  }
}

Table Cobro_Organismo {
  id_cobro int [pk, increment]
  id_pericia int [ref: > Pericia.id_pericia, not null]
  nro_factura varchar [not null]
  monto_total decimal(12,2) [not null]
  fecha_emision date [not null]
  fecha_cobro date
  estado_cobro varchar [not null]
}

Table Liquidacion_Pago_Pericia {
  id_liquidacion int [pk, increment]
  id_pericia int [ref: > Pericia.id_pericia, not null]
  id_perito int [ref: > Persona.id_persona, not null]
  monto_base decimal(12,2) [not null]
  modalidad_pago varchar [not null]
  monto_final decimal(12,2) [not null]
  cantidad_cuotas int [default: 1]
  fecha_vencimiento date
  estado_pago varchar [not null]
}

Table Historial_Pago {
  id_pago int [pk, increment]
  id_liquidacion int [ref: > Liquidacion_Pago_Pericia.id_liquidacion, not null]
  id_usuario_carga int [ref: > Usuario.id_usuario, not null]
  fecha_pago datetime [not null]
  monto_abonado decimal(12,2) [not null]
  modalidad_utilizada varchar [not null]
  nro_transaccion varchar
}

Table Juicio_Ejecucion_Honorarios {
  id_juicio int [pk, increment]
  id_liquidacion int [ref: - Liquidacion_Pago_Pericia.id_liquidacion, unique, not null]
  id_perito_promotor int [ref: > Persona.id_persona, not null]
  nro_expediente_ejecucion varchar [not null]
  juzgado_radicacion varchar [not null]
  fecha_inicio date [not null]
  monto_reclamado decimal(12,2) [not null]
  estado_juicio varchar [not null]
}
