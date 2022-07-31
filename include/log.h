#ifndef LOG_H_
#define LOG_H_

#include <memory.h>
#include <spdlog/spdlog.h>

namespace poopy {

class Logger {
 public:
  static void Init();
  inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return core_logger_; }

 private:
  static std::shared_ptr<spdlog::logger> core_logger_;
};

}  // namespace poopy

#define CORE_TRACE(...)    ::poopy::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)     ::poopy::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_DEBUG(...)    ::poopy::Logger::GetCoreLogger()->debug(__VA_ARGS__)
#define CORE_WARN(...)     ::poopy::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)    ::poopy::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_CRITICAL(...) ::poopy::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#endif  // LOG_H_
