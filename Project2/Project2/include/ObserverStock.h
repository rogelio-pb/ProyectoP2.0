#pragma once
#include "Prerequisites.h"
#include "Productos.h"

class Observer
{
public:
	virtual void actualizar(const std:: string& producto) = 0;
};

class AlertaStockBajo : public Observer
{
public:
	void actualizar(const std:: string& producto) override {
		
		std::cout << "Alerta: El producto: " << producto <<" Esta bajo en unidades" << std::endl;
	}
};