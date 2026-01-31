#include <stddef.h>
#include "transition_table.h"

// Definieer de table
const Transition transitions[] = {
    TRANSITION_TABLE
};

const size_t transitions_size = sizeof(transitions) / sizeof(transitions[0]);
