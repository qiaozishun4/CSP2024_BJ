#include<iostream>
#include<cstdio>
using namespace std;
char mp[1005][1005];
bool a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int cnt=1;
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        a[x][y]=1;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>mp[j][k];
            }
        }
        for(int j=1;j<=k;j++){
            switch(d){
                case 0:
                    if(y+1<=m && mp[x][y+1]!='x'){
                        y=y+1;
                        if(!a[x][y]){
                            a[x][y]=1;
                            cnt++;
                        }
                    }
                    else{
                        d=(d+1)%4;
                    }
                    break;
                case 1:
                    if(x+1<=n && mp[x+1][y]!='x'){
                        x=x+1;
                        if(!a[x][y]){
                            a[x][y]=1;
                            cnt++;
                        }
                    }
                    else{
                        d=(d+1)%4;
                    }
                    break;
                case 2:
                    if(y-1>=1 && mp[x][y-1]!='x'){
                        y=y-1;
                        if(!a[x][y]){
                            a[x][y]=1;
                            cnt++;
                        }
                    }
                    else{
                        d=(d+1)%4;
                    }
                    break;
                case 3:
                    if(x-1>=1 && mp[x-1][y]!='x'){
                        x=x-1;
                        if(!a[x][y]){
                            a[x][y]=1;
                            cnt++;
                        }
                    }
                    else{
                        d=(d+1)%4;
                    }
                    break;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}