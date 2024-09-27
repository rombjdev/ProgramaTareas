#include <iostream>
#include <string>
#include <vector>

int main(){
    /*
        Sacaremos lo siguiente:
            std::string tareas[MAX_TAREAS];
            const int MAX_TAREAS = 10;
            int totalTareas = 0;        
         para incorporar vectores, lo que nos permitirá trabajar con listas de tamaño dinámico
    */

    std::vector<std::string> tareas;
    std::vector<bool> estadoTareas;

    int opcion = 0;
    

    do
    {
        std::cout << "" << std::endl;;
        std::cout << "Menú de Gestion de Tareas" << std::endl;;
        std::cout << "1. Añadir tarea" << std::endl;;
        std::cout << "2. Ver tareas" << std::endl;
        std::cout << "3. Marcar tarea como completada" << std::endl;
        std::cout << "4. Eliminar tarea completada" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Elige una opcion: "<< std::endl;;
        std::cin >> opcion;
        std::cin.ignore();  // Ignorar el salto de línea que deja std::cin

        switch (opcion)
        {
            case 1:
                {
                    std::string nuevaTarea;
                    std::cout << "" << std::endl;;
                    std::cout << "Introduce la nueva tarea: " << std::endl;
                    std::getline(std::cin, nuevaTarea);
                    tareas.push_back(nuevaTarea);
                    estadoTareas.push_back(false);

                }
                break;
            case 2:
                std::cout << "" << std::endl;
                std::cout << "Lista de tareas:"<< std::endl;
                if(tareas.empty()){
                    std::cout << "" << std::endl;
                    std::cout << "No hay tareas en la lista" << std::endl;
                }else{
                    for(int i = 0; i < tareas.size(); i++){
                        std::cout << "." << tareas[i] << (estadoTareas[i] ? " (Completada)" : " (Pendiente)") <<  std::endl;
                    }
                }
                break;
            case 3:
                if(tareas.empty()){
                    std::cout << "" << std::endl;
                    std::cout << "No hay tareas, para añadir una seleccione la opción 1." << std::endl;        
                }else{
                    int tareaCompletada;
                    std::cout << "" << std::endl;
                    std::cout << "Introduce el numero de la tarea completada." << std::endl;
                    std::cin >> tareaCompletada;

                    if(tareaCompletada >= 1 && tareaCompletada <= tareas.size()){
                        std::string tarea = tareas[tareaCompletada-1];
                        estadoTareas[tareaCompletada-1] = true;

                        //std::string tarea = tareas[tareaCompletada-1];
                        // for(int i = tareaCompletada-1; i < tareas.size()-1; i++){
                            
                        //     tareas.erase(tareas.begin() + (tareaCompletada-1));
                        // }
                        std::cout << "" << std::endl;
                        std::cout << "Tarea '" << tarea << "' marcada como completada" << std::endl;
                    }else {
                        std::cout << "" << std::endl;
                        std::cout << "Numero de la tarea es invalido." << std::endl;
                    }
                       
                }
                break;
            case 4:
                if(tareas.empty()){
                    std::cout << "" << std::endl;
                    std::cout << "No hay tareas, para añadir una seleccione la opción 1." << std::endl;        
                }else{
                    int tareaCompletada;
                    std::cout << "" << std::endl;
                    std::cout << "Introduce el numero de la tarea que quieres eliminar." << std::endl;
                    std::cin >> tareaCompletada;

                    if(tareaCompletada >= 1 && tareaCompletada <= tareas.size()){
                        std::string tarea = tareas[tareaCompletada-1];
                        estadoTareas[tareaCompletada-1] = true;

                        if(estadoTareas[tareaCompletada-1] == true){
                            tareas.erase(tareas.begin() + (tareaCompletada-1));
                            estadoTareas.erase(estadoTareas.begin() + (tareaCompletada-1));
                        }else{
                            std::cout << "" << std::endl;
                            std::cout << "la tarea '" << tarea << "' no está marcada como completada" << std::endl;                        
                        }

                        //std::string tarea = tareas[tareaCompletada-1];
                        // for(int i = tareaCompletada-1; i < tareas.size()-1; i++){
                            
                        //     tareas.erase(tareas.begin() + (tareaCompletada-1));
                        // }
                        std::cout << "" << std::endl;
                        std::cout << "Tarea '" << tarea << "' marcada como completada" << std::endl;
                    }else {
                        std::cout << "" << std::endl;
                        std::cout << "Numero de la tarea es invalido." << std::endl;
                    }
                       
                }
                break;

            case 5:
                std::cout << "" << std::endl;
                std::cout << "Saliendo del programa..." << std::endl;
                break;    

            default:      
                std::cout << "" << std::endl;
               std::cout << "Opción invalida, intenta de nuevo." << std::endl;       
                break;
        }



    } while (opcion != 5);
    



    return 0;

}