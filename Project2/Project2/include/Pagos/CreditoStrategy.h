#pragma once
#include "Prerequisites.h"
#include "Pagos/Strategy.h"

class CreditoStrategy : public Strategy
{
public:
	CreditoStrategy() = default;
	~CreditoStrategy() = default;
	int execute(int pago) override {
		std::cout << "Pago realizado con debito. Monto: " << pago << std::endl;
		return static_cast<int>(pago);
	}
};
