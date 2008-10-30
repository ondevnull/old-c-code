/*
 * File:   ordenaciondearchivos.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 23, 2008, 11:58 AM
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

#ifndef _ORDENACIONDEARCHIVOS_H
#define	_ORDENACIONDEARCHIVOS_H

#include <cstdlib>

/*
 * Name: ordenar
 * Description:
 * Args:
 * Input:
 * Output:
 */
template <class Tr>
void ordenar ( FILE *f, Tr buf, int n)
{
	int i, j, posmen;
	Tr regmen, regini;
	for (i = 0; i < (n - 1); i++)
	{
		posmen = i;
		fseek (f, i * sizeof(buf), 0);
		fread (&buf, sizeof (buf), 1, f);
		regini = regmen = buf;
		for (j = i + 1; j < n; j++)
		{
			fread (&buf, sizeof(buf), 1, f);
			if (buf.clave < regmen.clave)
			{
				regmen = buf;
				posmen = j;
			}
		}
		if (i != posmen) {
			fseek (f, i * sizeof(buf), 0);
			fwrite (&regmen, sizeof(buf), 1, f);
			fseek (f, posmen * sizeof(buf), 0);
			fwrite (&regini, sizeof(buf), 1, f);
		}
	}
};

#endif	/* _ORDENACIONDEARCHIVOS_H */

