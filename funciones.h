
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para un Paciente
typedef struct {
    int id_historia_clinica;    // Se asignará al crear la lista
    char nombre_apellido[60];
    char* especialidad;         // Puntero para gestionar memoria dinámica
    int edad;                   
    int nivel_criticidad;       // de 1 a 10 (10 es más crítico)
} Paciente;

// Estructura para el reporte de ocupación por especialidad
typedef struct {
    int cardiologia;
    int neurologia;
    int traumatologia;
    int general;
} ReporteEspecialidades;

// --- Prototipos de Funciones de Carga Inicial ---

/**
 * @brief Crea una nueva instancia de Paciente con los datos proporcionados.
 * Asigna memoria dinámicamente para el campo 'especialidad'.
 * @param nombre Nombre y apellido del paciente.
 * @param especialidad Área médica a la que corresponde.
 * @param edad Edad del paciente.
 * @param criticidad Nivel de criticidad (1-10).
 * @return Una estructura Paciente inicializada.
 */
Paciente crearPaciente(const char* nombre, const char* especialidad, int edad, int criticidad) {
    Paciente p;
    p.id_historia_clinica = 0; // Se inicializa en 0, se asignará el valor real al crear la lista
    strcpy(p.nombre_apellido, nombre);
    
    // Asignar memoria para la especialidad
    p.especialidad = (char*) malloc(strlen(especialidad) + 1);
    if (p.especialidad != NULL) {
        strcpy(p.especialidad, especialidad);
    }
    
    p.edad = edad;
    p.nivel_criticidad = criticidad;
    return p;
}

/**
 * @brief Carga datos de ejemplo en el arreglo de ingresos por Emergencia.
 */
void cargarIngresosEmergencia(Paciente ingresos[], int tam) {
    if (tam < 8) return;
    ingresos[0] = crearPaciente("Juan Perez", "Cardiologia", 78, 9);
    ingresos[1] = crearPaciente("Ana Gomez", "Traumatologia", 34, 7);
    ingresos[2] = crearPaciente("Luis Fernandez", "Neurologia", 65, 8);
    ingresos[3] = crearPaciente("Maria Lopez", "General", 45, 5);
    ingresos[4] = crearPaciente("Carlos Sanchez", "Cardiologia", 82, 10);
    ingresos[5] = crearPaciente("Laura Martinez", "Traumatologia", 22, 6);
    ingresos[6] = crearPaciente("Pedro Ramirez", "General", 50, 4);
    ingresos[7] = crearPaciente("Sofia Torres", "Neurologia", 71, 7);
}

/**
 * @brief Carga datos de ejemplo en el arreglo de ingresos por Consultorios.
 */
void cargarIngresosConsultorios(Paciente ingresos[], int tam) {
    if (tam < 7) return;
    ingresos[0] = crearPaciente("Marta Diaz", "General", 33, 2);
    ingresos[1] = crearPaciente("Jorge Castro", "Cardiologia", 68, 5);
    ingresos[2] = crearPaciente("Lucia Morales", "Neurologia", 55, 4);
    ingresos[3] = crearPaciente("Ricardo Ortiz", "Traumatologia", 48, 6);
    ingresos[4] = crearPaciente("Valeria Guzman", "General", 29, 1);
    ingresos[5] = crearPaciente("Fernando Rios", "Cardiologia", 75, 6);
    ingresos[6] = crearPaciente("Elena Herrera", "Neurologia", 60, 3);
}

/**
 * @brief Carga datos de ejemplo en el arreglo de ingresos por Cirugía Programada.
 */
void cargarIngresosCirugia(Paciente ingresos[], int tam) {
    if (tam < 6) return;
    ingresos[0] = crearPaciente("Roberto Alvarado", "Traumatologia", 58, 7);
    ingresos[1] = crearPaciente("Silvia Mendoza", "Cardiologia", 72, 8);
    ingresos[2] = crearPaciente("Andres Flores", "General", 41, 4);
    ingresos[3] = crearPaciente("Gabriela Vargas", "Neurologia", 66, 7);
    ingresos[4] = crearPaciente("Esteban Rojas", "Traumatologia", 39, 5);
    ingresos[5] = crearPaciente("Paula Navarro", "General", 53, 3);
}

/**
 * @brief Muestra por pantalla el contenido de un arreglo de pacientes.
 * @param titulo Título para identificar el listado.
 * @param ingresos El arreglo de pacientes.
 * @param cantidad El número de elementos a mostrar.
 */
void mostrarIngresos(const char* titulo, Paciente ingresos[], int cantidad) {
    printf("\n--- Pacientes Ingresados por: %s ---\n", titulo);
    for (int i = 0; i < cantidad; i++) {
        printf("Nombre: %-20s | Especialidad: %-15s | Edad: %3d | Criticidad: %2d\n",
               ingresos[i].nombre_apellido,
               ingresos[i].especialidad,
               ingresos[i].edad,
               ingresos[i].nivel_criticidad);
    }
}

#endif // FUNCIONES_H