/**
 * @file FactoryProducto.h
 * @brief Implementa el patrón Factory para crear objetos Producto.
 */
#pragma once
#include "Prerequisites.h"
#include "Productos.h"
 /**
  * @class FactoryProducto
  * @brief Fábrica encargada de crear instancias de Producto.
  */
class FactoryProducto {
public:
    /**
 * @brief Crea un nuevo producto.
 * @param codigo Código del producto.
 * @param nombre Nombre del producto.
 * @param precio Precio del producto.
 * @param cantidad Cantidad inicial.
 * @return Objeto Producto creado.
 */
    virtual Producto crearProducto(const std::string& codigo,
        const std::string& nombre,
        double precio,
        int cantidad) {
        return Producto(codigo, nombre, precio, cantidad);
    }

    virtual ~FactoryProducto() = default;
};
