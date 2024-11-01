#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("explpre.in","r",stdin);
freopen("explore.out","w",stdout);
int T;
int dan[6]={0,0,0,0,0,0};
cin>>T;
for(int sy=0;sy<T;sy++){
    int x,y,d,n,m,k;
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    char a[2005][2005];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<k;i++){
        int xx,xy;
        if(d==0){
            xx=x;
        xy=y+1;
        }
        if(d==1){
         xy=y;
         xx=x+1;
        }
        if(d==2){
            xx=x;
            xy=y-1;
        }
        if(d==3){
            xx=x-1;
            xy=y;
        }
        if(a[xx][xy]=='.'&&xx<=n&&xy<=n){
                a[xx][xy]='1';
                dan[sy]++;
            x=xx;
            y=xy;
        }else if(a[xx][xy]=='1'&&xx<=n&&xy<=n){
        x=xx;
        y=xy;
        }else{
        d=(d+1)%4;
        }
    }
}
for(int i=0;i<T;i++){
    cout<<dan[i]<<endl;
}

return 0;
}
