#ifndef PERROS_H_
#define PERROS_H_
#define TAMCHAR 21
typedef struct
{
	int id;
	char nombre[TAMCHAR];
	char raza[TAMCHAR];
	int edad;
	int vacio;
}ePerro;

int perro_buscarPerroCargado(ePerro* perro,int tam,int* indice,int idPerro);
int perro_ListarPerros(ePerro* perro,int tam);
void perro_ListarPerro(ePerro perro);
int perro_ListarPromedioEdadPerros(ePerro* perro,int tam);

#endif /* PERROS_H_ */
