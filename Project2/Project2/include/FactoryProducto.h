#pragma once
#include "Prerequisites.h"
#include "Productos.h"

class FactoryProducto {
public:
    virtual Producto crearProducto(const std::string& codigo,
        const std::string& nombre,
        double precio,
        int cantidad) {
        return Producto(codigo, nombre, precio, cantidad);
    }

    virtual ~FactoryProducto() = default;
};
