#include<bits/stdc++.h>
using namespace std;
int a[600][600];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n = 0;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        string s;
        cin>>s;
        int x = (int)s[0];
        int y = (int)s[1];
        a[x][y] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= 500;i++)
    {
        for(int j = 1;j <= 500;j++)
        {
            if(a[i][j] == 1)
            {
                ans++;
            }
        }
    }
    cout<<52 - ans;
}
