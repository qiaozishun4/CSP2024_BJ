#include<bits/stdc++.h>
#define int long long
#define int long long
using namespace std;
int n,m;
int a[100005];
int c[100005];
char s[50005];
int d[20][50005];
int f[20][100005];
int rd;
int T;
vector<int>v;
int get_rd(int x){
    int nn=0;
    while((1<<nn)<x)nn++;
    return nn;
}
int x[4];
int get_ans(int w,int hh){
    int tt=get_rd(w);
    //cout<<tt<<endl;
    for(int i=1;i<=(1<<tt);i++)f[0][i]=i;
    for(int k=1;k<=tt;k++){
        for(int i=1;i<=1<<(tt-k);i++){
              //  cout<<k<<" "<<i<<endl;
            int s1,s2;
            s1=f[k-1][i*2-1],s2=f[k-1][i*2];
            if(d[k][i]==0){
                if(s1<=w){
                    if(a[s1]>=k)f[k][i]=s1;
                    else f[k][i]=s2;
                }
                else{
                    if(s2==hh)f[k][i]=s2;
                    else f[k][i]=s1;
                }
            }
            if(d[k][i]==1){
                if(s2<=w){
                    if(a[s2]>=k)f[k][i]=s2;
                    else f[k][i]=s1;
                }
                if(s2>w){
                    if(s1==hh)f[k][i]=hh;
                    else f[k][i]=s2;
                }
            }
        }
    }
    //cout<<f[tt][1]<<endl;
    if(f[tt][1]==hh)return hh;
    //cout<<f[tt][1]<<endl;
    else return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
//cout<<n<<m<<endl;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>c[i];
    rd=get_rd(n);
    for(int i=1;i<=rd;i++){
            cin>>s+1;
        for(int j=1;j<=(1<<(rd-i));j++){
            d[i][j]=s[j]-'0';
        }
    }
    cin>>T;
    while(T--){
        int anser=0;
        for(int i=0;i<=3;i++)cin>>x[i];
        for(int i=1;i<=n;i++)a[i]=a[i]^(x[i%4]);
        for(int i=1;i<=m;i++){
            int ans=0;
            int tt=get_rd(c[i]);
            for(int i=1;i<=(1<<tt);i++)ans+=(get_ans(c[i],i));
            anser^=(i*ans);
        }
        cout<<anser<<"\n";
    }
}
