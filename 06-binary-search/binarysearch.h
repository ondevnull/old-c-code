/*
 * File:   binarysearch.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 28, 2008, 11:13 AM
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

#ifndef _BINARYSEARCH_H
#define	_BINARYSEARCH_H
/*
 * Name: binary_searchr
 * Description: Binary Searcher
 * Args:
 *	+ v[]: data array
 *	+ clave: key
 *	+ li: start position
 *	+ ls: stop position
 * Input: `v[]' and `clave'
 * Output: position of the key, if doesn't exists then returns `-1', please make
 * a case-fail test when using.
 */
extern int binary_searchr (T v[], T clave, int li, int ls)
{
    int pmed;
    while (li <= ls) {
       pmed = (li + ls) / 2;
       if (clave == v[pmed])
          return pmed;
       if (clave > v[pmed])
          li = pmed + 1;
       else
          ls = pmed - 1;
    }
    return (-1);
}

#endif	/* _BINARYSEARCH_H */

