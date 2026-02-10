#include <stdio.h>

int main() {
    int num, i, count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    if(num < 2){
        count++;
    }

    for (i = 2; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }

    if (count == 0)
        printf("%d is a prime number\n", num);
    else
        printf("%d is not a prime number\n", num);

    return 0;
}
