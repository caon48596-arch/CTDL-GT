#include <stdio.h>
#include <string.h>
typedef struct HoaDon
{
    int mahd;
    int ngaylap;
    int tongtien;
    char loaikhach[10];
} HoaDon;
void nhap(HoaDon *HD)
{
    printf("nhap ma hd ");
    scanf("%d", &HD->mahd);
    getchar();
    printf("nhap ngay lap ");
    scanf("%d", &HD->ngaylap);
    getchar();
    printf("loai khach ");
    fgets(HD->loaikhach, sizeof(HD->loaikhach), stdin);
    printf("tong tien ");
    scanf("%d", &HD->tongtien);
    HD->loaikhach[strcspn(HD->loaikhach, "\n")] = '\0';
}
void phanloai(HoaDon *HD, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(HD[i].loaikhach, "VIP") == 0)
        {
            printf("tien khach vs hd %d dc giam con %d\n", HD[i].mahd, HD[i].tongtien * 90 / 100);
        }
        else
        {
            printf("tien khach vs hd %d dc giam con %d\n", HD[i].mahd, HD[i].tongtien);
        }
    }
}
int main()
{
    // int n;
    // printf("nhap sl khach ");
    // scanf("%d", &n);
    // HoaDon HD[n];
    // for (int i = 0; i < n; i++)
    // {
    //     nhap(&HD[i]);
    // }
    // phanloai(HD, n);

    int n;
    printf("nhap sl khach ");
    scanf("%d", &n);
    getchar();

    HoaDon HD[n];

    for (int i = 0; i < n; i++)
    {
        printf("nhap ma hd ");
        scanf("%d", &HD[i].mahd);
        getchar();

        printf("nhap ngay lap ");
        scanf("%d", &HD[i].ngaylap);
        getchar();

        printf("loai khach ");
        fgets(HD[i].loaikhach, sizeof(HD[i].loaikhach), stdin);
        HD[i].loaikhach[strcspn(HD[i].loaikhach, "\n")] = '\0';

        printf("tong tien ");
        scanf("%d", &HD[i].tongtien);
        getchar();
    }

    for (int i = 0; i < n; i++)
    {
        if (strcmp(HD[i].loaikhach, "VIP") == 0)
        {
            printf("tien khach vs hd %d dc giam con %d\n", HD[i].mahd,  HD[i].tongtien * 90 / 100);
        }
        else
        {
            printf("tien khach vs hd %d dc giam con %d\n", HD[i].mahd,   HD[i].tongtien);
        }
    }
}