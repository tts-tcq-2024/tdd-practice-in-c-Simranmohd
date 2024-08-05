#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringCalculator.h"

int Add(const char* numbers) {
    if (numbers == NULL || numbers[0] == '\0') {
        return 0;
    }

    int sum = 0;
    char delimiter = ',';
    const char* num_str = numbers;

    if (strncmp(numbers, "//", 2) == 0) {
        delimiter = numbers[2];
        num_str = strchr(numbers, '\n') + 1;
    }

    char* token;
    char* input_copy = strdup(num_str);
    char* rest = input_copy;

    while ((token = strtok_r(rest, &delimiter, &rest))) {
        char* end;
        long num = strtol(token, &end, 10);
        if (*end == '\0') {
            sum += num;
        }
    }

    free(input_copy);
    return sum;
}
