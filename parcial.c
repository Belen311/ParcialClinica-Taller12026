#include "funciones.h" // Incluimos nuestro archivo de cabecera con las estructuras y funciones de carga

// Prototipo para la función que liberará la memoria de los arreglos iniciales.
// Es buena práctica hacerlo aunque luego los datos se muevan a una lista.

typedef struct NodoPaciente{
    Paciente datos;
    struct NodoPaciente *Siguiente;
}NodoPaciente;

NodoPaciente *ListaVacia();

NodoPaciente *CrearNodo(Paciente datos[], int indice, int id);

void insertarInicio(NodoPaciente **Start, NodoPaciente *NuevoNodo);

void insertarFinal(NodoPaciente *Start, NodoPaciente *NuevoNodo);

void mostrarLista(NodoPaciente *Start);

void removerGeriatricos(NodoPaciente **start, int edad);

void derivacionCasosCriticos(NodoPaciente **start, int nivel);

void liberarMemoriaArreglos(Paciente arr[], int tam);

void liberarMemoriaNodo(NodoPaciente **start);

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
    int id = 10000;
    NodoPaciente *pNuevo = NULL;
    NodoPaciente *ListaClinica;
    ListaClinica = ListaVacia();
    for (int i = 0; i < tamEmergencia; i++)
    {
        pNuevo = CrearNodo(ingresosEmergencia, i, id);
        if (ListaClinica)
        {
            insertarFinal(ListaClinica, pNuevo);
        } else {
            insertarInicio(&ListaClinica, pNuevo);
        }
        
        id++;
    }

    for (int i = 0; i < tamConsultorios; i++)
    {
        pNuevo = CrearNodo(ingresosConsultorios, i, id);
        insertarFinal(ListaClinica, pNuevo);
        id++;
    }

    for (int i = 0; i < tamCirugia; i++)
    {
        pNuevo = CrearNodo(ingresosCirugia, i, id);
        insertarFinal(ListaClinica, pNuevo);
        id++;
    }

    int edad;
    printf("Ingrese una edad para remover de la lista: ");
    scanf("%d", &edad);

    removerGeriatricos(&ListaClinica, edad);

    int nivel;
    printf("Ingrese el nivel critico para remover de la lista: ");
    scanf("%d", &nivel);

    derivacionCasosCriticos(&ListaClinica, nivel);
    
    mostrarLista(ListaClinica);


    // --- Liberación de Memoria de los Arreglos Originales ---
    // Una vez que los datos se copian a la lista enlazada, la memoria
    // dinámica de los arreglos originales debe ser liberada.
    
    
    printf("\nMemoria de los arreglos iniciales liberada correctamente.\n");

    liberarMemoriaNodo(&ListaClinica);

    liberarMemoriaArreglos(ingresosCirugia, tamCirugia);

    liberarMemoriaArreglos(ingresosConsultorios, tamConsultorios);

    liberarMemoriaArreglos(ingresosEmergencia, tamEmergencia);


    return 0;
}

NodoPaciente *ListaVacia(){
    return NULL;
}

NodoPaciente *CrearNodo(Paciente datos[], int indice, int id){
    NodoPaciente *pAux = (NodoPaciente*)malloc(sizeof(NodoPaciente));

    pAux->datos.id_historia_clinica = id;
    //pAux->datos.nombre_apellido = (char*)malloc(strlen(datos[indice].nombre_apellido) + 1);
    strcpy(pAux->datos.nombre_apellido, datos[indice].nombre_apellido);
    pAux->datos.especialidad = (char*)malloc(strlen(datos[indice].especialidad) + 1);
    strcpy(pAux->datos.especialidad, datos[indice].especialidad);
    //pAux->datos.especialidad = datos[indice].especialidad;
    pAux->datos.edad = datos[indice].edad;
    pAux->datos.nivel_criticidad = datos[indice].nivel_criticidad;
    pAux->Siguiente = NULL;

    return pAux;
}

void insertarInicio(NodoPaciente **Start, NodoPaciente *NuevoNodo){
    NuevoNodo->Siguiente = *Start;
    *Start = NuevoNodo;
}

void insertarFinal(NodoPaciente *Start, NodoPaciente *NuevoNodo){
    NodoPaciente *pAux = Start;
    while (pAux->Siguiente)
    {
        pAux = pAux->Siguiente;
    }
    pAux->Siguiente = NuevoNodo;
}

void mostrarLista(NodoPaciente *Start){
    NodoPaciente *pAux = Start;
    while (pAux)
    {
        printf("| Id: %3d | Nombre: %-20s | Especialidad: %-15s | Edad: %3d | Criticidad: %2d\n", pAux->datos.id_historia_clinica,pAux->datos.nombre_apellido, pAux->datos.especialidad, pAux->datos.edad, pAux->datos.nivel_criticidad);
        pAux = pAux->Siguiente;
    }
}

void removerGeriatricos(NodoPaciente **start, int edad){
    NodoPaciente *pAux = *start, *pAnt, *NodoEncontrado;
    while (pAux)
    {
        if (pAux->datos.edad > edad)
        {
            NodoEncontrado = pAux;
            if (pAux == *start)
            {
                *start = pAux->Siguiente;
                pAux = *start;
            } else {
                pAnt->Siguiente = pAux->Siguiente;
                pAux = pAux->Siguiente;
            }
            NodoEncontrado->Siguiente = NULL;
            free(NodoEncontrado->datos.especialidad);
            free(NodoEncontrado);
        } else {
            pAnt = pAux;
            pAux= pAux->Siguiente;
        }
        
    }
    
}

void derivacionCasosCriticos(NodoPaciente **start, int nivel){
    NodoPaciente *pAux = *start, *pAnt, *NodoEncontrado;
    while (pAux)
    {
        if (pAux->datos.nivel_criticidad >= nivel)
        {
            NodoEncontrado = pAux;
            if (pAux == *start)
            {
                *start = pAux->Siguiente;
                pAux = *start;
            } else {
                pAnt->Siguiente = pAux->Siguiente;
                pAux = pAux->Siguiente;
            }
            NodoEncontrado->Siguiente = NULL;
            free(NodoEncontrado->datos.especialidad);
            free(NodoEncontrado);
        } else {
            pAnt = pAux;
            pAux= pAux->Siguiente;
        }
        
    }
    
}

void liberarMemoriaArreglos(Paciente arr[], int tam){
    for (int i = 0; i < tam; i++)
    {
        free(arr[i].especialidad);
    }
}

void liberarMemoriaNodo(NodoPaciente **start){
    NodoPaciente *pAux = *start, *pSiguiente = NULL;
    while (pAux)
    {
        pSiguiente = pAux->Siguiente;
        if (pAux->datos.especialidad)
        {
            free(pAux->datos.especialidad);
        }
        free(pAux);
        pAux = pSiguiente;
    }
    *start = NULL;
}

//int id_historia_clinica;    // Se asignará al crear la lista
//    char nombre_apellido[60];
//    char* especialidad;         // Puntero para gestionar memoria dinámica
//    int edad;                   
//    int nivel_criticidad;
