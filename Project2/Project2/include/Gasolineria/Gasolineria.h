#pragma once
#include "Prerequisites.h"
#include "Pagos/Strategy.h"
#include  "Gasolineria/RegistroGasolina.h"
#include "Gasolineria/ValidacionGas.h"
  /**
   * @class GasolineriaFacade
   * @brief Fachada para simplificar las operaciones de la gasolinería.
   */

class GasolineriaFacade
{
	public:
	GasolineriaFacade() = default;
	~GasolineriaFacade() = default;
	void procesarPago(Strategy* estrategia, int monto) {
		estrategia->execute(monto);
	}
	void registrarVenta() {
		std::cout << "Venta de gasolina registrada exitosamente." << std::endl;
	}
	void gestionarGasolina() {
		RegistroGasolina registro;
		ValidacionGas validacion;
		registro.registroDatos();
		registro.registroLitrosPrecio();
		double litros, monto;
		std::cout << "Ingrese la cantidad de litros para validar: ";
		std::cin >> litros;
		std::cout << "Ingrese el monto para validar: ";
		std::cin >> monto;
		validacion.ValidarLitros(litros, monto);
		//validacion.ValidarMonto(litros, monto, precioLitro);
	}
	void mostrarMensajeBienvenida() {
		std::cout << "Bienvenido a la Gasolineria!" << std::endl;
	}
};
