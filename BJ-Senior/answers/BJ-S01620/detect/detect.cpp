#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct qiche{
    int d,v,a;
    bool chao;
} a[N];
struct cesu{
    int w,ans;
}p[N];
int ans;

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l,v;
        ans=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].d>>a[i].v>>a[i].a;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i].w;
            p[i].ans=0;
        }
        for(int i=1;i<=n;i++)
        {
            bool f=0;
            if(a[i].a>0)
            {
                ll s=a[i].d+(v*v-a[i].v*a[i].v)/(2*a[i].a);
                if(p[m].w>s&&a[i].d<=p[m].w)
                {
                    p[m].ans++;
                    f=1;
                }
            /*    for(int j=1;j<=m;j++)
                {
                    if(p[j].w>s)
                    {
                        p[j].ans++;
                        f=1;

                        break;
                    }

                }*/
            }
            else if(a[i].a==0)
            {
                if(a[i].v>v)
                {
                    if(p[m].w>=a[i].d)
                    {
                        p[m].ans++;
                        f=1;
                      //  break;
                    }

                      /*  for(int j=1;j<=m;j++)
                        {


                            if(p[j].w>=a[i].d)
                            {
                                p[j].ans++;
                                f=1;
                                break;
                            }
                        }*/
                }
            }
            else if(a[i].a<0)
            {
                if(a[i].v>v)
                {
                    ll s=a[i].d+(v*v-a[i].v*a[i].v)/(2*a[i].a);
                    if(p[m].w>=a[i].d&&p[m].w<s)
                    {
                        p[m].ans++;
                        f=1;
                    }
                 /*   for(int j=1;j<=m;j++)
                    {
                        if(p[j].w>=a[i].d&&p[j].w<s)
                        {
                            p[j].ans++;
                            f=1;
                          //  cout<<j<<" "<<114514<<" "<<s<<" "<<p[j].w<<endl;
                            break;
                        }
                    }*/
                }
            }
            if(f==1)
            {
                ans++;
               // cout<<i<<" ";
            }
        }
        cout<<ans<<" ";
        if(ans==0)cout<<m<<endl;
        else cout<<m-1<<endl;
    }
    return 0;
}
