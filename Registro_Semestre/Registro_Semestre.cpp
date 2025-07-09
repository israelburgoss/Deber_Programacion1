#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
struct Registro {
    string nombre_estudiante;//el nombre del estudiante será 
    //tomado de manera 
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
}

void mostrar_notas() {
    const int num_estudiantes = 10;
    const int semestres = 6;
    Registro registros[num_estudiantes][semestres];
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
    int opcion;
    cout << "Bienvenido al Registro de notas de estudiantes \n";
    cout << "Que desea realizar? \n";
	cout << "1. Crear notas de estudiantes\n";
    cout << "2. Mostrar notas de estudiantes\n";
    cout << "3. Editar el registro de un estudiante \n";
    cout << "4. Eliminar el registro de un estudiante \n";
	cout << "5. Salir del programa \n"; 
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Creando notas a los estudiante aleatoriamente...\n";
            registrar_notas();
			Sleep(2000); // Simula un tiempo de espera para la creación de notas
			cout << "Notas creadas exitosamente.\n";
            break;
        case 2:
            mostrar_notas();
            break;
        case 3:
            cout << "Funcionalidad de eliminar registro no implementada.\n";
            break;
        case 4:
            cout << "Funcionalidad de eliminar registro no implementada.\n";
            break;
        case 5:
			cout << "Saliendo del programa. ¡Hasta luego!\n";
			return 0;
			break;
        default:
			cout << "Opción no válida. Por favor, intente de nuevo.\n";
    }
}
