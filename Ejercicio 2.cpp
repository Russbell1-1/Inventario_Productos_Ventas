#include<iostream>
#include<string>
using namespace std;

struct Producto{
	string nombre;
	float precio;
};

void registrarProducto(Producto productos[],int &n){
	if(n<100){
		cout<<"Nombre del producto: ";
		getline(cin>>ws,productos[n].nombre);
		cout<<"Precio: ";
		cin>>productos[n].precio;
		n++;
	}
}

int main(){
	Producto productos[100];
	int n=0;
	char op;
	do{
		cout<<"A. Registrar producto\nOpcion: ";
		cin>>op;
		switch(op){
			case 'A':registrarProducto(productos,n);break;
		}
	}while(true);
	return 0;
}
