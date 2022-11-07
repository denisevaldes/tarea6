#include<iostream> 


using namespace std; 


// se busca el vertice con la distancia minima.
void sumadenumerosV(int valorlistaoriginal, int lista[] , int V){
   
    cout<<valorlistaoriginal<<endl;
    for (int i = 0; i < valorlistaoriginal-1; i++){

        if((lista[i] + lista[i+1]) == V){
            cout<<"el valor de V = a la suma de :"<<lista[i]<<
            "+"<<lista[i+1]<<endl;
        }else{
            cout<<"la suma de los numeros no da V "<<lista[i]<<
            "+"<<lista[i+1]<<endl;
        }
    }
}

int main(){
    int lista[] = {1,2,3,4,5,6,7,8,9,10};
    int valorlistaoriginal = sizeof(lista)/sizeof(lista[0]);//largo de la lista
    int V = 3;//valor que se desea buscar de la suma de 2 numeros consecutivos
   
    sumadenumerosV(valorlistaoriginal, lista, V);
    return 0;
}