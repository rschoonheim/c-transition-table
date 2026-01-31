#include "../includes/transition_table.h"

#include <stdlib.h>

Transition * transition_create(int current_state, int event, int next_state, void (*action)(void)) {
    Transition *new_transition = (Transition *)malloc(sizeof(Transition));
    if (new_transition == NULL) {
        return NULL; // Fout bij geheugenallocatie
    }
    new_transition->current_state = current_state;
    new_transition->event = event;
    new_transition->next_state = next_state;
    new_transition->action = action;
    return new_transition;
}

TransitionTable * transition_table_create(const Transition* transitions, size_t size) {
    TransitionTable *new_table = (TransitionTable *)malloc(sizeof(TransitionTable));
    if (new_table == NULL) {
        return NULL; // Fout bij geheugenallocatie
    }
    new_table->transitions = transitions;
    new_table->size = size;
    return new_table;
}

void transition_table_add_transition(TransitionTable* table, Transition* transition) {
    // Maak een nieuwe array met ruimte voor de extra transition
    //
    Transition* new_transitions = (Transition *)malloc((table->size + 1) * sizeof(Transition));
    if (new_transitions == NULL) {
        return; // Fout bij geheugenallocatie
    }

    // Kopieer bestaande transitions naar de nieuwe array
    //
    for (size_t i = 0; i < table->size; i++) {
        new_transitions[i] = table->transitions[i];
    }

    // Voeg de nieuwe transition toe aan het einde van de
    // nieuwe array
    //
    new_transitions[table->size] = *transition;

    // Maak het geheugen vrij van de oude array.
    //
    free((void *)table->transitions);

    // Plaats de nieuwe array in de tabel en update de grootte.
    //
    table->transitions = new_transitions;
    table->size += 1;
}