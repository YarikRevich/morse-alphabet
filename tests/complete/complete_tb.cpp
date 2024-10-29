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

  Scheduler scheduler("scheduler", pipeline);
  Executor executor("executor", pipeline);

	scheduler.start_button = -1;
	scheduler.stop_button = -1;
	scheduler.input = -1;

  sc_start(1000, SC_SEC);

  return 0;
}
