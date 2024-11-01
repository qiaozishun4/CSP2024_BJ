#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,,num=0,mp[1002][1002];
bool check(int x,int y){
    return((x>=1)&&(x<=n)&&(y>=1)&&(y<=m)&&(mp[x][y]=='.'))
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;i++){
                cin>>mp[i][j];
            }
        }
        num=1;
        for(int i=0;i<k;i++){
            if(d==0){
                if(check(x,y+1)){
                    y=y+1;
                    num++;
                }
                else d=(d+1)%4;
            }
            else if(d==1){
                if(check(x+1,y)){
                    x=x+1;
                    num++;
                }
                else d=(d+1)%4;
            }
            else if(d==2){
                if(check(x,y-1)){
                    y=y-1;
                    num++;
                }
                else d=(d+1)%4;
            }
            else {
                if(check(x-1,y)){
                    x=x-1;
                    num++;
                }
                else d=(d+1)%4;
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
