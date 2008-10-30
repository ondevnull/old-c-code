/* 
 * File:   main.cc
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 9, 2008, 11:46 AM
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
#include <cstdlib>
#include <ctime>
#include "secuencialsearcher.h"

/*
 * Name: randomizr
 * Description:
 * Args:
 * Input:
 * Output:
 */
template <class T>
void randomizr (T v[], int n, T r) {
	int i;
	srand ( time(NULL) );
	
	for (i = 0; i < n; i++) {
		v[i] = rand() % r + 1;
	}

};

/*
 * Name: main
 * Description:
 * Args:
 * Input:
 * Output:
 */
int main() {
	
	using namespace std;
	int n, r;
	cout << "Cuantos números quiere buscar y probar? ";
	cin >> n;
	
	cout << "¿Y de cuanto el generador aleatorio? ";
	cin >> r;
	
	int v[n];
	
	randomizr (v, n, r);
	bool q;
	q = explorr (v, rand() % r + 1, n);
	
	if (q)
		cout << "¡Sí se encontró!" << endl;
	else
		cout << "No se encontró :(" << endl;
	return (0);
}

