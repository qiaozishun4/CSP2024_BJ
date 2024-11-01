#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define int long long
#define fin freopen("color.in","r",stdin);
#define fout freopen("color.out","w",stdout);
using namespace std;
const int RED=0,BLUE=1;
const int inf=1145141919810;
int tests,n,ans;
int a[200005];
int f[2005][2005][2];//f[i][j][c]: for 1~i elements, a[i] is colored c, last element colored (!c) is j, the maximum score
signed main()
{
    fin
    fout
    cin >> tests;
    while(tests--)
    {
        ans=0;
        cin >> n;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        for(int i=1;i<=n;i++)
            for(int j=0;j<n;j++)
                for(int c:{RED,BLUE})
                    f[i][j][c]=-inf;
        f[1][0][RED]=f[1][0][BLUE]=0;
        for(int i=1;i<n;i++)
            for(int j=0;j<n;j++)
                for(int c:{RED,BLUE})
                {
                    f[i+1][j][c]=max(f[i+1][j][c],f[i][j][c]+(a[i]==a[i+1]?a[i]:0));
                    f[i+1][i][1-c]=max(f[i+1][i][1-c],f[i][j][c]+(a[j]==a[i+1]?a[j]:0));
                }
        for(int i=0;i<n;i++)
            for(int c:{RED,BLUE})
                ans=max(ans,f[n][i][c]);
        cout << ans << endl;
    }
    return 0;
}
