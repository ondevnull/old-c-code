/* 
 * File:   knuth-sorting.cc
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on April 3, 2008, 12:39 AM
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
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

/*
 * Name: pif
 * Description: Counts how many lines does the file have. Doing the read of the
 * file in the old C-fashion
 * Args: None
 * Input: None
 * Output: return an integer
 */
int pif() {
    FILE *f;
    char trash[50];
    int a = 0;
    f = fopen ("permu.txt", "r");
    while (!(feof(f)))
    {
        fscanf (f, "%s", trash);
        a++;
    }
    fclose(f);
    return (a-1);
}

/*
 * Name: lo
 * Description: Loads the data in `*d', doing it in the C++ fashion
 * Args: `*d', the data dynamic array and `n', the amount of lines in 
 * `permu.txt'
 * Input: `f'
 * Output: `*d'
 */
void lo (string *d, int n) {
    cout << "Got in to `lo()' function" << endl;
    ifstream f;
    f.open ("permu.txt", ios::in);
    int a;
    cout << "Reading data from file..." << endl;
    for (a=0; a<n; a++)
        getline (f, d[a]);
    cout << "Loaded the data into the array of string!" << endl;
    for (a=0; a<n; a++)
        cout << d[a] << endl;
    f.close();
}

/*
 * Name: pr
 * Description: Prints the result in `solu.txt'.
 * Args: 
 * + `**d' is the data array.
 * + `p' is the position in the array where the final data is stored.
 * + `s' is how many sorts are.
 * + `q' determines if the file have been open already so will not overwrite but modify.
 * Input: `**d'
 * Output: `f'
 */
void pr (string **d, long p, long s, int q) {
    ofstream f;
    // If is the first line then open the file as new else open the file only to
    // modify.
    if (q==0)
        f.open ("solu.txt", ios::out);
    else
        f.open ("solu.txt", ios::app);
    long a;
    for (a=0; a<s; a++)
        f << d[p][a] << endl;
    f.close();
}

/*
 * Name: fac
 * Description: Determines the factorial of a number.
 * Args: `a', a long number.
 * Input: Args.
 * Output: return
 */
long fac (long a) {
  if (a > 1)
   return (a * fac(a-1));
  else
   return (1);
}

/*
 * Name: former
 * Description:
 * Args: 
 * + `h': string helper
 * + `**d': temporary dynamic data array
 * + `p': first position in the array according to the number of permuts
 * + `a': second position in the array occupied according to the line, that
 * means is not going to be repeated once since goes to the end twice.
 * + `k': this is the movible key
 * Input: `h' and `k'
 * Output: `**d'
 */
void former (string h, string **d, long p, long a, string k, long u, long cs) {
    string e1, e2;
    // If is the first position
    if (a==0) {
        d[p][cs] = k+h;
    } else if (a==u) {
        // If is the last position
        d[p][cs] = h+k;
    } else {
        // If is somewhere in the middle
        e1 = h.substr(0, a);
        e2 = h.substr(a);
        d[p][cs] = e1+k+e2;
    }
    cout << d[p][cs] << endl;
}

/*
 * Name: sort
 * Description: Sorts things in the way knuth did
 * Args: 
 *  + `*d': Data dinamic array.
 *  + `**dd': Dinamic array storing temporal data from sorts.
 *  + `cs': Counter of sorts.
 *  + `ms': Max amount of sorts giving by fac and how many characters are going
 *  to be sorted.
 *  + `chs': is how many characters are being sorted, should start with 2 always
 *  + `mcs': is the max amount of characters to be sorted.
 *  + `p': is the position of the string being sorted in `*d'
 * Input: `*d'
 * Output: `pr()' function
 */
