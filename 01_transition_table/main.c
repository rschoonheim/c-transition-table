#include <stdio.h>
#include "transition_table.h"

// Implementeer de action functies
void on_start(void) {
    printf("Action: Starting...\n");
}

void on_stop(void) {
    printf("Action: Stopping...\n");
}

void on_reset(void) {
    printf("Action: Resetting...\n");
}

// Functie om een transition te vinden en uit te voeren
int process_event(int *current_state, int event) {
    for (size_t i = 0; i < transitions_size; i++) {
        if (transitions[i].current_state == *current_state &&
            transitions[i].event == event) {
            printf("State transition: %d -> %d\n",
                   *current_state, transitions[i].next_state);

            if (transitions[i].action != NULL) {
                transitions[i].action();
            }

            *current_state = transitions[i].next_state;
            return 1;
            }
    }

    printf("No transition found for state %d and event %d\n",
           *current_state, event);
    return 0;
}


int main(void) {
    int current_state = STATE_IDLE;

    printf("Initial state: %d\n\n", current_state);

    // Test de transitions
    process_event(&current_state, EVENT_START);
    printf("Current state: %d\n\n", current_state);

    process_event(&current_state, EVENT_STOP);
    printf("Current state: %d\n\n", current_state);

    process_event(&current_state, EVENT_RESET);
    printf("Current state: %d\n\n", current_state);

    // Test een ongeldige transition
    process_event(&current_state, EVENT_STOP);

    return 0;
}
