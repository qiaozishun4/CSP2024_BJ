#include<iostream>
using namespace std;
int t;
char a[1005][1005];
long long p[1005][1005],sum=0;
void dfs(int s,int b,int c,int x2,int y2,int z){
    for(int i=1;i<=c;i++){
        if(z==0&&a[x2][y2+1]=='.'&&y2+1<=b){
            p[x2][y2]=1;
            y2+=1;
        }else if(z==1&&a[x2+1][y2]=='.'&&x2+1<=s){
            p[x2][y2]=1;
            x2+=1;
        }else if(z==2&&a[x2][y2-1]=='.'&&y2-1<=b){
            p[x2][y2]=1;
            y2-=1;
        }else if(z==3&&a[x2-1][y2]=='.'&&x2-1<=s){
            p[x2][y2]=1;
            x2-=1;
        }else{
            z=(z+1)%4;
        }
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t!=0){
        int n,m,k,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        p[x][y]==1;
        dfs(n,m,k,x,y,d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i][j]==1){
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
        sum=0;
        t--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
