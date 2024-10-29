#include "watcher.hpp"

Watcher::Watcher() {
    this->conversion_trigger = new sc_event();
    this->conversion_guard = new sc_semaphore(1);
}

sc_event* Watcher::get_conversion_trigger() {
    return conversion_trigger;
}

sc_semaphore* Watcher::get_conversion_guard() {
    return conversion_guard;
}