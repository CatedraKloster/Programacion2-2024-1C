#include <iostream>
#include <cstring>

using namespace std;

void cargarCadena(char *pal, int tam);

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int d=1, int m=1, int a=1900){
            dia=d;
            mes=m;
            anio=a;
        }
        void setDia(int d){
            if(d>0 && d<32){
                dia=d;
            }
        }
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        void setearFecha(int d, int m, int a){
            dia=d;
            mes=m;
            anio=a;
        }
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        void Cargar();
        void Mostrar(){
            cout<<dia<<"/"<<mes<<"/"<<anio;
        }
};

void Fecha::Cargar(){
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
}

class Persona{
    protected:
        int dni;
        char nombre[30];
        char apellido[30];
        Fecha fechaNacimiento;
        char telefono[15];
    public:
        Persona(int d=0, const char *n="S/N", const char *a="S/A", Fecha f=Fecha(), const char *t="S/T");
        void setDni(int d){dni=d;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setApellido(const char *a){strcpy(apellido, a);}
        void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
        void setTelefono(const char *t){strcpy(telefono, t);}
        void setDiaNacimiento(int d){fechaNacimiento.setDia(d);}
        int getDni(){return dni;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        Fecha getFechaNacimiento(){return fechaNacimiento;}
        int getDiaNacimiento(){return fechaNacimiento.getDia();}
        int getMesNacimiento(){return fechaNacimiento.getMes();}
        int getAnioNacimiento(){return fechaNacimiento.getAnio();}
        const char *getTelefono(){return telefono;}
        void Cargar();
        void Mostrar();
};

Persona::Persona(int d, const char *n, const char *a, Fecha f, const char *t){
    dni=d;
    strcpy(nombre,n);
    strcpy(apellido,a);
    fechaNacimiento=f;
    strcpy(telefono,t);
}


void Persona::Cargar(){
    cout<<"DNI: ";
    cin>>dni;
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 29);
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Cargar();
    cout<<"TELEFONO: ";
    cargarCadena(telefono,14);
}

void Persona::Mostrar(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<endl;
    cout<<"TELEFONO: "<<telefono<<endl;
}

class Docente : public Persona{
    private:
        char legajo[5];
        int numeroMateria;
    public:

};

///class Derivada : public Base{
///
///};

class Alumno : public Persona{
    private:
        int legajo;
        char codigoCarrera[5];
    public:
        Alumno(int l, const char *c);
        void setLegajo(int l){legajo=l;}
        int getLegajo(){return legajo;}
        void Cargar();
        void Mostrar();
        ~Alumno(){
        }
};

Alumno::Alumno(int l=1, const char *c="S/C"){
    legajo=l;
    strcpy(codigoCarrera,c);
}

void Alumno::Cargar(){
    Persona::Cargar();
    cout<<"LEGAJO: ";
    cin>>legajo;
    cout<<"CODIGO DE CARRERA: ";
    cin>>codigoCarrera;
}

void Alumno::Mostrar(){
    Persona::Mostrar();
    cout<<"LEGAJO: "<<legajo<<endl;
    cout<<"CODIGO DE CARRERA: "<<codigoCarrera<<endl;
}



int main(){
    Alumno obj;
    obj.Cargar();
    Persona aux;
    aux=obj;
    aux.Mostrar();
    return 0;
}

void cargarCadena(char *pal, int tam){
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}
