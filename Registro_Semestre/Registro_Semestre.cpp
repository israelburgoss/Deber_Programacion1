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
    int opcion_editar;
    do {
        system("cls");
        cout << "Editar registro del estudiante \n";
        cout << "Nombre del estudiante: " << alumnos[estudianteSeleccionado] << endl;
        cout << "Que desea modificar? \n";
        cout << "1. Modificar notas \n";
        cout << "2. Modificar materias \n";
        cout << "3. Volver al menu principal \n";
        cout << "Ingrese la opcion que desea: ";
        cin >> opcion_editar;
        

        // Declarar materiaValida aquí, antes del switch
        bool materiaValida = false;

        switch (opcion_editar) {
        case 1: {
            int semestre, notaSeleccionada, notaNueva;

            // Validar semestre
            do {
                system("cls");
                cout << "Ingrese el semestre que desea modificar (1-" << semestres << "): ";
                cin >> semestre;

                if (semestre < 1 || semestre > semestres) {
                    cout << "Semestre no valido. Intente de nuevo.\n";
                    Sleep(1200);
					system("cls");
                    continue;
                }
            } while (semestre < 1 || semestre > semestres);

            // Validar nota a modificar
            do {
                cout << "Cual de las 4 notas desea cambiar? (1-4): ";
                cin >> notaSeleccionada;

                if (notaSeleccionada < 1 || notaSeleccionada > 4) {
                    cout << "Nota no valida.\n";
                    Sleep(1200);
					system("cls");
                    continue;
                }
            } while (notaSeleccionada < 1 || notaSeleccionada > 4);

            // Pedir nueva nota hasta que esté en rango correcto
            bool notaValida = false;
            do {
                cout << "Nota actual: "
                    << registros[estudianteSeleccionado][semestre - 1].nota[notaSeleccionada - 1] << endl;

                cout << "Ingrese la nueva nota: ";
                cin >> notaNueva;

                if ((notaSeleccionada <= 2 && (notaNueva < 0 || notaNueva > 20)) ||
                    (notaSeleccionada >= 3 && (notaNueva < 0 || notaNueva > 30))) {
                    cout << "Nota no valida. Rango incorrecto.\n";
					system("cls");
                    Sleep(1200);
                    continue;
                }
                else {
                    notaValida = true;
                }

            } while (!notaValida);

            registros[estudianteSeleccionado][semestre - 1].nota[notaSeleccionada - 1] = notaNueva;
            cout << "Nota actualizada exitosamente.\n";
            Sleep(1200);
			system("cls");
            break;
        }
        case 2: {
            int semestreSeleccionado, nuevaMateria;
            do {
                system("cls");
                cout << "Seleccione el semestre (1-" << semestres << "): ";
                cin >> semestreSeleccionado;

                if (semestreSeleccionado < 1 || semestreSeleccionado > semestres) {
                    cout << "Semestre no valido. Intente de nuevo.\n";
                    Sleep(1200);
					system("cls");
                }
            } while (semestreSeleccionado < 1 || semestreSeleccionado > semestres);

            materiaValida = false; // Usar la variable declarada arriba
            do {
                cout << "Semestre " << semestreSeleccionado
                    << ", Materia actual: "
                    << registros[estudianteSeleccionado][semestreSeleccionado - 1].asignatura << endl;

                cout << "Materias Disponibles:\n";
                for (int i = 0; i < 10; i++) {
                    cout << i + 1 << ". " << materias[i] << endl;
                }

                cout << "Ingrese la nueva materia: ";
                cin >> nuevaMateria;

                if (nuevaMateria < 1 || nuevaMateria > 10) {
                    cout << "Materia no valida. Debe ser entre 1 y 10.\n";
                    Sleep(1200);
					system("cls");
                    continue;
                }

                if (materia_ya_escogida(registros[estudianteSeleccionado], semestres, materias[nuevaMateria - 1])) {
                    cout << "La materia ya fue seleccionada. Elija otra.\n";
                    Sleep(1200);
					system("cls");
                    continue;
                }

                registros[estudianteSeleccionado][semestreSeleccionado - 1].asignatura = materias[nuevaMateria - 1];
                cout << "Materia actualizada exitosamente: " << materias[nuevaMateria - 1] << endl;
                cout << "Presione cualquier tecla para continuar...\n";
                _getch();
				system("cls");
                materiaValida = true;
            } while (!materiaValida);
            break;
        }
        case 3: {
            system("cls");
            cout << "Volviendo al menu principal...\n";
            Sleep(1200);
			system("cls");
            return;
        }
        default: {
            system("cls");
            cout << "Opcion no valida. Por favor, intente de nuevo.\n";
            Sleep(1200);
            cout << "Presione cualquier tecla para continuar...\n";
            _getch();
            system("cls");
            continue;
        }
        }
    } while (true);
}
   

void cambiar_estado() {
    int semestreSeleccionado;
    int cambiarEstado;
    bool estadoBool;
    if (estudianteSeleccionado == -1) {
        system("cls");
        cout << "No hay notas registradas. \n";
        Sleep(1200);
        system("cls");
        return;
    }
	estadoBool = false;
    while (!estadoBool) {
		system("cls");
        cout << "Cambiar estado del estudiante: " << registros[estudianteSeleccionado][0].nombre_estudiante << endl;
        cout << "Seleccione el semestre para cambiar el estado (1-" << semestres << "): ";
        cin >> semestreSeleccionado;
        if (semestreSeleccionado < 1 || semestreSeleccionado > semestres) {
            cout << "Semestre no valido. \n";
            Sleep(1200);
            system("cls");
            continue;
        }
        cout << "Semestre Seleccionado: " << semestreSeleccionado << " Materia seleccionada : " << registros[estudianteSeleccionado][semestreSeleccionado - 1].asignatura << endl;
        cout << "Estado actual: " << (registros[estudianteSeleccionado][semestreSeleccionado - 1].activo ? "Activo" : "Inactivo") << endl;
        cout << "Desea cambiar el estado de la materia? (1 para Si, 0 para No): ";
        cin >> cambiarEstado;

        if (cambiarEstado == 1) {
            registros[estudianteSeleccionado][semestreSeleccionado - 1].activo =
                !registros[estudianteSeleccionado][semestreSeleccionado - 1].activo;
            cout << "Estado cambiado exitosamente.\n";
        }
        else {
            cout << "El estado no fue cambiado.\n";
        }

        cout << "Nuevo estado: "
            << (registros[estudianteSeleccionado][semestreSeleccionado - 1].activo ? "Activo" : "Inactivo")
            << endl;

		estadoBool = true; // Marcar como válido para salir del bucle

        cout << "Presione cualquier tecla para continuar...\n";
        _getch();
        system("cls");
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
            cambiar_estado();
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