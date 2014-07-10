/* 
 * File:   memoria_dinamica.c
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on April 1, 2008, 4:19 PM
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
/*
 * Name: f
 * Description: Function receiving a single-array pointer
 * Args: `*a'
 * Input:
 * Output:
 */
void f(int *a)
{
    a[2] = 3;
}


/*
 * Name: g
 * Description: Function receiving a multi-array pointer
 * Args: `**a'
 * Input:
 * Output:
 */
void g(int **a) {
    a[2][3] = 4;
}

/*
 * Name: main
 * Description:
 * Args:
 * Input:
 * Output:
 */
int main(int argc, char** argv) {
    
    
    int *a, **b;
    x = 5;
    // Así se inicializan las posiciones en los vectores
    a = new int [x];
    
    // Así  se inicializan las posiciones de las matrices de las filas
    b = new int *[x];
    // Luego con un for se inicializan las columnas
    for (i = 0; i < y; i++)
        b[i] = new int[y];
    
    // Así podremos utilizarlos
    a[i];
    b[i][j];
    
    // Se pasan los datos de arreglos sin &
    f(a);
    g(b);
    return (0);
}
