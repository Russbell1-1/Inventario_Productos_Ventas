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

void listarProductos(Producto productos[],int n){
	for(int i=0;i<n;i++){
		cout<<"Nombre: "<<productos[i].nombre<<endl;
		cout<<"Precio: "<<productos[i].precio<<endl<<endl;
	}
}

int main(){
	Producto productos[100];
	int n=0;
	char op;
	do{
		cout<<"A. Registrar producto\nB. Listar productos\nOpcion: ";
		cin>>op;
		switch(op){
			case 'A':registrarProducto(productos,n);break;
			case 'B':listarProductos(productos,n);break;
		}
	}while(true);
	return 0;
}
