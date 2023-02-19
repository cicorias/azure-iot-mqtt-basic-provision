#ifndef AZ_IOT_HELPER_H
#define AZ_IOT_HELPER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//
// Logging
//
#define IOT_SAMPLE_LOG_ERROR(...)                                                  \
  do                                                                               \
  {                                                                                \
    (void)fprintf(stderr, "ERROR:\t\t%s:%d %s(): ", __FILE__, __LINE__, __func__); \
    (void)fprintf(stderr, __VA_ARGS__);                                            \
    (void)fprintf(stderr, "\n");                                                   \
    fflush(stdout);                                                                \
    fflush(stderr);                                                                \
  } while (0)

#define IOT_SAMPLE_LOG_SUCCESS(...) \
  do                                \
  {                                 \
    (void)printf("SUCCESS:\t");     \
    (void)printf(__VA_ARGS__);      \
    (void)printf("\n");             \
  } while (0)

#define IOT_SAMPLE_LOG(...)    \
  do                           \
  {                            \
    (void)printf("\t\t");      \
    (void)printf(__VA_ARGS__); \
    (void)printf("\n");        \
  } while (0)

#define IOT_SAMPLE_LOG_AZ_SPAN(span_description, span)                                           \
  do                                                                                             \
  {                                                                                              \
    (void)printf("\t\t%s ", span_description);                                                   \
    (void)fwrite((char*)az_span_ptr(span), sizeof(uint8_t), (size_t)az_span_size(span), stdout); \
    (void)printf("\n");                                                                          \
  } while (0)



#endif // END AZ_IOT_HELPER