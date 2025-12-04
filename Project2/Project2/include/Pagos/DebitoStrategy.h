#pragma once
#include "Prerequisites.h"
#include "Pagos/Strategy.h"
/*
*@class DebitoStrategy
* @brief Implementa la estrategia de pago con débito.
*/
class
	DebitoStrategy : public Strategy {
public:
	DebitoStrategy() = default;
	~DebitoStrategy() = default;
	/*
	* @brief Ejecuta el pago con débito.
	* @param pago Monto a pagar.
	* @return Monto pagado.
	*/
	int execute(int pago) override {
		std::cout << "Pago realizado con debito. Monto: " << pago << std::endl;
		return pago;
	}
private:

};