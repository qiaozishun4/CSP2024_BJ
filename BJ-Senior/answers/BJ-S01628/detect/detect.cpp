#include<bits/std++.h>
using namespace std;
struct node
{
    double d,v,a;
    void read()
    {
        cin>>d>>v>>a;
    }
}car[100010];
bool spd[3010][3010];
int s[100010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l,v,cnt=0,ans=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++) car[i].read();
        for(int i=1;i<=m;i++) cin>>s[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[j]<car[i].d) continue;
                double dis=s[j]-car[i].d;
                if(sqrt(car[i].v+2.0*car[i].a*dis)>v)
                {
                    spd[i][j]=1;
                    cnt++;
                    break;
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            bool flag=0;
            for(int j=1;j<=n;j++)
            {
                if(spd[j][i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag) ans++;
        }
        cout<<cnt<<" "<<ans<<endl;
    }
    return 0;
}
