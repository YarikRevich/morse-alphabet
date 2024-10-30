#include "systemc"

#include "../../src/internal/core/executor/executor.hpp"
#include "../../src/internal/core/scheduler/scheduler.hpp"
#include "../../src/internal/core/pipeline/pipeline.hpp"
#include "../../src/internal/logger/logger.hpp"
#include "./helper/helper.hpp"

using namespace sc_core;

void init() {
  Logger::init();
}

int sc_main(int, char*[]) {
  init();

  Pipeline* pipeline = new Pipeline(PIPELINE_BATCH_SIZE);

	Watcher* watcher = new Watcher();

	sc_clock clk("clock", 10, SC_NS, 0.1);

  Scheduler scheduler(SCHEDULER_MODULE_NAME, pipeline, watcher, &clk);
  Executor executor(EXECUTOR_MODULE_NAME, pipeline, watcher);
	Helper helper(HELPER_MODULE_NAME, &clk);

	helper.start_button(scheduler.start_button);
	helper.stop_button(scheduler.stop_button);
	helper.convert_button(scheduler.convert_button);
	helper.input(scheduler.input);
	helper.output(executor.output);

	sc_start();

  return 0;
}
