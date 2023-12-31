Summatieve opdracht 3: Dijkstra Shortest Path & Datastructuren

11-06-2023

Jari Wezer

Ik heb een POC (proof of concept/piece of crap) geimplementeerd op basis van de bijgevoegde graph png:
![Graph](/docs/Graph.png)

Node 1 = Amsterdam,
Node 2 = Den Haag,
Node 3 = Brussel,
Node 4 = Antwerpen,
Node 5 = Parijs.
De kortste route moet worden bepaald op basis van afstand/tijd/kosten. Ik heb de deze op basis van google maps en fantasie bedacht.


Voor deze opdracht heb ik 4 verschillende classes gemaakt:

[Location class](/src/Location.cpp):
Dit is een soort placeholder voor toekomstige locaties (stel je wilt het verbinden met een API). 
Momenteel houdt dit alleen een plaatsnaam vast.

[Trip class](/src/Trip.cpp):
De Trip class is vergelijkbaar met de Step class in de opdracht.
Een Trip heeft een begin locatie (een pointer naar een Location), eind locatie, afstand in km's, tijd in minuten, kosten in dollars. Ik heb deze drie variabelen willekeurig gekozen omdat er bewezen moet worden dat het kortste pad met verschillende eisen kan worden gevonden.
Ook zit er een "mode of transport" op. Deze wilde ik ook nog implementeren, zodat een gebruiker een transport preferentie kan instellen, maar dit heb ik uiteindelijk niet gedaan.

[Node class](/src/Node.cpp):
De Node class heeft een Locatie aan zich verbonden. Op basis van deze locatie kunnen er via de Graph class instanties van Trips worden gekoppeld aan de Node.
Stel je hebt een trip van amsterdam naar den haag, dan wordt deze aan de amsterdam Node toegevoegd.
Er kunnen meerdere trips naar dezelfde locatie bestaan. Daarom is het nodig om te kunnen sorteren.
Als er op tijd gesorteerd moet worden, wordt voor elke neighbour Node de trip gekozen met de kortste tijd. Hiermee kunnen verschillende transport methoden worden gekoppeld aan een reis.

[Graph class](/src/Graph.cpp):
De Graph class heeft als belangrijkste functie de getShortestPath. Hieraan kan een start node, eind node en een conditie mee worden gegeven.
De conditie bepaalt wat de gebruiker het liefst heeft: een korte reis, een goedkope reis of een snelle reis. 
Alle Nodes dienen toegevoegd te worden aan de graph, en daarna kunnen de trips verbonden worden. Momenteel is dat allemaal hard gecodeerd, omdat ik ervanuit ging dat dit niet het belangrijkste onderdeel was van de opdracht.
Ik heb unordered maps gebruikt om afstanden (km/tijd/prijs) aan de Nodes te verbinden, en Nodes aan andere Nodes te verbinden als previous nodes.
Alle Nodes worden geinstantieerd tot eindeloos ver, behalve de start node. Daarna gaan we de onbezochte nodes een voor een langs op basis van welke de kleinste afstand heeft.
Voor alle sorteer functies heb ik lambda functies gebruikt die kortbondig kunnen sorteren m.b.v. algorithm en functional includes.
De "edges" worden op de spot berekend, en alle nodes worden langs gegaan tot de kortste route is berekend. Daarna wordt deze geprint naar de console.

Tot slot wordt alles geprint. Druk op enter om de applicatie te sluiten.
