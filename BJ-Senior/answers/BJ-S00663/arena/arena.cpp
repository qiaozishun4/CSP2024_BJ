#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=100000+10,M=20+2,T=5000+10;
int a[N],ta[N],c[N],n,m;
char str[M][N];
int x[5],_2[M];

vector<int>vc[M][T];

int calc(int u){
    int t1=lower_bound(_2,_2+21,u)-_2;
    for(int i=1;i<=_2[t1];i++)vc[0][i].push_back(i);
    for(int i=1;i<=t1;i++){
        for(int j=1;(j<<i)<=_2[t1];j++){
            int l=(j<<1)-1,r=j<<1;
            if(str[i][j]=='0'){
                bool flag=0;
                for(int k=0;k<vc[i-1][l].size();k++){
                    if(vc[i-1][l][k]>u)vc[i][j].push_back(vc[i-1][l][k]),flag=1;
                    else if(a[vc[i-1][l][k]]<i){
                        flag=1;
                    }
                    else vc[i][j].push_back(vc[i-1][l][k]);
                }
                if(flag)for(int k=0;k<vc[i-1][r].size();k++)vc[i][j].push_back(vc[i-1][r][k]);
            }else{
                bool flag=0;
                for(int k=0;k<vc[i-1][r].size();k++){
                    if(vc[i-1][r][k]>u)vc[i][j].push_back(vc[i-1][r][k]),flag=1;
                    else if(a[vc[i-1][r][k]]<i){
                        flag=1;
                    }
                    else vc[i][j].push_back(vc[i-1][r][k]);
                }
                if(flag)for(int k=0;k<vc[i-1][l].size();k++)vc[i][j].push_back(vc[i-1][l][k]);
            }
            vc[i-1][l].clear();vc[i-1][r].clear();
        }
    }
    int res=0;
    for(int i=0;i<vc[t1][1].size();i++)res+=vc[t1][1][i];
    vc[t1][1].clear();
    return res;
}

void test(){
    cin>>x[0]>>x[1]>>x[2]>>x[3];
    for(int i=1;i<=n;i++)a[i]=ta[i]^x[i%4];
    int ans=0;
    for(int i=1;i<=m;i++){
        ans^=i*calc(c[i]);
    }cout<<ans<<endl;
}

signed main(){
    /****************************************************************************************************************/
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    _2[0]=1;for(int i=1;i<=20;i++)_2[i]=_2[i-1]<<1;
    cin>>n>>m;for(int i=1;i<=n;i++)cin>>ta[i];for(int i=1;i<=m;i++)cin>>c[i];
    int t=lower_bound(_2+1,_2+21,n)-_2;
    for(int i=1;i<=t;i++)cin>>str[i]+1;
    int tt;cin>>tt;while(tt--)test();
    return 0;
}
