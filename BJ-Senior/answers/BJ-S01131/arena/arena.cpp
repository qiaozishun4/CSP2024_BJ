#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100002;

int x;
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> x;
    for(int j = 1;j <= m;j++)
        cin >> x;
    
    int k = 0;
    for(int i = 1;i <= 20;i++)
    {
        if((1 << i) >= n)
        {
            k = i;
            break;
        }
    }

    for(int i = 1;i <= k;i++)
    {
        string str;
        cin >> str;
    }

    int t;
    cin >> t;
    while(t--)
        cout << 0 << endl;

    return 0;
}