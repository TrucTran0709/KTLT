#include <stdio.h>


int uocChungLonNhat(int a, int b) {
    
    if (a == b) return a;
    
    if (a > b) return uocChungLonNhat(a - b, b);

    return uocChungLonNhat(a, b - a);
}

int main() {
    int a, b;
    printf("Nhap hai so nguyen duong a va b: ");
    scanf_s("%d %d", &a, &b);

    int ucln = uocChungLonNhat(a, b);
    printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, ucln);

    return 0;
}
