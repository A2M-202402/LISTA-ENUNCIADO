#ifndef __PA2M_H_
#define __PA2M_H_

#include <stdio.h>
#include <stdarg.h>

#define BLANCO "\x1b[37;1m"
#define VERDE "\x1b[32;1m"
#define ROJO "\x1b[31;1m"
#define AMARILLO "\x1b[33;1m"
#define NORMAL "\x1b[0m"

#define TILDE "✓"
#define CRUZ "✗"

int __pa2m_cantidad_de_pruebas_corridas = 0;
int __pa2m_cantidad_de_pruebas_fallidas = 0;

void pa2m_afirmar(int afirmacion, const char *descripcion, ...)
{
	if (afirmacion) {
		printf(VERDE TILDE " ");
	} else {
		__pa2m_cantidad_de_pruebas_fallidas++;
		printf(ROJO CRUZ " ");
	}
	printf(BLANCO);
	va_list va_list;
	va_start(va_list, descripcion);
	vprintf(descripcion, va_list);
	va_end(va_list);
	printf(NORMAL "\n");
	fflush(stdout);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void pa2m_nuevo_grupo(const char *descripcion)
{
	printf(AMARILLO "\n%s\n", descripcion);
	while (*(descripcion++))
		printf("=");
	printf(BLANCO "\n");
}

int pa2m_mostrar_reporte()
{
	printf("\n---------------------------------\n"
	       "%i pruebas corridas, %i errores - %s\n" NORMAL,
	       __pa2m_cantidad_de_pruebas_corridas,
	       __pa2m_cantidad_de_pruebas_fallidas,
	       __pa2m_cantidad_de_pruebas_fallidas == 0 ? "OK" : "D:");
	return __pa2m_cantidad_de_pruebas_fallidas;
}

#endif // __PA2M_H_
