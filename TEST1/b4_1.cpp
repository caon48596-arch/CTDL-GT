#include <stdio.h>
#include <string.h>
typedef struct NhanVien
{
    int manv;
    char ten[100];
    char phongban[100];
    int luong;
} NhanVien;
void nhap(NhanVien *NV, int n)
{
    printf("nhap manv ");
    scanf("%d", &NV->manv);
    getchar();
    printf("nhap ten nv ");
    fgets(NV->ten, sizeof(NV->ten), stdin);
    NV->ten[strcspn(NV->ten, "\n")] = '\0';
    printf("nhap phong ban ");
    fgets(NV->phongban, sizeof(NV->phongban), stdin);
    NV->phongban[strcspn(NV->phongban, "\n")] = '\0';
    printf("nhap luong ");
    scanf("%d", &NV->luong);
    getchar();
}
float TB(NhanVien *NV, int n)
{
    float tb = 0;
    for (int i = 0; i < n; i++)
    {
        tb += NV[i].luong;
    }
    return tb / n;
}
void xuattb(NhanVien *NV, int n)
{
    printf("nhan vien co lg cao hon tb la\n");
    for (int i = 0; i < n; i++)
    {
        if (NV[i].luong > TB(NV, n))
        {
            printf("nhan vien %s", NV[i].ten);
        }
    }
}
int main()
{
    // printf("nhap sl nhanvien ");
    // int n;
    // scanf("%d", &n);
    // NhanVien NV[n];
    // for (int i = 0; i < n; i++)
    // {
    //     nhap(&NV[i], n);
    // }
    // float c = TB(NV, n);
    // printf("\nluong tb la %.1f\n", c);
    // xuattb(NV, n);


     printf("nhap sl nhanvien ");
    int n;
    scanf("%d", &n);
    getchar();

    NhanVien NV[n];

    for (int i = 0; i < n; i++)
    {
        printf("nhap manv ");
        scanf("%d", &NV[i].manv);
        getchar();

        printf("nhap ten nv ");
        fgets(NV[i].ten, sizeof(NV[i].ten), stdin);
        NV[i].ten[strcspn(NV[i].ten, "\n")] = '\0';

        printf("nhap phong ban ");
        fgets(NV[i].phongban,
              sizeof(NV[i].phongban), stdin);
        NV[i].phongban[strcspn(NV[i].phongban, "\n")] = '\0';

        printf("nhap luong ");
        scanf("%d", &NV[i].luong);
        getchar();
    }

    float tb = 0;
    for (int i = 0; i < n; i++){
        tb += NV[i].luong;
    }

    tb /= n;

    printf("\nluong tb la %.1f\n", tb);

    printf("nhan vien co lg cao hon tb la\n");

    for (int i = 0; i < n; i++)
    {
        if (NV[i].luong > tb)
        {
            printf("nhan vien %s\n", NV[i].ten);
        }
    }
} 