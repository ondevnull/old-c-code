/* 
 * File:   main.cc
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 15, 2008, 11:05 PM
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

#include <iostream>
#include <string>
#include <cstdlib>
#include "secuencialsearcher-withindex.h"
#include "../metodos/stdbase.h"

/*
 * Name: menu
 * Description:
 * Args:
 * Input:
 * Output:
 */
extern int menu (int &n, int &tbloq, int &res) {
	int opt;
//	Texto en cuestión del menú
	cout << "\tMenú\n"
		"1. Crear vector inicial con valores aleatorio y crear índice\n"
		"2. Crear vector inicial con valores aleatorios\n"
		"3. (Re-)Crear índice\n"
		"4. Buscar valor\n"
		"5. Ingresar valor y recrear índice\n"
		"6. Eliminar valor y recrear índice\n"
		"7. Salir\n";
	cout << "\t Opción: ";
	cin >> opt;
//	Según casos hacer:
	switch (opt) {
		case (1):
			cout << "¿Cuantas posiciones va a tener el vector?";
			cin >> n;
			cout << "Creando vector aleatorio..." << endl;
			randomizr(v, n);
			cout << "Indexando..." << endl;
			n = sizeof(v)/sizeof(v[0]);
			tbloq = sqrt(n);
			res = n - (tbloq * n);
			indexr(v, ind, false, n, tbloq, res);
	}
}

/*
 * Name: main
 * Description:
 * Args:
 * Input:
 * Output:
 */
int main() {
	
	return (0);
}

