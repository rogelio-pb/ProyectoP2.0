#pragma once
#include "Prerequisites.h"
/**
 * @class Ticket
 * @brief Gestiona la creación de tickets para compras y gasolina, incluyendo cálculo de subtotales, IVA y generación de archivo.
 */
class Ticket
{
public:
    /**
  * @brief Agrega un producto al ticket.
  *
  * Registra código, nombre, cantidad, precio unitario y subtotal calculado.
  *
  * @param codigo Código del producto.
  * @param nombre Nombre del producto.
  * @param cantidad Cantidad comprada.
  * @param precio Precio por unidad.
  */
    void agregarProducto(const std::string& codigo, const std::string& nombre, int cantidad, double precio) {
        double subtotal = cantidad * precio;

        contenido += "Producto: " + nombre + "\n" +  
            "  Codigo: " + codigo + "\n" +
            "  Cantidad: " + std::to_string(cantidad) + "\n" +
            "  Precio c/u: " + std::to_string(precio) + "\n" + 
            "  Subtotal: " + std::to_string(subtotal) + "\n";

        subtotalProductos += subtotal;   
    }
    /**
  * @brief Agrega información de gasolina al ticket.
  *
  * Incluye tipo de combustible, litros cargados, precio por litro y total calculado.
  *
  * @param tipo Tipo de gasolina (Magna, Premium, Diesel).
  * @param litros Litros despachados.
  * @param precioLitro Precio por litro.
  * @param total Total a pagar por la gasolina.
  */
    void agregarGasolina(const std::string& tipo, double litros, double precioLitro, double total) {
        contenido1 += "Gasolina: " + tipo + "\n" +
            "  Litros: " + std::to_string(litros) + "\n" +
            "  Precio/Litro: " + std::to_string(precioLitro) + "\n" +
            "  Total: " + std::to_string(total) + "\n";

        subtotalGasolina += total;       
    }
    /**
   * @brief Establece el método de pago utilizado.
   *
   * @param metodo Método de pago (Efectivo, Tarjeta, Transferencia).
   */

    void establecerMetodoPago(const std::string& metodo) {
        metodoPago = metodo;
    }
    /**
 * @brief Genera un archivo de texto con el ticket completo.
 *
 * Incluye encabezado, productos, gasolina, totales, IVA, método de pago,
 * folio automático basado en la fecha y hora, y una simulación de envío por correo.
 *
 * @param nombreArchivo Nombre del archivo a generar. Por defecto "ticket.txt".
 */
    void generarArchivo(const std::string& nombreArchivo = "ticket.txt") {

        double subtotalGeneral = subtotalProductos + subtotalGasolina;
        double iva = subtotalGeneral * 0.16;
        double totalFinal = subtotalGeneral + iva;

        std::ofstream archivo(nombreArchivo);

        archivo << "Tienda el sufrimiento\n";
        archivo << "RFC: CME910515KW1\n";
        archivo << "Salto de Leon, Coroneo, Gto 4030   Tel: 4214267263\n";
        time_t t = time(0);
        archivo << "Sucursal: 01   "  <<      "Fecha: " << ctime(&t) <<"\n";
        archivo << contenido << "\n";
        archivo << contenido1 << "\n";
        archivo << "------------------------------------\n";
        archivo << "Subtotal Productos: $" << subtotalProductos << "\n";
        archivo << "Subtotal Gasolina: $" << subtotalGasolina << "\n";
        archivo << "Subtotal General:  $" << subtotalGeneral << "\n";
        archivo << "IVA (16%):         $" << iva << "\n";
        archivo << "-----------------------\n";
        archivo << "TOTAL A PAGAR:     $" << totalFinal << "\n";
        archivo << "Metodo de pago: " << metodoPago << "\n\n";
        archivo << "Cambios y devoluciones hasta 30 dias maximo\n";
        archivo << "codigo de barras:    " << "\n";

        archivo.close();

        std::cout << "\nTicket generado: " << nombreArchivo << std::endl;
        simularEnvioCorreo();
    }

private:
    std::string contenido;
    std::string contenido1;
    std::string metodoPago = "No especificado";

    double subtotalProductos = 0;
    double subtotalGasolina = 0;

    /**
   * @brief Simula el envío del ticket al correo del cliente.
   *
   * Muestra un mensaje en consola como representación del envío.
   */
    void simularEnvioCorreo() {
        std::cout << "(Simulando envío de ticket al correo...)\n";
        std::cout << "Ticket enviado correctamente.\n\n";
    }
};
