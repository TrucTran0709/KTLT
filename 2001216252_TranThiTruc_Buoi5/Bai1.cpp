#include <stdio.h>


void DiChuyenDia(char cotNguon, char cotDich) {
    printf("Chuyen dia tu cot %c sang cot %c\n", cotNguon, cotDich);
}


void ThapHaNoi(int soDia, char cotNguon, char cotDich, char cotTrungGian) {
    if (soDia == 1) {
        DiChuyenDia(cotNguon, cotDich);
    }
    else {
        ThapHaNoi(soDia - 1, cotNguon, cotTrungGian, cotDich);
        DiChuyenDia(cotNguon, cotDich);
        ThapHaNoi(soDia - 1, cotTrungGian, cotDich, cotNguon);
    }
}

int main() {
    int soDia = 3; // S? l??ng ??a
    ThapHaNoi(soDia, 'A', 'C', 'B');
    return 0;
}
