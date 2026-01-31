# Dynamische Transition Table

Een implementatie van een finite state machine in C met dynamische allocatie voor runtime flexibiliteit.

## Structuur

- `transition_table.h` - Header met state/event definities en transition table API
- `transition_table.c` - Implementatie van de dynamische transition table
- `main.c` - Voorbeeld gebruik van de state machine

## Hoe werkt het?

De transition table wordt tijdens runtime opgebouwd:

1. **States en events** worden gedefinieerd als constanten
2. **Transition struct** slaat transition data op
3. **Dynamic array** houdt alle transities bij
4. **API functies** voor toevoegen, verwijderen en zoeken van transities

## Voordelen

- **Runtime flexibiliteit**: Transities kunnen tijdens runtime toegevoegd/verwijderd worden
- **Dynamisch**: Table groeit mee met het aantal transities
- **Makkelijk te testen**: Verschillende configuraties mogelijk per test
- **Modulair**: Transities kunnen uit externe bronnen geladen worden
- **Conditie logica**: Guards kunnen eenvoudig toegevoegd worden
- **State hergebruik**: Dezelfde state machine structuur voor verschillende configuraties
- **Memory efficiënt**: Alleen geheugen alloceren wat nodig is

## Nadelen

- **Memory overhead**: Dynamische allocatie brengt overhead met zich mee
- **Runtime fouten**: Allocatie kan falen, error handling nodig
- **Langzamer**: Pointer dereferencing en malloc/free overhead
- **Memory leaks**: Risico op leaks als cleanup niet correct is
- **Complexer**: Meer code nodig voor memory management
- **Fragmentatie**: Kan leiden tot heap fragmentatie
- **Niet deterministic**: Allocatie tijd kan variëren
- **Debug moeilijker**: Memory issues zijn lastiger te traceren

