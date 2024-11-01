#include <bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int t,n,m,k,x,y,d;
int v[109][109];
int sum=1;
string s[N];
void dfs(int xx,int yy,int fx){
    if(k==1){
        return ;
    }
    int flag=0;
    v[xx][yy]=1;
    for(int i=1;i<=4;i++){
        if(fx==0){
            if(!v[xx][yy+1]&&s[xx-1][yy]=='.'){
                    flag=1;
                k--;
                sum++;
                dfs(xx,yy+1,0);
            }
        }else if(fx==1){
            if(!v[xx+1][yy]&&s[xx][yy-1]=='.'){
                    flag=1;
                k--;
                sum++;
                dfs(xx,yy+1,1);
            }else{
                fx=2;
            }
        }else if(fx==2){
            if(!v[xx][yy-1]&&s[xx-1][yy-1]=='.'){
                    flag=1;
                k--;
                sum++;
                dfs(xx,yy+1,2);
            }
        }else{
            if(!v[xx-1][yy]&&s[xx-2][yy-1]=='.'){
                    flag=1;
                k--;
                sum++;
                dfs(xx,yy+1,3);
            }
        }
        fx=fx+1;
        fx=fx%4;
    }
    if(!flag){
        k--;
    }
}
int main(){

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>t;
    while(t--){
        sum=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        dfs(x,y,d);
        cout<<sum<<endl;
    }
    return 0;
}
