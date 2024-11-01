#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define int long long
using namespace std;
int n,m,loc[100010],l,v;
bool choose[100010];
struct car{
    int d,a,v;
}cars[100010];
bool a=true,b=true,c=true;
bool exceed[100010];
void solve(){
    memset(exceed,0,sizeof(exceed));
    memset(choose,0,sizeof(choose));
    a=b=c=true;
    cin>>n>>m>>l>>v;
    for(int i=1;i<=n;i++){
        cin>>cars[i].d>>cars[i].v>>cars[i].a;
        if(cars[i].a>0)a=false,c=false;
        if(cars[i].a<0)a=false,b=false;
        if(cars[i].a==0)b=false,c=false;
    }
    for(int i=1;i<=m;i++)cin>>loc[i];
    sort(loc+1,loc+m+1);
    int ans1=0;
    for(int i=1;i<=m;i++){
        if((a||b)&&i!=m)continue;
        for(int j=1;j<=n;j++){
            if(cars[j].d<=loc[i]){
                int speed=cars[j].v*cars[j].v+2*cars[j].a*(loc[i]-cars[j].d);
                if(speed>=0&&sqrt(speed)-v>1e-8)exceed[j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++)ans1+=exceed[i];
    cout<<ans1<<" ";
    if(a||b){
        cout<<m-(bool)(ans1)<<endl;
        return ;
    }
    int ans=0,cnt=0,tmp=0;
    for(int subset=0;subset<(1LL<<m);subset++){
        memset(choose,0,sizeof(choose));
        tmp=0;
        for(int j=0;j<m;j++){
            if((subset>>j)&1){
                choose[j+1]=true;
                tmp++;
            }
        }
        cnt=0;
        memset(exceed,0,sizeof(exceed));
        for(int i=1;i<=m;i++){
            if(!choose[i]){
               
                for(int j=1;j<=n;j++){
                    if(cars[j].d<=loc[i]){
                        double speed=cars[j].v*cars[j].v+2*cars[j].a*(loc[i]-cars[j].d);
                        if(speed>=0&&sqrt(speed)-v>1e-8)exceed[j]=true;
                    }
                }
                
                
            }
        }
        for(int i=1;i<=n;i++)cnt+=exceed[i];
        if(cnt==ans1)ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}