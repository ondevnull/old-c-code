/*
 * File:   agencias.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on June 13, 2008, 9:04 AM
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

#ifndef AGENCIAS_H
#define	AGENCIAS_H
#include <iostream>
#include <string>
#include <cstdio>
#include "estructuras.h"
#include "autos.h"
/*
 * Name:
 * Description:
 * Args:
 * Input:
 * Output:
 */

class agencias {
private:
	FILE *f;
	std::string estados[] = {"ZULIA", "FALCON", "TACHIRA", "MERIDA", "TRUJILLO", "BARINAS"};
public:
	agencias (FILE *archivo);
	void agregar (std::string estado);
	void agregar_inv (std::string marca, int cod_agencia, int modelo, int n);
	int inv (std::string marca, int nom_agencia, int modelo);
	std::string agencia_estado (int cod_agencia);
	int qtyagencia(std::string marca);
};


agencias::agencias (FILE *archivo) {
	f = archivo;
}


int agencias::qtyagencia(std::string marca) {
	rewind(f);
	r_autos buf;
	while (!feof(f)) {
		fread (buf, sizeof(buf), 1, f);
		autos o(f);
		int q = o.marca_query(marca);
		// Si la marca se encontró entonces:
		if (q>=0) {
			for (int i=0; i < 6; i++) {
				if (buf.agencia[i].empty()) {
					break;
				}
			}
			return (i - 1);
		}
	}
	return (-2);
}

void agencias::agregar (std::string estado, std::string marca) {
	// Transformandolo a mayúsculas todo.
	std::transform (estado.begin(), estado.end(), estado.begin(), std::toupper);
	r_autos buf;
	autos o(f);
	int m = o.marca_query(marca);
	rewind (f);
	int c1 = -1;
	while (!feof(f)) {
		c1++;
		fread (buf, sizeof(buf), 1, f);
		if (buf.codmarca == m)
			break;
	}
	int pos = qtyagencia(marca) - 1;
	std::cout << "Introduzca el nombre de la nueva agencia: ";
	std::cin >> buf.agencia[pos];
	std::cout << "Introduzca el código de la agencia: ";
	std::cin >> buf.codagencia[pos];
	fseek (f, c1 * sizeof(buf), 0);
	fwrite (buf, sizeof(buf), 1, f);
	
	std::cout << "¿Desea ingresar inventario? <s/n> ";
	char q;
	std::cin >> q;
	
	int cont = 0;
	while (q == 's')||(q == 'S')) {
		o.modelos_query(m);
		std::cout << "Ingrese el código del auto a agregar en inventario: ";
		std::cin << int az;
		std::cout << "¿Cuantos va a agregar? ";
		std::cin << int n;
		agregar_inv (buf.codagencia[pos], az, n);
		std::cout << "¿Desea ingresar inventario en otros modelos? <s/n> ";
		std::cin >> q;
	}
}

void autos::agregar_inv (std::string marca, int cod_agencia, int modelo, int n) {
	if (f==NULL)
		std::cout << "No hay nada en el archivo!" << std::endl;
	else {
		r_autos buf;
		rewind (f);
		int c1 = -1;
		autos o(f);
		int m;
		if (m = o.marca_query(marca) > -1) {
			while (!feof(f)) {
				c1++;
				fread (buf, sizeof(buf), 1, f);
				if (m == buf.codmarca) {
					for (int i = 0; i < qtyagencia(marca); i++) {
						if (buf.codagencia[i] == cod_agencia) {
							for (int j = 0; j < o.cuantos(buf); j++) {
								if (buf.codmodelos[j] == modelo) {
									fseek (f, c1 * sizeof(buf), 0);
									buf.invmodelos[i][j] = n;
									fwrite (buf, sizeof(buf), 1, f);
								}
							}
						}
					}
				}
			}
		}
	}
}

int autos::inv (std::string marca, int nom_agencia, int modelo) {
	if (f==NULL)
		return (-1);
	else {
		rewind (f);
		r_autos buf;
		autos o(f);
		int m;
		if (m = o.marca_query(marca) > -1)
			while (!feof(f)) {
				fread (buf, sizeof(buf), 1, f);
				if (m == buf.codmarca) {
					for (int i = 0; i < qtyagencia(marca); i++) {
						if (buf.codagencia[i] == nom_agencia) {
							for (int j = 0; j < o.cuantos(buf); j++) {
								if (modelo == buf.codmodelos[j])
									return (buf.invmodelos[i][j]);
							}
						}
					}
				}
			}
		else
			return (-2);
	}
}
#endif	/* AGENCIAS_H */

