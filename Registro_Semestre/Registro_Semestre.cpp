#include <iostream>
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


int main()
{
    std::cout << "Hello World!\n";
}
