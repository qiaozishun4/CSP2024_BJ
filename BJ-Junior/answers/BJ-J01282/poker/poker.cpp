#include<iostream>
#include<map>
using namespace std;

int n;
map<string, bool> mp;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if(!mp[s]) cnt++, mp[s] = true;
    }
    cout << 52 - cnt << endl;
    return 0;
}
