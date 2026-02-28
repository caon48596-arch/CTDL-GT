#include <stdio.h>
#include <string.h>
typedef struct MonHoc
{
    char mon[10];
    int diem;
} MonHoc;
typedef struct SinhVien
{
    int MSSV;
    char ten[100];
    MonHoc Mon[100];
} SinhVien;
void nhap(SinhVien *SV, int *somon)
{
    printf("nhap MSSV ");
    scanf("%d", &SV->MSSV);
    getchar();
    printf("nhap ten sv ");
    fgets(SV->ten, sizeof(SV->ten), stdin);
    SV->ten[strcspn(SV->ten, "\n")] = '\0';
    printf("nhap sl mon hoc ");
    scanf("%d", somon);
    getchar();

    for (int i = 0; i < *somon; i++)
    {
        printf("nhap ten mon ");
        fgets(SV->Mon[i].mon, sizeof(SV->Mon[i].mon), stdin);
        SV->Mon[i].mon[strcspn(SV->Mon[i].mon, "\n")] = '\0';
        printf("nhap diem mon ");
        scanf("%d", &SV->Mon[i].diem);
        getchar();
    }
}
float TB(SinhVien *SV, int somon)
{
    float tb = 0;
    for (int i = 0; i < somon; i++)
    {
        tb += SV->Mon[i].diem;
    }
    return tb / somon;
}
void Max(SinhVien *SV, int somon, int n)
{
    float max = TB(&SV[0], somon);
    int max1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < TB(&SV[i], somon))
        {
            max = TB(&SV[i], somon);
            max1 = i;
        }
    }
    printf("\nSinh vien co TB cao nhat:\n");
    printf("MSSV: %d\n", SV[max1].MSSV);
    printf("Ten: %s\n", SV[max1].ten);
    printf("TB: %.1f\n", max);
}
int main()
{
    // printf("nhap sl sv ");
    // int n;
    // scanf("%d", &n);
    // SinhVien SV[n];
    // int somon;

    // for (int i = 0; i < n; i++)
    // {
    //     nhap(&SV[i], &somon);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     float c = TB(&SV[i], somon);
    //     printf("diem tb cua sv %s la %.1f\n", SV[i].ten, c);
    // }
    // Max(SV, somon, n);

    printf("nhap sl sv ");
    int n;
    scanf("%d", &n);
    getchar();

    SinhVien SV[n];
    int somon;
    for (int i = 0; i < n; i++)
    {
        printf("nhap MSSV ");
        scanf("%d", &SV[i].MSSV);
        getchar();

        printf("nhap ten sv ");
        fgets(SV[i].ten, sizeof(SV[i].ten), stdin);
        SV[i].ten[strcspn(SV[i].ten, "\n")] = '\0';

        printf("nhap sl mon hoc ");
        scanf("%d", &somon);
        getchar();

        for (int j = 0; j < somon; j++)
        {
            printf("nhap ten mon ");
            fgets(SV[i].Mon[j].mon, sizeof(SV[i].Mon[j].mon), stdin);
            SV[i].Mon[j].mon[strcspn(SV[i].Mon[j].mon, "\n")] = '\0';

            printf("nhap diem mon ");
            scanf("%d", &SV[i].Mon[j].diem);
            getchar();
        }
    }

    float max = 0;
    int max1 = 0;
    for (int i = 0; i < n; i++)
    {
        float tb = 0;
        for (int j = 0; j < somon; j++)
        {
            tb += SV[i].Mon[j].diem;
        }
        tb /= somon;

        printf("diem tb cua sv %s la %.1f\n", SV[i].ten, tb);

        if (i == 0 || tb > max)
        {
            max = tb;
            max1 = i;
        }
    }

    printf("\nSinh vien co TB cao nhat:\n");
    printf("MSSV: %d\n", SV[max1].MSSV);
    printf("Ten: %s\n", SV[max1].ten);
    printf("TB: %.1f\n", max);
}