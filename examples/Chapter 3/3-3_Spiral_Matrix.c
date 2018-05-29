#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{   
    if (argc != 2) { fprintf(stderr, "Invalid input.\n"); exit(1);}
    int size = (int)(strtol(argv[1], NULL, 10));
    
    int matrix[size][size];
    memset(matrix, 0, sizeof(matrix));
    
    int num = 1, row = 0, col = 0;
    while (num <= size * size)
    { 
#ifdef DEBUG
        while (col < size && !matrix[row][col]) { printf("while 1 - [%d, %d]: %d\n", row, col, num); matrix[row][col++] = num++;} col--;row++;
        while (row < size && !matrix[row][col]) { printf("while 2 - [%d, %d]: %d\n", row, col, num); matrix[row++][col] = num++;} col--;row--;
        while (col >= 0   && !matrix[row][col]) { printf("while 3 - [%d, %d]: %d\n", row, col, num); matrix[row][col--] = num++;} col++;row--;
        while (row >= 0   && !matrix[row][col]) { printf("while 4 - [%d, %d]: %d\n", row, col, num); matrix[row--][col] = num++;} col++;row++;
#else
        while (col < size && !matrix[row][col]) { matrix[row][col++] = num++;} col--;row++;
        while (row < size && !matrix[row][col]) { matrix[row++][col] = num++;} col--;row--;
        while (col >= 0   && !matrix[row][col]) { matrix[row][col--] = num++;} col++;row--;
        while (row >= 0   && !matrix[row][col]) { matrix[row--][col] = num++;} col++;row++;
#endif
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) { if (j) printf(" "); printf("%d", matrix[i][j]);}
        printf("\n");
    }

    return 0;
}