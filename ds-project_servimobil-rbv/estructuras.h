/*
 * File:   estructuras.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on June 15, 2008, 6:02 PM
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

#ifndef ESTRUCTURAS_H
#define	ESTRUCTURAS_H
#include <string>
/*
 * Name:
 * Description:
 * Args:
 * Input:
 * Output:
 */
struct r_autos {
	std::string marca;
	int codmarca;
	std::string agencia[6];
	int codagencia[6];
	int invmodelos[6][3];
	std::string modelos[3];
	int codmodelos[3];
	float precmodelos[3];
	char tipo_modelos[3];
};

struct r_clientese {
	std::string nom_cliente;
	int ci_cliente;
	int codmarca;
	int codmodelo;
	std::string estado;
};

struct r_clientes {
	std::string nom_cliente;
	int ci_cliente;
	int codmarca;
	int codmodelo;
	std::string estado;
	float montodecompra;
	float credito;
	float cuota;
	int tasa;
};

struct r_baseg {
	std::string nombre;
	int codigo;
};

#endif	/* ESTRUCTURAS_H */

