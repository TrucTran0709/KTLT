#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>

void menu();
void nhapMang(int* arr, int* n);
void taoMangNgauNhien(int* arr, int* n);
void xuatMang(int* arr, int n);
void timPhanTuLonNhat(int* arr, int n);
void xuatDiaChiChanLe(int* arr, int n);
void xoaPhanTu0(int* arr, int* n);
void themSauPhanTuDauTien(int* arr, int* n, int x);
int laSoChinhPhuong(int num);
void tinhTongSoChinhPhuong(int* arr, int n);
void timCucDai(int* arr, int n);

int main() {
    int arr[100];
    int n = 0, luaChon, x;

    while (1) {
        system("cls"); 
        menu();
        printf("Nhap lua chon: ");
        scanf_s("%d", &luaChon);

        switch (luaChon) {
        case 0:
            return 0;
        case 1:
            nhapMang(arr, &n);
            xuatMang(arr, n);
            break;
        case 2:
            taoMangNgauNhien(arr, &n);
            xuatMang(arr, n);
            break;
        case 3:
            xuatMang(arr, n);
            break;
        case 4:
            timPhanTuLonNhat(arr, n);
            break;
        case 5:
            xuatDiaChiChanLe(arr, n);
            break;
        case 6:
            xoaPhanTu0(arr, &n);
            break;
        case 7:
            printf("Nhap gia tri x: ");
            scanf_s("%d", &x);
            themSauPhanTuDauTien(arr, &n, x);
            break;
        case 8:
            tinhTongSoChinhPhuong(arr, n);
            break;
        case 9:
            timCucDai(arr, n);
            break;
        default:
            printf("Khong hop le hay nhap lai!!\n");
            break;
        }
        _getch();
    }
    return 0;
}

void menu() {
    printf("0. Thoat chuong trinh\n");
    printf("1. Tao va xuat mang\n");
    printf("2. Tao mang ngau nhien\n");
    printf("3. Xuat mang\n");
    printf("4. Tim phan tu lon nhat\n");
    printf("5. Xuat dia chi cua phan tu chan lon nhat va phan tu le nho nhat\n");
    printf("6. Xoa phan tu co gia tri 0\n");
    printf("7. Them phan tu x vao sau phan tu dau tien\n");
    printf("8. Tinh tong cac phan tu la so chinh phuong\n");
    printf("9. Xuat cac so cuc dai\n");
}

void nhapMang(int* arr, int* n) {
    printf("Nhap kich thuoc mang: ");
    scanf_s("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf_s("%d", &arr[i]);
    }
}

void taoMangNgauNhien(int* arr, int* n) {
    srand(time(0));
    printf("Nhap kich thuoc mang: ");
    scanf_s("%d", n);

    for (int i = 0; i < *n; i++) {
        arr[i] = rand() % 101; 
    }
}

void xuatMang(int* arr, int n) {
    printf("Mang da nhap la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void timPhanTuLonNhat(int* arr, int n) {
    int max = arr[0];
    int* max_ptr = arr;

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_ptr = &arr[i];
        }
    }

    printf("Phan tu lon nhat la %d tai dia chi %p\n", max, (void*)max_ptr);
}

void xuatDiaChiChanLe(int* arr, int n) {
    int max = -1; 
    int min = -1; 

   
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            if (max == -1 || arr[i] > arr[max]) {
                max = i; 
            }
        }
        else {
            if (min == -1 || arr[i] < arr[min]) {
                min = i; 
            }
        }
    }

    if (max != -1) {
        printf("Phan tu chan lon nhat la %d tai dia chi %p\n", arr[max], (void*)&arr[max]);
    }
    else {
        printf("Khong co phan tu chan trong mang.\n");
    }

    if (min != -1) {
        printf("Phan tu le nho nhat la %d tai dia chi %p\n", arr[min], (void*)&arr[min]);
    }
    else {
        printf("Khong co phan tu le trong mang.\n");
    }
}

void xoaPhanTu0(int* arr, int* n) {
    int count = 0;

    for (int i = 0; i < *n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }

    *n = count;

    printf("Mang sau khi xoa phan tu co gia tri 0:\n");
    for (int i = 0; i < *n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themSauPhanTuDauTien(int* arr, int* n, int x) {
    for (int i = *n; i > 1; i--) {
        arr[i] = arr[i - 1];
    }

    arr[1] = x;
    (*n)++;

    printf("Mang sau khi them phan tu %d vao sau phan tu dau tien:\n", x);
    for (int i = 0; i < *n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int laSoChinhPhuong(int num) {
    int sqrt_num = (int)sqrt(num);
    return sqrt_num * sqrt_num == num;
}

void tinhTongSoChinhPhuong(int* arr, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (laSoChinhPhuong(arr[i])) {
            sum += arr[i];
        }
    }

    printf("Tong cac phan tu la so chinh phuong la: %d\n", sum);
}

void timCucDai(int* arr, int n) {
    printf("Cac phan tu cuc dai trong mang:\n");

    for (int i = 0; i < n; i++) {
        if ((i == 0 || arr[i] > arr[i - 1]) && (i == n - 1 || arr[i] > arr[i + 1])) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
}
