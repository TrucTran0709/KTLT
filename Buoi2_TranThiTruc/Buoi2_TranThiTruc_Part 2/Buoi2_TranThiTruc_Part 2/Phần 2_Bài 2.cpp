#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int tu_so;
    int mau_so;
} PhanSo;


typedef struct {
    int phan_nguyen;
    PhanSo phan_so;
} HonSo;

// Hàm tìm ước chung lớn nhất 
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


PhanSo rutGonPhanSo(PhanSo ps) {
    int tu_so = abs(ps.tu_so);
    int mau_so = abs(ps.mau_so);
    int ucln = gcd(tu_so, mau_so);
    ps.tu_so /= ucln;
    ps.mau_so /= ucln;
    // Giữ dấu của phân số
    if ((ps.tu_so < 0 && ps.mau_so < 0) || (ps.tu_so > 0 && ps.mau_so < 0)) {
        ps.tu_so = -ps.tu_so;
        ps.mau_so = -ps.mau_so;
    }
    return ps;
}


void taoMangHonSo(HonSo mang[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        mang[i].phan_nguyen = rand() % 11;
        mang[i].phan_so.tu_so = rand() % 10 + 1;
        mang[i].phan_so.mau_so = rand() % 10 + 1;  // Mẫu khác 0
    }
}


void xuatDanhSachHonSo(HonSo mang[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d/%d\n", mang[i].phan_nguyen, mang[i].phan_so.tu_so, mang[i].phan_so.mau_so);
    }
}

int soSanhHonSo(HonSo a, HonSo b) {
    float giaTriA = a.phan_nguyen + (float)a.phan_so.tu_so / a.phan_so.mau_so;
    float giaTriB = b.phan_nguyen + (float)b.phan_so.tu_so / b.phan_so.mau_so;
    if (giaTriA > giaTriB) return 1;
    else if (giaTriA < giaTriB) return -1;
    else return 0;
}


PhanSo honSoToPhanSo(HonSo hs) {
    PhanSo ps;
    ps.tu_so = hs.phan_nguyen * hs.phan_so.mau_so + hs.phan_so.tu_so;
    ps.mau_so = hs.phan_so.mau_so;
    return rutGonPhanSo(ps);
}


HonSo phanSoToHonSo(PhanSo ps) {
    HonSo hs;
    hs.phan_nguyen = ps.tu_so / ps.mau_so;
    hs.phan_so.tu_so = ps.tu_so % ps.mau_so;
    hs.phan_so.mau_so = ps.mau_so;
    return hs;
}


PhanSo congPhanSo(PhanSo a, PhanSo b) {
    PhanSo ketQua;
    ketQua.tu_so = a.tu_so * b.mau_so + b.tu_so * a.mau_so;
    ketQua.mau_so = a.mau_so * b.mau_so;
    return rutGonPhanSo(ketQua);
}


PhanSo truPhanSo(PhanSo a, PhanSo b) {
    PhanSo ketQua;
    ketQua.tu_so = a.tu_so * b.mau_so - b.tu_so * a.mau_so;
    ketQua.mau_so = a.mau_so * b.mau_so;
    return rutGonPhanSo(ketQua);
}


PhanSo nhanPhanSo(PhanSo a, PhanSo b) {
    PhanSo ketQua;
    ketQua.tu_so = a.tu_so * b.tu_so;
    ketQua.mau_so = a.mau_so * b.mau_so;
    return rutGonPhanSo(ketQua);
}


PhanSo chiaPhanSo(PhanSo a, PhanSo b) {
    PhanSo ketQua;
    ketQua.tu_so = a.tu_so * b.mau_so;
    ketQua.mau_so = a.mau_so * b.tu_so;
    return rutGonPhanSo(ketQua);
}


void interchangeSort(HonSo mang[], int n, int tang_dan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int cmp = soSanhHonSo(mang[i], mang[j]);
            if ((tang_dan && cmp > 0) || (!tang_dan && cmp < 0)) {
                HonSo temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
}


void selectionSort(HonSo mang[], int n, int tang_dan) {
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            int cmp = soSanhHonSo(mang[j], mang[idx]);
            if ((tang_dan && cmp < 0) || (!tang_dan && cmp > 0)) {
                idx = j;
            }
        }
        HonSo temp = mang[idx];
        mang[idx] = mang[i];
        mang[i] = temp;
    }
}


