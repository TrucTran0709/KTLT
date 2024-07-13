#include <stdio.h>

int main() {
	int a, b, c;
	float ket_qua;

	printf("Nhập số nguyên a: ");
	scanf_s("%d", &a);
	printf("Nhập số nguyên b: ");
	scanf_s("%d", &b);
	printf("Nhập số nguyên c: ");
	scanf_s("%d", &c);

	if (c > 0) {
		ket_qua = (float)c / (a - b);
		printf("Kết quả của biểu thức c/(a-b) là: %.2f\n", ket_qua);
	}
	else {
		printf("C phải lớn hơn 0\n");
	}

	return 0;
}

