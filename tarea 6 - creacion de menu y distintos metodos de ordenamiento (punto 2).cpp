#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void mostrar(int arreglo[], int tamano){
    for(int i = 0; i < tamano; i++){
        cout<< arreglo[i]<<" ";
    }
}

void metodo_burbuja(int arreglo[], int tamano){

    for( int i = 0; i < tamano; i++){
        for(int j = 0; j < (tamano - 1); j++){
            if (arreglo[j] > arreglo[j+1]){
                int temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            }
        }
    }
}

void merge(int *arreglo, int inicio, int mitad, int tamano) {
   int i, j, k, izquierda, derecha;
   
   izquierda = mitad-inicio+1; 
   derecha = tamano-mitad;
   int larr[izquierda], rarr[derecha];
   
   for(i = 0; i<izquierda; i++)
      larr[i] = arreglo[inicio+i];
   for(j = 0; j<derecha; j++)
      rarr[j] = arreglo[mitad+1+j];
   i = 0; j = 0; k = inicio;
   
   while(i < izquierda && j<derecha) {
      if(larr[i] <= rarr[j]) {
         arreglo[k] = larr[i];
         i++;
      }else{
         arreglo[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<izquierda) {  
      arreglo[k] = larr[i];
      i++; k++;
   }
   while(j<derecha) {    
      arreglo[k] = rarr[j];
      j++; k++;
   }
}
void merge_sort(int *arreglo, int inicio, int tamano) {
   int mitad;
   if(inicio < tamano) {
      int mitad = inicio+(tamano-inicio)/2;

      merge_sort(arreglo, inicio, mitad);
      merge_sort(arreglo, mitad+1, tamano);

      merge(arreglo, inicio, mitad, tamano);
   }
}

void nuevo_arreglo(int *arreglo, int tamano){
    
    for(int i = 0; i<tamano; i++){
        arreglo[i] = 1 + rand()% 50;
    }
}

int main(){

    int opcion_metodo;
    int opcion;
    int tamano;
    int arreglo[tamano];

    cout << "eliga el tamanio de su arreglo: " << endl;
    cin >> tamano;

    

    while (1==1)
    {
        cout << " " << endl;
        cout << "eliga una opción:" << endl;
        cout << "[1] Mostrar datos del arreglo original sin arreglar " << endl;
        cout << "[2] Mostrar datos del arreglo ordenado mediante algoritmo burbuja " << endl;
        cout << "[3] Mostrar datos del arreglo ordenado mediante algoritmo mergesort " << endl;
        cout << "[4] Mostrar el tiempo de ejecucion de los algoritmos " << endl;
        cout << "[5] Salir " << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "se muestra un nuevo arreglo sin ordenar:" << endl;
            nuevo_arreglo(arreglo,tamano);
            mostrar(arreglo,tamano);
            break;
        case 2:
            cout << "Arreglo ordenado mediante algoritmo burbuja" << endl;
            metodo_burbuja(arreglo,tamano);
            mostrar(arreglo,tamano);
            break;
        case 3:
            cout << "Arreglo ordenado mediante algoritmo megesort" << endl;
            merge_sort(arreglo,0, tamano-1);
            mostrar(arreglo, tamano);
            break;
        case 4:
            cout << "eliga el metodo para ver su tiempo de ejecucion" << endl;
            cout << "1  metodo burbuja" << endl;
            cout << "2  metodo merge_sort" << endl;
            cout << "eliga una opción:" << endl;
            cin >> opcion_metodo;
            if (opcion_metodo == 1){
                unsigned t0, t1;
                t0=clock();
                metodo_burbuja(arreglo,tamano);
                t1 = clock();

                double time = ((double(t1-t0)/CLOCKS_PER_SEC));
                cout << "tiempo de ejecución: " <<fixed<< time<<"segundos."<< endl;
                break;
            }
            if(opcion_metodo == 2){
                unsigned r0, r1;
                r0=clock();
                merge_sort(arreglo,0, tamano-1);
                r1 = clock();

                double rime = ((double(r1-r0)/CLOCKS_PER_SEC));
                cout << "tiempo de ejecución: " <<fixed<< rime<<"segundos."<< endl;
                break;
            }

        case 5:
            exit(EXIT_SUCCESS);
            break;
        
        default:
            cout << "la opcion elegida no es valida" << endl;
            break;
        }
    }
    

    return 0;
}