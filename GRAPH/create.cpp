#include <bits/stdc++.h>
using namespace std;
const int Null = -1;
const int n = 4;
// const int true = 1;   // Đã thăm
// const int false = 0; // Chưa thăm
int a[n][n]; // Ma trận kề
int mark[n]; // Mảng đánh dấu
int FIRST(int v)
{
    for (int i = 0; i < n; i++)
    {
        if (a[v][i] == 1) // SỬA: Kiểm tra có cạnh (1) hay không
            return i;
    }
    return Null;
}

int NEXT(int v, int i)
{
    for (int j = i + 1; j < n; j++)
    {
        if (a[v][j] == 1)
        {
            return j;
        }
    }
    return Null;
}
void dfs(int v)
{
    cout << "Tham dinh: " << v << endl; // In ra để kiểm tra
    mark[v] = true;                     // Đánh dấu đã thăm
    int w = FIRST(v);
    while (w != Null)
    {
        if (mark[w] == false)
        {
            dfs(w);
        }
        w = NEXT(v, w);
    }
}

void duyet()
{
    for (int v = 0; v < n; v++)
    {
        mark[v] = false; // SỬA: mark[v] chứ không phải mark[n]
    }
    for (int v = 0; v < n; v++)
    { // SỬA: bắt đầu từ 0, dùng dấu chấm phẩy ;
        if (mark[v] == false)
        {
            dfs(v);
        }
    }
}

    int main()
    {
        // 1. Khởi tạo ma trận bằng 0
        // memset(a, 0, sizeof(a));

        a[0][2] = 1;
        a[2][0] = 1;
        a[0][3] = 1;
        a[3][0] = 1;
        a[2][1] = 1;
        a[1][2] = 1;

        // Test riêng hàm FIRST/NEXT (như code cũ của bạn)
        cout << "--- Test FIRST/NEXT cua dinh 0 ---" << endl;
        for (int k = 0; k < n; k++)
        {
            int i = FIRST(k);
            while (i != Null)
            {
                cout << "Ke voi " << k << " la: " << i << endl;
                i = NEXT(k, i);
            }
        }

        cout << "\n--- Bat dau duyet DFS toan bo do thi ---" << endl;
        duyet();

        return 0;
    }