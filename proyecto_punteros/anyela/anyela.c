/* 
 * Anyela Contreras
 * Milagros Zambrano
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fecha {
    int d; // Día
    int m; // Mes
    int a; // Año
};

struct es {
    char n[30]; // Nombre
    int ce; // Cantidad en Existencia
    float pvp; // Precio de venta al público
    struct fecha fe; // Fecha
};

void carga (struct es d[30]) {
    int i;
    for (i=0; i<30; i++) {
        printf ("\nProducto %d", i);
        printf ("\nNombre:");
        scanf ("%s", &d[i].n);
        printf ("\nCantidad en existencia: ");
        scanf ("%d", &d[i].ce);
        printf ("\nPrecio de Venta al Público: ");
        scanf ("%f", &d[i].pvp);
        printf ("\nFecha: ");
        scanf ("%d/%d/%d", &d[i].fe.d, &d[i].fe.m, &d[i].fe.a);
    }
}

void menorinv (struct es d[30]) {
    int i, m=-1, p;
    for (i = 0; i < 30; i++) {
        if (d[i].ce < m) {
            m = d[i].ce;
            p = i;
        }
    }
    printf ("\nEl producto de menor inventario es :%s", d[p].ce);
}

void masdias (struct es d[30]) {
    int i, di, m, a;
    printf ("\nCuál es la fecha de hoy? ");
    scanf ("%d/%d/%d", &di, &m, &a);
    for (i = 0; i < 30; i++) {
        if (((d[i].fe.m < m) && (m-d[i].fe.m)==1)||(d[i].fe.m==m)) {
            if (d[i].fe.m==m) {
                if ((d[i].fe.d==1)&&(di==30))
                    printf ("\nEs mayor a 30 días el inventario de %s.", d[i].n);
            }
            if ((d[i].fe.m<m)&&(d[i].fe.d==di))
                printf ("\nEs mayor a 30 días el inventario de %s.", d[i].n);
        } else {
            printf ("\nEs mayor a 30 días el inventario de %s.", d[i].n);
        }
    }
}

void main() {
    struct es datos[30];
    carga(&datos);
    menorinv(&datos);
    masdias(&datos);
}
