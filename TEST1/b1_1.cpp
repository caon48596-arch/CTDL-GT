#include <stdio.h>
#include <string.h>
typedef struct Sach
{
    int MaSach;
    char TenSach[100];
    int GiaTien;
} Sach;
void nhap(Sach *S)
{
    printf("nhap ma sach ");
    scanf("%d", &S->MaSach);
    getchar();
    printf("nhap ten sach ");
    fgets(S->TenSach, sizeof(S->TenSach), stdin);
    S->TenSach[strcspn(S->TenSach, "\n")] = '\0';
    printf("nhap gia tien ");
    scanf("%d", &S->GiaTien);
}
void xuat(Sach S)
{
    printf("ma sach %d\nten sach %s\ngia tien %d\n", S.MaSach, S.TenSach, S.GiaTien);
}
int main()
{
    // Sach S;
    // nhap(&S);
    // xuat(S);
    Sach S;

    printf("nhap ma sach ");
    scanf("%d", &S.MaSach);
    getchar();

    printf("nhap ten sach ");
    fgets(S.TenSach, sizeof(S.TenSach), stdin);
    S.TenSach[strcspn(S.TenSach, "\n")] = '\0';

    printf("nhap gia tien ");
    scanf("%d", &S.GiaTien);

    printf("\nma sach %d\n", S.MaSach);
    printf("ten sach %s\n", S.TenSach);
    printf("gia tien %d\n", S.GiaTien);
}