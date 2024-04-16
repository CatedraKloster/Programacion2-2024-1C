//Ejercicio:
//Autor:DEK
//Fecha:
//Comentario:

# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
#include <windows.h>
#include <ctime>
#include <conio.h>
///         que cosas les parecen extrañas, y que otras cosas les parece natural, igual a lo anterior.
using namespace std;

enum Color{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};
/// Se definen una serie de constantes que asumen el valor que se le asignó.
/// Es más fácil usar cBLANCO para setear el color a blanco, que acordarse el número 15

#include <windows.h>

void ocultarCursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(short x, short y){ ///UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

///ASIGNA COLORES AL TEXTO Y AL FONDO DEL TEXTO
void textcolor(int colorTexto=15, int colorFondo=0){
    int color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}


///CLASE.  Punto. CLASE ES UN MOLDE DONDE SE DEFINEN LAS PROPIEDADES(ATRIBUTOS, CARACTERISTICAS)
/// Y LOS METODOS, EL COMPORTAMIENTO, QUE VAN A TENER LOS OBJETOS DE ESA CLASE.
/// Permite declarar OBJETOS de tipo Punto y manipularlos

///encapsulamiento: protege los datos de los objetos. Para cambiar un valor es necesario usa
/// funciones de la propia clase

class Pantalla{ ///Esta es una clase que toma los valores del alto y ancho de la ventana de la consola y los almacena en las propiedades
    private:    ///correspondientes.
        int tamanioX;
        int tamanioY;
    public:
        Pantalla(){
            CONSOLE_SCREEN_BUFFER_INFO c;
            HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
            GetConsoleScreenBufferInfo(consoleHandle,&c);
            tamanioX=c.srWindow.Right+1;
            tamanioY=c.srWindow.Bottom+1;
        }
        int getTamanioX(){return tamanioX;}
        int getTamanioY(){return tamanioY;}
};

class Punto {
    ///ESPECIFICADORES DE ACCESO
    private:///acá van las PROPIEDADES de la CLASE
        int x;///posición del punto en el eje horizontal x
        int y;///posición del punto en el eje vertical y
        int color;///define el color. Los valores son los del enum de más arriba
    public:
        Punto(int a=0, int b=15, int nuevoColor=cNEGRO){///CONSTRUCTOR: asigna valores a las propiedades al momento de la declaración
            x=a;
            y=b;
            color=nuevoColor;
        }
        void setXAleatorio(){
            Pantalla aux;
            x=rand()%aux.getTamanioX()-1;//Devuelve un valor aleatorio entre 0 y 165
        }
        void setYAleatorio(){
            Pantalla aux;
            y=rand()%(aux.getTamanioY()-1);
        }
        void setColorAleatorio(){
            color=rand()%14;
        }
        void Mostrar(){///muestra el punto en la pantalla en la posición que se eligió previamente
            textcolor(color, 15);
            gotoxy(x,y);
            cout<<(char)219;
        }
        void MostrarValores();
        void Ocultar(){
            gotoxy(x,y);
            cout<<" ";
        }
        void cambiarX(int valor){
            //if(valor>=0 && valor<=75)
            x=valor;
        }
        void cambiarY(int valor){
            y=valor;
        }
        void cambiarColor(int nuevo){
            color=nuevo;
        }
        int getX(){return x;}
        int getY(){return y;}
        ~Punto(){///DESTRUCTOR: se ejecuta cuando el objeto cae fuera de su alcance.
            textcolor(0,15);
        }
        void decrementarX(){
            x--;
        }
        void incrementarX(){
            x++;
        }
};

void Punto::MostrarValores(){
        cout<<x<<endl;
        cout<<y<<endl;
        cout<<color<<endl;
    }

void dibujarLinea(){
    cout<<"Esta linea va a ocupar toda la pantalla";
    Punto a;
    Pantalla aux;
    a.cambiarY(1);
    for(int i=0;i<aux.getTamanioX();i++){
        a.cambiarX(i);
        a.Mostrar();
    }
    for(int i=0;i<aux.getTamanioY();i++){
        a.cambiarY(i);
        a.Mostrar();
    }
}

///
void punto6(){
    Punto objIzq(0,10, cNEGRO);
    Punto objDer(75,10, cAZUL);
    while(objIzq.getX()!=(objDer.getX()-1)){
        objIzq.cambiarX(objIzq.getX()+1);
        objDer.cambiarX(objDer.getX()-1);

        objIzq.Mostrar();
        objDer.Mostrar();
        Sleep(60);
       }
}

void punto7(){
   Punto objIzq(0,10, cNEGRO);
    Punto objDer(75,10, cAZUL);
    while(objIzq.getX()!=(objDer.getX()-1)){
        objIzq.cambiarX(objIzq.getX()+1);
        objDer.cambiarX(objDer.getX()-1);

        objIzq.Mostrar();
        objDer.Mostrar();
        Sleep(60);
       }
    while(objIzq.getY()!=0){
        objIzq.cambiarY(objIzq.getY()-1);
        objDer.cambiarY(objDer.getY()-1);

        objIzq.Mostrar();
        objDer.Mostrar();
        Sleep(60);

    }
}


void punto8(){
    int x, y;
    Punto obj;
    cout<<"INGRESE EL VALOR DE X: ";
    cin>>x;
    cout<<"INGRESE EL VALOR DE Y: ";
    cin>>y;
    obj.cambiarX(x);
    obj.cambiarY(y);
    obj.cambiarColor(cNEGRO);
    for(int i=0;i<50;i++){
        obj.Mostrar();
        Sleep(30);
        obj.Ocultar();
        Sleep(30);
    }
}
///Puede también hacerse un método parpadear que reciba como parámetro el tiempo de espera
///Se pueden modificar las funciones Mostrar() y Ocultar() mandándoles como parámetro el tiempo que se muestra
/// o se oculta

void punto9(){
    int lado1, lado2;
    Punto obj(10,10, cNEGRO);
    cout<<"INGRESE UN LADO: ";
    cin>>lado1;
    cout<<"INGRESE EL OTRO LADO: ";
    cin>>lado2;
    int i, inicioX=obj.getX();
    int inicioY=obj.getY();
    for(i=inicioX;i<inicioX+lado1;i++) {
        obj.Mostrar();
        obj.cambiarX(obj.getX()+1);
    }
    for(i=inicioY;i<inicioY+lado2;i++) {
        obj.Mostrar();
        obj.cambiarY(obj.getY()+1);
    }
    inicioX=obj.getX();
    inicioY=obj.getY();
    for(i=inicioX;i>inicioX-lado1;i--) {
        obj.Mostrar();
        obj.cambiarX(obj.getX()-1);
    }
    for(i=inicioY;i>inicioY-lado2;i--) {
        obj.Mostrar();
        obj.cambiarY(obj.getY()-1);
    }
}

void punto10(){
    Punto obj(10,10, cNEGRO);
    for(int i=0;i<30;i++){
        obj.Mostrar();
        Sleep(30);
        obj.Ocultar();
        Sleep(30);
        obj.cambiarX(obj.getX()+1);
    }
}
///Puede hacerse con un while que analice el valor de x
///Puede agregarse un método que se llame MoverX() que reciba el desplazamiento como parámetro.

void punto11(){
    Punto obj(10,0,cNEGRO);
    for(int i=0;i<10;i++){
        obj.Mostrar();
        Sleep(40);
        obj.Ocultar();
        Sleep(40);
        obj.cambiarY(obj.getY()+1);
    }
}

void punto13(){
    Punto a;
    a.cambiarColor(cNEGRO);
    while(kbhit()==false){
        a.setXAleatorio();
        a.setYAleatorio();
        a.setColorAleatorio();
        a.Mostrar();
        Sleep(40);
    }
}
///Puede hacerse con un while que analice el valor de Y
///Puede agregarse un método que se llame MoverY() que reciba el desplazamiento como parámetro.
void aleatorio(Punto *vec, int tam){
    srand(time(NULL));
    for(int i=0;i<tam;i++){
       vec[i].setXAleatorio();
       vec[i].setYAleatorio();
      }
}

void punto12(){
    Punto vec[20];
    int i, j;
    srand(time(NULL));

    for(j=0;j<1000;j++){
        aleatorio(vec,20);
        for(j=0;j<20;j++){
        vec[j].Mostrar();
        }
    }
  }

void kbhitEjemplo(){ ///Este es el ejemplo que les mostre del kbhit, no usen esta funcion porqeu es un bucle infinito.
    while(true){
        if(kbhit()){
            cout<<(char)getch();
        }
    }
}

void mover(){
    Punto obj(236, 3);
    obj.Mostrar();
//    for(int i=0; i<15; i++){
//        obj.Ocultar();
//        obj.decrementarX();
//        obj.Mostrar();
//        Sleep(200);
//    }
}

int main() {
    textcolor(0,15);
    Punto obj(35,10);
    ocultarCursor();
    int opc;
    while(true){
        system("cls");
        cout<<"----------MENU------------"<<endl;
        cout<<"1. DIBUJAR UN PUNTO EN LA POSICION QUE EL USUARIO PIDA POR TECLADO"<<endl;
        cout<<"2. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL EN UNA POSICION DEL EJE Y DEFINIDA"<<endl;
        cout<<"3. DIBUJAR UNA LINEA DE PUNTOS VERTICAL EN UNA POSICION DEL EJE X DEFINIDA"<<endl;
        cout<<"4. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"5. DIBUJAR UNA LINEA DE PUNTOS VERTICAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"6. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE LA PANTALLA "<<endl;
        cout<<" Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE DISTINTOS COLORES "<<endl;
        cout<<"7. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE LA PANTALLA "<<endl;
        cout<<" Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE DISTINTOS COLORES "<<endl;
        cout<<" AL ENCONTRARSE DEBEN LAS LINEAS DEBEN SUBIR HASTA LA POSICIÓN 0 DE Y "<<endl;
        cout<<"12. DIBUJAR UNA LLUVIA DE PUNTOS"<<endl;
        cout<<"13. DIBUJAR UNA LLUVIA DE PUNTOS HASTA QUE SE PRESIONA UNA TECLA"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1://punto1();
                break;

            case 2:
                dibujarLinea();
                break;

            case 3:
                mover();
                break;

            case 4:
                break;
            case 5:
                break;
            case 6:punto6();
                break;
            case 7:punto7();
                break;
            case 8:
                break;
            case 9:
                punto9();
                break;
            case 10:
                punto10();
                break;
            case 11:
                break;
            case 12:
                punto12();
                break;
            case 13:
                punto13();
                break;
            case 0:
                return 0;

        }
        system("pause>nul");

    }
    return 0;
}
/**
A partir de la clase Punto resolver lo siguiente:

8) Hacer un punto que parpadee en la pantalla en una posición dada.
9) Hacer un rectangulo, a partir de los valores de 2 lados
10) Hacer un punto que camine por la pantalla de manera horizontal
11) Hacer un punto que se desplaze por la pantalla de manera vertical
12) Hacer una lluvia de puntos aleatoria en la pantalla.
13) Igual que el anterior, pero debe terminar el programa cuando se
toca una tecla
Para este último hay una función que se llama kbhit()

Pueden agregar los métodos que consideren necesarios.
**/
