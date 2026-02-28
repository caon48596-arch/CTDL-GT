#include <stdio.h>
#include <string.h>
typedef struct HocSinh
{
    char ten[100];
    int diemtoan;
} HocSinh;
void nhap(HocSinh *HS)
{
    printf("nhap diem toan ");
    scanf("%d", &HS->diemtoan);
    getchar();
    printf("nhap ten hs ");
    fgets(HS->ten, sizeof(HS->ten), stdin);
    HS->ten[strcspn(HS->ten, "\n")] = '\0';
}
void sapxep(HocSinh *HS, int n)
{
    for (int i = 0; i < n; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (HS[max].diemtoan < HS[j].diemtoan)
            {
                max = j;
            }
        }
        int temp = HS[i].diemtoan;
        HS[i].diemtoan = HS[max].diemtoan;
        HS[max].diemtoan = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("ten hs %s\ndiem %d\n", HS[i].ten, HS[i].diemtoan);
    }
}
int main()
{

    // printf("nhap sl hs ");
    // int n;
    // scanf("%d", &n);
    // HocSinh HS[n];
    // for (int i = 0; i < n; i++)
    // {
    //     nhap(&HS[i]);
    // }
    // sapxep(HS, n);

     printf("nhap sl hs ");
    int n;
    scanf("%d", &n);
    getchar();

    HocSinh HS[n];

    for (int i = 0; i < n; i++)
    {
        printf("nhap diem toan ");
        scanf("%d", &HS[i].diemtoan);
        getchar();

        printf("nhap ten hs ");
        fgets(HS[i].ten, sizeof(HS[i].ten), stdin);
        HS[i].ten[strcspn(HS[i].ten, "\n")] = '\0';
    }

    for (int i = 0; i < n; i++)
    {
        int max = i;

        for (int j = i + 1; j < n; j++)
        {
            if (HS[max].diemtoan < HS[j].diemtoan)
            {
                max = j;
            }
        }

        int temp = HS[i].diemtoan;
        HS[i].diemtoan = HS[max].diemtoan;
        HS[max].diemtoan = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("ten hs %s\ndiem %d\n",
               HS[i].ten,
               HS[i].diemtoan);
    }

}