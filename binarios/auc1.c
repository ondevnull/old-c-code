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


#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

/**********************************************************
 * Name:
 * Description:
 * Args:
 * Input:
 * Output:
 **********************************************************/

int main(int argc, char *argv[]){ 
	char x[20], y[20], w;
	FILE *p;
	p = fopen("prueba.pollito",  "wb");
	printf ("Introduzca dato");
	scanf ("%s", &x);
	fwrite (x, sizeof(x), 1, p);
	fclose(p);
	p = fopen("prueba.pollito", "rb");
	while (!(feof(p)))
	{
		w = fread (y, sizeof(y), 1, p);
		if (w!=0) printf ("%s", y);
	}
	close(p);
        return(0);
}

