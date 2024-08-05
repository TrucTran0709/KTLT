#include <stdio.h>

void xuatDayFibonacci(int m) {
    int a = 1, b = 1;
    printf("%d ", a);
    if (m > 1) {
        printf("%d ", b);
    }
    int fib = a + b;
    while (fib < m) {
        printf("%d ", fib);
        a = b;
        b = fib;
        fib = a + b;
    }
    printf("\n");
}

int main() {
    int m;
    printf("Nhap gia tri m: ");
    scanf_s("%d", &m);

    if (m <= 0) {
        printf("Vui long nhap mot so nguyen duong lon hon 0.\n");
    }
    else {
        printf("Day so Fibonacci nho hon %d la: ", m);
        xuatDayFibonacci(m);
    }

    return 0;
}
