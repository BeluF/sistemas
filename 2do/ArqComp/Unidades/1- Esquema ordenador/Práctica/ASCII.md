### Código ASCII
* Código alfanumérico que permite interactuar con la computadora.
* Es un tipo de string.
* Representa cada caracter con 7 bits, se peuden representar 128 caracteres alfanuméricos.
* Existe tabla de 8 bits y se pueden traducir 256 caracteres alfanuméricos.

### Info de la arquitectura de la computadora

## Entorno gráfico: CPU-Z (Windows) y CPU-X (Linux)
* Aplicación para ver detalle del microprocesador y su arquitectura.
* Muestra set de instrucciones que soporta el microprocesador, detalles de la mother, memoria, slots, gráfica y rendimiento (benchmark) (comportamiento del procesador bajo estŕes).

## Comandos para ver información de la arquitectura de la computadora
* cpuinfo: cat /proc/cpuinfo. flags: instrucciones que soporta el micro.
* meminfo: cat /proc/meminfo. con "free -h" también se ve, pero no tanto.
* hwinfo: hay que instalarlo, es un comando.
* dmidecode: información de la mother. Es un comando.

Pregunta de parcial: por que surge la cache? Solucionar la disparidad entre la velocidad del micro y la memoria RAM.
