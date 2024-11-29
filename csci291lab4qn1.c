#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    float value;
    int invalidCount = 0;
    int result;

    // Open the input file
    inputFile = fopen("data.txt", "r");
    if (inputFile == NULL) {
        printf("cant open a inputFile.\n");
        return 1;
    }

    // Open the output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("cant create a output file.\n");
        fclose(inputFile);
        return 1;
    }

    printf("checking file 'data.txt'...\n");

    // Process the file and write valid floats to output.txt
    while (1) {
        result = fscanf(inputFile, "%f", &value);

        if (result == 1) {
            // Write valid float to the output file
            fprintf(outputFile, "%f\n", value);
        } else if (result == 0) {
            // Skip invalid values and count them
            printf("Invalid value encountered, skipping.\n");
            invalidCount++;
            fscanf(inputFile, "%*s"); // Skip the invalid token
        } else {
            break; // End of file or read error
        }
    }

    // Print the number of invalid float values
    printf("Number of invalid float values: %d\n", invalidCount);

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Valid floats have been written to 'output.txt'.\n");

    return 0;
}
