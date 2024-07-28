#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

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

void xuatCotToanLe(int a[MAX][MAX], int m, int n) {
    printf("Cac cot chi chua so le:\n");
    for (int j = 0; j < n; j++) {
        int toanLe = 1;
        for (int i = 0; i < m; i++) {
            if (a[i][j] % 2 == 0) {
                toanLe = 0;
                break;
            }
        }
        if (toanLe) {
            for (int i = 0; i < m; i++) {
                printf("%4d", a[i][j]);
            }
            printf("\n");
        }
    }
}

int timMaxTrenBien(int a[MAX][MAX], int m, int n) {
    int max = a[0][0];
    for (int i = 0; i < m; i++) {
        if (a[i][0] > max) max = a[i][0];
        if (a[i][n - 1] > max) max = a[i][n - 1];
    }
    for (int j = 0; j < n; j++) {
        if (a[0][j] > max) max = a[0][j];
        if (a[m - 1][j] > max) max = a[m - 1][j];
    }
    return max;
}

int demPhanTuChuaSo2(int a[MAX][MAX], int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int temp = a[i][j];
            while (temp != 0) {
                if (temp % 10 == 2) {
                    count++;
                    break;
                }
                temp /= 10;
            }
        }
    }
    return count;
}

void xuatPhanTuCucTieu(int a[MAX][MAX], int m, int n) {
    printf("Cac phan tu cuc tieu:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int isMin = 1;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < m && y >= 0 && y < n && !(x == i && y == j)) {
                        if (a[i][j] >= a[x][y]) {
                            isMin = 0;
                        }
                    }
                }
            }
            if (isMin) {
                printf("%4d", a[i][j]);
            }
        }
    }
    printf("\n");
}

void sapXepMaTranDong(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] > a[i][k]) || (i % 2 != 0 && a[i][j] < a[i][k])) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

void sapXepMaTranCot(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            for (int k = i + 1; k < m; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}

int kiemTraGiamDan(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i][j + 1]) {
                return 0;
            }
        }
        if (i < m - 1 && a[i][n - 1] < a[i + 1][0]) {
            return 0;
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            if (a[i][j] < a[i + 1][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void lietKeDongToanChan(int a[MAX][MAX], int m, int n) {
    printf("Cac dong chi chua so chan:\n");
    for (int i = 0; i < m; i++) {
        int toanChan = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                toanChan = 0;
                break;
            }
        }
        if (toanChan) {
            printf("Dong %d\n", i);
        }
    }
}


int main() {
    int a[MAX][MAX];
    int m, n, k;
    int choice;
    printf("\n Menu \n");
    printf("1. Tao va xuat ma tran\n");
    printf("2. Xuat cac cot chi chua so le\n");
    printf("3. Tim phan tu lon nhat tren bien\n");
    printf("4. Dem so phan tu co chu so 2\n");
    printf("5. Xuat cac phan tu cuc tieu\n");
    printf("6. Sap xep ma tran dong (chan giam, le tang)\n");
    printf("7. Sap xep ma tran cot (chan tang, le giam)\n");
    printf("8. Kiem tra ma tran giam dan\n");
    printf("9. Liet ke dong toan chan\n");
    printf("10. Liet ke dong giam dan\n");
    printf("11. Tim gia tri xuat hien nhieu nhat\n");
    printf("12. Tim chu so xuat hien nhieu nhat\n");
    printf("13. Liet ke cot tong nho nhat\n");
    printf("14. Hoan vi hai cot\n");
    printf("15. Hoan vi hai dong\n");
    printf("0. Thoat\n");

    do {
        
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so dong m: ");
            scanf_s("%d", &m);
            printf("Nhap so cot n: ");
            scanf_s("%d", &n);
            printf("Nhap gia tri k (de lay so ngau nhien tu 0 den k): ");
            scanf_s("%d", &k);
            taoMaTran(a, m, n, k);
            printf("Ma tran:\n");
            xuatMaTran(a, m, n);
            break;
        case 2:
            xuatCotToanLe(a, m, n);
            break;
        case 3:
            printf("Phan tu lon nhat tren bien: %d\n", timMaxTrenBien(a, m, n));
            break;
        case 4:
            printf("So phan tu co chu so 2: %d\n", demPhanTuChuaSo2(a, m, n));
            break;
        case 5:
            xuatPhanTuCucTieu(a, m, n);
            break;
        case 6:
            sapXepMaTranDong(a, m, n);
            printf("Ma tran sau khi sap xep dong (chan giam, le tang):\n");
            xuatMaTran(a, m, n);
            break;
        case 7:
            sapXepMaTranCot(a, m, n);
            printf("Ma tran sau khi sap xep cot (chan tang, le giam):\n");
            xuatMaTran(a, m, n);
            break;
        case 8:
            if (kiemTraGiamDan(a, m, n)) {
                printf("Ma tran giam dan theo cot va dong.\n");
            }
            else {
                printf("Ma tran khong giam dan theo cot va dong.\n");
            }
            break;
        case 9:
            lietKeDongToanChan(a, m, n);
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
