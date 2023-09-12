#include <stdio.h>
#include "LSO.h"
#include <ctype.h>
#define MAX_Envios 300

//lautaro reynoso y mateo villalva
//grupo14
int Lectura_datos();
void cargarenvio();
void mostrarestroctura();
void Eliminarenvio();
void Modificarenvio();
char* Mayusculas();
void consultadeenvio();
int main(void)
{
    lso lista;
    lista.contador = 0;


    int opcion;

    //menu
    do
    {

        printf( "\n   1. Ingresar un nuevo envio.");
        printf( "\n   2. eliminar envios existentes.");
        printf( "\n   3. modificar datos de un envio.");
        printf( "\n   4. consultar la informacion completa asociada al envio.");
        printf( "\n   5. Memorizacion Previa.");
        printf( "\n   6. Mostrar Estructura.");
        printf( "\n   7. Salir." );
        printf( "\n\n   Introduzca opcion (1-7): ");
        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
        case 1:
            system("cls");
            cargarenvio(&lista);

            break;
        case 2:
            system("cls");
            Eliminarenvio(&lista);
            break;
        case 3:
            system("cls");
            Modificarenvio(&lista);
            break;
        case 4:
            system("cls");
            consultadeenvio(&lista);
            break;
        case 5:
            system("cls");
            Lectura_datos(&lista);
            break;
        case 6:
            system("cls");
            mostrarestroctura(&lista);
            break;

        case 7:
            system("cls");
            break;

        }

        /* Fin del anidamiento */

    }
    while ( opcion != 7 );
    return 0;
}

void mostrarestroctura(lso *lista)
{
    int i;

    for(i = 0 ; i < lista->contador; i++)
    {
        mostrarenvio(lista->envios[i]);
        getchar();
    }
    printf("Total de %d envios\n", lista->contador);

}
char *Mayusculas(char string[])
{
    int i;
    for(i=0; string[i]!='\0'; i++)
    {
        string[i]=toupper(string[i]);
    }
    return  string;
}
void consultadeenvio(lso *lista)
{
    char codigo_a_e[8];
    printf("Codigo del envio que desea consultar: ");
    scanf("%s",codigo_a_e);

    Envio envio;


    int res = evocar(lista,Mayusculas(codigo_a_e),&envio);
    if (res == 1)
    {
        mostrarenvio(envio);
    }
    else
    {
        printf("No se encontro el codigo buscado.\n");
    }



}
void Eliminarenvio(lso *lista)
{

    char codigo_a_e[7];
    printf("Codigo a eliminar: \n");
    scanf("%s",codigo_a_e);
    int resultado = Baja(lista, Mayusculas(codigo_a_e));

    if (resultado == 0)
    {
        printf("Envio eliminado exitosamente.\n");
    }
    else if(resultado==1)
    {
        printf("No se encontro el envio a eliminar.\n");
    }
}



void Modificarenvio(lso *lista)
{
    int mod_resultado = Modificar(lista);
    if (mod_resultado == 0)
    {
        printf("Envio modificado exitosamente.\n");
    }
    else
    {
        printf("No se pudo modificar el envio.\n");
    }
}


void cargarenvio(lso *lista)
{

    if(lista->contador==MAX_Envios)
    {
        printf("La lista se encuentra llena");
    }
    else
    {


        Envio envio;
        char arreglo[8];

        printf("\nIntroduzca el codigo de envio:");
        scanf("%s", arreglo);
        strcpy(envio.codigo, Mayusculas(arreglo));

        printf("\nIntroduzca el dni del receptor:");
        scanf("%d", &envio.dni_receptor);

        printf("\nIntroduzca el nombre y apellido del receptor:");
        scanf(" %[^\n]", envio.nombre);

        printf("\nIntroduzca la direccion:");
        scanf(" %[^\n]", envio.direccion);

        printf("\nIntroduzca el dni del remitente:");
        scanf("%d", &envio.dni_remitente);

        printf("\nIntroduzca el nombre y apellido del remitente:");
        scanf(" %[^\n]", envio.nombre_r);

        printf("\nIntroduzca la fecha de envio format: aaaa/mm/dd:");
        scanf(" %[^\n]", envio.fecha_envio);

        printf("\nIntroduzca la fecha de recepcion format: aaaa/mm/dd:");
        scanf(" %[^\n]", envio.fecha_recepcion);

        int respuesta;

        respuesta = Alta(lista, envio);

        if (respuesta == 1)
        {
            printf("No se pudo cargar el envio, se encontro un envio con el mismo codigo de envio");
        }
        else
            printf("El alta se realizo con exito");
        // mostrarenvio(lista->envios[0]);
    }
}
int Lectura_datos(lso *lista)
{
    FILE *archivo;


    int contador_nuevos=0;
    int respuestaalta=2,i;
    archivo = fopen("Envios.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }
    Envio envio;
    while (!feof(archivo)&&lista->contador!=MAX_Envios)
    {

        fscanf(archivo, " %[^\n]", envio.codigo);

        for(i=0; i<=8; i++)
        {
            envio.codigo[i]=toupper(envio.codigo[i]);
        }
        fscanf(archivo, "%d", &envio.dni_receptor);
        fscanf(archivo, " %[^\n]", envio.nombre);
        fscanf(archivo, " %[^\n]", envio.direccion);
        fscanf(archivo, "%d", &envio.dni_remitente);
        fscanf(archivo, " %[^\n]", envio.nombre_r);
        fscanf(archivo, " %[^\n]", envio.fecha_envio);
        fscanf(archivo, " %[^\n]", envio.fecha_recepcion);
        // Llamar a la función Alta directamente con la estructura envio
        respuestaalta= Alta(lista, envio);

        if(respuestaalta==0)
        {
            contador_nuevos++;
        }

    }
    if(respuestaalta == 2)
    {
        printf ("\n\nOcurrio un error se lleno la lista.\n");
    }


    fclose(archivo);


    printf("Hay %d envio/s nuevo/s cargado/s\n",contador_nuevos);

    return 0;
}

