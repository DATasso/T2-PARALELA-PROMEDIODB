# T2-PARALELA-PROMEDIODB
El taller consiste en escribir un programa en C++, que pueda leer una base de datos (PostgreSQL) con los puntajes psu de una persona con el siguiente formato "rut;nem;ranking;lenguaje;matematicas;ciencias;historia" y luego deberá escribir un archivo con el promedio simple de estos puntajes por rut, teniendo finalmente un archivo con entradas "rut;promedio".

### Archivos
- `promediosDB.cpp` contiene el programa en C++

### Librerias
- `sudo apt-get install libpqxx-dev` libreria libpqxx (official C++ client API for PostgreSQL)

### Compilación
Para C++ Secuencial:
```
g++ promediosDB.cpp -lpqxx -lpq
```
### Ejecución
- C++ Windows
    `./main.exe
- C++ Linux
    `./a.out

#### Autores
- Daniel Aguilera Tasso
- Nicolás Andrews Sandoval
- Allan Morales Prado

(Grupo 6)
