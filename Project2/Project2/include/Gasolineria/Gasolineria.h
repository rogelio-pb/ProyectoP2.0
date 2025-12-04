#pragma once
#include "Prerequisites.h"
#include "Pagos/Strategy.h"
#include "Gasolineria/RegistroGasolina.h"
#include "Gasolineria/ValidacionGas.h"

/**
 * @class GasolineriaFacade
 * @brief Implementa el patrón Facade para simplificar la interacción con el sistema de gasolinera.
 *
 * Esta clase coordina:
 * - El registro de gasolina
 * - La validación del monto pagado
 * - El uso de estrategias de pago
 *
 * Permite que el usuario interactúe con un sistema complejo mediante métodos simples.
 */
class GasolineriaFacade{

public:
    GasolineriaFacade() = default;
    ~GasolineriaFacade() = default;
    /**
 * @brief Muestra un mensaje de bienvenida en la consola.
 */
    void mostrarMensajeBienvenida() {
        std::cout << "Bienvenido a la Gasolinería!" << std::endl;
    }
    /**
 * @brief Procesa el pago usando una estrategia de pago (Strategy Pattern).
 *
 * Este método ejecuta la estrategia elegida, registra el pago,
 * guarda el monto y el método utilizado.
 *
 * @param estrategia Puntero a la estrategia de pago a utilizar.
 * @param monto Monto a pagar ingresado por el usuario.
 * @param metodo Nombre del método de pago (Efectivo, Tarjeta, etc.).
 */

    void procesarPago(Strategy* estrategia, int monto, const std::string& metodo)
    {
        estrategia->execute(monto);
        pagoRealizado = true;
        ultimoMontoPagado = monto;
        metodoPagoUsado = metodo;

        std::cout << "Pago registrado. Ahora puede cargar gasolina." << std::endl;
    }
    /**
    * @brief Registra la venta de gasolina y valida que el pago haya sido correcto.
    *
    * Este método:
    * 1. Verifica si ya se realizó un pago.
    * 2. Registra datos de la gasolina.
    * 3. Calcula litros y precio.
    * 4. Valida si el monto coincide con el pago realizado.
    *
    * Si todo es válido, confirma la venta.
    */

    void registrarYValidarVenta()
    {
        if (!pagoRealizado) {
            std::cout << "ERROR: No se ha realizado un pago todavía." << std::endl;
            return;
        }

      
        registro.registroDatos();
        registro.registroLitrosPrecio();

    
        bool valido = validacion.ValidarMonto(
            registro.getLitros(),
            registro.getPrecioLitro(),
            ultimoMontoPagado
        );

        if (valido) {
          

            std::cout << "Venta registrada correctamente." << std::endl;
        }
        else {
            std::cout << "ERROR: Monto incorrecto. Venta cancelada." << std::endl;
        }
    }
    /**
    * @brief Obtiene el tipo de gasolina registrada.
    * @return Tipo de gasolina (Magna, Premium, Diesel).
    */
    std::string getTipoGasolina() const {
        return registro.getTipoGas();
    }
    /**
    * @brief Obtiene los litros registrados.
    * @return Litros de gasolina cargados.
    */
    double getLitros() const {
        return registro.getLitros();
    }

    double getPrecioLitro() const {
        return registro.getPrecioLitro();
    }


    /**
     * @brief Calcula el total de la venta de gasolina.
     *
     * @return Litros * precio por litro.
     */
    double getTotal() {
        return registro.getLitros() * registro.getPrecioLitro();
    }

private:
    RegistroGasolina registro;
    ValidacionGas validacion;

    bool pagoRealizado = false;
    double ultimoMontoPagado = 0;
    std::string metodoPagoUsado;
};
