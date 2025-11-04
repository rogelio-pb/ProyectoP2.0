#pragma once 
#include "Prerequisites.h"
#include "Productos.h"
#include "FactoryProducto.h"
#include "ObserverStock.h"

class Inventario {
	private:
	std::vector<Producto> productos;
	std::vector<Observer*> observadores;
	FactoryProducto* factory;

public:
	Inventario(FactoryProducto* f) : factory(f) {}
	~Inventario() {
		delete factory;
	}

	void agregarObservador(Observer* obs) {
		observadores.push_back(obs);
	}

	void notificar(const std:: string& producto) {
		for (auto o : observadores) 
			o->actualizar(producto);
	}

	void cargar(const std::string& archivo) {
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
			Producto p = factory->crearProducto(
				item["codigo"],
				item["nombre"],
				item["precio"],
				item["cantidad"]
			);
		}
		std::cout << "Productos cargados desde " << archivo << std::endl;
	}
	void guardar(const std::string& archivo) {
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

	void agregar(const Producto& p) {
		productos.push_back(p);
		if (p.getCantidad() < 5) {
			notificar(p.getNombre());
		}
	}
	void mostrar() const {
		for (const auto& p : productos) {
			p.mostrar();
		}
	}
	void buscar(const std::string& codigo) const {
		for (const auto& p : productos) {
			if (p.getCodigo() == codigo) {
				p.mostrar();
				return;
			}
		}
		std::cout << "Producto con codigo " << codigo << " no encontrado." << std::endl;
	}
	void eliminar(const std::string& codigo) {
		auto it = std::remove_if(productos.begin(), productos.end(),
			[&codigo](const Producto& p) { return p.getCodigo() == codigo; });
		if (it != productos.end()) {
			productos.erase(it, productos.end());
			std::cout << "Producto con codigo " << codigo << " eliminado." << std::endl;
		} else {
			std::cout << "Producto con codigo " << codigo << " no encontrado." << std::endl;
		}
	}

	void guardar() {
		guardar("productos.json");
	}
	void editar(const std::string& codigo, const Producto& nuevo) {
		for (auto& p : productos) {
			if (p.getCodigo() == codigo) {
				p = nuevo;
				std::cout << "Producto con codigo " << codigo << " editado." << std::endl;
				return;
			}
		}
		std::cout << "Producto con codigo " << codigo << " no encontrado." << std::endl;
	}

	void vender(const std::string& codigo, int cantidad) {
		for (auto& p : productos) {
			if (p.getCodigo() == codigo) {
				if (p.getCantidad() >= cantidad) {
					p.setCantidad(p.getCantidad() - cantidad);
					std::cout << "Venta realizada: " << cantidad << " unidades de " << p.getNombre() << std::endl;
					if (p.getCantidad() < 5) {
						notificar(p.getNombre());
					}
				} else {
					std::cout << "Stock insuficiente para el producto " << p.getNombre() << std::endl;
				}
				return;
			}
		}
		std::cout << "Producto con codigo " << codigo << " no encontrado." << std::endl;
	}
	};