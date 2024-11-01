#include <bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d,ans=0,l=0;
char a[1010][1010];
int v[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for (int i=1;i<=1002;i++)
    {
        for (int j=1;j<=1002;j++)
        {
            v[i][j]=0;
        }
    }
    for (long long i=1;i<=t;i++)
    {
        cin >> n >> m >> k >> x >> y >> d;
        for (long long j=1;j<=n;j++)
        {
            string s;
            cin >> s;
            for (long long h=0;h<m;h++)
            {
                a[j][h+1]=s[h];
            }
        }
        if (d==0){
            if (x>=1 && x<=n && y+1<=m &&y+1>=1 && a[x][y+1]=='.')
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
        else if (d==1){
            if (x+1>=1 && x+1<=n && y<=m &&y>=1 && a[x+1][y]=='.')
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
        else if (d==2){
            if (x>=1 && x<=n && y-1<=m &&y-1>=1 && a[x][y-1]=='.')
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
        else if (d==3){
            if (x-1>=1 && x-1<=n && y<=m &&y>=1 && a[x-1][y]=='.')
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
    }
    return 0;
}