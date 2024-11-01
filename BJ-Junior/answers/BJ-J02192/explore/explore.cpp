#include<bits/stdc++.h>
using namespace std;
long long x,y,k,m,n,d,cot=1,cc,sum[10];
int a[1010][1010];
char t;
int dfs(){
    //printf("%d %d %d %d ",x,y,d,k);
    if(d==0&&a[x][y+1]&&y+1<=m){
        y++;
        cot++;
    }
    else if(d==1&&a[x+1][y]&&x+1<=n){
        x++;
        cot++;
    }
    else if(d==2&&a[x][y-1]&&y-1>=1){
        y--;
        cot++;
    }
    else if(d==3&&a[x-1][y]&&x-1>=1){
        x--;
        cot++;
    }
    else d=(d+1)%4;
    k--;
    if(k==0){
        return 0;
    }
    else    return dfs();
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>cc;
    for(int s=1;s<=cc;s++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>t;
                if(t=='.'){
                    a[i][j]=1;
                }
                else    a[i][j]=0;
            }
        }
        cot=0;
        dfs();
        sum[s]=cot;
        //printf("%d ",cot);
    }
    for(int i=1;i<=cc;i++){
        cout<<sum[i]<<endl;
    }
    return 0;
}
