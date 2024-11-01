#include <iostream>
#include <string>
using namespace std;

string a[52];

bool check(string x)
{
    for(int i=0; i<=52; i++)
    {
        if(a[i] == x) return false;
    }
    return true;
}

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, pos=0;
    string s;
    cin >> n;
    while(n--)
    {
        cin >> s;
        if(check(s)) a[pos++]=s;
    }
    cout << 52-pos;
    return 0;
}

