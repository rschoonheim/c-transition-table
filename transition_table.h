#ifndef TRANSITION_TABLE_TRANSITION_TABLE_H
#define TRANSITION_TABLE_TRANSITION_TABLE_H

// Definieer de states
#define STATE_IDLE    0
#define STATE_RUNNING 1
#define STATE_STOPPED 2

// Definieer de events
#define EVENT_START 0
#define EVENT_STOP  1
#define EVENT_RESET 2

// Transition structure
typedef struct {
    int current_state;
    int event;
    int next_state;
    void (*action)(void);
} Transition;

// Forward declaraties van action functies
void on_start(void);
void on_stop(void);
void on_reset(void);

// Macro om een transition entry te definiëren
#define TRANSITION(current_state, event, next_state, action) \
{current_state, event, next_state, action}

// Macro om de transition table te definiëren
#define TRANSITION_TABLE \
TRANSITION(STATE_IDLE,    EVENT_START, STATE_RUNNING, on_start),   \
TRANSITION(STATE_RUNNING, EVENT_STOP,  STATE_STOPPED, on_stop),    \
TRANSITION(STATE_STOPPED, EVENT_RESET, STATE_IDLE,    on_reset)

// Declareer de table met extern
extern const Transition transitions[];
extern const size_t transitions_size;

#endif //TRANSITION_TABLE_TRANSITION_TABLE_H
