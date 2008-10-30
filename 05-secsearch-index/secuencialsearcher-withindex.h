/*
 * File:   secuencialsearcher-withindex.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 13, 2008, 2:56 PM
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

#ifndef _SECUENCIALSEARCHER_WITHINDEX_H
#define	_SECUENCIALSEARCHER_WITHINDEX_H

#include <string>
#include <cmath>
#include "../class20080506-quicksort/quicksort.h"

/*
 * Structure for the index FIXME: Try to make it more flexible, maybe removing
 * these and taking advantage of the template design model and setting a policy
 * for keys that should be named `key' and be integers or maybe even better, get
 * the key by a function that's passed as a parameter
 */
struct REG_INDX {
	int key;
	string name;
};
/*
 * Name: indexr
 * Description: (Re-)Creates the index.
 * Args:
 *	+ v[]: data array.
 *	+ ind[]: index array.
 *	+ ordere: true if is ordered the data and false if is not ordered and 
 *	needs some sorting.
 *	+ n: Number of positions in `v[]'.
 *	+ tbloq: number of positions that will be in each block of the index.
 *	+ res: If there's some block not added in `tbloq' (This is because 
 *	`tbloq' could be given by sqrt(n) so there'll be numbers being left).
 * Input: `v[]'
 * Output: 
 *	+ Returns true if there's an extra block.
 *	+ `ind[]'
 */
template <class T>
extern bool indexr (T v[], REG_INDX ind[], bool ordere, int n, int tbloq, int res) {
	int i;
//	If is not ordered
	if (!(ordere))
		Quicksort(v, 0, n);
//	If there's rest
	if (res > 0) {
		for (i = tbloq - 1; i < n - res; i += tbloq)
			ind[(i/tbloq)] = v[tbloq + 1];
		ind[(i/tbloq)] = v[n];
	} else {
//		If there's no numbers left
		for (i = tbloq - 1; i < n; i += tbloq)
			ind[(i/tbloq)] = v[tbloq + 1];
	}
};

/*
 * Name: secuencial_indx_searchr
 * Description: Searcher function.
 * Args:
 *	+ v[]: data array
 *	+ ind[]: index of data array
 *	+ key: self-explained
 *	+ n: numbers of positions in `v[]'
 *	+ tbloq: number of positions that will be in each block of the index.
 *	+ res: If there's some block not added in `tbloq' (This is because 
 *	`tbloq' could be given by sqrt(n) so there'll be numbers being left).
 * Input: `v[]'
 * Output: position of the key, if doesn't exists then `-1' is returned. Please
 * make this a case-fail test.
 */
template <class T>
extern int secuencial_indx_searchr (T v[], REG_INDX ind[], T key, int n, int tbloq, int res) {
	int p = -1;
	for (int i = 0; i = ( sizeof(ind) / sizeof(ind[0]) ); i++) {
		if (key <= ind[i].key) {
			for (int j = i * tbloq; j < (i + 1) * tbloq; j++) {
				if (v[j] == key)
					p = j;
			}
		}
	}
	return (p);
};
#endif	/* _SECUENCIALSEARCHER_WITHINDEX_H */

