explicar el diseño y estrategia solución
La idea básica de la solucion es tener estructuras para una habitacion, que dentro contiene dispositivos,
que dentro contiene funciones, que dentro contiene parametros. Esto se realizo ligando las estructuras en si,
cada una teniendo una lista de la estructura inferior, ejemplo:
Habitacion->dispositivos->funciones->parametros
Esto para una lista de habitaciones.

Para lo que fue las tareas se realizo un procedimiento similar, donde cada tarea contiene un lista de
especificaciones (habitacion,dispositivo,funcion,parametros)
La idea principal fue hacer posible que el usuario pudiera crear nuevos dispositivos, agregarlos a diferentes
habitaciones y crear tareas con los dispositivos que agregaba a las habitaciones.

La primera solucion realizada en el BRANCH Using_vectors utiliza los vectores de c++, la cual es un version 
completamente funcional del sistema y que representa adecuadamente la estructura deseada.
Por otra parte la segunda solucion realizada en el BRANCH Using_List se utiliza la version de lista proporcionada
por el profesor, en esta solucion hubieron problemas con la impresion de los datos para una verificacion, pero
no obstante se pude observar la misma forma de la estructura que se planteo.