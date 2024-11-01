#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    unordered_set<string> poker;

    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        poker.insert(s);
    }

    cout << 52 - poker.size() << endl;

    return 0;
}