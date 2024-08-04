#include <stdio.h>


int tinh_gia_tri_a(int n) {
    int A[100]; 
   
    A[0] = 1;
    A[1] = 0;
    A[2] = -1;
    
    if (n == 0) return A[0];
    if (n == 1) return A[1];
    if (n == 2) return A[2];

    for (int i = 3; i <= n; i++) {
        A[i] = 2 * A[i - 1] - 3 * A[i - 2] - A[i - 3];
    }

    return A[n];
}


int main() {
    int lua_chon, n;

    printf("\n Menu \n");
    printf("1. Tinh gia tri day so A1 (A0 = 1, A1 = 0, A2 = -1)\n");
    printf("2. Tinh gia tri day so A2 (A1 = 1, A2 = 2, A3 = 3)\n");
    printf("3. Thoat\n");

    while (1) {
        
        printf("Nhap lua chon : ");
        scanf_s("%d", &lua_chon);

        switch (lua_chon) {
        case 1:
            printf("Nhap vi tri n (n >= 0): ");
            scanf_s("%d", &n);
            if (n < 0) {
                printf("n phai la so nguyen duong.\n");
            }
            else {
                int gia_tri = tinh_gia_tri_a(n);
                printf("Gia tri phan tu thu %d cua day so A1 la: %d\n", n, gia_tri);
            }
            break;
        case 3:
            printf("Thoat chuong trinh.\n");
            return 0;

        default:
            printf("Lua chon khong hop le. Vui long chon tu 1 den 3.\n");
        }
    }

    return 0;
}
