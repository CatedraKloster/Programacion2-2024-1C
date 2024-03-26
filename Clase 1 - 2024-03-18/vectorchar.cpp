///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

int main(){
    char palabra[20]="HOLA";
/*
    cargarCadena(palabra, 19);   ///puntero constante que contiene la dirección del primer elemento

    cout<<palabra;
    /*int pos=0;
    palabra[2]='\0';
    while(palabra[pos]!='\0'){
        cout<<palabra[pos];
        pos++;
    }
      */

	strcpy(palabra,"HOLA");
	int resultado=strcmp(palabra,"SALUDOS");
	cout<<resultado<<endl;
	/*if(palabra=="HOLA"){
        cout<<"IGUALES";
	}
	else{
        cout<<"DISTINTOS"<<endl;
	}
      */
	//cout<<endl<<palabra<<endl;
	system("pause");
	return 0;
}
