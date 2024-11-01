#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[1004][1004];
int cnt[1004][1004];
int t;
void re(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt[i][j]=0;
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    int k;
    int x,y,d;
    for(int i=1;i<=t;i++){
        re();
        int ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int q=1;q<=m;q++){
                cin>>a[j][q];
            }
        }
        cnt[x][y]=1;
        //cout<<"first:"<<ans<<endl;
        //cout<<"   "<<x<<" "<<y<<endl;
        while(k--){
            if(d==0){
                if(y+1<=m && y+1>=1 && x<=n && x>=1 && a[x][y+1]=='.'){
                    x=x;
                    y=y+1;
                    if(cnt[x][y]==0){
                        ans++;
                        cnt[x][y]=1;
                    }
                }else {
                    d=(d+1)%4;
                }
                //cout<<ans<<endl;
                //cout<<"   "<<x<<" "<<y<<endl;
                continue;
            }
            if(d==1){
                if(y<=m && y>=1 && x+1<=n && x+1>=1 && a[x+1][y]=='.'){
                    x=x+1;
                    y=y;
                    if(cnt[x][y]==0){
                        ans++;
                        cnt[x][y]=1;
                    }

                }
                else {
                    d=(d+1)%4;
                }

                continue;
            }
            if(d==2){
                if(y-1<=m && y-1>=1 && x<=n && x>=1 && a[x][y-1]=='.'){
                    x=x;
                    y=y-1;
                    if(cnt[x][y]==0){
                        ans++;
                        cnt[x][y]=1;
                    }

                }else {
                    d=(d+1)%4;
                }

                continue;
            }
            if(d==3){
                if(y<=m && y>=1 && x-1<=n && x-1>=1 && a[x-1][y]=='.'){
                    x=x-1;
                    y=y;
                    if(cnt[x][y]==0){
                        ans++;
                        cnt[x][y]=1;
                    }

                }else {
                    d=(d+1)%4;
                }
                continue;
            }
        }
            cout<<ans<<endl;
    }
    return 0;
}
//zhuwomengdui!!!rp++
