#include<bits/stdc++.h>
using namespace std;
bool vis[5][14];
char a[105][3];
int n,m,cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
        if(a[i][1]=='S'){
            if(a[i][2]=='A'){
                vis[1][1]=1;
            }else if(a[i][2]>='2' && a[i][2]<='9'){
                vis[1][a[i][2]-'0']=1;
            }else if(a[i][2]=='T'){
                vis[1][10]=1;
            }else if(a[i][2]=='J'){
                vis[1][11]=1;
            }else if(a[i][2]=='Q'){
                vis[1][12]=1;
            }else{
                vis[1][13]=1;
            }
        }else if(a[i][1]=='H'){
            if(a[i][2]=='A'){
                vis[2][1]=1;
            }else if(a[i][2]>='2' && a[i][2]<='9'){
                vis[2][a[i][2]-'0']=1;
            }else if(a[i][2]=='T'){
                vis[2][10]=1;
            }else if(a[i][2]=='J'){
                vis[2][11]=1;
            }else if(a[i][2]=='Q'){
                vis[2][12]=1;
            }else{
                vis[2][13]=1;
            }
        }else if(a[i][1]=='C'){
            if(a[i][2]=='A'){
                vis[3][1]=1;
            }else if(a[i][2]>='2' && a[i][2]<='9'){
                vis[3][a[i][2]-'0']=1;
            }else if(a[i][2]=='T'){
                vis[3][10]=1;
            }else if(a[i][2]=='J'){
                vis[3][11]=1;
            }else if(a[i][2]=='Q'){
                vis[3][12]=1;
            }else{
                vis[3][13]=1;
            }
        }else{
            if(a[i][2]=='A'){
                vis[4][1]=1;
            }else if(a[i][2]>='2' && a[i][2]<='9'){
                vis[4][a[i][2]-'0']=1;
            }else if(a[i][2]=='T'){
                vis[4][10]=1;
            }else if(a[i][2]=='J'){
                vis[4][11]=1;
            }else if(a[i][2]=='Q'){
                vis[4][12]=1;
            }else{
                vis[4][13]=1;
            }
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(vis[i][j]==0){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
