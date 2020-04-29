#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct ventas{
	string zona;
	char identi;
	string socio;
	float descuento;
	float precio;
	int nvoletos;
	float totalvta;
};
void venta();
void reporte();

int main(){
	
	venta();
	reporte();
	
	return 0;
}
	
void venta(){
	string zona;
	char identi;
	char socio;
	float descuento;
	float precio;
	int nentradas;
	float totalvta;
	string s;
	
	cout<<"----- Venta de Boletos -----"<<endl;
	cout<<" Ingrese tipo de zona: "<<endl;
	cout<<" VIP    -> V " <<endl;
	cout<<" PLATEA -> P "<<endl;
	cout<<" POPULAR -> E  "<<endl;
	cin>>identi;
	cout<<"Indique el numero de entradas a comprar: "<<endl;
	cin>>nentradas;	
	cout<<"Usted es socio? Si -> s | No -> n"<<endl;
	cin>>socio;
	
	if (nentradas >= 3 || nentradas <= 6 ){
		switch(identi){
			case 'V':
					descuento = 0.05;
					precio = 350.00;
					totalvta = (precio - (descuento * precio) )* nentradas;
			break;
			case 'P':
					descuento = 0.05;
					precio = 130.00;
					totalvta = (precio - (descuento * precio) )* nentradas; 
			break;
			case 'E':
					descuento = 0.05;
					precio = 50.00;
					totalvta = (precio - (descuento * precio) )* nentradas;
			break;	
		}
	}
	else if (nentradas >= 7 || nentradas<=9 ){
		switch(identi){
			case 'V':
					descuento = 0.075;
					precio = 350.00;
					totalvta = (precio - (descuento * precio) )* nentradas;
			break;
			case 'P':
					descuento = 0.075;
					precio = 130.00;
					totalvta = (precio - (descuento * precio) )* nentradas; 
			break;
			case 'E':
					descuento = 0.075;
					precio = 50.00;
					totalvta = (precio - (descuento * precio) )* nentradas; 	
			break;	
		}
	} else if (nentradas > 9){
		switch(identi){
			case 'V':
					descuento = 0.10;
					precio = 350.00;
					totalvta = (precio - (descuento * precio) )* nentradas;
			break;
			case 'P':
					descuento = 0.10;
					precio = 130.00;
					totalvta = (precio - (descuento * precio) )* nentradas; 
			break;
			case 'E':
					descuento = 0.10;
					precio = 50.00;
					totalvta = (precio - (descuento * precio) )* nentradas; 	
			break;	
	}
}
	
	if(socio=='S'){
			descuento = 0.08;
			totalvta = totalvta * descuento;	
	}
	
	cout<<"Zona: "<<identi<<" Descuento: "<<descuento<<" Precio: "<<precio<<" Entradas: "<<nentradas<<" Total de la venta: "<<totalvta;
	ofstream grabararchivo;
	try {
		grabararchivo.open("HT4_EJERCICIO_02.txt",ios::app);
		grabararchivo<<identi<<"\t"<<descuento<<"\t"<<precio<<"\t"<<nentradas<<"\t"<<totalvta<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
	cout<<"\n"<<"Ventas Actuales"<<endl;
	cout<<" Zona  Descuento  Precio  Entradas  TotalVenta"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("HT4_EJERCICIO_02.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
}

void reporte(){
	ifstream db;
	float d,p,n,tv=0;
	char i;
	float sumatotal=0;
	float iV=0;
	float iP=0;
	float iE=0;	
	try{	
		db.open("boletos.txt",ios::in);
		
		while (db >>i >> d >>p>> n>>tv){
			sumatotal = tv + sumatotal;	
			if (i == 'V')
				iV+=tv;
			else if (i =='P')
				iP+=tv;
			else if (i =='E')
				iE+=tv;
		}	
		db.close();
		
		cout<<setprecision(5)<<"Total de Ventas:          "<<sumatotal<<endl;
		cout<<"Desgloce por boleto:  "<<endl;
		cout<<setprecision(5)<<"  VIP   "<<iV<<" - % sobre el total: "<<setprecision(3)<<iV*100/sumatotal<<endl;
		cout<<setprecision(5)<<"  PLATEA "<<iP<<" - % sobre el total: "<<setprecision(3)<<iP*100/sumatotal<<endl;
		cout<<setprecision(5)<<"  POPULAR    "<<iE<<" - % sobre el total: "<<setprecision(3)<<iV*100/sumatotal<<endl;
	
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
}
