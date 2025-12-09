#include <stdio.h>

struct producto{
    int codigo;
    char nombre[50];
    float cantidad;
    float precio;
    float total;
};

int main() {

    struct producto inventario[100];
    int totalProductos = 0;
    int option;

    do
    {
        printf("\n=======================================\n");
        printf("     SISTEMA DE GESTION DE INVENTARIO\n");
        printf("=======================================\n");
        printf("1. Agregar producto\n");
        printf("2. Modificar inventario\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar todos los productos\n");
        printf("5. Buscar producto\n");
        printf("6. Reportes y estadisticas\n");
        printf("0. Salir\n");
        printf("=======================================\n");
        printf("Opcion: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                // Agregar producto
                break;

            case 2:
                // Modificar inventario
                break;

            case 3:
                // Eliminar producto
                break;

            case 4:
                // Mostrar todos los productos
                break;

            case 5:
                // Buscar producto
                break;

            case 6:
                // Reportes y estadisticas 
                break;

            case 0:
                printf("Gracias por usar el programa\n");
                break;

            default:
                printf("Opcion invalida. Por favor intente de nuevo.\n");
        }

    } while (option != 0);

    return 0;
}
