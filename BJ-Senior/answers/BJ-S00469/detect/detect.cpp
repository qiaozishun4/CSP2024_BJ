#include<bits/stdc++.h>
using namespace std;
struct node
{
    int d,v,add;
}a[100005];
int p[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    int n,m,l,v;//nche  mcesu lluchang vxiansu
    while(t--)
    {
        int cntz=0,cntf=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].d>>a[i].v>>a[i].add;
            if(a[i].add>0)
            {
                cntz++;
            }
            else
            {
                cntf++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        int cnt=0;
        if(cntf==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(double(sqrt(a[i].d*a[i].d+2*a[i].add*(p[n]-a[i].d)))>v)
                {
                    cnt++;
                }
            }
            cout<<cnt<<" "<<m-1;;
        }
    }
    return 0;
}
