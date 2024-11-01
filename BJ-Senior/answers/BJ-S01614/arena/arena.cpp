#include <bits/stdc++.h>
using namespace std;
const int ttf=100005;
int n,m,a2[ttf],c[ttf],k,t,x[4],a[ttf];
bool d[ttf][ttf];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a2[i];
    for(int i=0;i<m;i++) cin>>c[i];
    while(pow(2,k)<n) k++;
    for(int r=0;r<k;r++)
    {
        for(int g=0;g<pow(2,k-r);g++) cin>>d[r][g];
    }
    cin>>t;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>x[j];
            a[j]=a2[j]^x[j%4];
            cout<<a[j]<<endl;
        }
    }
    return 0;
}