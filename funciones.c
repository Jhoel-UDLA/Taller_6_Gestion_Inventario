#include <stdio.h>
#define MAXProductos 10
#define MAXNOMBRE 50

char nombresProductos[MAXProductos][MAXNOMBRE] = {0};
float precios[MAXProductos] = {0.0f};
int contProductos = 0;

// Lee un entero validado de un archivo lecturas.c
int leerEnteroValidado(const char *mensaje, int min, int max) {
    int valor;
    while (1) {
        printf("%s", mensaje);
        if (scanf("%d", &valor) == 1) {

            if (valor >= min && valor <= max)
                return valor;

            printf("\nDebe estar entre %d y %d.\n", min, max);
        } else {
            printf("\nEntrada no valida. Debe ingresar un numero.\n");
        }

        while (getchar() != '\n'); // Limpia el buffer
    }
}

// Opción 1: Ingresar Datos
int ingresar_datos() {

    if (contProductos >= MAXProductos) {
        printf("\nInventario lleno. El maximo es: %d productos.\n", MAXProductos);
        return contProductos;
    }

    printf("\n--- Ingresar Nuevo Producto #%d ---\n", contProductos + 1);

    printf("Nombre del producto: ");
    if (scanf("%49s", nombresProductos[contProductos]) != 1) { 
        while (getchar() != '\n');
        printf("Error al leer el nombre.\n");
        return contProductos;
    }

    printf("Precio de %s: ", nombresProductos[contProductos]);
    if (scanf("%f", &precios[contProductos]) != 1) {
        while (getchar() != '\n');
        printf("Error al leer el precio.\n");
        return contProductos;
    }

    contProductos++;
    printf("Producto agregado con exito.\n");

    return contProductos;
}

// Opción 2: Calcular precio total
void calcular_total() {
    if (contProductos == 0) {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < contProductos; i++)
        total += precios[i];

    printf("\nPrecio total del inventario: %.2f\n", total);
}

// Opción 3: Encontrar el producto más caro y más barato
void encontrar_caro_barato() {
    if (contProductos == 0) {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    int caro = 0, barato = 0;

    for (int i = 1; i < contProductos; i++) {
        if (precios[i] > precios[caro]) caro = i;
        if (precios[i] < precios[barato]) barato = i;
    }

    printf("\nProducto mas caro: %s (%.2f)\n", nombresProductos[caro], precios[caro]);
    printf("Producto mas barato: %s (%.2f)\n", nombresProductos[barato], precios[barato]);
}

// Opción 4: Calcular precio promedio
void calcular_promedio() {
    if (contProductos == 0) {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    float suma = 0;
    for (int i = 0; i < contProductos; i++)
        suma += precios[i];

    printf("\nPrecio promedio: %.2f\n", suma / contProductos);
}

// OPpción 5: Buscar producto por nombre
void buscar_producto() {

    if (contProductos == 0) {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    char buscado[MAXNOMBRE];
    printf("\nIngrese el nombre del producto a buscar: ");
    scanf("%49s", buscado);

    int encontrado = 0;

    for (int i = 0; i < contProductos; i++) {

        int j = 0;
        while (nombresProductos[i][j] == buscado[j] && nombresProductos[i][j] != '\0' && buscado[j] != '\0') {
            j++;
        }

        if (nombresProductos[i][j] == '\0' && buscado[j] == '\0') {
            printf("\nProducto encontrado: %s su precio es: %.2f\n",
                   nombresProductos[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (encontrado==0){
        printf("\nProducto no encontrado.\n");
    }
}