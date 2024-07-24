#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Khai b�o c�c h�m
void taoMaTran(int a[MAX][MAX], int m, int n, int k);
void xuatMaTran(int a[MAX][MAX], int m, int n);


int main() {
    int m, n, k, choice;
    int a[MAX][MAX];

    printf("Nhap so dong m: ");
    scanf_s("%d", &m);
    printf("Nhap so cot n: ");
    scanf_s("%d", &n);
    printf("Nhap gia tri k (de lay so ngau nhien tu 0 den k): ");
    scanf_s("%d", &k);

    printf("\n Menu \n");
    printf("1. Xuat ma tran\n");
    printf("2. Tinh tong gia tri tung dong\n");
    printf("3. Xuat phan tu lon nhat tren tung cot\n");
    printf("4. Xuat cac phan tu thuoc duong bien\n");
    printf("5. Xuat cac phan tu cuc dai\n");
    printf("6. Xuat cac phan tu hoang hau\n");
    printf("7. Xuat cac phan tu diem yen ngua\n");
    printf("8. Xuat dong chi chua so chan\n");
    printf("9. Sap xep mang tang theo tung dong\n");
    printf("0. Thoat\n");

    taoMaTran(a, m, n, k);

    
    do {
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            xuatMaTran(a, m, n);
            break;
        case 2:
           
            break;
        case 3:
           
            break;
        case 4:
          
            break;
        case 5:
           
            break;
        case 6:
           
            break;
        case 7:
           
            break;
        case 8:
           
            break;
        case 9:
          
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 0);

    return 0;
}


void taoMaTran(int a[MAX][MAX], int m, int n, int k) {
    srand(time(NULL)); 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (k + 1); 
        }
    }
}


void xuatMaTran(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

