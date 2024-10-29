#include "logger.hpp"

void Logger::init() {
    sc_report_handler::set_log_file_name(LOG_FILE);
    sc_report_handler::set_actions(DEFAULT_LOG_TYPE, SC_INFO, SC_LOG);
}

void Logger::invoke_info(std::string message) {
    SC_REPORT_INFO(DEFAULT_LOG_TYPE, message.c_str());
}

void Logger::invoke_warning(std::string message) {
    SC_REPORT_WARNING(DEFAULT_LOG_TYPE, message.c_str());
}