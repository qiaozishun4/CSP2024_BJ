
#include<bits/stdc++.h>
using namespace std;
int w;
char a;int n,m,k,x,y,d;
int mx[4]={1,0,-1,0};
int my[4]={0,-1,0,1};
int b[2000][2000];
int  DFS(int x,int y,int d,int k,int w){
    b[x][y]=1;
    if(k==0){
        return w;
    }
    if(x+mx[d]>n||x+mx[d]<=0||y+my[d]<=0||y+my[d]>m||b[x+mx[d]][y+my[d]]==1){
        return max(DFS(x,y,(d+1)%4,k-1,w),DFS(x,y,(d-1)%4,k-1,w));
    }
    else{
        return DFS(x,y,(d)%4,k-1,w+1);
    }
}
int main()
{
  // freopen("explore.in","r",stdin);
   //freopen("explore.out","w",stdout);
    cin>>w;
    while(w--){

        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a;
                if(a=='.'){
                    b[i][j]=0;
                }
                else{
                    b[i][j]=1;
                }
            }
        }

        cout<<DFS(x,y,(d)%4,k,1)<<'\n';
    }
    return 0;
}
