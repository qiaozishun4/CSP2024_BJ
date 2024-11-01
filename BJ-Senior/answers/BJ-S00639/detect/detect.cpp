#include <iostream>
#include <cmath>
#include <random>
#include <string>
using namespace std;

void get(int a,int b,int c)
{
    cin>>a>>b>>c;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n,m,l,v;
    cin>>t>>n>>m>>l>>v;
    int di[n],ve[n],ac[n],p[m];
    for(int i = 0;i<t;i++)
    {
        for(int j = 0;j<n;j++)
        {
            get(di[j],ve[j],ac[j]);
        }
    }
    for(int k = 0;k<m;k++)
    {
        cin>>p[k];
    }
    return 0;
}
