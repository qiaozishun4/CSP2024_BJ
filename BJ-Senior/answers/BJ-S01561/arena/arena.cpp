#include<bits/stdc++.h>
using namespace std;
const int N=3e5,inf=INT_MAX;
typedef long long ll;
int n,m,_a[N],a[N],x[4],c[N],l[N],r[N];
bool d[30][N];
inline void solve(){
    cin>>x[0]>>x[1]>>x[2]>>x[3];
    for(int i=1;i<=n;i++)a[i]=_a[i]^x[i%4];
    for(int i=1;i<=n;i++)cerr<<a[i]<<' ';cerr<<endl;
    for(int i=1;i<=m;i++){
        int k=0;
        while(1<<k<c[i])k++;
        int num=(1<<k+1);
        for(int j=0;j<num;j++)l[j]=0,r[j]=inf;
        for(int z=1<<k;z<(1<<k)+c[i];z++)l[z]=r[z]=a[z-(1<<k)+1];
        for(int j=1;j<=k-1;j++){
            for(int z=(1<<k-j-1);z<(1<<k-j);z++){
                int ls=z<<1,rs=z<<1|1;
                if(d[j][z]==0){
                    if(r[ls]>=j)l[z]=min(j,l[rs]),r[z]=max(r[ls],r[rs]);
                    else l[z]=l[rs],r[z]=r[rs];
                }
                else{
                    if(r[rs]>=j)l[z]=min(j,l[ls]),r[z]=max(r[ls],r[rs]);
                    else l[z]=l[ls],r[z]=r[ls];
                }
            }
        }
        for(int z=0;z<16;z++)cerr<<l[z]<<' '<<r[z]<<endl;
        cerr<<"JJJ"<<endl;
    }
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>_a[i];
    for(int i=1;i<=m;i++)cin>>c[i];
    int KK=0;
    while(1<<KK<n)KK++;
    for(int i=1;i<=KK;i++){
        ll tmp;cin>>tmp;
        for(int j=0;j<1<<KK-i;j++)d[i][(1<<KK-i)-1-j]=tmp>>j&1;
    }
    for(int i=0;i<=3;i++){
        for(int j=0;j<4;j++)cout<<d[i][j]<<' ';
        cout<<endl;
    }
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
