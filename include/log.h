#ifndef LOG_H_
#define LOG_H_

#include <memory.h>
#include <spdlog/spdlog.h>

namespace poopy {

class Logger {
public:
  static void init();
  inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return core_logger_; }

private:
  static std::shared_ptr<spdlog::logger> core_logger_;
};

} // namespace poopy

#define CORE_TRACE(...)    ::poopy::Logger::get_core_logger()->trace(__VA_ARGS__)
#define CORE_INFO(...)     ::poopy::Logger::get_core_logger()->info(__VA_ARGS__)
#define CORE_DEBUG(...)    ::poopy::Logger::get_core_logger()->debug(__VA_ARGS__)
#define CORE_WARN(...)     ::poopy::Logger::get_core_logger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)    ::poopy::Logger::get_core_logger()->error(__VA_ARGS__)
#define CORE_CRITICAL(...) ::poopy::Logger::get_core_logger()->critical(__VA_ARGS__)

#endif // LOG_H_
