#pragma once
#include "Prerequisites.h"
#include "Pagos/Strategy.h"
/**
 * @class EfectivoStrategy
 * @brief Implementa la estrategia de pago en efectivo.
 *
 * Esta clase concreta del patrón Strategy define el comportamiento específico
 * para procesar pagos realizados en efectivo.
 */
class 
	EfectivoStrategy : public Strategy
{
public:
	EfectivoStrategy()=default;
	~EfectivoStrategy()=default;
	/**
	 * @brief Ejecuta el pago en efectivo.
	 *
	 * Este método simula la realización de un pago en efectivo
	 * e imprime el monto pagado en la consola.
	 *
	 * @param pago Monto a pagar.
	 * @return Monto pagado.
	 */

	int execute(int pago) override {
		std::cout << "Pago realizado en efectivo. Monto: " << pago << std::endl;
		return pago;
	}

private:

};

