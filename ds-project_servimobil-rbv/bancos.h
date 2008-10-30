/*
 * File:   bancos.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on June 19, 2008, 6:38 PM
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

#ifndef BANCOS_H
#define	BANCOS_H
#include "estructuras.h"
#include <string>
#include <cstdio>
/*
 * Name:
 * Description:
 * Args:
 * Input:
 * Output:
 */
class bancos {
private:
	FILE *f;
public:
	bancos (FILE *archivo) { f = archivo; }
	int agregar (std::string nombre, int cod);
	int q_banco_cod (std::string nombre);
	int q_banco_nom (std::string &nombre, int cod);
};

int bancos::agregar (std::string nombre, int cod) {
	if (f == NULL)
		return (-1); /* Error porque no hay archivo */
	else {
		r_baseg buf;
		buf.codigo = cod;
		std::transform (nombre.begin(), nombre.end(), nombre.begin(), std::toupper);
		buf.nombre = nombre;
		fseek (f, sizeof(buf), SEEK_END);
		fwrite (buf, sizeof(buf), 1, f);
		return (0); /* Succesfull */
	}
	return (-2); /* Si algo raro sucede llegará aquí */
}

int bancos::q_banco_cod (std::string nombre) {
	if (f == NULL)
		return (-1); /* Error porque no hay archivo */
	else {
		r_baseg buf;
		std::transform (nombre.begin(), nombre.end(), nombre.begin(), std::toupper); /* Transformando a mayusculas */
		rewind (f);
		while (!feof(f)) {
			fread (buf, sizeof(buf), 1, f);
			if (buf.nombre == nombre)
				return (buf.codigo);
		}
	}
	return (-2); /* No se encontró en el archivo el nombre */
}

int bancos::q_banco_nom (std::string &nombre, int cod) {
	if (f == NULL)
		return (-1); /* No hay ningún archivo */
	else {
		r_baseg buf;
		rewind (f);
		whil (!feof(f)) {
			fread (buf, sizeof(buf), 1, f);
			if (buf.codigo == cod) {
				nombre = buf.nombre;
				return (0); /* Succesfull */
			}
		}
	}
	return (-2); /* No se encontró */
}

#endif	/* BANCOS_H */

