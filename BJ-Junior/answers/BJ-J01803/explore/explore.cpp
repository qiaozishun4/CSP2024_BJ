#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,k1;
int d1;
int arr[1005][1005];
int x1[4]={0,1,0,-1};
int y1[4]={1,0,-1,0};
void dfs(int x,int y,int k1){
    if(x>n||y>m||k1>=k||arr[x][y]>=1||x<1||y<1){
        return;
    }
    arr[x][y]=2;
    if(d1>=4){
        d1=0;
    }
    return dfs(x+x1[d1],y+y1[d1],k1+1);
    d1+=1;
    return dfs(x+x1[d1],y+y1[d1],k1+1);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int x0,y0;
    int shu;
    cin>>shu;
    for(int c=0;c<shu;c++){
        cin>>m>>n>>k;
        cin>>x0>>y0>>d1;
        char ch;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>ch;
                if(ch=='x'){
                    arr[i][j]==1;
                }else if(ch=='.'){
                    arr[i][j]==0;
                }
            }
        }
        int cnt=0;
        dfs(x0,y0,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j]==2){
                    cnt++;
                }
            }
        }
    cout<<cnt<<endl;
    }
    return 0;
}