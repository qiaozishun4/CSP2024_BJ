#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m,l,T,mi[N],cnt1;
int vmax;
struct car{
    int d,v,a,cam=1e6;
}c[N];
bool chk1,chk2;
bool chkf(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(mi[i]>=c[x].d)return true;
    }
    return false;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int ans1=0,ans2=0;
        cin>>n>>m>>l>>vmax;
        for(int i=1;i<=n;i++)
            cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=1;i<=m;i++)
            cin>>mi[i];
        sort(mi+1,mi+m+1);

        chk1=false,chk2=false;
        for(int i=1;i<=n;i++)
        {
            if(c[i].a>0)chk1=true;
            if(c[i].a<0)chk2=true;
        }
        if(!chk1&&!chk2)//ai=0
        {
            for(int i=1;i<=n;i++)
            {
                if(c[i].v>vmax&&chkf(i)) ans1++;
            }
            cout<<ans1<<" "<<m-1<<endl;
        }
    }

    return 0;
}
