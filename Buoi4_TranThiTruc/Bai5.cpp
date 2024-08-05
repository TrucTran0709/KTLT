#include <stdio.h>

int x(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (n - i) * x(i);
    }

    return sum;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);

    printf("x_%d = %d\n", n, x(n));
    return 0;
}
