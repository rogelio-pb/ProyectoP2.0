#include "Prerequisites.h"
#include "Inventario.h"
#include "FactoryProducto.h"
#include "ObserverStock.h"

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
        std::cout << "7. Guardar y Salir\n";
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
            inv.guardar(ruta);
            std::cout << "Inventario guardado. Saliendo...\n";
            break;
        default:
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 7);

    return 0;
}
