#include <stdio.h>
#include <string.h>
typedef struct NgayThang
{
    int ngay;
    int thang;
} NgayThang;
typedef struct NhanVien
{
    int Manv;
    char hoten[100];
    NgayThang ngaysinh;
    int luong;
} NhanVien;
void nhapvaxuat(NhanVien *NV)
{
    printf("nhap manv ");
    scanf("%d", &NV->Manv);
    getchar();
    printf("nhap hoten ");
    fgets(NV->hoten, sizeof(NV->hoten), stdin);
    NV->hoten[strcspn(NV->hoten, "\n")] = '\0';
    printf("nhap ngay sinh va thang ");
    scanf("%d %d", &NV->ngaysinh.ngay, &NV->ngaysinh.thang);
    printf("nhap luong ");
    scanf("%d", &NV->luong);
    getchar();
    printf("ma nv %d\nhoten la %s\nngaythang la %d %d\nluong la %d", NV->Manv, NV->hoten, NV->ngaysinh.ngay, NV->ngaysinh.thang, NV->luong);
}
int main()
{
    // NhanVien NV;
    // nhapvaxuat(&NV);
     NhanVien NV;

    printf("nhap manv ");
    scanf("%d", &NV.Manv);
    getchar();

    printf("nhap hoten ");
    fgets(NV.hoten, sizeof(NV.hoten), stdin);
    NV.hoten[strcspn(NV.hoten, "\n")] = '\0';

    printf("nhap ngay sinh va thang ");
    scanf("%d %d", &NV.ngaysinh.ngay, &NV.ngaysinh.thang);

    printf("nhap luong ");
    scanf("%d", &NV.luong);

    printf("\nma nv %d\n", NV.Manv);
    printf("hoten la %s\n", NV.hoten);
    printf("ngay thang sinh %d %d\n", NV.ngaysinh.ngay, NV.ngaysinh.thang);
    printf("luong la %d\n", NV.luong);
}