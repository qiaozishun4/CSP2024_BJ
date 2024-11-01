#include <bits/stdc++.h>

using namespace std;
long long n,m,i,j,s[1000009],a,b;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long T;
    cin >>T;
    while(T--)
    {
        cin >>n;
        j=0;
        memset(s,0,sizeof(s));
        for(i=1;i<=n;i++)
        {
            cin >> m;
            s[m]++;
            if(s[m]==2)
            {
                s[m]=0;
                j++;
            }
        }
            cout <<j <<'\n';
    }
    return 0;
}


