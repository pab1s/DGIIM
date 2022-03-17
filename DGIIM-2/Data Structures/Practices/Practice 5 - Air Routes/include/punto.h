/**
 * @file punto.h
 * @author Ángel Olmedo & Pablo Olivares
 * @brief Clase que almacena y modifica los valores de un punto
 * de la ruta.
 * @date 2021-01-01
 */
#ifndef __PUNTO__
#define __PUNTO__

#include <iostream>

class Punto{
	private:
		std::string descripcion;
		double latitud, longitud;

		/**
		 * @brief Funcion privada que copia un punto dado en
		 * el actual.
		 * @param P Punto a copiar.
		 */
		void copiar(const Punto& P);

	public:

		/**
		 * @brief Construye a un nuevo objeto Punto sin 
		 * parámetros.
		 */
		Punto();

		/**
		 * @brief Construye a un nuevo objeto Punto con 
		 * parámetros.
		 * @param lat latitud en el mapa.
		 * @param lng longitud en el mapa.
		 */
		Punto(const double lat, const double lng);

		/**
		 * @brief Construye a un nuevo objeto Punto con 
		 * parámetros.
		 * @param lat latitud en el mapa.
		 * @param lng longitud en el mapa.
		 * @param desc Información de interés del punto.
		 */
		Punto(double lat, double lng, std::string desc);

		/**
		 * @brief Construye un nuevo objeto Punto a partir
		 * de un punto dado.
		 * @param P Punto a copiar.
		 */
		Punto(const Punto &P);

		/**
		 * @brief Sobrecarga del operador de asignación.
		 * @param P Punto que copia.
		 * @return Punto& Punto copiado.
		 */
		Punto & operator=(const Punto &P);

		/**
		 * @brief Establece la latitud del punto.
		 * @param lat latitud del punto.
		 */
		void setLatitud(const double lat);

		/**
		 * @brief Establece la longitud del punto.
		 * @param lng longitud del punto.
		 */
		void setLongitud(const double lng);

		/**
		 * @brief Establece las coordenadas del punto.
		 * @param lat latitud del punto.
		 * @param lng longitud del punto.
		 */
		void setCoordenadas(const double lat, double lng);

		/**
		 * @brief Establece la descripción del punto.
		 * @param des descripción del punto.
		 */
		void setDescripcion(const std::string des);

		/**
		 * @brief Devuleve la latitud del punto.
		 * @return double latitud.
		 */
		double getLatitud() const;

		/**
		 * @brief Devuleve la longitud del punto.
		 * @return double longitud.
		 */
		double getLongitud() const;

		/**
		 * @brief Devuleve la descripción del punto.
		 * @return string descripcion.
		 */
		std::string getDescripcion() const;
		
		/**
		 * @brief Función que dado un flujo, lee un punto. 
		 * @param is Flujo de entrada.
		 */
		void leerPunto(std::istream &is);

		/**
		 * @brief Función que dado un flujo, saca la información
		 * del punto.
		 * @param os Flujo de salida.
		 */
		void escribirPunto(std::ostream &os) const;

		/**
		 * @brief Sobrecarga del operador de entrada para Punto. 
		 * @param is Flujo de entrada.
		 * @param P Punto a leer.
		 * @return std::istream& Devuelve el flujo.
		 */
		friend std::istream &operator>>(std::istream &is, Punto &P);

		/**
		 * @brief Sobrecarga del operador de salida para devolver
		 * un punto.
		 * @param os Flujo de salida. 
		 * @param P Punto a devolver.
		 * @return std::ostream& Devuelve el flujo.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Punto &P);

		/**
		 * @brief Sobrecarga del operador de comparación de igualdad. 
		 * @param P Punto que comparar con el original.
		 * @return true Son iguales.
		 * @return false No lo son.
		 */
		bool operator==(const Punto &P) const;

		/**
		 * @brief Sobrecarga del operador resta. Resta las coordenadas de
		 * los puntos.
		 * @param g Punto a restar.
		 * @return Punto Valor del punto restado.
		 */
		Punto operator-(const Punto &g);

		/**
		 * @brief Sobrecarga del operador suma. Suma las coordenadas de
		 * los puntos.
		 * @param g Punto a sumar.
		 * @return Punto Valor del punto sumado.
		 */
		Punto operator+(const Punto &g);
};

#endif /*__PUNTO__*/