///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

# include "clases.h"


class EmpresaMuni{
    private:
        int numero;
        char nombre[30];
        int cantidadEmpleados;
        bool estado;///true si el registro está activo; false si está borrado
    public:
        EmpresaMuni(){estado=false;}
        void setNumero(int n){numero = n;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setEstado(bool e){estado = e;}
        void setCantidadEmpleados(int ce){cantidadEmpleados=ce;}
        int getNumero(){return numero;}
        int getCantidadEmpleados(){return cantidadEmpleados;}
        bool getEstado(){return estado;}
        void Cargar();
        void Mostrar();
};

void EmpresaMuni::Cargar(){
    cout<<"NUMERO: ";
    cin>>numero;
    if(numero<1){
        return;
    }
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"CANTIDAD DE EMPLEADOS: ";
    cin>>cantidadEmpleados;
    estado=true;
}

void EmpresaMuni::Mostrar(){
    if(estado==true){
        Municipio obj;
        cout<<"NUMERO: "<<numero<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"CANTIDAD DE EMPLEADOS: "<<cantidadEmpleados<<endl;
    }
}

class ArchivoEmpMuni{
    private:
        char nombre[30];
    public:
        ArchivoEmpMuni(const char *n="emp_muni.dat"){strcpy(nombre,n);}
        bool grabarRegistro(EmpresaMuni obj);
        EmpresaMuni leerRegistro(int pos);
        int buscarRegistro(int num);
        int contarRegistros();
        bool modificarRegistro(EmpresaMuni obj, int pos);
        bool listarRegistros();
};


bool ArchivoEmpMuni::grabarRegistro(EmpresaMuni obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}


bool ArchivoEmpMuni::listarRegistros(){
    FILE *p;
    EmpresaMuni obj;
    p=fopen(nombre, "rb");
    if(p==NULL) return false;
    while(fread(&obj, sizeof obj, 1, p)==1){
            obj.Mostrar();
            cout<<endl;
    }
    fclose(p);
    return true;
}

int ArchivoEmpMuni::buscarRegistro(int num){
    FILE *p;
    EmpresaMuni obj;
    p=fopen(nombre, "rb");
    int pos=0;
    if(p==NULL) return -1;
    while(fread(&obj, sizeof obj, 1, p)==1){
                if(obj.getNumero()==num){
                    fclose(p);
                    return pos;
                }
                pos++;
    }
    fclose(p);
    return -2;
}

EmpresaMuni ArchivoEmpMuni::leerRegistro(int pos){
    FILE *p;
    EmpresaMuni obj;
    p=fopen(nombre, "rb");
    obj.setNumero(-5);
    if(p==NULL) return obj;
    fseek(p, pos*sizeof obj,0);///función que permite ubicarse dentro del archivo
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoEmpMuni::modificarRegistro(EmpresaMuni obj, int pos){
    FILE *p;
    p=fopen(nombre, "rb+"); ///agrega al modo de apertura lo que le falta
    if(p==NULL) return false;
    fseek(p, pos*sizeof obj,0);///función que permite ubicarse dentro del archivo
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoEmpMuni::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);///función que permite ubicarse dentro del archivo, en este caso lo ubiqué al final EOF
    int tam=ftell(p);///me devuelve la cantidad de bytes que hay desde el principio del archivo a la posición actual del indicador de pFILE.
    fclose(p);
    return tam/sizeof(EmpresaMuni);
}

void punto1();

int main(){
    punto1();
	cout<<endl;
	system("pause");
	return 0;
}


void punto1(){
    int numero;
    Empresa reg;
    ArchivoEmpresas archiE;
    EmpresaMuni aux;
    ArchivoEmpMuni archiNuevo;
    cout<<"INGRESE EL MUNICIPIO ";
    cin>>numero;
    int cantReg=archiE.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiE.leerRegistro(i);
        if(numero==reg.getNumeroMunicipio()){
            aux.setNumero(reg.getNumero());
            aux.setNombre(reg.getNombre());
            aux.setCantidadEmpleados(reg.getCantidadEmpleados());
            archiNuevo.grabarRegistro(aux);

        }
    }


}
