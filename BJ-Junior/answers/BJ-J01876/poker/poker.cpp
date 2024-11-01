#include <iostream>
#include <cstring>
using namespace std;

const int N = 60;
int n, cnt = 52;

struct Node
{
    char x, y;
} a[N];

bool has[N];
string dic[2] = {
    "DCHS",
    "A23456789TJQK"
};

int f(string s, char c)
{
    for (int i = 0; i < s.size(); i++) if (s[i] == c) return i;
}

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        int id = f(dic[0], a[i].x) * 13 + f(dic[1], a[i].y) + 1;
        if (!has[id])
        {
            cnt--;
            has[id] = true;
        }
    }
    cout << cnt << endl;
    return 0;
}