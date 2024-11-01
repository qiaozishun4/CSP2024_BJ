#include <bits/stdc++.h>
using namespace std;
int n,a[200][200],cnt = 52;
string s[105];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
    }
    for(int i = 1;i <= n;i++)
    {
        if(a[s[i][0]][s[i][1]] != 1)
        {
            cnt--;
        }
        a[s[i][0]][s[i][1]] = 1;
    }
    cout << cnt;
    return 0;
}
