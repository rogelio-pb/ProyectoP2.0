#pragma once
#include "Prerequisites.h"

/**
 * @class ValidacionGas
 * @brief Clase encargada de validar que el monto pagado coincida con el costo real de la gasolina.
 *
 * Esta clase compara:
 * Litros cargados
 * Precio por litro
 * Monto que el usuario dice haber pagado
 *
 * Y verifica que el total sea correcto dentro de un margen mínimo de error.
 */

class ValidacionGas
{
public:
    ValidacionGas() = default;
    ~ValidacionGas() = default;
    /*
	*@brief Valida que el monto pagado coincida con el costo real de la gasolina.
	* @param precioLitro Precio por litro de gasolina.
	* @param litros Cantidad de litros cargados.
	* @param monto Monto que el usuario dice haber pagado.
	* @return true si el monto es correcto, false en caso contrario.
	* @note Se permite una pequeña tolerancia de 0.001 para errores de redondeo.
    */

    bool ValidarMonto(double litros, double precioLitro, double monto)
    {
        double totalCalculado = litros * precioLitro;

        if (fabs(totalCalculado - monto) < 0.001) {
            return true;
        }
        else {
            std::cout << "Monto incorrecto. Total real: "
                << totalCalculado << std::endl;
            return false;
        }
    }
};
