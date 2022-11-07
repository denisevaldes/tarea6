//Busqueda Binaria

#include<iostream>
#include<string>


using namespace std;
void busquedabinaria(int inf, int sup,int valorlistaoriginal, int dato, int numeros[]){
    char band='F';
    inf=0;
	sup=10;
    int i=0;
    int mitad;
	mitad = (inf+sup)/2;
	while((inf<=sup)&&(i<5)&&(mitad +1 < valorlistaoriginal)){
		mitad = (inf+sup)/2;
		if(numeros[mitad] + numeros[mitad + 1] == dato){
			band='V';
			break;
		}
		if(numeros[mitad] + numeros[mitad + 1]>dato){
			sup = mitad;
			mitad = (inf+sup)/2;
		}
		if(numeros[mitad] + numeros[mitad + 1]<dato){
			inf = mitad;
			mitad = (inf+sup)/2;
		}
		i++;
	}
	
	if(band == 'V'){
		cout<<"el valor del dato es igual a la suma de : "<<numeros[mitad]<<"+"<<numeros[mitad+1]<<endl;
	}
	else{
		cout<<"el dato NO se encontro""\n"<<endl;
	}
}

int main(){


	int numeros[] = {1,2,3,4,5,6,7,8,9,10};
	int inf,sup,dato;
	
	int valorlistaoriginal = sizeof(numeros)/sizeof(numeros[0]);
	dato = 20;

	int opcion;
    int opcion2;   
    bool repetir = true;

    do{

        cout<<"\nBusqueda binaria"<<endl;

        cout<<"\n\nMenu de opciones"<<endl;
        cout<<"\t1 Elegir el dato, la suma de 2 numeros consecutivos = dato"<<endl;
        cout<<"\t0 Salir"<<endl;

        cout<<"\n\t ingrese una opcion:  "<<endl;
        cin >> opcion;
        

        switch (opcion){

        case 1:
            
            cout<<"\n\t la lista existente es : ( 1,2,3,4,5,6,7,8,9,10 )\t"<<endl;

            cout<<"\n\t ejemplo, 1 = x , 2 = y , dato = 3, la suma de x + y = dato\t"<<endl;
            cout<<"\n\t informacion : el programa le informara que numeros dan como resultado el dato ingresado \t\t\t"<<endl;
            cout<<"\n\t posibles datos : ( 3,5,7,9,11,13,15,17,19 ) \t"<<endl;
            cout<<"\n\t ingrese el dato que desea buscar:  "<<endl;
            cin >> opcion2;
            
            busquedabinaria(0,10,valorlistaoriginal,opcion2,numeros);

            break;
        case 0:
            cout<<"el programa a terminado\n\n\n"<<endl;
            repetir = false;
            break;
        
        default:
            cout<<"la opcion que ingreso es incorrecta"<<endl;
            break;
        }

    }while(repetir);
	

	return 0;
}
