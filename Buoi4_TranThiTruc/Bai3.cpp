#include <stdio.h>


int capSoCong(int a, int r, int n) {
    if (n == 1) {
        return a;
    }
    else {
        return a + (n - 1) * r;
    }
}

int main() {
    int a, r, n;

    printf("Nhap hang dau a: ");
    scanf_s("%d", &a);

    printf("Nhap cong sai r: ");
    scanf_s("%d", &r);

    printf("Nhap vi tri n: ");
    scanf_s("%d", &n);

    int gia_tri = capSoCong(a, r, n);
    printf("Gia tri phan tu thu %d cua cap so cong la: %d\n", n, gia_tri);

    return 0;
}
