#include<bits/stdc++.h>
#define ll long long
#define lson pos<<1
#define rson pos<<1|1
using namespace std;
const int maxn=1e5+10;
const ll mod=998244353;
const ll inf=1e9+10;
ll n,m,t,l,ans;
double v;
int c[maxn],a[maxn],load[maxn],X[10];
int def[20][maxn],winner[20][maxn];
char s[maxn<<1];

struct node{
    double d,v,a;
}q[maxn];

struct line{
    int id,checker,opt;
}p[maxn*2];

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%lld%lld",&n,&m);

    for(int i=1;i<=n;i++){
        scanf("%d",&load[i]);
    }

    for(int i=1;i<=m;i++){
        scanf("%d",&c[i]);
    }
    int k=1;
    while((1<<k)<n) k++;
    for(int i=1;i<=k;i++){
        scanf("%s",s+1);
        for(int j=1;j<=(1<<(k-i));j++){
            def[i][j]=s[j]-'0';
      //      cout<<i<<" "<<j<<" "<<def[i][j]<<endl;
        }
    }
    scanf("%lld",&t);

    while(t--){
        for(int i=0;i<4;i++) scanf("%d",&X[i]);
        for(int i=1;i<=n;i++) a[i]=load[i]^X[i%4],winner[0][i]=i;

        int cp=n;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=min(cp,1<<(k-i+1));j+=2){
                if(def[i][(j+1)>>1]==0){
                  //  cout<<i<<" "<<j<<" "<<winner[i-1][j]<<endl;
                    if(a[winner[i-1][j]]>=i) winner[i][(j+1)>>1]=winner[i-1][j];
                    else winner[i][(j+1)>>1]=winner[i-1][j+1];
                }
                else if(j<cp){
                  //  cout<<t<<" "<<i<<" "<<j<<" "<<winner[i-1][j+1]<<endl;
                    if(a[winner[i-1][j+1]]>=i) winner[i][(j+1)>>1]=winner[i-1][j+1];
                    else winner[i][(j+1)>>1]=winner[i-1][j];
                }
            }
            cp>>=1;
        }

        for(int i=1;i<=m;i++){
            int tmp=1,round=0;
            while(tmp<c[i]) tmp<<=1,round++;
            if(tmp==c[i]){
                printf("%d\n",winner[round][1]);
            }
        }
    }

   fclose(stdin);
    fclose(stdout);
    return 0;
}
