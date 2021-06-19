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

/*Guarda en una variable lo que es ingresado por teclado y 
lo devuleve al main */

int opcionElegida(){

    int opcion;

    scanf("%d",&opcion);                                             
                                                                    
    return opcion;

}

/*Se pide espacio en la memoria para cada uno de
los punteros de la estructura "Contacto" y
Se guarda lo ingresado por teclado en los mismos */

void ingresoTecladoDatos(SNodo* nuevoNodo){
    printf("\n\n\n");
    printf("Ingrese el nombre: \n");
    nuevoNodo->personas.nombre = malloc(sizeof(char)*20);
    scanf("%s",nuevoNodo->personas.nombre);
    for(int i=0;nuevoNodo->personas.nombre[i];i++){
        if(i==0)
            nuevoNodo->personas.nombre[i]=toupper(nuevoNodo->personas.nombre[i]);
        else
         nuevoNodo->personas.nombre[i]=tolower(nuevoNodo->personas.nombre[i]);
    }
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

/*Se crea un nuevo nodo en el cual se le ingresa los datos y
 se hacen las referencias de los punteros "sig" y "ant" */

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

/*Muestro en pantalla los datos del nodo que se le haya pasado
 a la funcion */

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

/*Se recorren todos los nodos y se van mostrando los datos
 que hay en cada uno
En el caso que no haya nodos, se muestra un mensaje que lo indica*/

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

/*En la string de char que se le pasa a la funcion
Se guarda lo ingresado por teclado*/

void ingresoTecladoBusquedaNombre(char nombreBuscar[]){
    printf("Ingrese el nombre: \n");
    scanf("%s",nombreBuscar);                                                   
    for(int i=0;nombreBuscar[i];i++){
        if ((i==0))
            nombreBuscar[i]=toupper(nombreBuscar[i]);
        else
            nombreBuscar[i]=tolower(nombreBuscar[i]);
    }                                          
}


/*En la string de char que se le pasa a la funcion 
Se guarda lo ingresado por teclado*/

void ingresoTecladoBusquedaTelefono(char telefonoBuscar[]){
    printf("Ingrese el telefono: \n");                                                                                   
    scanf("%s",telefonoBuscar);                                                 
}

/*Recorre todos los nodos hasta que se encuentra uno que coincida con
con "nombreBuscar" y se llama a la funcion "mostrarDatos"*/

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


/*Recorre todos los nodos hasta que se encuentra uno que coincida con
con "telefonoBuscar" y se llama a la funcion "mostrarDatos" */

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

/*Esta funcion libera el espacio pedido del nodo que se le pase*/

void liberarMemoria(SNodo *nodo){

    free(nodo->personas.nombre);
    free(nodo->personas.telefono);                                            
    free(nodo->personas.direccion);
    free(nodo->personas.mail);
    free(nodo->personas.aliasTelegram);
    free(nodo->personas.usuarioInstagram);
    free(nodo);

}

/*En el caso que el usuario quiera confirmar que quiere eliminar un contacto 
Le pide que ingrese 1      
Lo ingresado por teclado se guarda en una variable y lo devuelve */       

int confirmacionUsuario(){

    int a;

    printf("Esta seguro que desea eliminar el contacto/los contactos?\n");
    printf("Ingrese 1 para confirmar:");                                           
    scanf("%d",&a);                                                             
    printf("\n");                                                              
    return a;


}

/*Elimina el nodo a partir del nombre que se ingrese
En el caso que el nombre no exista, se le es mostrado en la pantalla
Lo primero que hace es el caso en el que sea un solo nodo
Lo siguiente que hace es el caso que el nodo en el que se esta es el primero
Luego el caso en el que se este en el medio o sea de que el nodo no sea ni el primero ni el ultimo
Y el ultimo caso es si esta ubicado en el ultimo nodo*/

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

/*Se va recorriendo la lista de forma recursiva y se va elminando nodo por nodo
Y por ultimo se le indica al usuario que la agenda fue eliminada*/

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

/*Mienstras que la confirmacion del usuario sea 1 y la lista no este vacia
llama a la funcion "borrarRecursivo"*/

void eliminarTodosContactos(SList *lista){
    
    if(confirmacionUsuario() == 1 && lista->primero != NULL && lista->ultimo != NULL)
        borrarRecursivo(lista);                                                         
                                                                                        

}

/*Se guarda la opcion que quiere el usuario en una variable y dependiendo de 
Lo que se ingreso, se llama a las distintas funciones*/

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