void quickSort(HonSo mang[], int left, int right, int tang_dan) {
    int i = left, j = right;
    HonSo pivot = mang[(left + right) / 2];
    while (i <= j) {
        while ((tang_dan && soSanhHonSo(mang[i], pivot) < 0) || (!tang_dan && soSanhHonSo(mang[i], pivot) > 0)) i++;
        while ((tang_dan && soSanhHonSo(mang[j], pivot) > 0) || (!tang_dan && soSanhHonSo(mang[j], pivot) < 0)) j--;
        if (i <= j) {
            HonSo temp = mang[i];
            mang[i] = mang[j];
            mang[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) quickSort(mang, left, j, tang_dan);
    if (i < right) quickSort(mang, i, right, tang_dan);
}


void menu() {
    int n = 5;
    HonSo mang[5];
    int choice;
    printf("\nMenu:\n");
    printf("1. Tao mang hon so ngau nhien\n");
    printf("2. Xuat danh sach hon so\n");
    printf("3. So sanh 2 hon so\n");
    printf("4. Chuyen hon so thanh phan so\n");
    printf("5. Chuyen phan so thanh hon so\n");
    printf("6. Tinh tong, hieu, tich, thuong 2 hon so\n");
    printf("7. Sap xep mang tang/giam\n");
    printf("8. Thoat\n");
    do {
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            taoMangHonSo(mang, n);
            printf("Da tao mang hon so ngau nhien.\n");
            break;
        case 2:
            printf("Danh sach hon so:\n");
            xuatDanhSachHonSo(mang, n);
            break;
        case 3: {
            int idx1, idx2;
            printf("Nhap chi so 2 hon so can so sanh (0-%d): ", n - 1);
            scanf_s("%d %d", &idx1, &idx2);
            int cmp = soSanhHonSo(mang[idx1], mang[idx2]);
            if (cmp > 0) printf("Hon so thu nhat lon hon hon so thu hai.\n");
            else if (cmp < 0) printf("Hon so thu nhat nho hon hon so thu hai.\n");
            else printf("Hai hon so bang nhau.\n");
            break;
        }
        case 4: {
            int idx;
            printf("Nhap chi so hon so can chuyen (0-%d): ", n - 1);
            scanf_s("%d", &idx);
            PhanSo ps = honSoToPhanSo(mang[idx]);
            printf("Phan so tuong ung: %d/%d\n", ps.tu_so, ps.mau_so);
            break;
        }
        case 5: {
            PhanSo ps;
            printf("Nhap phan so (tu_so mau_so): ");
            scanf_s("%d %d", &ps.tu_so, &ps.mau_so);
            HonSo hs = phanSoToHonSo(ps);
            printf("Hon so tuong ung: %d %d/%d\n", hs.phan_nguyen, hs.phan_so.tu_so, hs.phan_so.mau_so);
            break;
        }
        case 6: {
            int idx1, idx2;
            printf("Nhap chi so 2 hon so can tinh toan (0-%d): ", n - 1);
            scanf_s("%d %d", &idx1, &idx2);
            PhanSo ps1 = honSoToPhanSo(mang[idx1]);
            PhanSo ps2 = honSoToPhanSo(mang[idx2]);
            PhanSo tong = congPhanSo(ps1, ps2);
            PhanSo hieu = truPhanSo(ps1, ps2);
            PhanSo tich = nhanPhanSo(ps1, ps2);
            PhanSo thuong = chiaPhanSo(ps1, ps2);
            printf("Tong: %d/%d\n", tong.tu_so, tong.mau_so);
            printf("Hieu: %d/%d\n", hieu.tu_so, hieu.mau_so);
            printf("Tich: %d/%d\n", tich.tu_so, tich.mau_so);
            printf("Thuong: %d/%d\n", thuong.tu_so, thuong.mau_so);
            break;
        }
        case 7: {
            int tang_dan, loai_sap_xep;
            printf("Nhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
            scanf_s("%d", &tang_dan);
            printf("Chon loai sap xep (1. Interchange Sort, 2. Selection Sort, 3. Quick Sort): ");
            scanf_s("%d", &loai_sap_xep);
            switch (loai_sap_xep) {
            case 1:
                interchangeSort(mang, n, tang_dan);
                break;
            case 2:
                selectionSort(mang, n, tang_dan);
                break;
            case 3:
                quickSort(mang, 0, n - 1, tang_dan);
                break;
            default:
                printf("Loai sap xep khong hop le.\n");
                continue;
            }
            printf("Danh sach hon so sau khi sap xep:\n");
            xuatDanhSachHonSo(mang, n);
            break;
        }
        case 8:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
    } while (choice != 8);
}

int main() {
    menu();
    return 0;
}