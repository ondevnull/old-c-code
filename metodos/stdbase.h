/*
 * File:   stdbase.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 10, 2008, 11:01 AM
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

#ifndef _STDBASE_H
#define	_STDBASE_H
#include <ctime> // For srand seeding
#include <cstdlib> // For randomizr

/*
 * Name: swappr
 * Description:
 * Args:
 * Input:
 * Output:
 */
template <class T>
extern void swappr (T &a, T &b)
{
	T aux;
	aux = a;
	a = b;
	b = aux;
};

template <class T>
extern void randomizr (T v[], int n)
{
	srand ( time(NULL) );
	for (int i = 0; i < n; i++)
		v[i] = rand() % n + 1;
};

#endif	/* _STDBASE_H */

