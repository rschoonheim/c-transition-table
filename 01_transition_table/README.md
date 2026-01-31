# Transition Table met Macro's

Een implementatie van een finite state machine in C met behulp van macro's om een transition table te definiëren.

## Structuur

- `transition_table.h` - Header met state/event definities en transition table macro's
- `transition_table.c` - Implementatie van de transition table
- `main.c` - Voorbeeld gebruik van de state machine

## Hoe werkt het?

De transition table wordt gedefinieerd met macro's:

1. **States en events** worden gedefinieerd als constanten
2. **TRANSITION macro** maakt een entry in de table
3. **TRANSITION_TABLE macro** bevat alle mogelijke transities
4. Een **Transition struct** slaat de transition data op

## Voordelen

- **Overzichtelijk**: Alle transities zijn op één plek gedefinieerd
- **Compact**: Macro's reduceren code duplicatie
- **Makkelijk uit te breiden**: Nieuwe transities toevoegen is simpel
- **Type-safe**: Compiler checks de struct definitie
- **Geen dynamische allocatie**: Alles gebeurt compile-time
- **Snel**: Direct array lookup zonder overhead

## Nadelen

- **Beperkte flexibiliteit**: Alle transities moeten compile-time bekend zijn
- **Moeilijk te debuggen**: Macro's kunnen cryptische foutmeldingen geven
- **Forward declarations nodig**: Action functies moeten vooraf gedeclareerd worden
- **Geen runtime wijzigingen**: Table kan niet tijdens runtime aangepast worden
- **Code bloat**: Bij veel transities wordt de table groot
- **Geen conditie logica**: Guards moeten in action functies geïmplementeerd worden
- **Multiple compilation units**: Vereist aparte `.c` file voor de table definitie

## Voorbeeld
Zie `main.c` voor een voorbeeld van hoe de transition table gebruikt kan worden in een eenvoudige state machine.