#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
const int maxn=int(1e5+5);
int k=0,nummax=0,ans=0;
struct trans{
    int d,v,a;
    int osstart,osend;
}c[maxn];
int p[maxn];
int num[int(1e6+5)];
bool vis[int(1e6+5)];
void init(){
    for(int i=0;i<maxn;i++){
        c[i].d=c[i].a=c[i].v=0;
        c[i].osstart=c[i].osend=0;
    }
    memset(p,0,sizeof(p));
    memset(vis,false,sizeof(vis));
    memset(num,0,sizeof(num));
    k=0,nummax=0,ans=0;

}

void dfs(int u,int cnt,int notuse){
    if(u==m&&cnt!=nummax){
        return ;
    }

    if(cnt==nummax){
        ans=max(notuse+m-u,ans);
        return ;
    }
    //cout<<u<<" "<<cnt<<" "<<notuse<<endl;
    //chose
    int gen=0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(c[i].osstart<=p[u+1]&&c[i].osend>=p[u+1]){
            if(vis[i]==false){
                gen++;
                q.push(i);
                vis[i]=true;
            }
        }
    }
    dfs(u+1,gen+cnt,notuse);

    //not chose
    while(!q.empty()){
        int head=q.front();
        q.pop();
        vis[head]=false;
    }
    dfs(u+1,cnt,notuse+1);
}



int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>T;
    while(T--){
        init();
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a==0){
                if(c[i].v>V){
                    c[i].osstart=c[i].d;
                    c[i].osend=L;
                }
                if(c[i].v<=V){
                    c[i].osstart=-1;
                    c[i].osend=-1;
                }
            }
            else{
                if(c[i].v>V&&c[i].a>0){
                    c[i].osstart=c[i].d;
                    c[i].osend=L;
                }
                 if(c[i].v<=V&&c[i].a<0){
                    c[i].osstart=-1;
                    c[i].osend=-1;
                }
                int lenpie=(pow(V,2)-pow(c[i].v,2))/(2*c[i].a);
                if(c[i].v>V&&c[i].a<0){
                        c[i].osstart=c[i].d;
                        c[i].osend=c[i].d+lenpie;
                }
                if(c[i].v<=V&&c[i].a>0){
                        c[i].osstart=c[i].d+lenpie;
                        c[i].osend=L;
                }




            }
            //cout<<i<<" "<<c[i].osstart<<" "<<c[i].osend<<endl;
            if(c[i].osend!=-1){
                num[c[i].osstart]++;
                num[c[i].osend]--;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }

        bool usevis[int(1e6+5)];
        memset(usevis,false,sizeof(usevis));
        nummax=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(c[i].osstart<=p[j+1]&&c[i].osend>=p[j+1]){
                    if(usevis[i]==false){
                        nummax++;
                        usevis[i]=true;
                    }
                }

            }
        }

        cout<<nummax<<" ";
        int countn=0;
        for(int i=1;i<=n;i++){
        if(c[i].osstart<=p[1]&&c[i].osend>=p[1]){
            vis[i]=true;
            countn++;
            }
        }
        dfs(1,countn,0);
        memset(vis,false,sizeof(vis));
        dfs(1,0,1);

        cout<<ans<<endl;
    }

    return 0;
}
