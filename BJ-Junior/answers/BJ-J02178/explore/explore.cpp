#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k;
int xi,yi,di;
char mpc[1005][1005]={};
int mp[1005][1005]={};
int forwd(int x,int y){
    if(mp[x][y]!=0){
        return true;
    }
    return false;
}
int main(){
    cin>>T;
    for(int ti=1;ti<=T;ti++){
        cin>>n>>m>>k;
        cin>>xi>>yi>>di;
        for(int x=1;x<=n;x++){
            for(int y=1;y<=m;y++){
                cin>>mpc[x][y];
                if(mpc[x][y]=='.'){
                    mp[x][y]=1;
                }
                if(mpc[x][y]=='x'){
                    mp[x][y]=0;
                }
            }
        }
        mp[xi][yi]=2;
        for(int i=0;i<k;i++){
            if(di==0 && forwd(xi,yi+1)){
                yi+=1;
                mp[xi][yi]=2;
            }
            else if(di==1 && forwd(xi+1,yi)){
                xi+=1;
                mp[xi][yi]=2;
            }
            else if(di==2 && forwd(xi,yi-1)){
                yi-=1;
                mp[xi][yi]=2;
            }
            else if(di==3 && forwd(xi-1,yi)){
                xi-=1;
                mp[xi][yi]=2;
            }
            else{
                if(di==3)
                    di=0;
                else di++;
            }
        }
        int sum=0;
        for(int x=1;x<=n;x++){
            for(int y=1;y<=m;y++){
                if(mp[x][y]==2){
                    sum++;
                }
                mpc[x][y]=' ';
                mp[x][y]=0;
            }
        }
        cout<<sum<<endl;
    }

}