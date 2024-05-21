///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

///la clase Cadena tiene que servir para manejar cadenas de caracteres.
///El vector de char que contenga la cadena de caracteres debe ajustar su tamaño a lo estrictamente necesario.


class Cadena{
private:
    char *cad;
    int tam;
public:
    Cadena(const char *valorIni){
        tam=strlen(valorIni)+1;
        cad=new char[tam];
        if(cad==NULL)exit(1);
        strcpy(cad,valorIni);
        cad[tam-1]='\0';
    }
    void Mostrar(){
        cout<<cad<<endl;
    }
    ~Cadena(){
        delete []cad;
    }
    int getTam(){return tam;}
    char getCaracter(int pos){
        ///ver que habría que hacer para validar esta
        return cad[pos];
    }
    void aMayuscula(int cuantas=2){
        if(cuantas==1) cad[0]-=32;
        else{
            for(int i=0;i<tam-1;i++){
                cad[i]-=32;
            }
        }
    }

};


int main(){

    Cadena palabra("vaparatodoslosdelaclase"), otra("veremosquepasa");
    palabra.Mostrar();
    otra.Mostrar();
    cout<<"EL OBJETO palabra tiene "<<palabra.getTam()<<" caracteres en total"<<endl;
    cout<<"EL OBJETO otra tiene "<<otra.getTam()<<" caracteres en total"<<endl<<endl;

    if(palabra.getCaracter(0)==otra.getCaracter(0)){
        cout<<"LAS DOS CADENAS EMPIEZAN CON LA MISMA LETRA"<<endl;
    }
    else{
        cout<<"LAS DOS CADENAS NO EMPIEZAN CON LA MISMA LETRA"<<endl;
    }
	cout<<endl;

	otra.aMayuscula();
	otra.Mostrar();
	cout<<endl;

	system("pause");
	return 0;
}
