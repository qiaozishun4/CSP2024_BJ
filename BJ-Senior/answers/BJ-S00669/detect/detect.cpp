#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        bool flag=0;
        int d[100010]={0},b[100010]={0},a[100010]={0},p[100010]={0},cnt=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>b[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(b[i]>v)
            {
                cnt++;
                flag=1;
            }
        }
        if(flag)
        {
            cout<<cnt<<' '<<m-1;
        }else
        {
            cout<<cnt<<' '<<m;
        }

    }

    return 0;
}