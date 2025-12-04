#pragma once
#include "Prerequisites.h"
/**
 * @class Strategy
 * @brief Interfaz base para las estrategias de pago (Strategy Pattern).
 *
 * Esta clase define el método execute que debe ser implementado
 * por todas las estrategias concretas de pago.
 */
class Strategy
{
public:	
	virtual ~Strategy()=default;
	virtual int execute(int pago) = 0;
};


