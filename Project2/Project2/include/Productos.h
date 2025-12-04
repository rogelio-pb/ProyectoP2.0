/**
 * @file Productos.h
 * @brief Define la clase Producto que representa un artículo en el inventario.
 */
#pragma once
#include "Prerequisites.h"
 /**
  * @class Producto
  * @brief Representa un producto con código, nombre, precio y cantidad.
  */

class
	Producto {

	/**
 * @brief Constructor del producto.
 * @param c Código del producto.
 * @param n Nombre del producto.
 * @param p Precio del producto.
 * @param cant Cantidad en inventario.
 */

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
		std::cout << "Codigo: " << codigo << "\n"
			<< "Nombre: " << nombre << "\n"
			<< "Precio: " << precio << "\n"
			<< "Cantidad: " << cantidad << "\n"
			<< "--------------------------\n";
	}

	/**
	 * @brief Convierte el producto a formato JSON.
	 * @return Objeto JSON con los datos del producto.
	 */

	json toJSON() const {
		return json{
			{"codigo", codigo},
			{"nombre", nombre},
			{"precio", precio},
			{"cantidad", cantidad}
		};
	}
private:
	std::string codigo;
	std::string nombre;
	double precio;
	int cantidad;
};
