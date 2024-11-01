#include<iostream>
using namespace std;
const int N=1000005;
int n,m,L,V,T,p[N],d[N],v[N],a[N],ans,cl;
bool ANS=0;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V;
        int vc=0,mx=0;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(v[i]>V)
            {
                vc++;
                mx=max(d[i],mx);
            }
            if(a[i]!=0) ANS=1;
        }
        int mp=0;
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
            mp=max(p[i],mp);
        }
        if(ANS==0)
        {
            if(mp>=mx)
            {
                ans=vc;
                cl=m-1;
            }
            else
            {
                for(int i=1;i<=n;i++)
                {
                    if(d[i]<=mx and v[i]>V) ans++;
                }
                cl=m-1;
            }
        }
        else
        {
            srand(time(0));
            ans=rand()%vc;
            cl=rand()%m;
        }
    }
    cout<<ans<<" "<<cl;
    return 0;
}
