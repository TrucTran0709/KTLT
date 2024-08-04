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

double tongPhanSoDeQuy(int n) {
    if (n == 1) return 1.0 / 2;
    return (double)n / (n + 1) + tongPhanSoDeQuy(n - 1);
}

double tongPhanSoKhongDeQuy(int n) {
    double tong = 0.0;
    for (int i = 1; i <= n; i++) {
        tong += (double)i / (i + 1);
    }
    return tong;
}


double tongPhanSoLeDeQuy(int n) {
    if (n == 0) return 0.0; 
    return 1.0 / (2 * n - 1) + tongPhanSoLeDeQuy(n - 1);
}


double tongPhanSoLeKhongDeQuy(int n) {
    double tong = 0.0;
    for (int i = 1; i <= n; i++) { 
        tong += 1.0 / (2 * i - 1);
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
        case 2:
            printf("Ket qua bang de quy: %lf\n", tongPhanSoDeQuy(n));
            printf("Ket qua khong de quy: %lf\n", tongPhanSoKhongDeQuy(n));
            break;
        case 3:
            printf("Ket qua bang de quy: %lf\n", tongPhanSoLeDeQuy(n));
            printf("Ket qua khong de quy: %lf\n", tongPhanSoLeKhongDeQuy(n));
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
