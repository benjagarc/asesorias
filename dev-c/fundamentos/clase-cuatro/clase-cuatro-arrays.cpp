#include <stdio.h>
#include <conio.h>

main()
{
    int *pint, arreglo_int[5];
    double *pdou, arreglo_dou[5];
    
    pint = arreglo_int;
    pdou = arreglo_dou;
    
    for (int i = 0; i < sizeof(arreglo_int)/sizeof(*arreglo_int); i++)
    {
        *pint = i * 2;
        pint++;
        *pdou = i * 3.0;
        pdou++;
    }

    // iteración
    // valor inicial
    // [0,0,0,0,0]
    // *pint = i*2;
    // [0] = 0x2;[0,0,0,0,0]
    // [1] = 2; [0,2,0,0,0]
    // [2] = 2x2; [0,2,4,0,0]
    // [3] = 2x3;[0,2,4,6,0]
    // [4] = 2x4; [0,2,4,6,8]

    // [0,0,0,0,0]
    // *pint = i*3.0;
    // [0] = 0x3.0;[0,0,0,0,0]
    // [1] = 1x3.0; [0,3.0,0,0,0]
    // [2] = 2x3.0; [0,3.0,6.0,0,0]
    // [3] = 3x3.0;[0,3.0,6.0,9.0,0]
    // [4] = 4x3.0; [0,3.0,6.0,9.0,12.0]

    
    for (int i = 0; i < sizeof(arreglo_int)/sizeof(*arreglo_int); i++)
        printf("el valor de pint es %d en la posicion %d\n", arreglo_int[i], i);
        // [0,2,4,6,8]
        // [0]
        // [2]
        // [4]
        // [6]
        // [8]
        
    for (int i = 0; i < sizeof(arreglo_dou)/sizeof(*arreglo_dou); i++)
        printf("el valor de pint es %f en la posicion %d\n", arreglo_dou[i], i);
        
    getch();
}


// arreglouno = [0,0,6,8,9];
// sizeof(arreglouno) = 5;
// arreglouno = [0,0,6,8,9,2];
// sizeof(arreglouno) = 6;



