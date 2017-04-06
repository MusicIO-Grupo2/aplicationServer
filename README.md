# Application Server


Este server es el encargado de la transmisión de canciones, la cual sera consumida por la aplicacion mobile

## Antes de empezar


Esta aplicación cuenta con una base de datos mongo, para lo cual es necesario que se instalen ciertos componentes:

* [MongoDB](https://docs.mongodb.com/manual/installation/)

* [Mongocxx Driver](https://mongodb.github.io/mongo-cxx-driver/mongocxx-v3/installation/) 

Es necesario una version de [CMake](https://cmake.org/download/) de 3.7 mínima.

## Compilación
```
$ cd ApplicationServer

$ mkdir build

$ cd build

$ cmake ..
```

Una vez compilado el proyecto se debe generar el ejecutable.  Para esto correr el siguiente comando: (dentro de la caperta build)

```
$ make
```

Despues de generado el ejecutable, solamente faltaría ejecutarlo: (dentro de la carpeta build)
```
$ ./ApplicationServer 
```

Una vez corriendo, la aplicación estará escuchando en el puerto 8080.

### Posibles problemas al compilar:
Es posible que no encuentren correctamente la librería de los drivers de mongocxx, un posible motivo es el directorio de la librería:

1. Buscar en el directorio /usr/local/include las carpetas mongocxx y bsoncxx
2. Si dentro de estas carpetas se encuentra dos subcarpetas (siendo la segunda mongocxx / bsoncxx), se deberá eliminar la carpeta intermedia
3. Finalmente debe quedar una estructura de /usr/local/include/mongocxx/$[archivos]

