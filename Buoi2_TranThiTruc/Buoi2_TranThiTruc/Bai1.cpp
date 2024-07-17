#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void taoMangNgauNhien(int* a, int* n, int min_size);
void taoMangSoChan(int* a, int n, int* b, int* m);
int timKiemTuyenTinh(int* a, int n, int x);
void sapXepInterchange(int* a, int n, int tangDan);
int timKiemNhiPhan(int* a, int n, int x);
void sapXepSelection(int* a, int n);
void sapXepQuickSort(int* a, int left, int right);

int main() {
	srand(time(0));
	int a[100], n = 0, b[100], m, x, viTri;
	int choice;
	printf("\nMenu:\n");
	printf("1. Tao mang ngau nhien\n");
	printf("2. Tao mang so chan\n");
	printf("3. Tim kiem tuyen tinh\n");
	printf("4. Sap xep Interchange Sort\n");
	printf("5. Tim kiem nhi phan\n");
	printf("6. Sap xep Selection Sort\n");
	printf("7. Sap xep Quick Sort\n");
	printf("0. Thoat\n");

	do {
	
		printf("Nhap lua chon: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			taoMangNgauNhien(a, &n, 15);
			printf("Mang ngau nhien: ");
			for (int i = 0; i < n; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
			break;
		case 2:
			taoMangSoChan(a, n, b, &m);
			printf("Mang so chan: ");
			for (int i = 0; i < m; i++) {
				printf("%d ", b[i]);
			}
			printf("\n");
			break;
		case 3:
			printf("Nhap gia tri x can tim: ");
			scanf_s("%d", &x);
			viTri = timKiemTuyenTinh(a, n, x);
			if (viTri != -1) {
				printf("Tim thay %d tai vi tri %d\n", x, viTri);
			}
			else {
				printf("Khong tim thay %d\n", x);
			}
			break;
		case 4:
			sapXepInterchange(a, n, 1);
			printf("Mang sap xep tang dan (Interchange Sort): ");
			for (int i = 0; i < n; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
			break;
		case 5:
			printf("Nhap gia tri x can tim: ");
			scanf_s("%d", &x);
			viTri = timKiemNhiPhan(a, n, x);
			if (viTri != -1) {
				printf("Tim thay %d tai vi tri %d (Binary Search)\n", x, viTri);
			}
			else {
				printf("Khong tim thay %d (Binary Search)\n", x);
			}
			break;
		case 6:
			sapXepSelection(a, n);
			printf("Mang sap xep tang dan (Selection Sort): ");
			for (int i = 0; i < n; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
			break;
		case 7:
			sapXepQuickSort(a, 0, n - 1);
			printf("Mang sap xep tang dan (Quick Sort): ");
			for (int i = 0; i < n; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
	} while (choice != 0);

	return 0;
}

void taoMangNgauNhien(int* a, int* n, int min_size) {
	*n = min_size + rand() % (100 - min_size + 1);
	for (int i = 0; i < *n; i++) {
		a[i] = rand() % 101; 
	}
}

void taoMangSoChan(int* a, int n, int* b, int* m) {
	*m = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			b[*m] = a[i];
			(*m)++;
		}
	}
}

int timKiemTuyenTinh(int* a, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

void sapXepInterchange(int* a, int n, int tangDan) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((tangDan && a[i] > a[j]) || (!tangDan && a[i] < a[j])) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int timKiemNhiPhan(int* a, int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (a[mid] == x) {
			return mid;
		}
		if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

void sapXepSelection(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		int temp = a[min_idx];
		a[min_idx] = a[i];
		a[i] = temp;
	}
}

void sapXepQuickSort(int* a, int left, int right) {
	if (left >= right) {
		return;
	}
	int pivot = a[(left + right) / 2];
	int i = left, j = right;
	while (i <= j) {
		while (a[i] < pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	sapXepQuickSort(a, left, j);
	sapXepQuickSort(a, i, right);
}