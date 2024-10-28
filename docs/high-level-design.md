```plantuml
title

High-level design of "morse-alphabet"

end title

cloud "Static environment" {
node "State"
}

component "Control plane" {
node "Scheduler"
node "Pipeline"
node "Executor"
}

component "External environment" {
  node "Device"
}

[Scheduler] <--> [State]: " Create operations according to current state"
[Scheduler] <-> [Pipeline]: " Schedule operations to be executed"
[Pipeline] --> [Executor]: " Execute operations"
[Executor] --> [Device]: " Send output signal"
```