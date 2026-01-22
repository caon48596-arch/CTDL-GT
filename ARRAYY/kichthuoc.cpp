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
void size(list *l)
{
    cout << l->last + 1;
}

int main()
{
    list l;
    makenull(&l);
    int n;
    cin >> n;
    l.last = n;
    for (int i = 1; i <= l.last; i++)
    {
        cout << "mag[" << i << "] = ";
        cin >> l.ET[i];
    }
    endlist(&l);
    return 0;
}