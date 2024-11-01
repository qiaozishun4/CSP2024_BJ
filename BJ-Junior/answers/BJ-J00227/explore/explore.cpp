#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool ma[1100][1100];
bool mp[1100][1100];
ll m,n,sum,t,d0,k,xx,yy,num1,num2;
void DFS(ll x,ll y,ll d,ll p){
    //cout<<x<<' '<<y<<' '<<d<<' '<<p<<'\n';
    if(p>k)return ;
    mp[x][y]=true;
    num1=0,num2=0;
    if(d==0)num2=1;
    else if(d==1)num1=1;
    else if(d==2)num2=-1;
    else if(d==3)num1=-1;
    if(ma[x+num1][y+num2]){
        DFS(x+num1,y+num2,d,p+1);
    }
    else{
        DFS(x,y,(d+1)%4,p+1);
    }
    return ;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>xx>>yy>>d0;
        //cout<<n<<' '<<m<<' '<<k<<' '<<xx<<' '<<yy<<' '<<d0<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='.')ma[i][j]=true;
            }
        }
        DFS(xx,yy,d0,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j])sum++;
                mp[i][j]=false;
                ma[i][j]=false;
            }
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}
