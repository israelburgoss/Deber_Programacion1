#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Registro {
    string nombre_estudiante;//el nombre del estudiante será 
    ///tomado de manera 
    //aleatoria de una lista de 10 nombres
    string asignatura;
    float nota[4];//La nota tiene 4 componentes, el primero sobre 20 
    //puntos, el segundo sobre 20, el tercero y cuarto    //sobre 30 cada uno. 
    bool activo; // Indica si el registro está activo (true) 
    // o fue eliminado (false)
};

const string alumnos[10] = {
        "Luis Fernandez",
        "Joel Montenegro",
        "Raúl Villalobos",
        "Omar Maldonado",
        "Hugo Barrientos",
        "Noel Santillana",
        "Alan Bustamante",
        "Ivan Montecinos",
        "Eric Castellano",
        "Enzo Villacorte"
};

const string materias[6] = {
	"Programacion 1",
	"Sistemas Operativos",
	"Ingenieria en Software",
	"Base de Datos",
	"Redes",
	"Microcontroladores"
};

bool existeEnMatriz(Registro registros[], int semestres, const string& materia) {
    for (int i = 0; i < semestres; i++) {
        if (registros[i].asignatura == materia) {
            return true;
        }
    }
    return false;
}

void registrar_notas() {
    srand(time(NULL));
    const int num_estudiantes = 10;
    const int semestres = 6;
    Registro registros[num_estudiantes][semestres];

    for (int i = 0; i < num_estudiantes; i++) {
        string nombre = alumnos[rand() % 10];
        for (int j = 0; j < semestres; j++) {
            registros[i][j].nombre_estudiante = nombre;

            // Evitar materias repetidas en la fila del estudiante
            do {
                registros[i][j].asignatura = materias[rand() % 6];
            } while (existeEnMatriz(registros[i], j, registros[i][j].asignatura));

            registros[i][j].nota[0] = rand() % 21;
            registros[i][j].nota[1] = rand() % 21;
            registros[i][j].nota[2] = rand() % 31;
            registros[i][j].nota[3] = rand() % 31;
            registros[i][j].activo = true;
        }
    }

    cout << "Registro de Notas de Estudiantes:\n\n";
    cout << "=== REGISTROS ===\n";
    for (int i = 0; i < num_estudiantes; i++) {
        cout << "-------------------------\n";
        cout << "Estudiante: " << registros[i][0].nombre_estudiante << endl;
        for (int j = 0; j < semestres; j++) {
            cout << "  Semestre " << j + 1 << ": ";
            cout << "Asignatura: " << registros[i][j].asignatura << endl;

            for (int k = 0; k < 4; k++) {
                cout << registros[i][j].nota[k] << " ";
            }
            cout << "| Estado: " << (registros[i][j].activo ? "Activo" : "Inactivo") << endl;

            int promedio = registros[i][j].nota[0] + registros[i][j].nota[1]
                + registros[i][j].nota[2] + registros[i][j].nota[3];

            cout << "Promedio: " << promedio << endl;
            if (promedio >= 70) {
                cout << "Estado: Aprobado\n";
            }
            else {
                cout << "Estado: Reprobado\n";
            }
        }
        cout << "-------------------------\n\n";
    }
}


int main()
{
	registrar_notas();
	return 0;
}
