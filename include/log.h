#ifndef LOG_H_
#define LOG_H_

#include <memory.h>
#include <spdlog/spdlog.h>

namespace Poopy {

class Logger {
 public:
  static void Init();
  inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return core_logger_; }

 private:
  static std::shared_ptr<spdlog::logger> core_logger_;
};

}  // namespace Poopy

#define CORE_TRACE(...) ::Poopy::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)  ::Poopy::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_DEBUG(...)  ::Poopy::Logger::GetCoreLogger()->debug(__VA_ARGS__)
#define CORE_WARN(...)  ::Poopy::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...) ::Poopy::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...) ::Poopy::Logger::GetCoreLogger()->fatal(__VA_ARGS__)

#endif  // LOG_H_
