//
// Created by lautaro on 19/8/2023.
//

#ifndef UNTITLED_ENVIOS_H
#define UNTITLED_ENVIOS_H
#define MAX_REGISTROS 1000
#define MAX_LONGITUD 100


#define MAX_Envios 300

typedef struct {
    char codigo[7];
    int dni_receptor;
    char nombre[80];
    char direccion[80];
    int dni_remitente;
    char nombre_r[80];
    char fecha_envio[MAX_LONGITUD];
    char fecha_recepcion[MAX_LONGITUD];


}Envio;


void mostrarenvio (Envio envio){

    printf("Codigo: %s\n", envio.codigo);
    printf("Dni receptor: %d\n", envio.dni_receptor);
    printf("Nombre y Apellido del receptor: %s\n", envio.nombre);
    printf("Direccion: %s\n", envio.direccion);
    printf("Dni remitente: %d\n", envio.dni_remitente);
    printf("Fecha de envio: %s\n", envio.fecha_envio);
    printf("Fecha recepcion: %s\n", envio.fecha_recepcion);
    printf("Nombre remitente: %s\n\n", envio.nombre_r);

}

#endif //UNTITLED_ENVIOS_H


