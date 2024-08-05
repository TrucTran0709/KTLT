#include <stdio.h>

int fibonacci(int n) {
    if (n <= 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap mot so nguyen duong.\n");
    }
    else {
        int fib = fibonacci(n);
        printf("So Fibonacci thu %d la: %d\n", n, fib);
    }

    return 0;
}
