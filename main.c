#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {

    char *nombre,*direccion,*telefono,*mail,*aliasTelegram,*usuarioInstagram;

} Contacto ;

typedef struct _SNodo {

    Contacto personas;
    struct _SNodo *sig;
    struct _SNodo *ant;

} SNodo;

typedef struct {

    SNodo* primero;
    SNodo* ultimo;

} SList;

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

SList* nuevoContacto(SList* lista){

    SNodo* nuevoNodo = malloc(sizeof(SNodo));
    ingresoTecladoDatos(nuevoNodo);
    nuevoNodo->sig = lista->primero;
    nuevoNodo->ant = NULL;
    if(lista->primero != NULL)
        lista->primero->ant = nuevoNodo;
    if(lista->ultimo ==  NULL)
        lista->ultimo = nuevoNodo;
    lista->primero = nuevoNodo;


    return lista;

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

void mostrarContactos(SList *lista){
    int contador = 1;
    int contador2 = 0;         
    for(SNodo *nodo = lista->ultimo;nodo != NULL; nodo = nodo->ant){
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

void buscarContactosNombre(SList *lista){
    char nombreBuscar[20];
    ingresoTecladoBusquedaNombre(nombreBuscar);
    int contador = 1;
    int contador2 = 0;
    for(SNodo *nodo = lista->ultimo;nodo != NULL; nodo = nodo->ant){
        if(strcmp(nombreBuscar,nodo->personas.nombre) == 0){
            mostrarDatos(nodo,contador);
            contador++;
            contador2++;
        }
       
    }
    if(contador2 == 0)
    printf("No se encontro ningun contacto con ese nombre\n");

}

void buscarContactosTelefono(SList *lista){

    char telefonoBuscar[20];
    ingresoTecladoBusquedaTelefono(telefonoBuscar);
    int contador = 1;
    int contador2 = 0;
    for(SNodo *nodo = lista->ultimo;nodo != NULL; nodo = nodo->ant){
        if(strcmp(telefonoBuscar,nodo->personas.telefono) == 0){
            mostrarDatos(nodo,contador);
            contador++;
            contador2++;
        }
       
    }
    if(contador2 == 0)
    printf("No se encontro ningun contacto con ese telefono\n");


}

void liberarMemoria(SNodo *nodo){

    free(nodo->personas.nombre);
    free(nodo->personas.telefono);
    free(nodo->personas.direccion);
    free(nodo->personas.mail);
    free(nodo->personas.aliasTelegram);
    free(nodo->personas.usuarioInstagram);
    free(nodo);

}

int confirmacionUsuario(){

    int a;

    printf("Esta seguro que desea eliminar el contacto/los contactos?\n");
    printf("Ingrese 1 para confirmar:");
    scanf("%d",&a);
    printf("\n");
    return a;


}


void elminarContactoNombre(SList *lista){

    char nombreBuscar[20];
    ingresoTecladoBusquedaNombre(nombreBuscar);
    int contador2 = 0;
    SNodo *nodo = lista->ultimo;
    int confirmacion = confirmacionUsuario();

    if(nodo->ant == NULL && nodo->sig == NULL && confirmacion == 1){
        if(strcmp(nombreBuscar,nodo->personas.nombre)==0){
            lista->primero = NULL;
            lista->ultimo = NULL;
            liberarMemoria(nodo);
            nodo = NULL;
            contador2++;
        }

    }
    else{
        
        for(;nodo != NULL && confirmacion == 1; nodo = nodo->ant){
            if(strcmp(nombreBuscar,nodo->personas.nombre) == 0){

                if(nodo->ant == NULL){
                    nodo->sig->ant = NULL;
                    lista->primero=nodo->sig;
                    contador2++;
                    liberarMemoria(nodo);
 
                }
        
                if(nodo->sig != NULL && nodo->ant !=NULL ){
                    nodo->ant->sig = nodo->sig;
                    nodo->sig->ant = nodo->ant;
                    contador2++;
                    liberarMemoria(nodo);
                   
                  
                }
        
                if(nodo->sig == NULL){
                    nodo->ant->sig = NULL;
                    lista->ultimo = nodo->ant;
                    contador2++;
                    liberarMemoria(nodo);    
                }
                
            }

        }
    }
    if(contador2==0 && confirmacion == 1){
        printf("El contacto que busca no se encuentra en la agenda");
    }

}

void borrarRecursivo(SList *lista){

    SNodo* nodo = lista->ultimo;
    lista->ultimo = nodo->ant;
    liberarMemoria(nodo);
    if(lista->ultimo != NULL){
        borrarRecursivo(lista);
    }
    else{
        lista->primero = NULL;
    }
    printf("Agenda Eliminada\n");

}
void eliminarTodosContactos(SList *lista){
    
    if(confirmacionUsuario() == 1 && lista->primero != NULL && lista->ultimo != NULL)
        borrarRecursivo(lista);

}

void menu(){

    int opcion = 1;
    
    SList* lista = malloc(sizeof(SList));
    lista->primero = NULL;
    lista->ultimo = NULL;

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
        if(opcion == 6)
        eliminarTodosContactos(lista);
    }
}

int main(){

    menu();

    return 0;


}
