#pragma once
#include "Prerequisites.h"

class Producto {
private:
	std::string codigo;
	std::string nombre;
	double precio;
	int cantidad;

public:
	Producto(std::string c, std::string n, double p, int cant)
		: codigo(c), nombre(n), precio(p), cantidad(cant) {
	}

	std::string getCodigo() const { return codigo; }
	std::string getNombre() const { return nombre; }
	double getPrecio() const { return precio; }
	int getCantidad() const { return cantidad; }

	void setCantidad(int c) { cantidad = c; }

	void mostrar() const {
		std::cout << "Codigo: " << codigo
			<< ", Nombre: " << nombre
			<< ", Precio: " << precio
			<< ", Cantidad: " << cantidad << std::endl;
	}
	json toJSON() const {
		return json{
			{"codigo", codigo},
			{"nombre", nombre},
			{"precio", precio},
			{"cantidad", cantidad}
		};
	}
};
