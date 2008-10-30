/*
 * File:   structures.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 31, 2008, 12:21 PM
 *
 * Copyright (c) 2008 Jose Luis Rivas <ghostbar38@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _STRUCTURES_H
#define	_STRUCTURES_H
#include <string>
/*
 * Name:  REG_ALU
 * Description: Estructura de `ALUMNO.DAT'
 */
struct REG_ALUMNO {
	int ced; // cedula - clave
	string nom; // nombre
	int carr; // carrera
	float ind; // indice
};

/*
 * Name:  REG_NOTA
 * Description: Estructura de `NOTA.DAT'
 */
struct REG_NOTA {
	unsigned ced; // cedula - clave
	int not; // notas
	int per; // Período
};

/*
 * Name:  REG_MATERIA
 * Description: Estructura de `MATERIA.DAT'
 */
struct REG_MATERIA {
	int cod; // código de materia - clave
	string des; // nombre de la materia
};

/*
 * Name:  REG_CARRERA
 * Description: Estructura de `CARRERA.DAT'
 */
struct REG_CARRERA {
	int cod; // código de carrera - clave
	string des; // nombre de carrera
};


/*
 * Name: REG_DATA
 * Description: Registro de donde están los archivos
 */
struct REG_DATA {
	string what; // Que
	string where; // Donde
};


#endif	/* _STRUCTURES_H */

