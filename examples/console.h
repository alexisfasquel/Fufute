#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

// Transforming printf and perror so it adds the calling function name at the beginning and \n at the end (256 bytes buffer restriction)


static inline void console(int error, char const* funcname, char* fmt, ...) {

    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, 256, fmt, args);
    va_end(args);

    printf("[%s] - ", funcname);
    if (error) {
      printf("%s %s\n", buffer, strerror(errno));
    } else {
      printf("%s\n", buffer);
    }
}

// Defining symboles for our new info and error functions
#define info(...) console(0, __func__, ##__VA_ARGS__)
#define error(...) console(1, __func__, ##__VA_ARGS__)

#endif /* CONSOLE_H */
