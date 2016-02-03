#ifndef _NUMBER_TO_STRING_H_INT8_T
#define _NUMBER_TO_STRING_H_INT8_T

#include <stdint.h>


/* RSSI用int8_t型表示用 */
#define ASCII_NUMBER_0 (0x30)
#define MAX_100        (127)
#define MIN_100        (100)
#define MAX_10         (99)
#define MIN_10         (10)
#define MAX_1          (9)
#define MIN_1          (0)
#define INT8_T_MINIMUM (-128)
#define INT8_T_MAXIMUM (127)


/* prototype of function */
char *number_to_string_int8_t(int8_t num);


#endif
