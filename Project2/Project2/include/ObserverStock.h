/**
 * @file ObserverStock.h
 * @brief Implementa un observador que alerta cuando un producto tiene bajo stock.
 */
#pragma once
#include "Prerequisites.h"
#include "Productos.h"
#include "Observer.h"
 /**
  * @class AlertaStockBajo
  * @brief Observador que imprime una alerta cuando el stock de un producto es bajo.
  */

class AlertaStockBajo : public Observer
{
public:
	void actualizar(const std:: string& producto) override {
		
		std::cout << "Alerta: El producto: " << producto <<
			" Esta bajo en unidades" << std::endl;
	}
};