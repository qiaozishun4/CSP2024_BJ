#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long int d[100010]={0};
long long int v[100010]={0};
long long int a[100010]={0};
long long int p[100010]={0};
bool ooo(long long int xx,long long int yy)
{
    if(xx>yy)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    long long int t=0;
    cin>>t;
    long long int n=0,m=0,l=0,vmax=0;
    for(long long int j0=1;j0<=t;j0++)
    {
        cin>>n>>m>>l>>vmax;
        for(long long int j1=1;j1<=n;j1++)
        {
            cin>>d[j1]>>v[j1]>>a[j1];
        }
        for(long long int j2=1;j2<=m;j2++)
        {
            cin>>p[j2];
        }
        sort(p+1,p+m+1,ooo);
        long long int liangshu=0;
        for(long long int j3=1;j3<=n;j3++)
        {
            if(d[j3]<=p[1])
            {
                if(v[j3]>vmax)
                {
                    liangshu++;
                }
            }
        }
        long long int yishu=m-1;
        if(liangshu==0)
        {
            yishu=m;
        }
        cout<<liangshu<<" "<<yishu<<endl;
    }
    return 0;
}
