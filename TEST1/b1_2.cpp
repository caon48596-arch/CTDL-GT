#include <stdio.h>
typedef struct HCN
{
    float chieudai;
    float chieurong;
} HCN;
void chunhat(HCN *HN)
{
    printf("nhap chieu dai ");
    scanf("%f", &HN->chieudai);
    printf("nhap chieu rong ");
    scanf("%f", &HN->chieurong);
    printf("chieu rong la %.1f va chieu dai la %.1f\n", HN->chieurong, HN->chieudai);
}
void Chuvi(HCN *HN)
{
    float dientich = HN->chieudai * HN->chieurong;
    float chuvi = (HN->chieudai + HN->chieurong) * 2;
    printf("chu vi bang %.1f va dien tich la %.1f", chuvi, dientich);
}
int main()
{
    // HCN HN;
    // chunhat(&HN);

    // Chuvi(&HN);
    HCN HN;

    printf("nhap chieu dai ");
    scanf("%f", &HN.chieudai);

    printf("nhap chieu rong ");
    scanf("%f", &HN.chieurong);

    printf("chieu rong la %.1f va chieu dai la %.1f\n",
           HN.chieurong, HN.chieudai);

    float dientich = HN.chieudai * HN.chieurong;
    float chuvi = (HN.chieudai + HN.chieurong) * 2;

    printf("chu vi bang %.1f va dien tich la %.1f",
           chuvi, dientich);
}