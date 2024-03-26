///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

struct Materia{
    int numeroMateria;
    char nombreMateria[30];
    int cantidadAlumnos;
    int cantidadDocentes;
};

void mostrarMateria(Materia aux){
    cout<<"NUMERO "<<aux.numeroMateria<<endl;
    cout<<"NOMBRE "<<aux.nombreMateria<<endl;
    cout<<"CANTIDAD DE ALUMNOS "<<aux.cantidadAlumnos<<endl;
    cout<<"CANTIDAD DE DOCENTES "<<aux.cantidadDocentes<<endl;


}

/*void cargarMateria(Materia &aux){
    cout<<"NUMERO ";
    cin>>aux.numeroMateria;
    cout<<"NOMBRE ";
    cin>>aux.nombreMateria;
    cout<<"CANTIDAD DE ALUMNOS ";
    cin>>aux.cantidadAlumnos;
    cout<<"CANTIDAD DE DOCENTES ";
    cin>>aux.cantidadDocentes;
} */


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


Materia cargarMateria(){
    Materia aux;
    cout<<"NUMERO ";
    cin>>aux.numeroMateria;
    cout<<"NOMBRE ";
    cin>>aux.nombreMateria;
    cout<<"CANTIDAD DE ALUMNOS ";
    cin>>aux.cantidadAlumnos;
    cout<<"CANTIDAD DE DOCENTES ";
    cin>>aux.cantidadDocentes;
    return aux;
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
    }
    cout<<endl;
}


int main(){
    Materia reg, vReg[5], *preg, otroNombre;
    cargarMaterias(vReg,3);
    system("cls");
    cout<<"LISTADO DE MATERIAS "<<endl;
    mostrarMaterias(vReg, 3);
	cout<<endl;
	system("pause");
	return 0;
}
