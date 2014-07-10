/* 
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * More? http://ghostbar.ath.cx/ 
 *
 * Copyright (c) 2008 Jose Luis Rivas <ghostbar38@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining 
a copy
 * of this software and associated documentation files (the "Software"), 
to deal
 * in the Software without restriction, including without limitation the 
rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or 
sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be 
included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT 
SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR 
OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
DEALINGS IN
 * THE SOFTWARE.
 */


#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib> 

using namespace std;
        
/**********************************************************
 * Name:
 * Description:
 * Args:
 * Input:
 * Output:
 **********************************************************/

int main(){ 

        string q = "abc", h, k, o;
        int chs=2;
        o = q.substr(0, chs); // Get the substring from 0 with length of chs minus 1 into `h'
	h = o.substr(0, chs - 1);
        k = o.substr(chs - 1);
	cout << h << " " << k << " " << o << endl;

        return(0);
}

