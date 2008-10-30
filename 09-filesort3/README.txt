Para el maraton de programación se requiere conocer un grupo de estudiantes 
candidatos de la carrera informática (código 8) y de electrónica (código 6). Se 
determinó que este grupo de candidatos deben tener un índice mínimo de 7.0 y
haber aprobado con nota mínima de 8 las asignaturas:
	+ Estructura de datos (código 47)
	+ Programación I (código 89)
	+ Programación II (código 93)
En el caso de los estudiantes de informática.

En el caso de los estudiantes de electrónica:
	+ Computación I (código 11)
	+ Computación II (código 22)

Para el procesamiento se cuenta con archivos binarios creados
	+ ALUMNO.DAT:
	+---------------+---------------+---------------+--------+
	| cedula 	| nom 		| carrera 	| indice |
	+---------------+---------------+---------------+--------+
	| 17342111 	| Ana 		| 6 		| 8.2 	 |
	| 16411222 	| Luis 		| 5 		| 9.0 	 |
	| 17123432 	| maria 	| 8 		| 8.0    |
	| 16241324 	| pedro 	| 8 		| 7.9 	 |
	+---------------+---------------+---------------+--------+

	+ NOTAS.DAT:
	+---------------+---------+---+
	| cedula/asig 	| periodo | d |
	+---------------+---------+---+
	| 1734211122 	| 2007-2  | 8 |
	| 1641134411 	| 2006-3  | 5 |
	| 1624132447 	| 2007-2  | 8 |
	| 1734211111 	| 2007-1  | 9 |
	| 1624132493 	| 2008-1  | 8 |
	| 1624132489 	| 2007-3  | 8 |
	+---------------+---------+---+

	+ MATERIA.DAT:
	+-----+-----------------+
	| cod | nombre 		|
	+-----+-----------------+
	| 11  | Computación I 	|
	| 22  | Computación II  |
	| 47  | Estructura 	|
	| 89  | Programación I  |
	| 93  | Programación II |
	+-----+-----------------+

	+ CARRERA.DAT:
	+-----+-----------------+
	| cod | Nombre 		|
	+-----+-----------------+
	| 5   | Ing. Industrial |
	| 6   | Ing. Electrónica|
	| 8   | Ing. Informática|
	| 9   | Ing. Mecánica 	|
	+-----+-----------------+

Para la salida del programa genera un archivo txt llamado MARATON.TXT indicando
en la parte superior: 
Título y rótulo de las columnas, cédula, nombre del alumno, carrera, índice, 
nombre de la asignatura donde obtuvo la más alta puntuación
