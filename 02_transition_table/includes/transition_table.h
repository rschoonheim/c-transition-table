#ifndef TRANSITION_TABLE_TRANSITION_TABLE_H
#define TRANSITION_TABLE_TRANSITION_TABLE_H

#include <stddef.h>


/**
 * @brief Definieert een transition van een state machine.
 */
typedef struct Transition_t {
    int current_state;
    int event;
    int next_state;
    void (*action)(void);
} Transition;

/**
 * @brief Collectie van alle mogelijke transitions in de state machine.
 */
typedef struct TransitionTable_t {
    const Transition* transitions;
    size_t size;
} TransitionTable;

/**
 * @brief Maak een nieuwe Transition aan.
 *
 * @param {int} current_state - De huidige state van de transition.
 * @param {int} event - De gebeurtenis die de transition activeert.
 * @param {int} next_state - De volgende state na de transition.
 * @param {void (*action)(void)} - Pointer naar de actie functie die uitgevoerd wordt tijdens de transition.
 *
 * @return {Transition*} - Pointer naar de aangemaakte Transition.
 */
Transition * transition_create(int current_state, int event, int next_state, void (*action)(void));

/**
 * @brief Maak een nieuwe TransitionTable aan.
 *
 * @param {const Transition*} transitions - Array van transitions.
 * @param {size_t} size - Aantal transitions in de array.
 *
 * @return {TransitionTable*} - Pointer naar de aangemaakte TransitionTable.
 */
TransitionTable * transition_table_create(const Transition* transitions, size_t size);

/**
 * @brief Een transition toevoegen aan de TransitionTable.
 *
 * @param {TransitionTable*} table - Pointer naar de TransitionTable.
 * @param {Transition*} transition - Pointer naar de toe te voegen Transition.
 */
void transition_table_add_transition(TransitionTable* table, Transition* transition);

#endif //TRANSITION_TABLE_TRANSITION_TABLE_H