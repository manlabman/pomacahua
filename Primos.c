#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int n = 1000;
    int esPrimo;
    
    printf("Números primos del 2 al %d:\n", n);
    
    for (int i = 2; i <= n; i++) {
        esPrimo = 1;  // Asumir que es primo
        
        // Verificar divisibilidad hasta la raíz cuadrada de i
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                esPrimo = 0;  // No es primo
                break;
            }
        }
        
        // Si es primo, imprimirlo
        if (esPrimo) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    return 0;
}
