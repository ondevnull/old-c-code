/*
 * File:   aseguradoras.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on June 19, 2008, 6:11 PM
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

#ifndef ASEGURADORAS_H
#define	ASEGURADORAS_H
#include <cstdio>
#include <string>
#include "estructuras.h"

/*
 * Name:
 * Description:
 * Args:
 * Input:
 * Output:
 */
class aseguradoras {
private:
	FILE *f;
public:
	aseguradoras (FILE *archivo) { f = archivo; }
	int agregar (std::string nombre, int cod);
	int query (int cod, std::string &nombre);
	
};

int aseguradoras::agregar(std::string nombre, int cod) {
	if (f==NULL)
		return (-1); /* Devuelve -1 cuando no hay archivo */
	else {
		std::transform (nombre.begin(), nombre.end(), nombre.begin(), std::toupper);
		r_baseg buf;
		buf.nombre = nombre;
		buf.codigo = cod;
		fseek (f, sizeof(buf), SEEK_END);
		fwrite (buf, sizeof(buf), 1, f);
		return (0); /*Succesfull */
	}
	return (-2); /* Si algo raro sucede y llega hasta acá */
}

int aseguradoras::query (int cod, std::string &nombre) {
	if (f == NULL)
		return (-1); /* Si no hay archivo */
	else {
		rewind (f);
		r_baseg buf;
		while (!feof(f)) {
			fread (buf, sizeof(buf), 1, f);
			if (buf.codigo == cod) {
				nombre = buf.nombre;
				return (0); /* Operación exitosa */
			}
		}
	}
	return (-2); /* Si no consigue nada */
}

#endif	/* ASEGURADORAS_H */

