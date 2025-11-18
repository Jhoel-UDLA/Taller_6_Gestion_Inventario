#include "funciones.h"
#include <stdio.h>

int main() {

    int opcion;

    do {
        printf("\n==================================\n");
        printf("      GESTION DE INVENTARIO C\n");
        printf("==================================\n");
        printf("1. Ingresar Nuevo Producto\n");
        printf("2. Calcular Precio Total\n");
        printf("3. Encontrar Producto mas caro o barato\n");
        printf("4. Calcular Precio Promedio\n");
        printf("5. Buscar Producto por Nombre\n");
        printf("6. Salir\n");
        printf("==================================\n");

        opcion = leerEnteroValidado("Seleccione una opcion: ", 1, 6);

        switch (opcion) {

            case 1:
                ingresar_datos();
                break;

            case 2:
                calcular_total();
                break;

            case 3:
                encontrar_caro_barato();
                break;

            case 4:
                calcular_promedio();
                break;

            case 5:
                buscar_producto();
                break;

            case 6:
                printf("\nHasta luego. Adios\n");
                break;
        }

    } while (opcion != 6);

    return 0;
}