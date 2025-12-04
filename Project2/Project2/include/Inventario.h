/**
 * @file Inventario.h
 * @brief Gestiona una colección de productos utilizando patrones Factory y Observer.
 */
#pragma once 
#include "Prerequisites.h"
#include "Productos.h"
#include "FactoryProducto.h"
#include "ObserverStock.h"
 /**
  * @class Inventario
  * @brief Administra los productos y notifica a observadores cuando hay stock bajo.
  */
class
	Inventario {


public:
	Inventario(FactoryProducto* f) : factory(f) {}
	~Inventario() {
		delete factory;
	}

	void 
		agregarObservador(Observer* obs) {
		observadores.push_back(obs);
	}


	void 
		notificar(const std:: string& producto) {
		for (auto o : observadores) 
			o->actualizar(producto);
	}
	/**
 * @brief Notifica a todos los observadores sobre un producto.
 * @param producto Nombre del producto afectado.
 */


	void 
		cargar(const std::string& archivo) {
		std::ifstream file(archivo);
		if (!file.is_open()) {
			std::cerr << "No se pudo abrir el archivo: " << archivo << std::endl;
			return;
		}
		json j;
		file >> j;
		file.close();

		productos.clear();
		for (auto& item : j["productos"]) {
			Producto p(item["codigo"], item["nombre"], item["precio"], item["cantidad"]);
			productos.push_back(p);
		}
		std::cout << "Productos cargados desde " << archivo << std::endl;
	}
	/**
	  * @brief Carga los productos desde un archivo JSON.
	  * @param archivo Nombre del archivo.
	  */

	void 
		guardar(const std::string& archivo) {
		json j;
		for (const auto& p : productos) {
			j["productos"].push_back(p.toJSON());
		}
		std::ofstream file(archivo);
		if (!file.is_open()) {
			std::cerr << "No se pudo abrir el archivo para escribir: " << archivo << std::endl;
			return;
		}
		file << j.dump(4);
		file.close();
		std::cout << "Productos guardados en " << archivo << std::endl;
	}
	    /**
     * @brief Guarda en productos.json por defecto.
     */


	void 
		agregar(const Producto& p) {
		productos.push_back(p);
		if (p.getCantidad() < 5) {
			notificar(p.getNombre());
		}
	}
	/**
	  * @brief Agrega un nuevo producto.
	  * @param p Producto a agregar.
	  */

	void
		mostrar() const {
		for (const auto& p : productos) {
			p.mostrar();
		}
	}
	/**
 * @brief Muestra todos los productos.
 */

	void 
		buscar(const std::string& codigo) const {
		for (const auto& p : productos) {
			if (p.getCodigo() == codigo) {
				p.mostrar();
				return;
			}
		}
		std::cout << "Producto con codigo " << codigo << 
			" no encontrado." << std::endl;
	}
	/**
 * @brief Busca un producto por código.
 * @param codigo Código del producto.
 */

	void 
		eliminar(const std::string& codigo) {
		auto it = std::remove_if(productos.begin(), productos.end(),
			[&codigo](const Producto& p) { return p.getCodigo() == codigo; });
		if (it != productos.end()) {
			productos.erase(it, productos.end());
			std::cout << "Producto con codigo " << codigo <<
				" eliminado." << std::endl;
		} else {
			std::cout << "Producto con codigo " << codigo <<
				" no encontrado." << std::endl;
		}
	}
	/**
	* @brief Elimina un producto por código.
	* @param codigo Código del producto.
	*/


	void 
		guardar() {
		guardar("productos.json");
	}
	void editar(const std::string& codigo, const Producto& nuevo) {
		for (auto& p : productos) {
			if (p.getCodigo() == codigo) {
				p = nuevo;
				std::cout << "Producto con codigo " << codigo << 
					" editado." << std::endl;
				return;
			}
		}
		std::cout << "Producto con codigo " << codigo << 
			" no encontrado." << std::endl;
	}
	/**
 * @brief Edita un producto existente.
 * @param codigo Código del producto.
 * @param nuevo Nueva información del producto.
 */


	Producto vender(const std::string& codigo, int cantidad) {//el auto devuelve una copia del producto vendido
		for (auto& p : productos) {
			if (p.getCodigo() == codigo) {
				if (p.getCantidad() >= cantidad) {
					p.setCantidad(p.getCantidad() - cantidad);
					std::cout << "Venta realizada: " << cantidad << 
						" unidades de " << p.getNombre() << std::endl;
					if (p.getCantidad() < 5) {
						notificar(p.getNombre());
					}
					return p;
				} else {
					std::cout << "Stock insuficiente para el producto " 
						<< p.getNombre() << std::endl;
					return Producto("", "", 0, 0);
				}
			}
		}
		std::cout << "Producto con codigo " << codigo <<
			" no encontrado." << std::endl;
		return Producto("", "", 0, 0);
	}
		private:
			std::vector<Producto> productos;
			std::vector<Observer*> observadores;
			FactoryProducto* factory;
	};
	/**
   * @brief Realiza una venta, descuenta stock y devuelve el producto vendido.
   * @param codigo Código del producto.
   * @param cantidad Cantidad a vender.
   * @return Copia del producto vendido, o uno vacío si hay error.
   */