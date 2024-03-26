///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

/*Un negocio tiene el registro de las ventas de este año. Por cada venta registró lo siguiente:

- día 2
- mes 1 (1,2,3)
- importe de la venta 100
- número de empleado que atendió (1 a 5). 3

Hacer un programa para ingresar los datos de las ventas, e informar el importe recaudado por cada mes y empleado.

El fin del ingreso de datos se establece ingresando un valor de mes igual a 0

El empleado que más ventas hizo.

registrar datos por mes (1 a 3) y empleado (1 a 5)
  */






void cargarDatos(float matRec[][5], int vec[]);///PROTOTIPO, FIRMA O DECLARACION DE LA FUNCION

void mostrarRecaudacion(float matRec[3][5]);

void vendedorMas(int vec[], int tam);



int main(){
    float matRec[3][5]={0}, (*m)[5];
    int ventasEmp[5]={0};
    m=matRec;
    cargarDatos(m, ventasEmp);///LLAMADA A LA FUNCION
    system("cls");///LLAMADA A LA FUNCION
    mostrarRecaudacion(matRec);///LLAMADA A LA FUNCION
	cout<<endl;
	system("pause"); ///LLAMADA A LA FUNCION
	system("cls");
	vendedorMas(ventasEmp, 5);
	system("pause");
	return 0;
}
/*
float matRec[3][5]
float matRec[][5]
float (*matRec)[5]

puntero a la dirección de la primera fila de la matriz (&matRec[0])

*****
int vec[5]
int vec[]
int *vec

puntero a la dirección de inicio del vector (&vec[0])

 */
void cargarDatos(float matRec[3][5], int vec[]){///DESARROLLO DE LA FUNCION
    int mes, empleado;
    float importe;
    cout<<"MES ";
    cin>>mes;
    while(mes!=0){
        cout<<"EMPLEADO ";
        cin>>empleado;
        cout<<"IMPORTE ";
        cin>>importe;
        matRec[mes-1][empleado-1]+=importe;  ///
        ///punto b
        vec[empleado-1]++;

        cout<<"MES ";
        cin>>mes;

    }
}


void mostrarRecaudacion(float (*matRec)[5]){
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<5;j++){
            cout<<"MES "<<i+1<<" RECAUDACION EMPLEADO "<<j+1<<" "<<matRec[i][j]<<endl;
        }
        cout<<endl;
    }

}

void vendedorMas(int vec[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<"EMPLEADO "<<i+1<<" CANTIDAD DE VENTAS "<<vec[i]<<endl;
    }

}
