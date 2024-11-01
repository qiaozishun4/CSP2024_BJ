#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        int p[1001][1001];
        for(int j=1;j<=n;j++){
            string s;
            cin>>s;
            for(int l=1;l<=s.size();l++){
                if(s[l-1]=='x') p[j][l]=1;
                else p[j][l]=0;
            }
        }
        int arrive[1001][1001];
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                arrive[j][l]=0;
                arrive[x][y]=1;
            }
        }
        int tot=1;
        while(k!=0){
            if(d==0){
                if(p[x][y+1]==0&&0<y+1&&y+1<=m){
                    y=y+1;
                    if(arrive[x][y]==0){
                        tot+=1;
                        arrive[x][y]=1;
                    }
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==1){
                if(p[x+1][y]==0&&0<x+1&&x+1<=n){
                    x=x+1;
                    if(arrive[x][y]==0){
                        tot+=1;
                        arrive[x][y]=1;
                    }
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==2){
                if(p[x][y-1]==0&&0<y-1&&y-1<=m){
                    y=y-1;
                    if(arrive[x][y]==0){
                        tot+=1;
                        arrive[x][y]=1;
                    }
                }
                else{
                    d=(d+1)%4;
                }
            }
            else{
                if(p[x-1][y]==0&&0<x-1&&x-1<=n){
                    x=x-1;
                    if(arrive[x][y]==0){
                        tot+=1;
                        arrive[x][y]=1;
                    }
                }
                else{
                    d=(d+1)%4;
                }
            }
            k--;
            }
        cout<<tot<<endl;
        }
    return 0;
}
