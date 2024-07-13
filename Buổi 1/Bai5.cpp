#include <stdio.h>

int main() {
    int a, b, c;
    float ket_qua;

    printf("Nhap so nguyen a: ");
    scanf_s("%d", &a);
    printf("Nhap so nguyen b: ");
    scanf_s("%d", &b);
    printf("Nhap so nguyen c: ");
    scanf_s("%d", &c);

    if (c > 0) {
        if (a - b != 0) {
            ket_qua = (float)c / (a - b);
            printf("Kết quả của biểu thức c/(a-b) là: %.2f\n", ket_qua);
        }
        else {
            printf("a - b bằng 0, không thể chia cho 0.\n");
        }
    }
    else {
        printf("C phải lớn hơn 0\n");
    }

    return 0;
}


