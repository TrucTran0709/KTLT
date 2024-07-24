#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Khai báo các hàm
void taoMaTran(int a[MAX][MAX], int m, int n, int k);
void xuatMaTran(int a[MAX][MAX], int m, int n);
void tinhTongTungDong(int a[MAX][MAX], int m, int n);
void phanTuLonNhatTrenCot(int a[MAX][MAX], int m, int n);
void xuatDuongBien(int a[MAX][MAX], int m, int n);
void xuatPhanTuCucDai(int a[MAX][MAX], int m, int n);

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
            tinhTongTungDong(a, m, n);
            break;
        case 3:
            phanTuLonNhatTrenCot(a, m, n);
            break;
        case 4:
            xuatDuongBien(a, m, n);
            break;
        case 5:
            xuatPhanTuCucDai(a, m, n);
           
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

void tinhTongTungDong(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += a[i][j];
        }
        printf("Tong dong %d: %d\n", i, sum);
    }
}

void phanTuLonNhatTrenCot(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        int max = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        printf("Phan tu lon nhat tren cot %d: %d\n", j, max);
    }
}

// Xuất các phần tử thuộc đường biên trên, dưới, trái và phải
void xuatDuongBien(int a[MAX][MAX], int m, int n) {
    printf("Cac phan tu thuoc duong bien:\n");

    for (int j = 0; j < n; j++) {
        printf("%4d", a[0][j]);
    }
    printf("\n");

    for (int i = 1; i < m - 1; i++) {
        printf("%4d", a[i][0]); // Đường biên trái
        for (int j = 1; j < n - 1; j++) {
            printf("    ");
        }
        printf("%4d\n", a[i][n - 1]); // Đường biên phải
    }

    for (int j = 0; j < n; j++) {
        printf("%4d", a[m - 1][j]);
    }
    printf("\n");
}

// Xuất các phần tử cực đại
void xuatPhanTuCucDai(int a[MAX][MAX], int m, int n) {
    printf("Cac phan tu cuc dai:\n");
    int coCucDai = 0; 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int isMax = 1;
            // Kiểm tra các phần tử xung quanh
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    // Kiểm tra các phần tử xung quanh (không vượt quá biên của ma trận)
                    if (x >= 0 && x < m && y >= 0 && y < n && !(x == i && y == j)) {
                        if (a[i][j] <= a[x][y]) {
                            isMax = 0;
                            break; 
                        }
                    }
                }
                if (!isMax) break; 
            }
            if (isMax) {
                printf("%4d", a[i][j]);
                coCucDai = 1; 
            }
        }
    }
    if (!coCucDai) {
        printf("Khong co phan tu cuc dai.\n");
    }
    else {
        printf("\n");
    }
}


