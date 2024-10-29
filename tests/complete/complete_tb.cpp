#include "systemc"

#include "../../src/internal/core/executor/executor.hpp"
#include "../../src/internal/core/scheduler/scheduler.hpp"
#include "../../src/internal/core/pipeline/pipeline.hpp"
#include "../../src/internal/logger/logger.hpp"

using namespace sc_core;

void init() {
  Logger::init();
}

int sc_main(int, char*[]) {
  init();

  Pipeline* pipeline = new Pipeline(PIPELINE_BATCH_SIZE);

	Watcher* watcher = new Watcher();

  Scheduler scheduler("scheduler", pipeline, watcher);
  Executor executor("executor", pipeline, watcher);

	scheduler.start_button = 1;
	scheduler.stop_button = 0;
	scheduler.input = 0;

  sc_start(1000, SC_SEC);

  return 0;
}
