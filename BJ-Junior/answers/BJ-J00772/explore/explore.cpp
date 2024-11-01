#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN=1e5+5;
const ll MOD=1e9+7;
char a[1010][1010];
ll b[1010][1010];
string s;
ll sum=1,xd[10]={0,1,0,-1},yd[10]={1,0,-1,0},n,m;
void dfs(ll now,ll x,ll y,ll d){
    if(now<=0){
        return;
    }
    ll xx=x+xd[d];
    ll yy=y+yd[d];
    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]!='x'){
        if(b[xx][yy]==0){
            sum+=1;
            b[xx][yy]=1;
        }
        //cout<<"x="<<xx<<" y="<<yy<<" sum="<<sum<<endl;
        dfs(now-1,xx,yy,d);
        //cout<<xx<<" "<<yy<<endl;
        return;
    }
    else{
        dfs(now-1,x,y,(d+1)%4);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ll t,k,x,y,d;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        //cout<<n<<" "<<m<<" "<<k<<endl;
        cin>>x>>y>>d;
        for(ll i=1;i<=n;i++){
            cin>>s;
            //cout<<i<<" "<<n<<endl;
            for(ll j=1;j<=m;j++){
                //s[j-1]='1';
                //cout<<i<<" "<<j<<endl;
                //cout<<i<<" "<<"meier";
                a[i][j]=s[j-1];
                //cout<<j<<" ";
            }
        }
        for(ll i=1;i<=1005;i++){
            for(ll j=1;j<=1005;j++) b[i][j]=0;
        }
        sum=1;
        b[x][y]=1;
        dfs(k,x,y,d);
        cout<<sum<<endl; 
    }
    return 0;
}