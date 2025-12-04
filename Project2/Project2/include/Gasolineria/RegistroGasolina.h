#pragma once
#include "Prerequisites.h"

/**
 * @class RegistroGasolina
 * @brief Gestiona la información relacionada con una venta de gasolina.
 *
 * Esta clase se encarga de solicitar y almacenar:
 *  Tipo de gasolina, Barata, Cara, Diesel
 *  Litros cargados
 *  Precio por litro
 *
 * Además, permite obtener los datos registrados y calcular el total.
 */
class 
	RegistroGasolina{
public:
	RegistroGasolina(): litros(0.0), precioLitro(0.0) {}
	~RegistroGasolina()=default;

	/**
   * @brief Solicita al usuario el tipo de gasolina.
   *
   * Pide al usuario que escriba:
   *  Barata
   *  Cara
   * Diesel
   */
	void registroDatos() {
		std::cout << "Ingrese el tipo de gasolina (Barata, Cara, Dissel): ";
		std::cin >> tipoGas;

	}

	/**
   * @brief Solicita al usuario los litros y el precio por litro.
   *
   * También guarda los valores en los atributos internos.
   */
	void registroLitrosPrecio() {
		std::cout << "Ingrese la cantidad de litros: ";
		std::cin >> litros;
		std::cout << "Ingrese el precio por litro: ";
		std::cin >> precioLitro;
	}

	/*
	*@brief Obtiene los litros registrados.
	* @return Litros de gasolina cargados.
	*/
	double getLitros()
		const { return litros; }
	/**
 * @brief Obtiene el precio por litro registrado.
 * @return Precio por litro.
 */
	double getPrecioLitro() 
		const { return precioLitro; }
	std::string getTipoGas()
		const { return tipoGas; }
	/**
	* @brief Calcula el total de la venta de gasolina.
	* @return Litros * precio por litro.
	*/
	double getTotal() const {
		return litros * precioLitro;
	}

private:
	std::string tipoGas;
	double litros;
	double precioLitro;
	std::string tipoGasolina;
	
};


