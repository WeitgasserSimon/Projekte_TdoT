#include <stdio.h>
#include <stdlib.h>

#define MAX_PATIENTS 100

// Die Patienten werden durch eine Struktur definiert, die ihre Ankunfts- und Abfahrtszeiten speichert.
typedef struct {
    int arrival_time;    // Ankunftszeit des Patienten
    int departure_time;  // Abfahrtszeit des Patienten
} Patient;

// Eine Warteschlange (Queue) wird erstellt, um die Patienten zu verwalten.
typedef struct {
    Patient data[MAX_PATIENTS];  // Daten-Array zur Speicherung der Patienten
    int front, rear;            // Vorderes und hinteres Ende der Warteschlange
} Queue;

// Funktion zum Hinzufügen eines Patienten zur Warteschlange (enqueue)
void enqueue(Queue *queue, Patient patient) {
    if (queue->rear == MAX_PATIENTS - 1) {
        printf("Die Warteschlange ist voll.\n");
        return;
    }
    queue->rear++;
    queue->data[queue->rear] = patient;
}

// Funktion zum Entfernen eines Patienten aus der Warteschlange (dequeue)
Patient dequeue(Queue *queue) {
    if (queue->front > queue->rear) {
        printf("Die Warteschlange ist leer.\n");
        Patient empty_patient = {0, 0};
        return empty_patient;
    }
    return queue->data[queue->front++];
}

int main() {
    Queue waiting_room = {0};  // Eine Warteschlange für das Wartezimmer erstellen
    int total_waiting_time = 0;  // Gesamte Wartezeit initialisieren
    int num_patients = 0;  // Anzahl der Patienten initialisieren

    // Fügen Sie hier Patienten mit Ankunfts- und Abfahrtszeiten hinzu
    // Beispiel-Patienten hinzufügen:
    Patient patient1 = {0, 10};
    Patient patient2 = {5, 15};
    Patient patient3 = {12, 20};

    // Die Patienten zur Warteschlange hinzufügen
    enqueue(&waiting_room, patient1);
    enqueue(&waiting_room, patient2);
    enqueue(&waiting_room, patient3);

    num_patients = 3;  // Die Anzahl der Patienten auf 3 setzen

    // Die Wartezeiten der Patienten berechnen
    while (num_patients > 0) {
        Patient current_patient = dequeue(&waiting_room);
        total_waiting_time += current_patient.departure_time - current_patient.arrival_time;
        num_patients--;
    }

    // Die durchschnittliche Wartezeit berechnen und ausgeben
    float average_waiting_time = (float)total_waiting_time / 3;  // Durchschnittliche Wartezeit berechnen
    printf("Durchschnittliche Wartezeit: %.2f\n", average_waiting_time);

    return 0;
}
