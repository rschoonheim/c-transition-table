#include <stdio.h>

#include "includes/transition_table.h"

void print_transitions(TransitionTable * table) {
    for (size_t i = 0; i < table->size; i++) {
        printf(
            "Transition %zu: %d --(%d)--> %d\n", i,
            table->transitions[i].current_state,
            table->transitions[i].event,
            table->transitions[i].next_state
        );
    }
}

// Actie transition 0
void handle_event_1_on_state_0(void) {
    printf("Action: Handling event 1 on state 0\n");
}

// Actie transition 1
void handle_event_0_on_state_2(void) {
    printf("Action: Handling event 0 on state 2\n");
}

int process_event(TransitionTable * table, int *current_state, int event) {
    // Zoek naar een geldige transition
    for (size_t i = 0; i < 2; i++) {
        if (table->transitions[i].current_state == *current_state &&
            table->transitions[i].event == event) {
            printf("State transition: %d -> %d\n",
                   *current_state, table->transitions[i].next_state);

            // Voer de actie uit als die bestaat
            if (table->transitions[i].action != NULL) {
                table->transitions[i].action();
            }

            // Update de huidige state
            *current_state = table->transitions[i].next_state;
            return 1;
        }
    }

    printf("No transition found for state %d and event %d\n",
           *current_state, event);
    return 0;
}

int main() {
    Transition *transitions = transition_create(0, 1, 2, handle_event_1_on_state_0);
    TransitionTable *table = transition_table_create(transitions, 1);

    printf("Initial transitions:\n");
    print_transitions(table);

    // Voeg extra transition toe aan de table.
    Transition *extra_transition = transition_create(2, 0, 1, handle_event_0_on_state_2);
    transition_table_add_transition(table, extra_transition);

    printf("\nAfter adding extra transition:\n");
    print_transitions(table);


    printf("\nProcessing events:\n");
    int current_state = 0;
    process_event(table, &current_state, 1);
    process_event(table, &current_state, 0);

    return 0;
}
