#ifndef NEXO_H_
#define NEXO_H_
#include "perros.h"
#include "functions.h"
#include "estadia.h"

int estadia_reservarEstadiaConPerroCargado(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro, int* ultimoId,int* contEstadias);
int estadia_listarEstadiasConPerros(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro);
void estadia_listarEstadiaConPerro(eEstadia estadia,ePerro perro);
int estadia_eliminarEstadiaDePerro(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro,int* contEstadias);
int estadia_modificarEstadiaDePerro(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro);

#endif /* NEXO_H_ */
