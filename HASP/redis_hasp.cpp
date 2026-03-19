#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> S;

    S.insert(10);
    S.insert(21);
    S.insert(32);

    if (S.find(21) != S.end())
    {
        cout << "Tim thay";
    }

    S.erase(21);
}