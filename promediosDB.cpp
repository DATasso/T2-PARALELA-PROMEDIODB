#include <iostream>
#include <fstream>
#include <pqxx/pqxx>
#include <stdlib.h>
#include <string>

using namespace std;
using namespace pqxx;
/**
 * Función que muestra los participantes del grupo
 */
void participante();


int main(int argc, char** argv) {
   char * sql;
   std::ofstream archivoSalida("promediosDB.csv");
   string rut,promedio;
   try {
      connection C("dbname = psudb user = psu password = psu \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }

      /* Create SQL statement */
      sql = "SELECT rut, (SUM(nem + ranking + matematica + lenguaje + ciencias + historia) / 6.0)AS promedio FROM puntajes GROUP BY rut ORDER BY rut";

      /* Create a non-transactional object. */
      nontransaction N(C);
      
      /* Execute SQL query */
      result R( N.exec( sql ));
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
         rut = c[0].as<string>();
         promedio = c[1].as<string>();
         archivoSalida << rut << ";" << promedio << ";" << std::endl;
      }
      cout << "Operation done successfully" << endl;
      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;
   }    
   archivoSalida.close();

    participante();
    return EXIT_SUCCESS;
}

void participante() {
    std::cout << std::endl << "=== Tarea ===" << std::endl;
    std::cout << std::endl << "Daniel Aguilera Tasso" << std::endl << "Nicolas Andrews Sandoval" << std::endl << "Allan Morales Prado" << std::endl;
}