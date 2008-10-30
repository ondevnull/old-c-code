/* 
 * File:   main.cc
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 2, 2008, 11:18 AM
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


/* Codificación del método SHELL:
 * Ordenar un verctor de enteros en forma ascendente utilizando SHELL.
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <errno.h>
#include "shell.h"

using namespace std;

/*
 * Name: imprimir
 * Description:
 * Args:
 * Input:
 * Output:
 */
template <class T>
void imprimir (T v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
	 cout << "valor " << i + 1 << ": " << v[i] << endl;   
}

/*
 * Name: main
 * Description:
 * Args:
 * Input:
 * Output:
 */
int main() {
    int v[] = {19, 25, 32, 14, 22, 11, 30, 35, 16, 28};
    int num = sizeof(v) / sizeof(v[0]);
    imprimir (v, num);
    shell (v, num);
    imprimir (v, num);    
    return (0);
}

