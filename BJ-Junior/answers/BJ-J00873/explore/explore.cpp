#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
bool b[1005][1005];
long long anmm;
int d;
char a[1005][1005];
void dfs(int xx,int yy,int ans,int num,int anm,int k){
    for(int i=0;i<k;i++){
            i--;
        if(d==0&&b[xx][yy+1]){
        b[xx][yy]==false;
        ans++;
        dfs(xx,yy+1,ans,num,anm,k);
        ans--;
        b[xx][yy]=true;
    }
    if(d==1&&b[xx+1][yy]){
        b[xx][yy]==false;
        ans++;
        dfs(xx+1,yy,ans,num,anm,k);
        ans--;
        b[xx][yy]=true;

    }
    if(d==2&&b[xx][yy-1]){
        b[xx][yy]==false;
        ans++;
        dfs(xx,yy-1,ans,num,anm,k);
        ans--;
        b[xx][yy]=true;
    }
    if(d==3&&b[xx-1][yy]){
        b[xx][yy]==false;
        ans++;
        dfs(xx,yy+1,ans,num,anm,k);
        ans--;
        b[xx][yy]=true;

    }

    if((b[xx][yy+1]==false)&&(b[xx+1][yy]==false)&&(b[xx][yy-1]==false)&&(b[xx-1][yy]==false)){
        if(ans>=num&&anm>=num){
            anm-=num;
        }
        num=max(ans,num);
        anm+=num;
        anmm=anm;
        k++;
        cout<<anm<<" "<<1<<endl;
        b[xx][yy]==true;

        return;
    }
    d++;
    d%=4;
    k--;
    }

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]=='x'){
                    b[i][j]=false;
                }else{
                    b[i][j]=true;
                }
            }
        }
        dfs(x,y,0,0,0,k);
        cout<<anmm<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]==' ';
                b[i][j]==false;
            }
        }
    }
    return 0;
}
