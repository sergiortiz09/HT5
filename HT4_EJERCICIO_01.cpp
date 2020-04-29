//Programa 1

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct terrenos{
	char categoria[30];
	char zona;
	int tipo;
	float precio, largo , ancho, area; 
	float total;
};
void venta();
void reporte();
int main(){
	
	venta();
	reporte();
	
	
	return 0;
}

 void venta(){
	char categoria[30];
	char zona;
	int tipo;
	float precio, largo , ancho, area; 
	float total;
	
	cout<<"\n----- Venta de Terrenos -----\n";
	cout<<" Digite la categoria: "<<endl;
	cin>>categoria;
	if(categoria[0] == 'r'){
		cout<<" Digite zona -> A  |  B |  C :  "<<endl;
		cin>>zona;
	}
	else{
		cout<<" Digite zona -> A  |  B :  "<<endl;
		cin>>zona;
	}
	cout<<" Digite tipo -> 1. Terreno | 2. Casa | 3. Departamento  : "<<endl;
	cin>>tipo;
	cout<<" Digite largo del terreno: "<<endl; 
	cin>>largo;
	cout<<" Digite ancho del terreno: "<<endl; 
	cin>>ancho;
	
	
	
	if(categoria[0]='c' && zona == 'A'){
		switch(tipo){
			case 1:
				precio = 2200; 
				total = (2200 * (largo*ancho)); 
			break;
			case 2:
				precio = 2500;
				total = (2500 * (largo*ancho)); 
			break;
			case 3:
				precio = 2100;
				total = (2100 * (largo*ancho));
			break;
		}
	}
	else if(categoria[0]=='c' && zona=='B'){
		switch(tipo){
			case 1:
				precio = 1300;
				total = (1300 * (largo*ancho));
			break;
			case 2:
				precio = 1500;
				total = (1500 * (largo*ancho)); 
			break;
			case 3:
				precio = 1200;
				total = (1200 * (largo*ancho));
			break;
		}
	}
	
	if(categoria[0]=='r' && zona=='A'){
		switch(tipo){
			case 1:
				precio = 2100;
				total = (2100 * (largo*ancho)); 
			break;
			case 2:
				precio = 2500;
				total = (2500 * (largo*ancho));
			break;
			case 3:
				precio = 2100;
				total = (2100 * (largo*ancho));
			break;
		}
	}
	else if(categoria[0]=='r' && zona=='B'){
		switch(tipo){
			case 1:
				precio = 1500;
				total = (1500 * (largo*ancho));
			break;
			case 2:
				precio = 1600;
				total = (1600 * (largo*ancho));
			break;
			case 3:
				precio = 1300;
				total = (1300 * (largo*ancho)); 
			break;
		}
	}
	else if(categoria[0]=='r' && zona=='C'){
		switch(tipo){
			case 1:
				precio = 1100;
				total = (1100 * (largo*ancho));
			break;
			case 2:
				precio = 1300;
				total = (1300 * (largo*ancho));
			break;
			case 3:
				precio = 1000;
				total = (1000 * (largo*ancho));
			break;
		}
	}

}

void reporte(){
	char categoria[30], zona;
	float tipo, precio, total ;

	
	cout<<"\n-------- Reporte de total vendido---------\n"<<endl;

	cout<<"Precio x metro cuadrado: "<<precio<<endl;
	cout<<"Total: "<<total<<endl;
}
