#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int si[2000][2000];  //X=-1,vis=1,none=0;
long long n,m,d;
long long x,y,k;
long long cnt;
long long newx,newy;
int ix[4]={0,1,0,-1};
int iy[4]={1,0,-1,0};

void zuo(){
    string s;
    cin>>n>>m>>k;
    cin>>x>>y;
    cin>>d;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='x'){
                si[i][j+1]=-1;
            }else{
                si[i][j+1]=0;
            }
        }
    }
    cnt=1;
    si[x][y]=1;
    for(int i=1;i<=k;i++){
        newx=x+ix[d];
        newy=y+iy[d];
        if(newx>n||newx<1||newy>m||newy<1||si[newx][newy]==-1){
            d=(d+1)%4;
        }else{
            if(si[newx][newy]==0){
                cnt++;
            }
            si[newx][newy]=1;
            x=newx;
            y=newy;
        }

    }
    cout<<cnt<<endl;
}



int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        zuo();
    }
    return 0;
}
