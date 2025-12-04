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
#include "Ticket.h"

 /**
  * @brief Función principal del programa.
  *
  * Crea un inventario, carga los productos desde un archivo JSON y
  * ofrece un menú para administrar los productos (agregar, editar, eliminar, vender, etc.).
  *
  * @return int Código de salida del programa (0 = éxito).
  */

int main() {

	Ticket Ticket;
    FactoryProducto* fabrica = new FactoryProducto(); 
	GasolineriaFacade gasolineria;
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
            /*
			*@brief Agrega un nuevo producto al inventario.
			* @details Solicita al usuario los detalles del producto y lo agrega al inventario.
            */
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
			  /*
			  * @brief Muestra todos los productos en el inventario.
              */
        case 2:
            inv.mostrar();
            break;
			/*
			* @brief Busca un producto por su código.
            */
        case 3: {
            std::string codigo;
            std::cout << "Ingrese codigo a buscar: ";
            std::cin >> codigo;
            inv.buscar(codigo);
            break;
        }
			  /*
              * @brief Elimina un producto del inventario por su código.
			  */
        case 4: {
            std::string codigo;
            std::cout << "Ingrese codigo a eliminar: ";
            std::cin >> codigo;
            inv.eliminar(codigo);
            break;
        }
			  /*
			  * @brief Edita un producto existente en el inventario.
              */
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
			  /*
			  * @brief Vende un producto del inventario.
              */
        case 6: {
            std::string codigo;
            int cantidad;
            std::cout << "Ingrese codigo del producto a vender: ";
            std::cin >> codigo;
            std::cout << "Ingrese cantidad a vender: ";
            std::cin >> cantidad;
             Producto vendido = inv.vender(codigo, cantidad);
    Ticket.agregarProducto(
        vendido.getCodigo(),
        vendido.getNombre(),
        cantidad,
        vendido.getPrecio()
    );
            break;
        }
			  /*
              * @brief Procesa la carga de gasolina en la gasolinera.
			  */

        case 7:
        {
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
            std::string metodo;

            switch (metodoPago) {
                /*
				*@brief Selecciona y ejecuta la estrategia de pago basada en la elección del usuario.
                */
            case 1:
                estrategia = new EfectivoStrategy();
                metodo = "Efectivo";
                break;
				/*
                * @brief Selecciona la estrategia de pago con débito.
				*/
            case 2:
                estrategia = new DebitoStrategy();
                metodo = "Debito";
                break;
				/*
				* @brief Selecciona la estrategia de pago con crédito.
                */
            case 3:
                estrategia = new CreditoStrategy();
                metodo = "Credito";
                break;
            default:
                std::cout << "Metodo de pago invalido." << std::endl;
                continue;
            }
            /*
			* @brief Procesa el pago y registra la venta de gasolina.
            */
            gasolineria.procesarPago(estrategia, monto, metodo);
            gasolineria.registrarYValidarVenta();

          /*
		  *@brief Agrega la información de la gasolina al ticket.
          */
            Ticket.agregarGasolina(
                gasolineria.getTipoGasolina(),
                gasolineria.getLitros(),
                gasolineria.getPrecioLitro(),
                gasolineria.getTotal() 
            );

			/*
            * @brief Establece el método de pago en el ticket.
			*/
            Ticket.establecerMetodoPago(metodo);

            delete estrategia;
            break;
        }
        /*
		* @brief Guarda el inventario en un archivo y sale del programa.
        * @details Llama al método guardar del inventario y genera el archivo de ticket final.
	     */
        case 8:
            
            
            inv.guardar(ruta);
            Ticket.generarArchivo("ticket_final.txt");
            std::cout << "Inventario guardado. Saliendo...\n";
            break;
        default:
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 8);

    return 0;
}