void sort (string *d, string **dd, long cs, long ms, long chs, long mcs, int p) {
    long q, u = chs-1, a, y;
    string h, k;
    q = cs;
    /*
     * Getting the key, does get it from the original string depending of the
     * position in the original array and depending on the value of `chs' that
     * shows which character is being sorted
     */
    k = d[p].substr(chs - 1, 1);
    
    // The decision here is, is at the end? If not then: start running!
    if ((chs==mcs)&&((cs + 1)==ms))
    {
        cs++;
        // If is not the first character being sorted then:
        if (chs!=2) {
            /*
             * What's `y'? It comes from the size of how many characters are in
             * the last string sorted.
             */
            y = dd[chs - 3][0].size();
            h = dd[chs - 3][y - 1].substr(0);
        } else {
            // If is the first character being sorted then y it's 1...
            y = 1;
            h = d[p].substr(0, 1);
        }
        former (h, dd, chs - 2, y, k, u, cs - 1);
        // If it's here then that means ended sorting and there's a result,
        // let's print then!
        cout << "The recursive function has got to the end now" << endl << "let's print the result" << endl;        
        cout << "Calling `pr()'..." << endl;
        pr(dd, chs - 2, ms, p);
        cout << "Printed the sorts of the string " << d[p] << "." << endl;
        cout << "Freeing memory from the dynamic array" << endl;
        delete[] dd;
        cout << "Clean." << endl;
    } else {
        /* If the amount of sorts it's equal to the max amount then makes `cs'
         * zero and adds one more to `ms'
         */
        if ((cs + 1)>ms) {
            cs = 0;
            q = 0;
            ms = fac(++chs);
            cout << "Getting a new key for sorting..." << endl;
            k = d[p].substr(chs - 1, 1);
        }
        /* If `cs' is zero that means is starting so we need the exact string 
         * that's going to be sorted out and create the dynamic array.
         */
        if (cs==0) {
            dd[chs - 2] = new string [fac(chs)]; // Creates the dynamic array

        }
        /* If is starting, that means is the first sort then should happen that
         * copies d[p] to dd to make the substring.
         */
        if (chs==2) {
            h = d[p].substr(0, 1);
        } else {
            /*
             * What's `a'?:  it's something like:
             *      a = ( The sort being passed / (factorial of how many chars
             *      are being sorted) that sum between how many chars are being
             *      sorted and the minus of 0.0001 is trying to avoid that when
             *      gives an entire number it show one more, should show one
             *      number less.
             */
            a = (cs / (fac((dd[chs - 3][0].size() + 1)) / (dd[chs - 3][0].size() + 1))) - 0.0001;
            /*
             * What's `y'?: it's the sort being passed between the result that 
             * `a' should give.
             */
            y = (cs / (dd[chs - 3][0].size() + 1));
            // `h' is the string helper
            h = dd[chs - 3][y].substr(0);
        }
        // If chs is not 2
        if (chs!=2) {
            // `q' is himself less the amount of complete set of sorts passed.
            q = q - (y*(h.size() + 1));
        } else if (cs == 1) {
            // If chs is 2 and cs is 1 that means is the second sorting
            q = 1;
        }
        former (h, dd, chs - 2, q, k, u, cs);
        cout << ++cs << "/" << ms << " :: " << chs << "/" << mcs << endl;
        sort (d, dd, cs, ms, chs, mcs, p);
    }
}

/*
 * Name: main
 * Description:
 * Args:
 * Input:
 * Output:
 */
int main () {
    string *d;
    string **dd;
    int nd, a;
    nd = pif();
    cout << "Loaded the amount of lines" << endl;
    d = new string [nd];
    cout << "Built the dynamic array" << endl;
    lo(d, nd);
    cout << "Loaded all the data, now let's sort" << endl;
    // Running the sort as many times as lines exists in the input file
    for (a=0; a<nd; a++) {
        cout << "Creating temporal dynamic array..." << endl;
        dd = new string *[d[a].size()];
        cout << "Created." << endl;
        cout << "Sorting line number " << a + 1 << endl;
        sort(d, dd, 0, fac(2), 2, d[a].size(), a);
    }
    cout << "Done sorting, check the results in the output file..." << endl;
    cout << "Lines processed from permu.txt: " << a << "." << endl;
    return 0;
}
