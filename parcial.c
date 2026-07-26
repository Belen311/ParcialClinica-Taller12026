#include "funciones.h" // Incluimos nuestro archivo de cabecera con las estructuras y funciones de carga

// Prototipo para la función que liberará la memoria de los arreglos iniciales.
// Es buena práctica hacerlo aunque luego los datos se muevan a una lista.
void liberarMemoriaArreglos(Paciente arr[], int tam);



int main() {
    // --- 1. Definición y Carga de los Arreglos Iniciales ---
    printf("Cargando datos iniciales de pacientes...\n");

    // Área de Emergencias
    const int tamEmergencia = 8;
    Paciente ingresosEmergencia[tamEmergencia];
    cargarIngresosEmergencia(ingresosEmergencia, tamEmergencia);

    // Área de Consultorios Externos
    const int tamConsultorios = 7;
    Paciente ingresosConsultorios[tamConsultorios];
    cargarIngresosConsultorios(ingresosConsultorios, tamConsultorios);

    // Área de Cirugías Programadas
    const int tamCirugia = 6;
    Paciente ingresosCirugia[tamCirugia];
    cargarIngresosCirugia(ingresosCirugia, tamCirugia);

    // --- 2. Muestra de los Datos Cargados en los Arreglos ---
    printf("\n=======================================================");
    printf("\n       REGISTROS INICIALES POR AREA DE INGRESO       ");
    printf("\n=======================================================\n");

    mostrarIngresos("Emergencias", ingresosEmergencia, tamEmergencia);
    mostrarIngresos("Consultorios Externos", ingresosConsultorios, tamConsultorios);
    mostrarIngresos("Cirugias Programadas", ingresosCirugia, tamCirugia);
    
    printf("\n\n--- Fin de la carga inicial. A continuacion se procesaran las listas. ---\n");


    // Aquí iría el resto de la lógica del parcial (crear listas, mover nodos, etc.)
    




    // --- Liberación de Memoria de los Arreglos Originales ---
    // Una vez que los datos se copian a la lista enlazada, la memoria
    // dinámica de los arreglos originales debe ser liberada.
    
    
    printf("\nMemoria de los arreglos iniciales liberada correctamente.\n");

    return 0;
}


//int id_historia_clinica;    // Se asignará al crear la lista
//    char nombre_apellido[60];
//    char* especialidad;         // Puntero para gestionar memoria dinámica
//    int edad;                   
//    int nivel_criticidad;
