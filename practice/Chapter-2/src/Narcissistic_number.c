/*
 * Return the Narcissistic numbers range from 100 ~ 999.
 * Definition of Narcissistic numbers: the sum of its 
 * own digits each raised to the power of the number of digits
 * i.e. ABC = A^3 + B^3 + C^3
 */
#include <stdio.h>
#include <math.h>

int main() {
    int d_num;
    printf("Please input the number of digits: ");
    scanf("%d", &d_num);
    printf("Narcissistic numbers: ");

    int count = 0;
    for (int i = pow(10.0, (double)d_num - 1); i <= pow(10.0, (double)d_num); i++) {
        
        int temp = i;
        int sum = 0;
        for (int j = 0; j < d_num; j++) {
            sum += pow((double)(temp % 10), (double)d_num);
            temp /= 10;
        }

        if (sum == i) { printf(" %d", sum); count++; }
    }
    printf("\nCount: %d\n", count);
}