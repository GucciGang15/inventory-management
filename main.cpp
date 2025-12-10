#include <stdio.h>
#include <string.h>

struct producto {
    int codigo;
    char nombre[50];
    float cantidad;
    float precio;
    float total;
};

int main() {

    struct producto inventario[100];
    int codigos[100];
    int totalProductos = 0;
    int option;
	int encontrado = 0;
	
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

        switch (option) {

            case 1: {
                // --Agregar producto

                // Verificar si hay espacio en el inventario
                if (totalProductos >= 100) {
                    printf("ERROR: El inventario esta lleno.\n");
                    break;
                }

                struct producto nuevo;

                // Verificacion de que el codigo no este repetido
                int codigoRepetido;
                do {

                    codigoRepetido = 0;

                    printf("\nIngrese el codigo del producto: ");
                    scanf("%d", &nuevo.codigo);

                    for (int i = 0; i < totalProductos; i++) {
                        if (codigos[i] == nuevo.codigo) {
                            printf("ERROR: El codigo ya existe. Ingrese otro.\n");
                            codigoRepetido = 1;
                            break;
                        }
                    }

                } while (codigoRepetido == 1);

                // Verificacion de que el nombre no este vacio
                do {

                    printf("Ingrese el nombre del producto: ");
                    scanf("%s", nuevo.nombre);

                    if (strlen(nuevo.nombre) == 0) {
                        printf("ERROR: El nombre no puede estar vacio.\n");
                    }

                } while (strlen(nuevo.nombre) == 0);

                // Verificacion de que la cantidad no sea negativa ni igual a cero
                do {

                    printf("Ingrese la cantidad del producto: ");
                    scanf("%f", &nuevo.cantidad);

                    if (nuevo.cantidad <= 0) {
                        printf("ERROR: La cantidad debe ser mayor que 0.\n");
                    }

                } while (nuevo.cantidad <= 0);

                // Verificación de que el precio no sea negativo ni igual a cero
                do {

                    printf("Ingrese el precio del producto: ");
                    scanf("%f", &nuevo.precio);

                    if (nuevo.precio <= 0) {
                        printf("ERROR: El precio debe ser mayor que 0.\n");
                    }

                } while (nuevo.precio <= 0);

                // Calculo del total
                nuevo.total = nuevo.cantidad * nuevo.precio;

                // Guardar en inventario
                inventario[totalProductos] = nuevo;
                codigos[totalProductos] = nuevo.codigo;
                totalProductos++;

                printf("\nProducto agregado exitosamente.\n");

                break;
            }

            case 2:
                // Modificar producto
                break;

            case 3:
                // Eliminar producto
                break;

            case 4:
                // Mostrar todos los productos
                break;

            case 5:
                // --Buscar producto

                // Verificar si el total de productos no es cero
                if (totalProductos == 0) {
                    printf("El invetario esta vacio.\n");
                    break;
                }

                int codigoBuscado;

                printf("\nIngrese el codigo del producto que desea encontrar: ");
                scanf("%d", &codigoBuscado);

                for (int i = 0; i < totalProductos; i++){
                    if (inventario[i].codigo == codigoBuscado) {
                        printf("--------------------------------\n");
                        printf("El codigo ingresado ha coincidido con un producto del inventario:\n");
                        printf("--------------------------------\n");
                        printf("Codigo: %d\n", inventario[i].codigo);
                        printf("Nombre: %s\n", inventario[i].nombre);
                        printf("Cantidad: %.2f\n", inventario[i].cantidad);
                        printf("Precio: %.2f\n", inventario[i].precio);
                        printf("Total: %.2f\n", inventario[i].total);
                        printf("--------------------------------\n");

                        encontrado = 1;
                        break;
                    }
                    
                }
                
                if (!encontrado) {
                    printf("No existe un prducto registradi con ese codigo.\n");
                }

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