#pragma once
#include "Prerequisites.h"
#include "Pagos/Strategy.h"

class 
	EfectivoStrategy : public Strategy
{
public:
	EfectivoStrategy()=default;
	~EfectivoStrategy()=default;

	int execute(int pago) override {
		std::cout << "Pago realizado en efectivo. Monto: " << pago << std::endl;
		return static_cast<int>(pago);
	}

private:

};

