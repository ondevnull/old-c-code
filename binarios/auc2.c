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
 * Name: main
 * Description: 
 * Args: None
 * Input: stdin
 * Output: entrada.ent, salida.sal
 **********************************************************/

int main(){ 
	
	FILE *q, *qq;
	int a, f, w, i;
	char z;
	q = fopen ("entrada.ent", "wb");
	do
	{
		printf ("\nIngrese número: ");
		scanf ("%d", &a);
		fwrite(&a, sizeof(a), 1, q);
		printf ("\nDesea ingresar otro número? <y/n> ");
		getchar();
		z = getchar();

	} while ((z=='y')||(z=='Y'));
	fclose (q);
	q = fopen ("entrada.ent", "rb");
	qq = fopen ("salida.sal", "wb");
	while (!(feof(q)))
	{
		f=0;
		fread (&w, sizeof(w), 1, q);
		// We check how many numbers are divisible
		if (w!=1) {
		for (i=1; i<w; i++)
		{
			if (w%i==0)
				f++;
		}
		}
		// If there's only one number divisible integer then it's prime or
                // if w it's equal to 1
		if ((f==1)||(w==1))
			fwrite (&w, sizeof(w), 1, qq);
	}
        // Closing files
	fclose(q);
	fclose(qq);
/*	
 *	This is just for testing:...
 *
 * 	qq = fopen("salida.sal", "rb");
 *	// Now let's print what's in 'salida.sal'
 *	printf ("\n\n");
 *	while (!(feof(qq)))
 *	{
 *		fread (&w, sizeof(w), 1, qq);
 *		printf ("\n%d", w);
 *	}
 */	fclose(qq);
        return(0);
}

