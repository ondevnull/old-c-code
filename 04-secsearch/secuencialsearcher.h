/*
 * File:   secuencialsearcher.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 9, 2008, 11:45 AM
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


#ifndef _SECUENCIALSEARCHER_H
#define	_SECUENCIALSEARCHER_H

#include "../class20080506-quicksort/quicksort.h"
#include <cmath>
#include <iostream>

/*
 * Name: printr
 * Description:
 * Args:
 * + n is the number that have the array.
 * + v[]: data
 * Input: Args.
 * Output: stdout
 */
template <class T>
void printr (T v[], int n) {
	int i;
	using namespace std;
	for (i = 0; i < n; i++)
		cout << v[i] << endl;
};

/*
 * Name: searchr
 * Description: Searcher that returns if some key is found
 * Args:
 * + n is the number that have the array.
 * + v[]: data
 * + key: what we're looking for
 * + a: block in wich the data is
 * Input: Args.
 * Output: Returns true or false if found something.
 */
template <class T>
bool searchr (T v[], T key, int n, int a, int tbloq)
{
	int i, st, li;
	if ( a <= (pow (tbloq, 2)) ) {
		st = a - tbloq;
		li = a;
	} else {
		st = n - a;
		li = n;
	}
	for (i = st; i < li; i++) {
		if (key == v[i]) {
			return (true);
			break;
		}
	}
	return (false);
};

/*
 * Name: searchr
 * Description: Searcher that returns the position where found trough the p 
 * pointer
 * Args:
 * + n is the number that have the array.
 * + v[]: data
 * + key: what we're looking for
 * + a: block in wich the data is
 * + &p: returns the position
 * Input: Args.
 * Output: Returns true or false if found something.
 */
template <class T>
bool searchr (T v[], T key, int n, int a, int tbloq, int &p)
{
	int i, st, li;
	if ( a <= (pow (tbloq, 2)) ) {
		st = a - tbloq;
		li = a;
	} else {
		st = n - a;
		li = n;
	}
	for (i = st; i < li; i++) {
		if (key == v[i]) {
			p = i;
			return (true);
			break;
		}
	}
	return (false);
};


/*
 * Name: explorr
 * Description: Explorer of data, finds how to divide in blocks after sorting.
 * Args:
 * + v[]: data
 * + n: number of positions in v[].
 * + key: value too look for.
 * Input: Args.
 * Output: returns true or false if the value was found
 */
template <class T>
bool explorr (T v[], T key, int n) {
	using namespace std;
	
	int tbloq, res, a;
	bool q = false, k = false;
//	Organizr
	Quicksort (v, 0, n);
	
	printr (v, n);
	
	tbloq = sqrt(n);
	res = n % a;
	
	for (a = tbloq; a < n; a += tbloq) {
		if (v[a] <= key) {
			k = searchr (v, key, n, a, tbloq);
			q = true;
		}
	}
	if ((!q)&&(res>0)) {
		k = searchr (v, key, n, res, tbloq);
	}
	
	return (k);
};

/*
 * Name: explorr
 * Description: Explorer of data, finds how to divide in blocks after sorting.
 * Returns the position where key was found.
 * Args:
 * + v[]: data
 * + n: number of positions in v[].
 * + key: value too look for.
 * + &p: Position where the key was found
 * Input: Args.
 * Output: returns true or false if the value was found
 */
template <class T>
bool explorr (T v[], T key, int n, int &p) {
	using namespace std;

	int tbloq, res, a;
	bool q = false, k = false;
//	Organizr
	Quicksort (v, 0, n);
	
	printr (v, n);
	
	tbloq = sqrt(n);
	res = n % a;
	
	for (a = tbloq; a < n; a += tbloq) {
		if (v[a] <= key) {
			k = searchr (v, key, n, a, tbloq, p);
			q = true;
		}
	}
	if ((!q)&&(res>0)) {
		k = searchr (v, key, n, res, tbloq, p);
	}
	
	return (k);
};

#endif	/* _SECUENCIALSEARCHER_H */

