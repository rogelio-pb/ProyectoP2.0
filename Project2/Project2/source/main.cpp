/**
 * @file main.cpp
 * @brief Programa principal del sistema de gestión de inventario.
 *
 * Este archivo implementa un menú interactivo para gestionar productos
 * utilizando los patrones de diseño Factory y Observer.
 */
#include "Prerequisites.h"
#include "Inventario.h"
#include "FactoryProducto.h"
#include "ObserverStock.h"
#include "Gasolineria/Gasolineria.h"
#include "Pagos/EfectivoStrategy.h"
#include "Pagos/DebitoStrategy.h"
#include "Pagos/CreditoStrategy.h"

 /**
  * @brief Función principal del programa.
  *
  * Crea un inventario, carga los productos desde un archivo JSON y
  * ofrece un menú para administrar los productos (agregar, editar, eliminar, vender, etc.).
  *
  * @return int Código de salida del programa (0 = éxito).
  */

int main() {
    
    FactoryProducto* fabrica = new FactoryProducto(); 
    Inventario inv(fabrica);                         

    AlertaStockBajo alerta;
    inv.agregarObservador(&alerta);

    std::string ruta = "productos.json";
    inv.cargar(ruta);

    int opcion;
    do {
        std::cout << "\nMenu de Inventario:\n";
        std::cout << "1. Agregar Producto\n";
        std::cout << "2. Mostrar Productos\n";
        std::cout << "3. Buscar Producto\n";
        std::cout << "4. Eliminar Producto\n";
        std::cout << "5. Editar Producto\n";
        std::cout << "6. Vender Producto\n";
        std::cout << "7. Cargar Gasolineria:\n";
        std::cout << "8. Guardar y Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            std::string codigo, nombre;
            double precio;
            int cantidad;
            std::cout << "Ingrese codigo: ";
            std::cin >> codigo;
            std::cout << "Ingrese nombre: ";
            std::cin >> nombre;
            std::cout << "Ingrese precio: ";
            std::cin >> precio;
            std::cout << "Ingrese cantidad: ";
            std::cin >> cantidad;

            Producto p(codigo, nombre, precio, cantidad);
            inv.agregar(p);
            break;
        }
        case 2:
            inv.mostrar();
            break;
        case 3: {
            std::string codigo;
            std::cout << "Ingrese codigo a buscar: ";
            std::cin >> codigo;
            inv.buscar(codigo);
            break;
        }
        case 4: {
            std::string codigo;
            std::cout << "Ingrese codigo a eliminar: ";
            std::cin >> codigo;
            inv.eliminar(codigo);
            break;
        }
        case 5: {
            std::string codigo, nombre;
            double precio;
            int cantidad;
            std::cout << "Ingrese codigo del producto a editar: ";
            std::cin >> codigo;
            std::cout << "Ingrese nuevo nombre: ";
            std::cin >> nombre;
            std::cout << "Ingrese nuevo precio: ";
            std::cin >> precio;
            std::cout << "Ingrese nueva cantidad: ";
            std::cin >> cantidad;
            Producto nuevoProducto(codigo, nombre, precio, cantidad);
            inv.editar(codigo, nuevoProducto);
            break;
        }
        case 6: {
            std::string codigo;
            int cantidad;
            std::cout << "Ingrese codigo del producto a vender: ";
            std::cin >> codigo;
            std::cout << "Ingrese cantidad a vender: ";
            std::cin >> cantidad;
            inv.vender(codigo, cantidad);
            break;
        }
        case 7:
        {
            GasolineriaFacade gasolineria;
            gasolineria.mostrarMensajeBienvenida();
            int monto;
            std::cout << "Ingrese el monto a pagar por la gasolina: ";
            std::cin >> monto;
            int metodoPago;
            std::cout << "Seleccione el metodo de pago:\n";
            std::cout << "1. Efectivo\n";
            std::cout << "2. Debito\n";
            std::cout << "3. Credito\n";
            std::cin >> metodoPago;
            Strategy* estrategia = nullptr;
            switch (metodoPago) {
            case 1:
                estrategia = new EfectivoStrategy();
                break;
            case 2:
                estrategia = new DebitoStrategy();
                break;
            case 3:
                estrategia = new CreditoStrategy();
                break;
            default:
                std::cout << "Metodo de pago invalido." << std::endl;
                continue;
            }
            gasolineria.procesarPago(estrategia, monto);
            gasolineria.registrarVenta();
            delete estrategia;
            break;
        }
        case 8:
            inv.guardar(ruta);
            std::cout << "Inventario guardado. Saliendo...\n";
            break;
        default:
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 8);

    return 0;
}
