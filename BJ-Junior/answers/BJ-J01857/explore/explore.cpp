#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>

using namespace std;
bool xx[1005][1005];
bool visited[5][1005][1005];
int t,n,m;
string s;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int a=0;a<t;a++){
        int k=0,x=0,y=0,d=0,ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=0;i<n;i++){
            s="";
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='x'){
                    xx[i][j]=true;
                }
                else{
                    xx[i][j]=false;
                }
            }
        }
        visited[a][x][y]=true;
        for(int i=0;i<k;i++){
            if(d==0){
                if((y+1<m)&&(!xx[x][y+1])){
                    y+=1;
                    visited[a][x][y]=true;
                }
                else{
                    d++;
                }
            }
            else if(d==1){
                if((x+1<n)&&(!xx[x+1][y])){
                    x+=1;
                    visited[a][x][y]=true;
                }
                else{
                    d++;
                }
            }
            else if(d==2){
                if((y-1>=0)&&(!xx[x][y-1])){
                    y-=1;
                    visited[a][x][y]=true;
                }
                else{
                    d++;
                }
            }
            else if(d==3){
                if((x-1>=0)&&(!xx[x-1][y])){
                    x-=1;
                    visited[a][x][y]=true;
                }
                else{
                    d++;
                }
            }
            d%=4;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[a][i][j]){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}