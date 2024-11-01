#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node{
    int l,r;
}cnt[N];
int n,m,L,ans;
int d[N],p[N],len;
double v[N],a[N],V;
bool cmp(Node x,Node y)
{
    if(x.r==y.r)return x.l<y.l;
    return x.r<y.r;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=len=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            cnt[i].l=cnt[i].r=0;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            double s=(V*V-v[i]*v[i])/(2*a[i]);
            //cout<<s<<endl;
            bool flag=false,f2=false;
            for(int j=1;j<=m;j++)
            {
                if(p[j]<d[i])continue;
                int s2=p[j]-d[i];
                if(a[i]>=0&&s2>s)
                {
                    flag=true;
                    cnt[len].l=j;
                    cnt[len++].r=m;
                    break;
                }
                else if(a[i]<0){
                    //cout<<j;
                    if(!f2&&s2<s)
                    {
                        //cout<<i<<" ";
                        f2=true;
                        cnt[len].l=j;
                    }
                    if(s2>=s&&f2){
                        //cout<<i<<" ";
                        cnt[len++].r=j-1;
                        flag=true;
                        break;
                    }
                }
            }
            if(flag==false&&f2)
                cnt[len++].r=m,flag=true;
            if(flag){
                ans++;
            }
        }
        //cout<<1;
        cout<<ans<<" ";
        ans=0;
        sort(cnt,cnt+len,cmp);
        int r2=-1;
        for(int i=0;i<len;i++)
        {
            //cout<<cnt[i].l<<" "<<cnt[i].r<<endl;
            if(cnt[i].l>r2){
                r2=cnt[i].r,ans++;
                //cout<<i<<" ";
            }
        }
        cout<<m-ans<<endl;
    }
    return 0;
}

