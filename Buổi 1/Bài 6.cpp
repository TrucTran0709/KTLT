#include <stdio.h>
#include <string.h>

int main() {
    char hoTen[100];
    int ngay, thang, nam;
    char gioiTinh[10];
    int tuoi, tuoiNghiHuu, namNghiHuu, thangNghiHuu;
    int namHienTai = 2024;
    int tuoiNamNghiHuu = 62;
    int tuoiNuNghiHuu = 60;

    printf("Nhap ho ten : ");
    fgets(hoTen, sizeof(hoTen), stdin);
    hoTen[strcspn(hoTen, "\n")] = 0;  

    printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf_s("%d %d %d", &ngay, &thang, &nam);

    printf("Nhap gioi tinh (nam/nu): ");
    scanf_s("%9s", &gioiTinh,sizeof(gioiTinh));

    tuoi = namHienTai - nam;

    // Xử lý ngoại lệ
    if (tuoi < 18 || (tuoi > 60 && strcmp(gioiTinh, "nu") == 0) || (tuoi > 62 && strcmp(gioiTinh, "nam") == 0)) {
        printf("Loi: Tuoi khong thuoc trong tuoi lao dong. Ma loi: 101\n");
        return 101;
    }

    if (strcmp(gioiTinh, "nam") != 0 && strcmp(gioiTinh, "nu") != 0) {
        printf("Loi: Gioi tinh khong hop le. Ma loi: errcode\n");
        return -1;
    }

    
    if (strcmp(gioiTinh, "nam") == 0) {
        tuoiNghiHuu = tuoiNamNghiHuu;
    }
    else {
        tuoiNghiHuu = tuoiNuNghiHuu;
    }

    namNghiHuu = nam + tuoiNghiHuu;
    thangNghiHuu = thang;

    printf("%s, gioi tinh %s, sinh ngay %02d/%02d/%d. Hien tai (nam %d) đa %d tuoi. Thoi gian duoc nghi huu la: %02d/%d.\n",
        hoTen, gioiTinh, ngay, thang, nam, namHienTai, tuoi, thangNghiHuu, namNghiHuu);

    return 0;
}
