/**
 * @file Observer.h
 * @brief Define la interfaz del patrón Observer.
 */
#pragma once
 /**
  * @class Observer
  * @brief Interfaz base para los observadores del sistema.
  */
class Observer
{
public:
	/**
 * @brief Método que será llamado cuando ocurra un evento.
 * @param producto Nombre del producto afectado.
 */

	virtual void actualizar(const std::string& producto) = 0;
};
