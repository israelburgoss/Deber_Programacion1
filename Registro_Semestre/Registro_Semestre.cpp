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
int estudianteSeleccionado = -1;
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

const string materias[10] = {
    "Programacion",
    "Sistemas Operativos",
    "Ingenieria en Software",
    "Base de Datos",
    "Redes",
    "Microcontroladores",
    "Arquitectura del computador",
    "Computacion Distribuidas",
	"Inteligencia Artificial",
    "Desarrollo Web"
};

bool materia_ya_escogida(Registro registros[], int cantidad, const string& materia) {
    for (int i = 0; i < cantidad; i++) {
        if (registros[i].asignatura == materia) {
            return true;
        }
    }
    return false;
}

void registrar_notas() {
    srand(time(NULL));
    estudianteSeleccionado = rand() % num_estudiantes;
    string nombre = alumnos[estudianteSeleccionado];

    for (int j = 0; j < semestres; j++) {
        bool materiaValida = false;
        while (!materiaValida) {
            cout << "Estudiante: " << nombre << endl;
			cout << "Semestre #" << j + 1 << endl;
            cout << "Seleccione que desee escoger: \n";

            for (int k = 0; k < 10; k++) {
                cout << k + 1 << ". " << materias[k] << endl;
            }

            int opcionMateria;
            cin >> opcionMateria;

            if (opcionMateria < 1 || opcionMateria > 10) {
                cout << "Opcion no valida. Intente de nuevo.\n";
                Sleep(1400);
				system("cls");
                continue;
            }
            string materiaSeleccionada = materias[opcionMateria - 1];

            if (materia_ya_escogida(registros[estudianteSeleccionado], j, materiaSeleccionada)) {
                cout << "La materia ya fue seleccionada. Elija otra.\n";
                Sleep(1400);
				system("cls");
                continue;
            }

            cout << "Usted ha seleccionado la materia: " << materias[opcionMateria - 1] << endl;

            registros[estudianteSeleccionado][j].nombre_estudiante = nombre;
            registros[estudianteSeleccionado][j].asignatura = materiaSeleccionada;

            registros[estudianteSeleccionado][j].nota[0] = rand() % 21;
            registros[estudianteSeleccionado][j].nota[1] = rand() % 21;
            registros[estudianteSeleccionado][j].nota[2] = rand() % 31;
            registros[estudianteSeleccionado][j].nota[3] = rand() % 31;
            registros[estudianteSeleccionado][j].activo = true;

            materiaValida = true;
            Sleep(2000);
            system("cls");
        }
    }
}

void mostrar_notas() {
    if (estudianteSeleccionado == -1) {
        cout << "No hay notas registradas.\n";
        return;
    }
    cout << "=== REGISTRO DEL ESTUDIANTE ===\n";
    cout << "Estudiante: " << registros[estudianteSeleccionado][0].nombre_estudiante << endl;
    for (int j = 0; j < semestres; j++) {
        cout << "Semestre " << j + 1 << ": " << registros[estudianteSeleccionado][j].asignatura << endl;
        cout << "Notas: ";
        int suma = 0;
        for (int k = 0; k < 4; k++) {
            cout << registros[estudianteSeleccionado][j].nota[k] << " ";
            suma += registros[estudianteSeleccionado][j].nota[k];
        }
        cout << "| Promedio: " << suma;
        cout << " | Estado: " << (suma >= 70 ? "Aprobado" : "Reprobado");
        cout << " | " << (registros[estudianteSeleccionado][j].activo ? "Activo" : "Inactivo") << endl;
        cout << "-----------------------------------\n";
    }
}

void editar() {
    int materiaSeleccionada;
    int notaNueva;
    int opcion_editar;
    int notaSeleccionada;
    string nombre = alumnos[estudianteSeleccionado];
    // Esta funcion vamos a implementarla para cambiar las notas y las materias que deseemos
    cout << "Editar de registro del estudiante \n";
    cout << "Nombre del estudiante: " << nombre << endl;
    cout << "Que desea modificar? \n";
    cout << "1. Modificar notas \n";
    cout << "2. Modificar materias \n";
    cout << "3. Volver al menu principal \n";
    cin >> opcion_editar;
    switch (opcion_editar) {
    case 1: {
        int semestre;
        cout << "Ingrese el semestre que desea modificar (1-" << semestres << "): ";
        cin >> semestre;
        if (semestre < 1 || semestre > semestres) {
            cout << "Semestre no valido.\n";
            return;
        }
        cout << "Cual de las 4 notas desea cambiar (1-4)? ";
        cin >> notaSeleccionada;
        if (notaSeleccionada < 1 || notaSeleccionada > 4) {
            system("cls");
            cout << "Nota no valida. \n";
            Sleep(1200);
            system("cls");
            return;
        }
        cout << "Nota seleccionada: " << registros[estudianteSeleccionado][semestre - 1].nota[notaSeleccionada - 1] << endl;
        cout << "Ingrese la nueva nota: ";
        cin >> notaNueva;
        if (notaSeleccionada == 1 || notaSeleccionada == 2 && notaNueva > 20) {
            system("cls");
            cout << "Nota no valida. Debe ser entre 0 y 20. \n";
            Sleep(1200);
            system("cls");
        }
        else if (notaSeleccionada == 3 || notaSeleccionada == 4 && notaNueva > 30) {
            system("cls");
            cout << "Nota no valida. Debe ser entre 0 y 30. \n";
            Sleep(1200);
        }
        else {
            registros[estudianteSeleccionado][semestre - 1].nota[notaSeleccionada - 1] = notaNueva;
            cout << "Nota actualizada exitosamente.\n";
        }
        break;
    }
    case 2: {
        cout << "Que materia desea cambiar?\n";
        for (int j = 0; j < semestres; j++) {
            cout << j + 1 << ". " << registros[estudianteSeleccionado][j].asignatura << endl;
        }
        cout << "Ingrese el numero de la materia: ";
        cin >> materiaSeleccionada;
        if (materiaSeleccionada < 1 || materiaSeleccionada > semestres) {
            cout << "Materia no valida.\n";
            return;
        }
        cout << "Ingrese la nueva materia: ";
        string nuevaMateria;
        cin.ignore();
        getline(cin, nuevaMateria);
        if (materia_ya_escogida(registros[estudianteSeleccionado], semestres, nuevaMateria)) {
            cout << "La materia ya fue seleccionada. Elija otra.\n";
            return;
        }
        registros[estudianteSeleccionado][materiaSeleccionada - 1].asignatura = nuevaMateria;
        cout << "Materia actualizada exitosamente.\n";
        break;
    }
    case 3: {
        system("cls");
        cout << "Volviendo al menu principal...\n";
        Sleep(1200);
        system("cls");
        return;
    default:
        cout << "Opcion no valida. Intente de nuevo.\n";
    }
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
            registrar_notas();
            cout << "Creando notas a los estudiante aleatoriamente...\n";
            Sleep(2000); // Simula un tiempo de espera para la creación de notas
            cout << "Notas creadas exitosamente.\n";
            cout << "Presione cualquier tecla para continuar...\n";
            _getch();
            system("cls");
			seCreoNotas = true;
            break;
        case 2:
            if (seCreoNotas == true) {
                system("cls");
                mostrar_notas();
                cout << "Presione cualquier tecla para limpiar la pantalla..." << endl;
                _getch();
				system("cls");
            }
            else {
                system("cls");
                cout << "Primero debe generar una nota" << endl;
                Sleep(2000);
                system("cls");
            }
            break;
        case 3:
            editar();
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
