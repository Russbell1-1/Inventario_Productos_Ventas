#include<iostream>
#include<string>
using namespace std;

struct Producto{
	string nombre;
	float precio;
};

struct Venta{
	int idVenta;
	string producto;
	int cantidad;
	float precioTotal;
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

void buscarProducto(Producto productos[],int n){
	string nombre;
	cout<<"Nombre a buscar: ";
	getline(cin>>ws,nombre);
	for(int i=0;i<n;i++){
		if(productos[i].nombre==nombre){
			cout<<"Nombre: "<<productos[i].nombre<<endl;
			cout<<"Precio: "<<productos[i].precio<<endl;
			return;
		}
	}
}

void actualizarProducto(Producto productos[],int n){
	string nombre;
	cout<<"Nombre del producto a actualizar: ";
	getline(cin>>ws,nombre);
	for(int i=0;i<n;i++){
		if(productos[i].nombre==nombre){
			cout<<"Nuevo nombre: ";
			getline(cin,productos[i].nombre);
			cout<<"Nuevo precio: ";
			cin>>productos[i].precio;
			return;
		}
	}
}

void eliminarProducto(Producto productos[],int &n){
	string nombre;
	cout<<"Nombre del producto a eliminar: ";
	getline(cin>>ws,nombre);
	for(int i=0;i<n;i++){
		if(productos[i].nombre==nombre){
			for(int j=i;j<n-1;j++){
				productos[j]=productos[j+1];
			}
			n--;
			return;
		}
	}
}

void registrarVenta(Venta ventas[],int &nv,Producto productos[],int np){
	if(nv<100){
		string nombre;
		int cantidad;
		cout<<"Nombre del producto vendido: ";
		getline(cin>>ws,nombre);
		cout<<"Cantidad: ";
		cin>>cantidad;
		for(int i=0;i<np;i++){
			if(productos[i].nombre==nombre){
				ventas[nv].idVenta=nv+1;
				ventas[nv].producto=nombre;
				ventas[nv].cantidad=cantidad;
				ventas[nv].precioTotal=productos[i].precio*cantidad;
				nv++;
				return;
			}
		}
	}
}

int main(){
	Producto productos[100];
	Venta ventas[100];
	int n=0,nv=0;
	char op;
	do{
		cout<<"A. Registrar producto\nB. Listar productos\nC. Buscar producto\nD. Actualizar producto\nE. Eliminar producto\nF. Registrar venta\nOpcion: ";
		cin>>op;
		switch(op){
			case 'A':registrarProducto(productos,n);break;
			case 'B':listarProductos(productos,n);break;
			case 'C':buscarProducto(productos,n);break;
			case 'D':actualizarProducto(productos,n);break;
			case 'E':eliminarProducto(productos,n);break;
			case 'F':registrarVenta(ventas,nv,productos,n);break;
		}
	}while(true);
	return 0;
}
