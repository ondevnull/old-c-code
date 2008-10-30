/* 
 * File:   quicksort.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 6, 2008, 11:15 AM
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
// What's the maximum number of elements for burbuja being efficient
#define max 5

#ifndef _QUICKSORT_H
#define	_QUICKSORT_H
#include "../metodos/stdbase.h"

/*
 * Name: burbuja
 * Description:
 * Args:
 * Input:
 * Output:
 */
template <class T>
void burbuja (T v[], int ini, int fin)
{
	int i, j;
	for (i = fin; i > ini; i--)
	{
		for (j = ini; j < i; j++)
			if (v[j]>v[j+1]) 
				swappr(v[j], v[j+1]);
	}
};

/*
 * Name: Quicksort
 * Description: Este es un Quicksort que usa como pivote
 * Args: 
 *	+ v[] = vector
 *	+ li = Posición de arranque
 *	+ ls = limite superior
 * Input:
 * Output:
 */
template <class T>
void Quicksort (T v[], int li, int ls)
{
	if (ls - li + 1 <= max)
		burbuja(v, li, ls);
	else {
		int i = li + 1, j = ls;
		T pivo = v[li];
		do {
			while (v[i] < pivo && i <= ls) 
				i++;
			while (v[j]>pivo) 
				j--;
			if (i<j)
			{
				swappr(v[i], v[j]);
				i++; j--;
			}
		} while (i<j);
		swappr (v[li], v[j]);
		Quicksort (v, li, j-1);
		Quicksort (v, j+1, ls);
	}
};

template <class T>
void Imprimir (T v[], int n)
{
	using namespace std;
	int i;
	for (i = 0; i < n; i++)
		cout << v[i] << " " << endl;
};

#endif	/* _QUICKSORT_H */

