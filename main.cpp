#include "MySQLConexion.h"
#include "EloquentORM.h"
#include <iostream>
using namespace std;

int main() {
    MySQLConexion conn("root", "Marioco@2025.", "control_horario");
    if (!conn.open()) {
        cerr << "No se pudo conectar." << endl;
        return 1;
    }

    vector<string> columnas = { "NOMBRE", "EDAD", "GENERO"};
    EloquentORM personas(conn, "personas", columnas);

    auto lista = personas.getAll();
    for (auto &reg : lista) {
        cout << "ID: " << reg["id"] << ", Nombre: " << reg["NOMBRE"] << endl;
    }
    
    return 0;
}