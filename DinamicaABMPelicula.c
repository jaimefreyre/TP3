#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/stat.h>

#define MAX 100
#define ARCHIVO "archivo.dat"


typedef struct
{
    char titulo[MAX];
    char genero[MAX];
    float duracion;
    char descripcion[MAX];
    int puntaje;
    char linkDeImagen[MAX];
    int estado;
} Pelicula;


Pelicula * alta(Pelicula * pelicula, int * longitudPers);
int mostrar(Pelicula * pelicula, int * longitudPers);
int buscar(Pelicula * pelicula, int * longitudPers);

void menu();

int main()
{


    int option = 0;
    int * longitudPers ;
    Pelicula * pelicula;
   
    do{
        menu();
        printf("ingrese una opcion:");
        scanf("%d", &option);
        switch (option){
            case 1 : pelicula = alta(pelicula, longitudPers);break;
            case 2 : mostrar(pelicula, longitudPers);break;
            case 3 : buscar(pelicula, longitudPers);break;
        }

    }while(option != 5);

}

void menu(){
    // system("cls");
    printf("1-Alta\n");
    printf("2-Mostar\n");
    printf("3-Busca\n");
    printf("5-Salir\n");
}

Pelicula * alta(Pelicula *pelicula, int *longitudPers){
    printf("alta \n");

    int option=1;
    int auxNuevaLogitud;
    int imenos = 1;

    mostrar(pelicula, longitudPers);
    
    Pelicula *punteroAux;
    if (*longitudPers <= 1){
        printf("entro \n");
        *longitudPers = 1;
        pelicula = (Pelicula * ) malloc(sizeof(Pelicula));
    }else{
        auxNuevaLogitud = sizeof(Pelicula) * (*longitudPers + 1) ;
        punteroAux = (Pelicula*)realloc( pelicula, auxNuevaLogitud);
        if (punteroAux == NULL)
        {
            printf("\nNo hay lugar en memoria\n");
        }
        (*longitudPers)++;
        pelicula = punteroAux;
    }   

    while (option == 1)
    {
        system("cls");

        

        fflush(stdin);
        
        printf("Titulos:  " );
        scanf("%s[^\n]", &(pelicula[*longitudPers -imenos].titulo) );
        // scanf("%s[^\n]", &(pelicula[*longitudPers].titulo) );
        fflush(stdin);
        
        printf("Genero:  " );
        scanf("%s[^\n]", &(pelicula[*longitudPers -imenos].genero) );
        // scanf("%s[^\n]", &(pelicula[*longitudPers].genero) );
        fflush(stdin);
        
        printf("Duracion: ");
        // scanf("%[/\S+@\S+\.\S+/]", &(pelicula[*longitudPers].duracion));
        scanf("%d", &(pelicula[*longitudPers -imenos].duracion));
        // scanf("%d", &(pelicula[*longitudPers ].duracion));
        fflush(stdin);

        // mostrar(pelicula, longitudPers);

        printf("Descripcion: ");
        scanf("%s", &(pelicula[*longitudPers -imenos].descripcion));
        // scanf("%s", &(pelicula[*longitudPers ].descripcion));
        fflush(stdin);
        
        printf("Puntajes: ");
        scanf("%d", &(pelicula[*longitudPers -imenos].puntaje));
        // scanf("%d", &(pelicula[*longitudPers ].puntaje));
        fflush(stdin);

        printf("Ingrese la linkDeImagen: ");
        scanf("%s", &((pelicula+*longitudPers -imenos)->linkDeImagen) ); // puntero
        // scanf("%s", &((pelicula+*longitudPers )->linkDeImagen) ); // puntero
        fflush(stdin);

        printf("Ingrese estado: ");
        scanf("%d", &((pelicula+*longitudPers -imenos)->estado) ); // puntero
        // scanf("%d", &((pelicula+*longitudPers )->estado) ); // puntero
        fflush(stdin);

        // mostrar(pelicula, longitudPers);
        
        // (pelicula+*longitudPers)->estado = 0; // puntero}


        printf("Si desea cargar otra pelicula ingrese 1 o para finalizar 2: ");
        scanf("%d", &option);

        if(option == 1)
        {

            auxNuevaLogitud = sizeof(Pelicula) * (*longitudPers + 1) ;

            punteroAux = (Pelicula*)realloc( pelicula, auxNuevaLogitud);
            if (punteroAux == NULL)
            {
                printf("\nNo hay lugar en memoria\n");
                break;
            }
            (*longitudPers)++;
            pelicula = punteroAux;
            // system("cls");
        }
        else
        {
            break;
        }
    }
    mostrar(pelicula,longitudPers);
    return pelicula;
}

int mostrar(Pelicula * peliculas, int * longitudPers){
    system("cls");
    printf("mostrar %d\n",*longitudPers);

    // for(int i = 0 ; i < (* longitudPers -1); i++ ){
    for(int i = 0 ; i < (* longitudPers); i++ ){
        printf("Posicion %d\n", *longitudPers);
        printf("Nombre: %s\n", peliculas[i].titulo);
        printf("Genero: %s\n", peliculas[i].genero);
    }

     return 1;
}

int buscar(Pelicula *pelicula, int * longitudPers)
{
    system("cls");

    char contact[40];
    int bandera=0;

    printf("Ingrese apellido/s y nombre/s: :  " );
    scanf("%s", contact);

    for(int i=0; i< *longitudPers; i++)
    {
        if(strcmp((pelicula+i)->titulo, contact)==0 && (pelicula+i)->estado==0)
        {
            printf("Titulo: %s\n", pelicula[i].titulo);
            printf("Duracion: %d\n", pelicula[i].duracion);
            printf("Descripcion: %s\n", pelicula[i].descripcion);
            printf("Puntaje: %d\n", pelicula[i].puntaje);
            printf("LINK: %s\n", pelicula[i].linkDeImagen);
            bandera=1;
        }
    }

    if(bandera==0)
    {
        printf("No se encontro el contacto\n");
    }
}