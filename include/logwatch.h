#pragma once

#include <stddef.h>

// Log levels
typedef enum {
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_INFO,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_ERROR
} LogLevel;

typedef struct Logwatch Logwatch;

// Logwatchs
Logwatch *logwatch_create_file(const char *filename, LogLevel level,
                               size_t max_size, int rotations);
Logwatch *logwatch_create_console(LogLevel level);

// API
void logwatch_destroy(Logwatch *logwatch);
void Logwatch_log(Logwatch *logwatch, LogLevel level, const char *format, ...);

// Macros
#define LOGWATCH_DEBUG(logwatch, ...)                                          \
  Logwatch_log(logwatch, LOG_LEVEL_DEBUG, __VA_ARGS__)
#define LOGWATCH_INFO(logwatch, ...)                                           \
  Logwatch_log(logwatch, LOG_LEVEL_INFO, __VA_ARGS__)
#define LOGWATCH_WARNING(logwatch, ...)                                        \
  Logwatch_log(logwatch, LOG_LEVEL_WARNING, __VA_ARGS__)
#define LOGWATCH_ERROR(logwatch, ...)                                          \
  Logwatch_log(logwatch, LOG_LEVEL_ERROR, __VA_ARGS__)
