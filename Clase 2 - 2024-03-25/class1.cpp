///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

class Materia{
    private:
        int numeroMateria;
        char nombreMateria[30];
        int cantidadAlumnos;
        int cantidadDocentes;
    public:
        void cargarMateria(){
            cout<<"NUMERO ";
            cin>>numeroMateria;
            cout<<"NOMBRE ";
            cin>>nombreMateria;
            cout<<"CANTIDAD DE ALUMNOS ";
            cin>>cantidadAlumnos;
            cout<<"CANTIDAD DE DOCENTES ";
            cin>>cantidadDocentes;
        }

        void mostrarMateria(){
            cout<<"NUMERO "<<numeroMateria<<endl;
            cout<<"NOMBRE "<<nombreMateria<<endl;
            cout<<"CANTIDAD DE ALUMNOS "<<cantidadAlumnos<<endl;
            cout<<"CANTIDAD DE DOCENTES "<<cantidadDocentes<<endl;
        }
};





/*
void cargarMateria(Materia *aux){
    cout<<"NUMERO ";
    cin>>(*aux).numeroMateria;
    cout<<"NOMBRE ";
    cin>>aux->nombreMateria;
    cout<<"CANTIDAD DE ALUMNOS ";
    cin>>aux->cantidadAlumnos;
    cout<<"CANTIDAD DE DOCENTES ";
    cin>>aux->cantidadDocentes;
}



void cargarMaterias(Materia *v, int tam){
    int i;
    for(i=0;i<tam;i++){
       /// cargarMateria(v+i);
       /// cargarMateria(v++);
       /// cargarMateria(&v[i]);
       v[i]=cargarMateria();

    }

}

void mostrarMaterias(Materia *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        mostrarMateria(v[i]);
        cout<<endl;
    }

}

*/
int main(){
    Materia reg;
    reg.cargarMateria();
    reg.mostrarMateria();
   /* system("cls");
    cout<<"LISTADO DE MATERIAS "<<endl;
    mostrarMaterias(vReg, 3);
	cout<<endl;*/
	system("pause");
	return 0;
}
