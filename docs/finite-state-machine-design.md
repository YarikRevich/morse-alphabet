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
recordinput --> convertinput: Input data to be converted is provided
convertinput --> recordinput: Back to record input to receive new data to be converted
convertinput --> awaitinput: "Stop record" button is pressed
```