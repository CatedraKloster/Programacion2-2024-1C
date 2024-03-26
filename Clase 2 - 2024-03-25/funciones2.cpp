///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;


void  devolverNombre(char *aux){
    cout<<"INGRESA NOMBRE ";
    cin>>aux;
}
/* NO TIENE SENTIDO ESTA FORMA DE FUNCION AUNQUE SE EJECUTE CORRECTAMENTE
char *  devolverNombre(char *aux){
    cout<<"INGRESA NOMBRE ";
    cin>>aux;
    return aux;
}

*/
/// En c++ existe un mecanismos que se llama SOBRECARGA DE FUNCIONES
///Permite tener funciones distintas con el mismo nombre se tiene que diferenciar en los parámetros

void funcion(int num){
    cout<<"SOY FUNCION E IMPRIMO UN NUMERO "<<num<<endl;
}

void funcion(const char *cadena="que pasa?"){
    cout<<"SOY FUNCION E IMPRIMO UNA CADENA "<<cadena<<endl;
}

///Valor devuelto de una función puede ser cualquier tipo de dato

int main(){
    int numero=10;
    char palabra[20]="HOLA";
    funcion(numero);
    funcion(palabra);
    funcion();

	system("pause");
	return 0;
}
