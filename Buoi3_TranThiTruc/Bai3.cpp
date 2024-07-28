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
