#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void int_vec_to_str(int vector[], size_t length, char* out_string) {
    if (length == 0) {
        strcpy(out_string, "[]");
        return;
    }

    memcpy(out_string, "[ ", 2 * sizeof(char)); // Don't want the \0
    out_string += 2;

    for (size_t i = 0; i < length; ++i)
        out_string += sprintf(out_string, "%d", vector[i]);
}



int main() {
    printf("Input vector size: ");
    size_t length;
    scanf("%zu", &length);

    float* vector = (float*)malloc(sizeof(float) * length);

    for (size_t i = 0; i < length; ++i) {
        printf("Input element [%zu]: ", i);
        scanf("%f", &vector[i]);
    }

    printf("Input k (power): ");
    float k;
    scanf("%f", &k);

    printf("\nInput vector: ");

    free(vector);
}
