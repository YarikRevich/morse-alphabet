#include "executor.hpp"

Executor::Executor(sc_module_name name, Pipeline* pipeline) : pipeline{pipeline} {
    SC_THREAD(process);
}

void Executor::process() {

}