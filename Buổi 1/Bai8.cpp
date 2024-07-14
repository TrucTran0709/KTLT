#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
    int tu;
    int mau;
} PhanSo;

void menu();
void nhapMangPhanSo(PhanSo* arr, int n);
void xuatMangPhanSo(PhanSo* arr, int n);
void xuatPhanSoMauLonHonTu(PhanSo* arr, int n);
int demPhanSoMauVaTuChan(PhanSo* arr, int n);
void rutGonPhanSo(PhanSo* ps);
PhanSo tichPhanSo(PhanSo* arr, int n);
PhanSo timPhanSoLonNhat(PhanSo* arr, int n);
int UCLN(int a, int b);

int main() {
    int luaChon, n = 0;
    PhanSo* arr = NULL;

    while (1) {
        system("cls");
        menu();
        printf("Nhap lua chon: ");
        scanf_s("%d", &luaChon);

        switch (luaChon) {
        case 0:
            free(arr);
            return 0;
        case 1:
            printf("Nhap so luong phan so: ");
            scanf_s("%d", &n);
            arr = (PhanSo*)malloc(n * sizeof(PhanSo));
            nhapMangPhanSo(arr, n);
            xuatMangPhanSo(arr, n);
            break;
        case 2:
            if (arr != NULL) {
                xuatMangPhanSo(arr, n);
            }
            else {
                printf("Mang phan so rong!\n");
            }
            break;
        case 3:
            if (arr != NULL) {
                xuatPhanSoMauLonHonTu(arr, n);
            }
            else {
                printf("Mang phan so rong!\n");
            }
            break;
        case 4:
            if (arr != NULL) {
                int count = demPhanSoMauVaTuChan(arr, n);
                printf("So phan so co mau va tu chan: %d\n", count);
            }
            else {
                printf("Mang phan so rong!\n");
            }
            break;
        case 5:
            if (arr != NULL) {
                for (int i = 0; i < n; i++) {
                    rutGonPhanSo(&arr[i]);
                }
                printf("Mang phan so sau khi rut gon:\n");
                xuatMangPhanSo(arr, n);
            }
            else {
                printf("Mang phan so rong!\n");
            }
            break;
        case 6:
            if (arr != NULL) {
                PhanSo tich = tichPhanSo(arr, n);
                printf("Tich cac phan so: %d/%d\n", tich.tu, tich.mau);
            }
            else {
                printf("Mang phan so rong!\n");
            }
            break;
        case 7:
            if (arr != NULL) {
                PhanSo max = timPhanSoLonNhat(arr, n);
                printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);
            }
            else {
                printf("Mang phan so rong!\n");
            }
            break;
        default:
            printf("Khong hop le! Vui long lua chon lai!\n");
            break;
        }
      
        _getch();
    }
    return 0;
}

void menu() {
    printf("0. Thoat chuong trinh!\n");
    printf("1. Nhap/xuat mang phan so\n");
    printf("2. Xuat mang phan so\n");
    printf("3. Xuat cac phan so co mau lon hon tu\n");
    printf("4. Dem so phan so co mau va tu chan\n");
    printf("5. Rut gon cac phan so\n");
    printf("6. Tinh tich cac phan so\n");
    printf("7. Tim phan so lon nhat\n");
}

void nhapMangPhanSo(PhanSo* arr, int n) {
    for (int i = 0; i < n; i++) {
        do {
            printf("Nhap phan so thu %d (tu mau): ", i + 1);
            scanf_s("%d%d", &arr[i].tu, &arr[i].mau);
            if (arr[i].mau == 0) {
                printf("Mau so phai khac 0. Vui long nhap lai!\n");
            }
        } while (arr[i].mau == 0);
    }
}

void xuatMangPhanSo(PhanSo* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", arr[i].tu, arr[i].mau);
    }
    printf("\n");
}

void xuatPhanSoMauLonHonTu(PhanSo* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i].mau > arr[i].tu) {
            printf("%d/%d ", arr[i].tu, arr[i].mau);
        }
    }
    printf("\n");
}

int demPhanSoMauVaTuChan(PhanSo* arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].tu % 2 == 0 && arr[i].mau % 2 == 0) {
            count++;
        }
    }
    return count;
}

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

void rutGonPhanSo(PhanSo* ps) {
    int ucln = UCLN(ps->tu, ps->mau);
    ps->tu /= ucln;
    ps->mau /= ucln;
}

PhanSo tichPhanSo(PhanSo* arr, int n) {
    PhanSo tich = { 1, 1 };
    for (int i = 0; i < n; i++) {
        tich.tu *= arr[i].tu;
        tich.mau *= arr[i].mau;
    }
    rutGonPhanSo(&tich);
    return tich;
}

PhanSo timPhanSoLonNhat(PhanSo* arr, int n) {
    PhanSo max = arr[0];
    for (int i = 1; i < n; i++) {
        if ((double)arr[i].tu / arr[i].mau > (double)max.tu / max.mau) {
            max = arr[i];
        }
    }
    return max;
}
