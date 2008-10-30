/* 
 * File:   main.cc
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on May 29, 2008, 10:45 AM
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
#include <cstdio>


/*
 * Name: main
 * Description:
 * Args:
 * Input:
 * Output:
 */
int main(int argc, char** argv) {
	
	// Checking if the program has been initiated before
	starter ();
	// Declaro la structura de la data
	data = new REG_DATA [4];
	// Le doy valores
	data[0].what = "alumno"; data[1].what = "notas"; data[2].what = "carrera"; data[3].what = "materia";
	open_files (falu, fnot, fcar, fmat, data);
	
	
	
	return (0);
}
