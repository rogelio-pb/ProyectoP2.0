#pragma once
#include "Prerequisites.h"
#include "Pagos/Strategy.h"
/**
 * @class CreditoStrategy
 * @brief Implementa la estrategia de pago con crédito.
 *
 * Esta clase concreta del patrón Strategy define el comportamiento específico
 * para procesar pagos realizados con crédito.
 */

class CreditoStrategy : public Strategy
{
public:
	CreditoStrategy() = default;
	~CreditoStrategy() = default;
	/**
	 * @brief Ejecuta el pago con crédito.
	 *
	 * Este método simula la realización de un pago con crédito
	 * e imprime el monto pagado en la consola.
	 *
	 * @param pago Monto a pagar.
	 * @return Monto pagado.
	 */
	int execute(int pago) override {
		std::cout << "Pago realizado con credito. Monto: " << pago << std::endl;
		return pago;
	}
private:

};
