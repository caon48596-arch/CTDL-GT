#include <stdio.h>
#include <string.h>
typedef struct SanPham
{
    int masp;
    char tensp[100];
    int gia;
} SanPham;
void nhap(SanPham *SP)
{
    printf("nhap ma sp ");
    scanf("%d", &SP->masp);
    getchar();
    printf("nhap ten sp");
    fgets(SP->tensp, sizeof(SP->tensp), stdin);
    SP->tensp[strcspn(SP->tensp, "\n")] = '\0';
    printf("nhap gia sp ");
    scanf("%d", &SP->gia);
    getchar();
}
void seach(SanPham SP[], int n)
{
    int seach;
    int a = 0;
    printf("nhap ma sp can tim ");

    scanf("%d", &seach);
    for (int i = 0; i < n; i++)
    {
        if (seach == SP[i].masp)
        {
            printf("ma %d\n", SP[i].masp);
            printf("ten %s\n", SP[i].tensp);
            printf("gia %d\n", SP[i].gia);
            a = 1;
        }
    }
    if (a == 0)
    {
        printf("k tim thay");
    }
}
int main()
{
    // printf("nhap sl sp ");
    // int n;
    // scanf("%d", &n);
    // getchar();
    // SanPham SP[n];
    // for (int i = 0; i < n; i++)
    // {
    //     nhap(&SP[i]);
    //     printf("\n");
    // }
    // seach(SP, n);

    printf("nhap sl sp ");
    int n;
    scanf("%d", &n);
    getchar();

    SanPham SP[n];

    for (int i = 0; i < n; i++)
    {
        printf("nhap ma sp ");
        scanf("%d", &SP[i].masp);
        getchar();

        printf("nhap ten sp ");
        fgets(SP[i].tensp, sizeof(SP[i].tensp), stdin);
        SP[i].tensp[strcspn(SP[i].tensp, "\n")] = '\0';

        printf("nhap gia sp ");
        scanf("%d", &SP[i].gia);
        getchar();
    }

    int seach;
    int a = 0;

    printf("nhap ma sp can tim ");
    scanf("%d", &seach);

    for (int i = 0; i < n; i++)
    {
        if (seach == SP[i].masp)
        {
            printf("ma %d\n", SP[i].masp);
            printf("ten %s\n", SP[i].tensp);
            printf("gia %d\n", SP[i].gia);
            a = 1;
        }
    }

    if (a == 0)
    {
        printf("k tim thay");
    }
}
