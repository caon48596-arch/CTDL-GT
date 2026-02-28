#include <stdio.h>
#include <string.h>
typedef struct SinhVien
{
    int MSSV;
    char hoten[100];
    int diemTB;
} SinhVien;
void DSSV(SinhVien *SV)
{
    printf("nhap msvv ");
    scanf("%d", &SV->MSSV);
    getchar();
    printf("nhap hoten ");
    fgets(SV->hoten, sizeof(SV->hoten), stdin);
    SV->hoten[strcspn(SV->hoten, "\n")] = '\0';
    printf("nhap diem tb ");
    scanf("%d", &SV->diemTB);
    getchar();
}
void xuatds(SinhVien &SV)
{

    printf("mssv %d\nhoten %s\ndiem tb %d\n", SV.MSSV, SV.hoten, SV.diemTB);
}
void Max(SinhVien SV[], int n)
{
    int max1;
    int max = SV[0].diemTB;
    for (int i = 0; i < n; i++)
    {
        if (max < SV[i].diemTB)
        {
            max = SV[i].diemTB;
            max1 = i;
        }
    }
    printf("diem lon nhat la %d ten %s", max, SV[max1].hoten);
}
int main()
{
    // SinhVien SV[100];
    // printf("nhap n sl sv ");
    // int n;
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     DSSV(&SV[i]);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     xuatds(SV[i]);
    // }
    // Max(SV, n);

    SinhVien SV[100];
    int n;

    printf("nhap n sl sv ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {

        printf("nhap mssv ");
        scanf("%d", &SV[i].MSSV);
        getchar();

        printf("nhap hoten ");
        fgets(SV[i].hoten, sizeof(SV[i].hoten), stdin);

        printf("nhap diem tb ");
        scanf("%d", &SV[i].diemTB);
        getchar();
    }

    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++)
    {
        printf("mssv %d\n", SV[i].MSSV);
        printf("hoten %s", SV[i].hoten); // đã có '\n' sẵn
        printf("diem tb %d\n\n", SV[i].diemTB);
    }

    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (SV[i].diemTB > SV[max].diemTB)
            max = i;
    }

    printf("diem lon nhat la %d ten %s", SV[max].diemTB, SV[max].hoten);
}