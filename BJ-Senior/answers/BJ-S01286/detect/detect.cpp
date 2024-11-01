#include<bits/stdc++.h>
using namespace std;
const int N=100005,L=1000005;
int t,n,m,l,v,in[N],out[N],ti[N],to[N],po[N];
int b[L][2];
int main()
{
//    freopen("detect.in","r",stdin);
//    freopen("detect.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        vector<int>ve[N];
        cin>>n>>m>>l>>v;
        for(int i=1,d,V,a;i<=n;i++)
        {
            cin>>d>>V>>a;
            if(a>0)
            {
                out[i]=l;
                if(V>v)in[i]=d;
                in[i]=d+(v*v-V*V)/(2*a)+1;
            }
            if(a<0)
            {
                in[i]=d;
                if(V<v)in[i]=out[i]=L;
                else if((v*v-V*V)%(2*a)==0)out[i]=d+(v*v-V*V)/(2*a)-1;
                else out[i]=d+(V*V-v*v)/(2*a);
            }
            if(a==0)
            {
                if(V>v)in[i]=d,out[i]=l;
                else in[i]=out[i]=L;
            }
        }
        for(int i=1,p;i<=m;i++)
        {
            cin>>p;
            b[p][0]=1;
            b[p][1]=i;
        }
        for(int i=1;i<=n;i++)for(int j=in[i];j<=out[i];j++)if(b[j][0])
        {
            ti[i]=b[j][1];
            break;
        }
        for(int i=1;i<=n;i++)for(int j=out[i];j>=in[i];j--)if(b[j][0])
        {
            to[i]=b[j][1];
            break;
        }
        int ans=0;
        for(int i=1;i<=n;i++)if(ti[i])ans++;
        cout<<ans<<" "<<'\n';
        for(int i=1;i<=n;i++)for(int j=ti[i];j<=to[i];j++)
        {
            po[j]++;
            ve[j].push_back(i);
        }
        ans=0;
        while(1)
        {
            int mx=0,mp;
            for(int i=1;i<=m;i++)if(po[i]>mx)mx=po[i],mp=i;
            if(!mx)break;
            for(int i=0;i<ve[mp].size();i++)for(int j=ti[ve[mp][i]];j<=to[ve[mp][i]];j++)po[j]--;
            ans++;
        }
        cout<<m-ans<<'\n';
        for(int i=1;i<=l;i++)b[l][0]=b[l][1]=0;
        for(int i=1;i<=n;i++)in[i]=out[i]=ti[i]=to[i]=po[i]=0;
    }
    return 0;
}
