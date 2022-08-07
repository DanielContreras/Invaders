#include "log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace poopy {

std::shared_ptr<spdlog::logger> Logger::core_logger_;

void Logger::init() {
  spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%n] [%^%l%$] %v");
  core_logger_ = spdlog::stdout_color_mt("Core");
  core_logger_->set_level(spdlog::level::debug);
}

} // namespace poopy
