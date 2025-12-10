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
    int codigoRepetido = 0;
    int option;
	int encontrado = 0;
	int codigoModificar;
	int indiceModificar = -1;
	int codigoEliminar;
	int indiceEliminar = -1;
    float valorTotalInventario = 0.0f;
    int bajoStock = 0;


    // -----Cargadndir inventariio desde archivo 

    FILE *archivo = fopen("inventario.txt", "r");

    if (archivo == NULL) {
        printf("No se encontro el archivo 'inventario.txt'. Se creara uno nuevo al salir del programa.\n");
    }else{
        printf("Cargando inventario desde 'inventario.txt'...\n");

        while (fscanf(archivo, "%d %49s %f %f %f\n", &inventario[totalProductos].codigo, inventario[totalProductos].nombre, &inventario[totalProductos].cantidad, &inventario[totalProductos].precio, &inventario[totalProductos].total) == 5) {
            codigos[totalProductos] = inventario[totalProductos].codigo;
            totalProductos++;
        }
        fclose(archivo);
        printf("Inventario cargado exitosamente. Total de productos: %d\n\n", totalProductos);
        
    }
    



	
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
                // --Modificar producto
                if (totalProductos == 0) {
                    printf("El intario esta vacio\n");
                    break;
                }

                printf("\nIngrese el codigo del producto que desea modificar: ");
                scanf("%d", &codigoModificar);

                // Buscando el producto por su codigo
                for(int i = 0; i < totalProductos; i++) {
                    if (inventario[i].codigo == codigoModificar) {
                        indiceModificar = i;
                        break;
                    }
                }

                if (indiceModificar == -1){
                    printf("No hay un producto con ese codigo en el inventario.\n");
                    break;
                }

                // Menu para modificar el producto
                int optionModificar;
                printf("\nMenu de modificacion\n");
                printf("1. Modificar nombre\n");
                printf("2. Modificar cantidad\n");
                printf("3. Modificar precio\n");
                printf("0. Cancelar\n");
                printf("Que desea hacer?: ");
                scanf("%d", &optionModificar);
                
                switch (optionModificar)
                {
                case 1:
                    // Modificar nombre
                    do{

                        printf("Ingrese el nuevo nombre: ");
                        scanf("%s", inventario[indiceModificar].nombre);

                        if (strlen(inventario[indiceModificar].nombre) == 0) {
                            printf("ERROR: El nombre no puede estar vacio.\n");
                        }
                        
                    } while (strlen(inventario[indiceModificar].nombre) == 0);
                    
                    break;

                case 2:
                    // Modificar cantidad
                    do{

                        printf("Ingrese la nueva cantidad: ");
                        scanf("%f", &inventario[indiceModificar].cantidad);

                        if (inventario[indiceModificar].cantidad <= 0) {
                            printf("ERROR: La cantidad debe ser mayor que 0.\n");
                        }

                    } while (inventario[indiceModificar].cantidad <= 0);

                    break;

                case 3:
                    // Modificar precio
                    do{

                        printf("Ingrese el nuevo precio: ");
                        scanf("%f", &inventario[indiceModificar].precio);

                        if (inventario[indiceModificar].precio <= 0) {
                            printf("ERROR: El precio debe ser mayor que 0.\n");
                        }

                    } while (inventario[indiceModificar].precio <= 0);

                    break;
                
                case 0:
                    printf("Saliendo del menu de modificacion...\n");
                    break;
                
                default:
                    printf("ERROR. La opcion ingresada no es valida. Saliendo del menu de modificacion...\n");
                    break;
                }
                
                // Recalcular total (solo si se modificó algo)
                inventario[indiceModificar].total = inventario[indiceModificar].cantidad * inventario[indiceModificar].precio;

                printf("El producto ha sido modificado exitosamente.\n");

                break;

            case 3:
                // --Eliminar producto
                if (totalProductos == 0){
                    printf("El inventario esta vacio.\n");
                    break;
                }
            
                printf("\nIngrese el codigo del producto a eliminar: ");
                scanf("%d", &codigoEliminar);
                indiceEliminar = -1;


                // Buscando el indice del producto que vamos a elminar
                for (int i = 0; i < totalProductos; i++){
                    if  (inventario[i].codigo == codigoEliminar){
                        indiceEliminar = i;
                        break;
                    }
                }
                
                if (indiceEliminar == -1){
                    printf("No existe un producto registrado con el codigo ingresado.\n");
                    break;
                }

                // Mostrando el producto que coincidio con el codigo que se desea eliminar
                printf("--------------------------------\n");
                printf("Codigo: %d\n", inventario[indiceEliminar].codigo);
                printf("Nombre: %s\n", inventario[indiceEliminar].nombre);
                printf("Cantidad: %.2f\n", inventario[indiceEliminar].cantidad);
                printf("Precio: %.2f\n", inventario[indiceEliminar].precio);
                printf("Total: %.2f\n", inventario[indiceEliminar].total);
                printf("--------------------------------\n");

                // Confirmando que si se desea eliminar el registro del producto
                char confirmacion;
                printf("Desea realmente eliminar el producto? (s/n): ");
                scanf(" %c", &confirmacion);

                if (confirmacion != 's' && confirmacion != 'S') {
                    printf("Cancelando...\n");
                    break;
                }
                
                // Un if demasiado fascinante, para mover de lugar todas las posiciones de manera consecutiva
                for (int i = indiceEliminar; i < totalProductos - 1; i++){
                    inventario[i] = inventario[i + 1];
                    codigos[i] = codigos[i + 1];
                }
                
                totalProductos--;
                printf("El producto  ha sido eliminado exitosamente.\n");

                break;

            case 4:
                // --Mostrar todos los productos
                if (totalProductos == 0){
                    printf("El inventario esta vacio.\n");
                    break;
                }

                printf("\n--- LISTA COMPLETA DE PRODUCTOS ---\n");
                printf("+--------+----------------------+----------+----------+----------+\n");
                printf("| Codigo |        Nombre        | Cantidad |  Precio  |   Total  |\n");
                printf("+--------+----------------------+----------+----------+----------+\n");

                for (int i = 0; i < totalProductos; i++){
                    printf("| %-6d | %-20s | %-8.2f | %-8.2f | %-8.2f |\n", inventario[i].codigo, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio, inventario[i].total);
                }
                printf("+--------+----------------------+----------+----------+----------+\n");
                printf("Total de los productos en el inventario: %d\n", totalProductos);

                break;

            case 5:
                // --Buscar producto

                encontrado = 0;  

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
                    printf("No existe un producto registrado con ese codigo.\n");
                }

                break;

            case 6:
                // --Reportes y estadisticas
                printf("--------------------------------\n");
                printf("--- REPORTES Y ESTADISTICAS ---\n");
                printf("--------------------------------\n");
                printf("Total de productos registrados en el inventario: %d\n", totalProductos);

                valorTotalInventario = 0.0f;
                for (int i = 0; i < totalProductos; i++) {
                    valorTotalInventario += inventario[i].total;
                }
                printf("Valor total del inventario: %.2f\n", valorTotalInventario);

                printf("--------------------------------\n");
                printf("Productos con bajo stock (cantidad <= 10):\n");
                printf("+--------+----------------------+----------+\n");
                printf("| Codigo |        Nombre        | Cantidad |\n");
                printf("+--------+----------------------+----------+\n");

                bajoStock = 0;
                for (int i = 0; i < totalProductos; i++) {
                    if (inventario[i].cantidad < 10) {
                        printf("| %-6d | %-20s | %-8.2f |\n", inventario[i].codigo, inventario[i].nombre, inventario[i].cantidad);
                        bajoStock = 1;
                    }
                }

                printf("+--------+----------------------+----------+\n");

                if (!bajoStock) {
                    printf("No hay productos con stock bajo.\n");
                }
                

                break;

            case 0:{

                printf("\nGuardando inventario en 'inventario.txt'...\n");

                FILE *archivoSalida = fopen("inventario.txt", "w");

                if (archivoSalida == NULL) {
                    printf("ERROR: No se pudo abrir el archivo para guardar.\n");
                    break;
                }

                for(int i = 0; i < totalProductos; i++) {
                    fprintf(archivoSalida, "%d %s %.2f %.2f %.2f\n", inventario[i].codigo, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio, inventario[i].total);
                }

                fclose(archivoSalida);
                
                printf("Inventario guardado exitosamente.\n");
                printf("Gracias por usar el programa\n");
                break;
            }

            default:
                printf("Opcion invalida. Por favor intente de nuevo.\n");
        }

    } while (option != 0);

    return 0;
}