#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char *nombre,*direccion,*telefono,*mail,*aliasTelegram,*usuarioInstagram;

} Contacto ;

typedef struct _SNodo {

    Contacto personas;
    struct _SNodo *sig;

} SNodo;

void mostrarOpciones(){
    printf("AGENDA PERSONAL\n");
    printf("Opciones: \n\n");
    printf("1.Crear nuevo contacto\n");
    printf("2.Mostrar los contactos registrados\n");
    printf("3.Buscar contacto por nombre\n");
    printf("4.Buscar contacto por telefono\n");
    printf("5.Eliminar contacto por nombre\n");
    printf("6.Eliminar todos los contactos\n");
    printf("0.Salir de la agenda\n\n");

    printf("Ingresee la opcion a la que quiera acceder: ");
}

int opcionElegida(){

    int opcion;

    scanf("%d",&opcion);

    return opcion;

}

void ingresoTecladoDatos(SNodo* nuevoNodo){
    printf("\n\n\n");
    printf("Ingrese el nombre: \n");
    nuevoNodo->personas.nombre = malloc(sizeof(char)*20);
    scanf("%s",nuevoNodo->personas.nombre);
    printf("Ingrese el direccion: \n");
    nuevoNodo->personas.direccion = malloc(sizeof(char)*20);
    scanf("%s",nuevoNodo->personas.direccion);
    printf("Ingrese el telefono: \n");
    nuevoNodo->personas.telefono = malloc(sizeof(char)*20);
    scanf("%s",nuevoNodo->personas.telefono);
    printf("Ingrese el mail: \n");
    nuevoNodo->personas.mail = malloc(sizeof(char)*20);
    scanf("%s",nuevoNodo->personas.mail);
    printf("Ingrese el nombre de Telegram: \n");
    nuevoNodo->personas.aliasTelegram = malloc(sizeof(char)*20);
    scanf("%s",nuevoNodo->personas.aliasTelegram);
    printf("Ingrese el nombre de Instagram: \n");
    nuevoNodo->personas.usuarioInstagram = malloc(sizeof(char)*20);
    scanf("%s",nuevoNodo->personas.usuarioInstagram);

}

SNodo* nuevoContacto(SNodo* lista){

    SNodo* nuevoNodo = malloc(sizeof(SNodo));
    ingresoTecladoDatos(nuevoNodo);
    nuevoNodo->sig = lista;
    return nuevoNodo;

}

void mostrarDatos(SNodo *nodo,int contador){
    printf("\n\n\n");
    printf("Contacto Numero: %d\n",contador);
    printf("Nombre: %s\n",nodo->personas.nombre);
    printf("Direccion: %s\n",nodo->personas.direccion);
    printf("Telefoino: %s\n",nodo->personas.telefono);
    printf("Mail: %s\n",nodo->personas.mail);
    printf("Telegram: %s\n",nodo->personas.aliasTelegram);
    printf("Instagram: %s\n",nodo->personas.usuarioInstagram);


}

void mostrarContactos(SNodo *lista){
    int contador = 1;
    int contador2 = 0;         
    for(SNodo *nodo = lista;nodo != NULL; nodo = nodo->sig){
        mostrarDatos(nodo,contador);
        contador++;
        contador2++;
    }
    if(contador2 == 0)
    printf("No hay ningun contacto en su agenda\n");
}

void ingresoTecladoBusquedaNombre(char nombreBuscar[]){
    printf("Ingrese el nombre: \n");
    scanf("%s",nombreBuscar);
}
void ingresoTecladoBusquedaTelefono(char telefonoBuscar[]){
    printf("Ingrese el telefono: \n");
    scanf("%s",telefonoBuscar);
}

void buscarContactosNombre(SNodo *lista){
    char nombreBuscar[20];
    ingresoTecladoBusquedaNombre(nombreBuscar);
    int contador = 1;
    int contador2 = 0;
    for(SNodo *nodo = lista;nodo != NULL; nodo = nodo->sig){
        if(strcmp(nombreBuscar,nodo->personas.nombre) == 0){
            mostrarDatos(nodo,contador);
            contador++;
            contador2++;
        }
       
    }
    if(contador2 == 0)
    printf("No se encontro ningun contacto con ese nombre\n");

}

void buscarContactosTelefono(SNodo *lista){

    char telefonoBuscar[20];
    ingresoTecladoBusquedaTelefono(telefonoBuscar);
    int contador = 1;
    int contador2 = 0;
    for(SNodo *nodo = lista;nodo != NULL; nodo = nodo->sig){
        if(strcmp(telefonoBuscar,nodo->personas.telefono) == 0){
            mostrarDatos(nodo,contador);
            contador++;
            contador2++;
        }
       
    }
    if(contador2 == 0)
    printf("No se encontro ningun contacto con ese telefono\n");


}

void elminarContactoNombre(SNodo *lista){

     char nombreBuscar[20];
    ingresoTecladoBusquedaNombre(nombreBuscar);

    int contador2 = 0;
    for(SNodo *nodo = lista;nodo != NULL; nodo = nodo->sig){
        if(strcmp(nombreBuscar,nodo->personas.nombre) == 0){
            lista = lista->sig;
            contador2++;
            free(nodo->personas.nombre);
            free(nodo->personas.direccion);
            free(nodo->personas.telefono);
            free(nodo->personas.mail);
            free(nodo->personas.aliasTelegram);
            free(nodo->personas.usuarioInstagram);
            free(nodo);
        }
          
    }
       
    
    if(contador2 == 0)
    printf("No se encontro ningun contacto con ese nombre\n");



}

void menu(){

    int opcion = 1;
    SNodo* lista = NULL;

    while(opcion !=0){

        printf("\n\n\n");

        mostrarOpciones();

        opcion = opcionElegida();

        if(opcion == 1)
        lista = nuevoContacto(lista);
        if(opcion == 2)
        mostrarContactos(lista);
        if(opcion == 3)
        buscarContactosNombre(lista);
        if(opcion == 4)
        buscarContactosTelefono(lista);
        if(opcion == 5)
        elminarContactoNombre(lista);
        
        
        


    }
}

int main(){

    menu();

    return 0;


}
