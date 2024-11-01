#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
struct op{
    int id1,id2;
}ji[maxn][maxn];
int T,n,k,q,l1[maxn],l2[maxn],a[maxn][maxn],r,c;
//int mx;
bool dfs(int x,int y,int le){
    //cout<<r<<" "<<c<<endl<<x<<" "<<y<<" "<<a[x][y]<<" "<<le<<endl;
    if(l1[x] == y)return false;
    if(le == r){
        for(int i = y+1 ; i < min(y+k,l1[x]+1) ; i++){
            if(a[x][i] == c)return true;
        }
        return false;
    }
    for(int i = y+1 ; i < min(y+k,l1[x]+1) ; i++){
        int v = a[x][i];
        for(int j = 1 ; j <= l2[v] ; j++){
            if(ji[v][j].id1 == x)continue;
            if(dfs(ji[v][j].id1,ji[v][j].id2,le+1))return true;
        }
    }
    return false;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        memset(l2,0,sizeof(l2));
        for(int i = 1 ; i <= n ; i++){
            cin>>l1[i];
            for(int j = 1 ; j <= l1[i] ; j++){
                cin>>a[i][j];
                //mx = max(mx,a[i][j]);
                ji[a[i][j]][++l2[a[i][j]]].id1 = i;
                ji[a[i][j]][l2[a[i][j]]].id2 = j;
            }
        }
        //for(int i = 1 ; i <= mx ; i++)cout<<i<<" "<<l2[i]<<endl;
        for(int kkk = 1 ; kkk <= q ; kkk++){
            cin>>r>>c;
            bool k2 = 1;
            for(int i = 1 ; i <= l2[1] ; i++){
                if(dfs(ji[1][i].id1,ji[1][i].id2,1)){cout<<1<<endl;k2 = 0;break;}
            }
            if(k2)cout<<0<<endl;
            ///cout<<endl<<endl<<endl;
        }
    }
    return 0;
}
