#include <stdio.h>

int tongDeQuy(int n) {
    if (n == 1) return 1;
    return n + tongDeQuy(n - 1);
}

int tongKhongDeQuy(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += i;
    }
    return tong;
}

int main() {
    int choice, n;
    printf("Chon bai can tinh:\n");
    printf("1. Tinh tong S(n) = 1 + 2 + 3 + ... + n\n");
    printf("2. Tinh tong S(n) = 1/2 + 2/3 + ... + n/(n + 1)\n");
    printf("3. Tinh tong S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n + 1)\n");
    printf("4. Tinh tong S(n) = 1*2 + 2*3 + ... + n*(n+1)\n");
    printf("5. Thoat\n");
    do {
       
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            printf("Nhap gia tri cua n: ");
            scanf_s("%d", &n);
        }

        switch (choice) {
        case 1:
            printf("Ket qua bang de quy: %d\n", tongDeQuy(n));
            printf("Ket qua khong de quy: %d\n", tongKhongDeQuy(n));
            break;
        case 5:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le .Vui long nhap lai\n");
        }
    } while (choice != 5);

    return 0;
}
