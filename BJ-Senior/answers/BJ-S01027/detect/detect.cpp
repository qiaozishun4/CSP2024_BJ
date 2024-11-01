//#include<cassert>
#include<iostream>
#include<algorithm>
using namespace std;
struct car{
    bool flag;
    int d,v,a,l,r;
}c[100005];
bool used[100005];
std::pair<int,int> mxd[100005<<1];
int T,n,m,len,V,p[100005],ans1,cnt,lst,ans2;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--)
    {
        ans1=ans2=cnt=0;
        cin>>n>>m>>len>>V;
        for(int i=1;i<=n;i++)
            cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=1;i<=m;i++)
            cin>>p[i];
        for(int i=1;i<=n;i++)
        {
            c[i].flag=used[i]=false;
            if(c[i].a>0)
            {
                if(c[i].v>V)
                    c[i].l=lower_bound(p+1,p+1+m,c[i].d)-p,c[i].r=m+1;
                else
                    c[i].l=upper_bound(p+1,p+1+m,c[i].d+(V*V-c[i].v*c[i].v)/(2.0*c[i].a))-p,c[i].r=m+1;
                if(c[i].l<=m)c[i].flag=true,ans1++;
            }
            if(c[i].a==0)
            {
                if(c[i].v>V)
                {
                    c[i].l=lower_bound(p+1,p+1+m,c[i].d)-p,c[i].r=m+1;
                    if(c[i].l<=m)c[i].flag=true,ans1++;
                }
                else
                    c[i].l=c[i].r=m+1;
            }
            if(c[i].a<0)
            {
                c[i].r=lower_bound(p+1,p+1+m,c[i].d+max((V*V-c[i].v*c[i].v)/(2.0*c[i].a),0.0))-p-1;
                //cout<<c[i].d+(V*V-c[i].v*c[i].v)/(2.0*c[i].a)<<","<<p[c[i].r]<<"~"<<p[c[i].r+1]<<endl;
                if(c[i].r<1)c[i].l=c[i].r;
                else
                {
                    //assert((p[c[i].r+1]==0||p[c[i].r+1]>c[i].d+(V*V-c[i].v*c[i].v)/(2.0*c[i].a))&&c[i].d+(V*V-c[i].v*c[i].v)/(2.0*c[i].a)>p[c[i].r]);
                    c[i].l=lower_bound(p+1,p+1+m,c[i].d)-p;
                    //cout<<c[i].d<<" in "<<p[c[i].l-1]<<"~"<<p[c[i].l]<<endl;
                    if(c[i].l<=c[i].r)
                        c[i].flag=true,ans1++;
                }
            }
            if(c[i].flag)
            {
                //cout<<i<<":"<<c[i].l<<" "<<c[i].r<<endl;
                mxd[++cnt]=std::make_pair(c[i].l,-i);
                mxd[++cnt]=std::make_pair(c[i].r,i);
            }
        }
        sort(mxd+1,mxd+1+cnt);
        lst=1;
        for(int i=1;i<=cnt;i++)
        {
            //cout<<mxd[i].second<<endl;
            if(mxd[i].second>0&&!used[abs(mxd[i].second)])
            {
                //cout<<lst<<"->"<<i<<endl;
                for(int j=lst;j<=i;j++)
                    used[abs(mxd[j].second)]=true;
                lst=i+1,ans2++;
            }
        }
        cout<<ans1<<' '<<m-ans2<<'\n';
    }
    return 0;
}
