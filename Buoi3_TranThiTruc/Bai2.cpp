#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMaTranVuong(int a[MAX][MAX], int n, int k) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (k + 1);
        }
    }
}

void xuatMaTran(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void xuatDuongCheoChinh(int a[MAX][MAX], int n) {
    printf("Cac phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < n; i++) {
        printf("%4d", a[i][i]);
    }
    printf("\n");
}



int main() {
    int a[MAX][MAX];
    int n, k;
    int choice;
    printf("\n Menu \n");
    printf("1. Tao va xuat ma tran vuong\n");
    printf("2. Xuat cac phan tu tren duong cheo chinh\n");
    printf("3. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh\n");
    printf("4. Tim phan tu max thuoc tam giac tren cua duong cheo chinh\n");
    printf("5. Sap xep ma tran tang dan theo kieu zic-zac\n");
    printf("6. Sap xep duong cheo chinh tang dan tu tren xuong duoi\n");
    printf("0. Thoat\n");
    do {
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap cap ma tran vuong n (n >= 5): ");
            scanf_s("%d", &n);
            printf("Nhap gia tri k (de lay so ngau nhien tu 0 den k): ");
            scanf_s("%d", &k);
            if (n >= 5) {
                taoMaTranVuong(a, n, k);
                printf("Ma tran:\n");
                xuatMaTran(a, n);
            }
            else {
                printf("Cap ma tran phai lon hon hoac bang 5\n");
            }
            break;
        case 2:
            xuatDuongCheoChinh(a, n);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long nhap lai!\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
