#include <iostream>
#include <cstdio>
using namespace std;
int a[200010];
int f[200010][3];
int p0[200010][3];
int p1[200010][3];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> a[i];
        for(int i=1; i<=n; i++)
        {
            int df=0;
            p0[i][0]=a[i];
            p1[i][1]=a[i];
            int f00=f[i-1][0]+(a[i]==p0[i-1][0])*a[i];
            int f01=f[i-1][1]+(a[i]==p0[i-1][1])*a[i];
            int f10=f[i-1][0]+(a[i]==p1[i-1][0])*a[i];
            int f11=f[i-1][1]+(a[i]==p1[i-1][1])*a[i];
            if(f00>=f01)
            {
                f[i][0]=f00;
                p1[i][0]=p1[i-1][0];
            }
            else
            {
                f[i][0]=f01;
                p1[i][0]=p1[i-1][1];
            }
            if(f10>=f11)
            {
                f[i][1]=f10;
                p0[i][1]=p0[i-1][0];
            }
            else
            {
                f[i][1]=f11;
                p0[i][1]=p0[i-1][1];
            }
        }
        cout << max(f[n][0],f[n][1]) << endl;
    }
    return 0;
}