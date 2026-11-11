# Plataforma de Streaming en C++

Aplicación de consola que simula un servicio de streaming. Carga un catálogo de películas y series desde un archivo CSV y permite filtrar videos por calificación o género, consultar los episodios de una serie y calificar contenido.

Proyecto integrador de la materia Programación Orientada a Objetos (TC1030) del Tecnológico de Monterrey, Campus Estado de México.

## Funcionalidades

1. Cargar el catálogo desde `BasePeliculas.csv`
2. Mostrar videos (películas y episodios) con calificación mayor a un valor o de un género específico
3. Mostrar los episodios de una serie
4. Mostrar películas con calificación mayor a un valor
5. Calificar un video (la nueva calificación se promedia con la anterior)

El programa valida las entradas del usuario: maneja opciones fuera de rango, texto donde se espera un número, calificaciones fuera de 0 a 10, y géneros o videos que no existen.
