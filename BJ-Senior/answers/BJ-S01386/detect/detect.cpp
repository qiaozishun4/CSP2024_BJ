#include<iostream>
using namespace std;
int v[100005];
double a[100005];
int p[100005];
double d[100005];
int n,m,L;int Vl;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;cin>>T;
    while(T--)
    {
        int cnt=0;
        cin>>n>>m>>L>>Vl;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        int P=0;
        for(int i=1;i<=m;i++)
            {cin>>p[i];P=max(p[i],P);}
        for(int i=1;i<=n;i++)
            if(d[i]<=P&&v[i]>Vl)
                cnt++;
        cout<<cnt<<" "<<m-1<<endl;
    }
    return 0;   
}