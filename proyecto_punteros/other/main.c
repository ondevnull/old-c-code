/* 
 * File:   main.c
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on March 31, 2008, 11:34 AM
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

void buscar (char nom[], char n[][30], float k[], int *m)
{
    int p, i;
    for (i=0; i<30; i++)
    {
        if (strcmp(nom, n[i])==0)
        {
            printf ("\nPeso en toneladas: ");
            scanf ("%d", &p);
            if (k[i]>199)
                *m = p*10500;
            else
                *m = p*15400;
        }
    }
}

/*
 * Name: main
 * Description:
 * Args:
 * Input:
 * Output:
 */
void main() {
    
    int i, m;
    char nomciu[30][30], opcion, nom1[30];
    float kilom[30];
    
    for (i=0; i<2; i++)
    {
        printf ("\nIngrese nombre de la ciudad");
        scanf ("%s", nomciu[i]);
        printf ("\nIngrese distancia en kilometros");
        scanf ("%f", &kilom[i]);
    }
    
    do {
        printf ("\nA. Mostrar");
        printf ("\nB. Calcular");
        printf ("\nC. Salir");
        printf ("\nOpción? ");
        scanf ("%c", &opcion);
        
        switch(opcion)
        {
            case 'A':
                for (i=0; i<30; i++)
                {
                    printf ("\n%s \t %f", nomciu[i], kilom[i]);
                }
                break;
            case 'B':
                printf ("\nQue ciudad desea ingresar? ");
                scanf ("%s", &nom1);
                buscar (&nom1, &nomciu, &kilom, &m);
                printf ("\nEl monto es: %d", m);
                break;
        }
    } while (opcion!='C');

}
