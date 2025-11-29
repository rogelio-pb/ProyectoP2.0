#pragma once
#include "Prerequisites.h"

class ValidacionGas
{
public:
	ValidacionGas()=default;
	~ValidacionGas()=default;

	void ValidarLitros(double litros, double monto) {
		if (litros == monto) {
			std::cout << "Cantidad de litros correcta" << std::endl;
		}
		else {
			std::cout << "Cantidad de litros incorrecta" << std::endl;
		}
	}

	/*/void ValidarMonto(double litros, double monto, double precioLitro) {
		if (monto == litros * precioLitro) {
			std::cout << "Monto correcto" << std::endl;
		}
		else {
			std::cout << "Monto incorrecto" << std::endl;
		}
	}/*/


private:
	

};
