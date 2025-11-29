#pragma once
#include "Prerequisites.h"
#include "Pagos/Strategy.h"

class
	DebitoStrategy : public Strategy {
public:
	DebitoStrategy() = default;
	~DebitoStrategy() = default;
	int execute(int pago) override {
		std::cout << "Pago realizado con debito. Monto: " << pago << std::endl;
		return static_cast<int>(pago);
	}
};