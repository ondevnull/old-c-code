/*
 * File:   shell.h
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 10, 2008, 10:59 AM
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

#ifndef _SHELL_H
#define _SHELL_H

#include "../metodos/stdbase.h"
/*
 * Name: shell
 * Description:
 * Args:
 * Input:
 * Output:
 */
template <class T>
void shell (T v[], int n) {
  int inter = n/2, i;
  bool band;
  
  while (inter) {
    band = true;
    while (band) {
      band = false;
      for (i = 0; i + inter < n; i++) {
        if (v[i] > v[i+inter]) {
          swappr (v[i], v[i+inter]);
          band = true;
        }
      }
    }
    inter /= 2; // inter = inter / 2;
  }
};

#endif  /* _SHELL_H */

