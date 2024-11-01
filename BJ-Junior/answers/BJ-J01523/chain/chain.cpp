#include<bits/stdc++.h>
using namespace std;
#define fio(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

const int bound=200005,N=100005;
int T,n,k,q,to[bound],Ecnt,l[N],suml;
//int from[N];
bool vis[bound][105],bestart[N];
struct edge
{
    int n,f;
}nxt[bound],last[bound];
struct node
{
    int n,r,f,l;
};
queue<node> qu;

void linkedge(int s,int t,int p)
{
    nxt[++Ecnt]=last[s];
    last[s]={Ecnt,p};
    to[Ecnt]=t;
    //from[Ecnt]=s;
}

int main()
{
    fio("chain");
    cin>>T;
    while(T--)
    {
        Ecnt=0,suml=0;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            suml+=l[i];
            for(int j=1,pre=0,s;j<=l[i];j++)
            {
                cin>>s;
                if(s==1) bestart[i]=true;
                if(pre) linkedge(pre,s,i);
                pre=s;
            }
        }
        //for(int i=1;i<=Ecnt;i++) cout<<"                           "<<i<<" "<<from[i]<<" "<<to[i]<<" "<<nxt[i].n<<"\n";
        while(q--)
        {
            int r,c;
            cin>>r>>c;
            for(int i=1;i<=n;i++) if(bestart[i]) qu.push({1,1,i,1});
            memset(vis,0,sizeof(vis));
            int limit=0;
            while(!qu.empty())
            {
                limit++;
                if(limit>=1ll*suml*r)
                {
                    //cout<<"NO";
                    break;
                }
                node top=qu.front();
                //cout<<"      "<<top.n<<" "<<top.r<<" "<<top.f<<" "<<top.r<<"\n";
                qu.pop();
                if(top.n==c&&top.r==r&&top.l>1)
                {
                    cout<<"1\n";
                    goto OUT;
                }
                for(edge i=last[top.n];i.n&&i.f;i=nxt[i.n])
                {
                    int t=to[i.n];
                    //cout<<"               "<<top.n<<" "<<t<<" "<<i.f<<"\n";
                    if(i.f!=top.f&&!vis[t][top.r+1])
                        vis[t][top.r+1]=true,qu.push({t,top.r+1,i.f,2});
                    else if(i.f==top.f&&top.l<k&&top.l<l[top.f]);
                        vis[t][top.r]=true,qu.push({t,top.r,top.f,top.l+1});
                }
            }
            cout<<"0\n";
            OUT:;
        }
    }
}
