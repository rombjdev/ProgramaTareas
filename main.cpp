#include <iostream>
#include <string>

int main(){

    const int MAX_TAREAS = 10;
    int totalTareas = 0;
    int opcion = 0;
    std::string tareas[MAX_TAREAS];

    do
    {
        std::cout << "" << std::endl;;
        std::cout << "Menú de Gestion de Tareas" << std::endl;;
        std::cout << "1. Añadir tarea" << std::endl;;
        std::cout << "2. Ver tareas" << std::endl;
        std::cout << "3. Marcar tarea como completada" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Elige una opcion: "<< std::endl;;
        std::cin >> opcion;
        std::cin.ignore();  // Ignorar el salto de línea que deja std::cin

        switch (opcion)
        {
            case 1:
                if(totalTareas < MAX_TAREAS){
                    std::cout << "" << std::endl;;
                    std::cout << "Introduce la nueva tarea: " << std::endl;
                    std::getline(std::cin, tareas[totalTareas]);
                    totalTareas++ ;
                }else{
                    std::cout << "" << std::endl;;
                    std::cout << "Has alcanzado el máximo de tareas permitido."<< std::endl;
                }
                break;
            case 2:
                std::cout << "" << std::endl;
                std::cout << "Lista de tareas:"<< std::endl;
                if(totalTareas == 0){
                    std::cout << "" << std::endl;
                    std::cout << "No hay tareas en la lista" << std::endl;
                }else{
                    for(int i = 0; i < totalTareas; i++){
                        std::cout << "." << tareas[i] << std::endl;
                    }
                }
                break;
            case 3:
                if(totalTareas == 0){
                    std::cout << "" << std::endl;
                    std::cout << "No hay tareas, para añadir una seleccione la opción 1." << std::endl;        
                }else{
                    int tareaCompletada;
                    std::cout << "" << std::endl;
                    std::cout << "Introduce el numero de la tarea completada." << std::endl;
                    std::cin >> tareaCompletada;

                    if(tareaCompletada >= 1 && tareaCompletada <=totalTareas){
                        std::string tarea = tareas[tareaCompletada-1];
                        for(int i = tareaCompletada-1; i < totalTareas-1; i++){
                            tareas[i] = tareas[i + 1];
                        }
                        totalTareas--;
                        std::cout << "" << std::endl;
                        std::cout << "Tarea '" << tarea << "' completada y eliminada" << std::endl;
                    }else {
                        std::cout << "" << std::endl;
                        std::cout << "Numero de la tarea es invalido." << std::endl;
                    }
                       
                }
                break;
            case 4:
                std::cout << "" << std::endl;
                std::cout << "Saliendo del programa..." << std::endl;
                break;    

            default:      
                std::cout << "" << std::endl;
               std::cout << "Opción invalida, intenta de nuevo." << std::endl;       
                break;
        }



    } while (opcion != 4);
    



    return 0;

}