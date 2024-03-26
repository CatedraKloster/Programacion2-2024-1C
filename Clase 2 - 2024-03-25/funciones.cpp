///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

void funcionCambiar(int &a,const int &d);///prototipo o declaración

int main(){
    int var, num;
    ///int &refe=var;
    /*cout<<"var "<<var<<endl;
    cout<<"refe "<<refe<<endl;

    cout<<"&var "<<&var<<endl;
    cout<<"&refe "<<&refe<<endl;

    var=10;
    cout<<refe<<endl;*/

    cout<<"INGRESE UN VALOR ENTERO ";
    cin>>num;
    funcionCambiar(var, num);/// llamada de la función
	cout<<var<<endl;
	cout<<num<<endl;
	system("pause");
	return 0;
}

void funcionCambiar(int &a,const int &d){
    //cout<<a<<endl;
    a=d;
}

/*
void funcionCambiar(int a){
    a=123;
}

*/
/*
void funcionCambiar(int *a){
    *a=123;
}
*/
/*
void funcionCambiar(int &a){
    a=123;
}

*/
