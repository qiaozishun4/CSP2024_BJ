#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    char e;
    int T,n,m,k,x,y,d,sum=0;
    bool mymap[1005][1005][2]={};
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int o=1;o<=m;o++){
                cin>>e;
                if(e!='x'){
                    mymap[j][o][0]=1;
                }
            }
        }
        mymap[x][y][1]=1;
        for(int j=1;j<=k;j++){
            if(d==0){
                if(mymap[x][y+1][0]==1){
                    mymap[x][++y][1]=1;
                    continue;
                }
            }else if(d==1){
                if(mymap[x+1][y][0]==1){
                    mymap[++x][y][1]=1;
                    continue;
                }
            }else if(d==2){
                if(mymap[x][y-1][0]==1){
                    mymap[x][--y][1]=1;
                    continue;
                }
            }else if(mymap[x-1][y][0]==1){
                    mymap[--x][y][1]=1;
                    continue;
            }
            d++;
            if(d==4){
                d=0;
            }
        }
        for(int j=1;j<=n;j++){
            for(int o=1;o<=m;o++){
                if(mymap[j][o][1]){
                    sum++;
                    mymap[j][o][1]=0;
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int o=1;o<=m;o++){
                mymap[j][o][0]=0;
            }
        }
        cout<<sum<<endl;
        sum=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
