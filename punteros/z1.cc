/* 
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * More? http://ghostbar.ath.cx/ 
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
#include <cstring>
#include <cstdlib> 

using namespace std;

void former (string h, int p, int a, string k) {
    string e1, e2;
    int u = h.size();
    cout << "Got1 " << a << endl;
    if (a==0) {
        cout << "Got2" << endl;
        cout << k+h << endl;
    } else if (a==(h.size()-1)) {
        cout << "Got3" << endl;
        cout << h+k << endl;
    } else {
        cout << "Got4" << endl;
        e1 = h.substr(0, a);
        e2 = h.substr(a);
        cout << e1+k+e2 << endl;
    }
//    cout << d[p][a] << endl;
}
	
/**********************************************************
 * Name:
 * Description:
 * Args:
 * Input:
 * Output:
 **********************************************************/

int main(){ 
	string q;
	q = "abc";
	cout << q << " " << q.size() << endl;
	former (q, 0, 1, "d");
        return(0);
}

