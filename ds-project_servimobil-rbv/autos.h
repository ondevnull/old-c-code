/*
 * File:   autos.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on June 13, 2008, 9:16 AM
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

#ifndef AUTOS_H
#define	AUTOS_H
#include <string>
#include <cstdio>
#include <iostream>
#include "estructuras.h"
/*
 * Name:
 * Description:
 * Args:
 * Input:
 * Output:
 */
class autos {
private:
	FILE *f;
public:
	autos (FILE *archivo);
	void agregarmarca();
	bool agregarauto (int marca);
	char tipo_query (int modelo);
	void modelos_query (int marca);
	void escribir();
	int cuantos (r_autos buf);
	int marca_query (std::string marca);
};

autos::autos(FILE *archivo) {
	archivo = f;
}

template <class t>
void autos::modelos_query (int marca) {
	if (f==NULL)
		std::cout << "No hay datos en el archivo" << endl;
	else {
		rewind (f);
		while (!feof(f)) {
			r_autos buf;
			fread (buf, sizeof(buf), 1, f);
			if (buf.codmarca == marca) {
				for (int i = 0; i < cuantos (buf); i++)
					std::cout << "Modelo: " << buf.modelos[i] << " Código: " << buf.codmodelos[i] << endl;
			}
		}
	}
}


int autos::marca_query (std::string marca) {
	if (f==NULL) {
		std::cout << "¡El archivo está vacio!" << std::endl;
		return (-1);
	}
	rewind (f);
	std::transform (marca.begin(), marca.end(), marca.begin(), std::toupper);
	while (!feof(f)) {
		fread (buf, sizeof(buf), 1, f);
		if (buf.marca == marca)
			return (buf.codmarca);
	}
	std::cout << "¡No se encontró nada!" << std::endl;
	return (-2);
}

int autos::cuantos (r_autos buf) {
	int q = 0;
	for (int i = 0; i < 3; i++) {
		if (!buf.modelos[i].empty())
			q++;
		else
			break;
	}
	return q;
}

bool autos::agregarauto (int marca) {
	if (f == NULL) {
		std::cout << "¡No hay ninguna marca en el archivo!" << std::endl;
		return (false);
	}
	
	r_autos buf;
	rewind (f);
	int c1 = -1;
	while (!feof(f)) {
		c1++;
		fread (buf, sizeof(buf), 1, f);
		if (buf.marca == marca) {
			int a = cuantos (buf);
			if (a == 3) {
				std::cout << "Ya están llenas las 3 posiciones, no puede guardar más" << endl;
				return (false);
			} else {
				std::cout << "Ingrese el nombre del modelo: ";
				std::cin >> buf.modelos[a];
				std::cout << "Ingrese el código del modelo: ";
				std::cin >> buf.codmodelos[a];
				std::cout << "¿Que tipo es? A para auto y C para camioneta: ";
				std::cin >> buf.tipo_modelos[a];
				std::cout >> "¿Cuál es el precio? ";
				std::cin >> buf.precmodelos[a];
				if (buf.tipo_modelos[a] == 'a')
					buf.tipo_modelos[a] = 'A';
				if (buf.tipo_modelos[a] == 'c')
					buf.tipo_modelos[a] = 'C';
				fseek (f, c1 * sizeof(buf), 0);
				fwrite (buf, sizeof(buf), 1, f);
			}
			if (a == 2)
				return (false);
			else
				return (true);
		} else {
			std::cout << "La marca enviada no se encuentra" << endl;
			return (false);
		}
	}
}

void autos::agregarmarca () {
	r_autos buf;
	
	std::cout << "Por favor ingrese la marca: ";
	std::cin >> buf.marca;
	std::transform (buf.marca.begin(), buf.marca.end(), buf.marca.begin(), std::toupper);
	std::cout << "Por favor ingrese el código de la marca: ";
	std::cin >> buf.codmarca;
	
	fseek (f, sizeof(buf), SEEK_END);
	fwrite (buf.marca, sizeof(buf), 1, f);
	
	char q;
	std::cout << "¿Desea ingresar los datos de los modelos? <s/n> ";
	std::cin >> q;
	
	while ((q=='s')||(q=='S')) {
		bool t = agregarauto (buf.marca);
		if (t) {
			std::cout << "¿Desea ingresar otro modelo? <s/n> ";
			std::cin >> q;
		}
	}
}

char autos::tipo_query (int modelo) {
	if (f==NULL) {
		std::cout << "¡No hay nada en el archivo" << endl;
		return ('E');
	} else {
		while (!feof(f)) {
			r_autos buf;
			fread (buf, sizeof(buf), 1, f);
			for (int i = 0; i < 3; i++) {
				if (modelo == buf.codmodelos[i])
					return (buf.tipo_modelos[i]);
			}
		}
	}
	return ('N');
}

#endif	/* AUTOS_H */
