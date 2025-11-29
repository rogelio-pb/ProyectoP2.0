#pragma once
#include "Prerequisites.h"

class RegistroGasolina
{
public:
	RegistroGasolina()=default;
	~RegistroGasolina()=default;

	void registroDatos() {
		std::cout << "Ingrese el tipo de gasolina (Regular, Premium, Diesel): ";
		std::cin >> tipoGas;

	}

	void registroLitrosPrecio() {
		std::cout << "Ingrese la cantidad de litros: ";
		std::cin >> litros;
		std::cout << "Ingrese el precio por litro: ";
		std::cin >> precioLitro;
	}

private:
	std::string tipoGas;
	double litros;
	double precioLitro;
};


