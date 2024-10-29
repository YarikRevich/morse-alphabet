```plantuml
title

Finite state machine design of "morse-alphabet"

end title

hide empty description

state "Await input" as awaitinput
state "Record input" as recordinput
state "Convert input" as convertinput

[*] --> awaitinput: Device startup
awaitinput --> awaitinput: "Stop record" button is pressed
awaitinput --> recordinput: "Start record" button is pressed
recordinput --> awaitinput: "Stop record" button is pressed
recordinput --> convertinput: "Convert record" button is pressed
convertinput --> recordinput: When all the provided data is converted
convertinput --> awaitinput: "Stop record" button is pressed
```