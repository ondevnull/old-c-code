/* 
* File:   insercion.h
* Author: Jose Luis Rivas <ghostbar38@gmail.com>
* Created on May 6, 2008, 11:13 AM
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

#ifndef _INSERCION_H
#define	_INSERCION_H

/*
 * Name: insercion
 * Description:
 * Args:
 * Input:
 * Output:
 */
template <class tipo>
void insercion(tipo v[], int n)
{
	int i, j;
	tipo eleins;
	for (i = 1; 1 < n; i++)
	{
		eleins = v[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (eleins < v[j])
				v[j + 1] = v[j];
			else
				break;
		}
		v[j + 1] = eleins;
	}
};


#endif	/* _INSERCION_H */

