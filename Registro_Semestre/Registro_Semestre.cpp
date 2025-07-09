#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Registro {
    string nombre_estudiante;
    string asignatura;
    float nota[4];
    bool activo;
};

const int num_estudiantes = 10;
const int semestres = 6;
Registro registros[num_estudiantes][semestres];

const string alumnos[10] = {
        "Luis Fernandez",
        "Joel Montenegro",
        "Raul Villalobos",
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
    for (int i = 0; i < num_estudiantes; i++) {
        string nombre = alumnos[rand() % 10];
        for (int j = 0; j < semestres; j++) {
            registros[i][j].nombre_estudiante = nombre;
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
    cout << "Registro de Notas de Estudiantes:\n\n";
    cout << "=== REGISTROS ===\n";
    for (int i = 0; i < num_estudiantes; i++) {
        cout << "-------------------------\n";
        cout << "Estudiante: " << registros[i][0].nombre_estudiante << endl;
        for (int j = 0; j < semestres; j++) {
            cout << "  Semestre " << j + 1 << ": " << "| Asignatura: " << registros[i][j].asignatura << "| Notas del Semestre: " << " ";
            for (int k = 0; k < 4; k++) {
                cout << registros[i][j].nota[k] << " ";
            }

            int promedio = registros[i][j].nota[0] + registros[i][j].nota[1]
                + registros[i][j].nota[2] + registros[i][j].nota[3];

            if (promedio >= 70) {
                if (registros[i][j].activo) {
                    cout << "| Promedio: " << promedio << "| Estado: Aprobado" << " | Estado: Activo" << " \n";
                }
                else {
                    cout << "| Promedio: " << promedio << "| Estado: Aprobado" << " | Estado: Inactivo" << " \n";
				}
            }
            else {
                cout << "| Promedio: " << promedio << "| Estado: Reprobado" << "| Estado: " << (registros[i][j].activo ? "Activo" : "Inactivo") << " \n";
            }
        }
        cout << "-------------------------\n\n";
    }
}

int main()
{
    int verNotas;
    int opcion;
    bool seCreoNotas = false;

    do {
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
			system("cls");
            cout << "Creando notas a los estudiante aleatoriamente...\n";
            registrar_notas();
            Sleep(2000); // Simula un tiempo de espera para la creación de notas
            cout << "Notas creadas exitosamente.\n";
            seCreoNotas = true;
            Sleep(3000);
            system("cls");
            break;
        case 2:
            if (seCreoNotas == true) {
				system("cls");
                mostrar_notas();
                cout << "Presione cualquier tecla para limpiar la pantalla..." << endl;
                if (_kbhit()) {
                    _getch(); // Captura la tecla presionada
                    system("cls");
                }
            }
            else {
                system("cls");
                cout << "Primero debe generar una nota" << endl;
                Sleep(2000);
				system("cls");
            }
            
            break;
        case 3:
            cout << "Funcionalidad de eliminar registro no implementada.\n";
            break;
        case 4:
            cout << "Funcionalidad de eliminar registro no implementada.\n";
            break;
        case 5:
            cout << "Saliendo del programa. Vuelve Luego!\n";
            return 0;
            break;
        default:
            cout << "Opción no válida. Por favor, intente de nuevo.\n";
        }
    } while (true);
}
