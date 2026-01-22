#include <iostream>
using namespace std;

#define MAX_LENGTH 10

typedef int elementType;
typedef int position;

typedef struct
{
    elementType ET[MAX_LENGTH];
    position last; // số phần tử hiện có
} list;
void makenull(list *l)
{
    l->last = 0;
}
void first(const list *l)
{
    if (l->last == 0)
    {
        cout << "Danh sách rỗng";
    }
    else
    {
        cout << l->ET[0];
    }
}

int main()
{
    list l;
    makenull(&l);
    int n;
    cin >> n;
    l.last = n;
    for (int i = 0; i < l.last; i++)
    {
        cout << "mag[" << i + 1 << "] = ";
        cin >> l.ET[i];
    }
    first(&l);
    return 0;
}