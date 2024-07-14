#include <stdio.h>

void tinhTong(int* pa, int* pb, int* tong);
void tinhHieu(int* pa, int* pb, int* hieu);
void tinhTich(int* pa, int* pb, int* tich);
void tinhThuong(int* pa, int* pb, float* thuong);

int main() {
    int a, b;
    int tong, hieu, tich;
    float thuong;
    int* pa = &a, * pb = &b;

    printf("Nhap so a: ");
    scanf_s("%d", pa);
    printf("Nhap so b: ");
    scanf_s("%d", pb);

    tinhTong(pa, pb, &tong);
    tinhHieu(pa, pb, &hieu);
    tinhTich(pa, pb, &tich);
    tinhThuong(pa, pb, &thuong);

    printf("Tong: %d, dia chi: %p\n", tong, (void*)&tong);
    printf("Hieu: %d, dia chi: %p\n", hieu, (void*)&hieu);
    printf("Tich: %d, dia chi: %p\n", tich, (void*)&tich);
    printf("Thuong: %.2f, dia chi: %p\n", thuong, (void*)&thuong);

    return 0;
}

void tinhTong(int* pa, int* pb, int* tong) {
    *tong = *pa + *pb;
}

void tinhHieu(int* pa, int* pb, int* hieu) {
    *hieu = *pa - *pb;
}

void tinhTich(int* pa, int* pb, int* tich) {
    *tich = *pa * *pb;
}

void tinhThuong(int* pa, int* pb, float* thuong) {
    if (*pb != 0) {
        *thuong = (float)(*pa) / (*pb);
    }
    else {
        printf("Khong the chia cho 0\n");
        *thuong = 0;
    }
}
