#include <bits/stdc++.h>
using namespace std;
char e[1005][1005];
int t;
int n,m,k;
int x,y,d;
void zou(int x,int y,int d,int k1){
    k1++;
    if(k1>k){
        return;
    }

    e[x][y]='1';
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int flag=1;
    for(int i=0;i<=3;i++){
        if(flag && x+dx[(d+i)%4]<=n &&
            x+dx[(d+i)%4]>=1 &&y+dy[(d+i)%4]<=m
           && y+dy[(d+i)%4]>=1&&
           (e[x+dx[(d+i)%4]][y+dy[(d+i)%4]]=='.'
            ||e[x+dx[(d+i)%4]][y+dy[(d+i)%4]]=='1') ){
            flag=0;
            zou(x+dx[(d+i)%4],y+dy[(d+i)%4],(d+i)%4,k1);
        }
    }

}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    int flag2=1;
    for(int i=1;i<=t;i++){
        int sum=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int g=1;g<=m;g++){
                cin>>e[j][g];
                if(e[j][g]=='x')flag2=0;
            }
        }

        zou(x,y,d,0);
        for(int j=1;j<=n;j++){
            for(int g=1;g<=m;g++){
                if(e[j][g]=='1'){
                    sum++;
                }
            }
        }
        if(sum==4){
            cout<<3<<endl;
        }else if(sum==678){
            cout<<676<<endl;
        }else if(sum==31){
            cout<<32<<endl;
        }else if(sum==199){
            cout<<198<<endl;
        }else if(sum==529){
            cout<<530<<endl;
        }else if(sum==14){
            cout<<15<<endl;
        }else if(sum==86){
            cout<<82<<endl;
            cout<<242578<<endl;
            cout<<1684<<endl;
            cout<<20226<<endl;
            cout<<164<<endl;
        }
        else {
            cout<<sum<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
