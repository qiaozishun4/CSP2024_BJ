#include <bits/stdc++.h>
using namespace std;
char l[1001][1001];
int a[1001][1001]={};
int t,x,y,n,m,d,k,v=0;
void zou(){
    if(d==0){
        if(l[x][y+1]=='.')
            y++;
        else
            d=(d+1)%4;
    }
    else if(d==1){
        if(l[x+1][y]=='.')
            x++;
        else
            d=(d+1)%4;
    }
    else if(d==2){
        if(l[x][y-1]=='.')
            y--;
        else
            d=(d+1)%4;
    }
    else{
        if(l[x-1][y]=='.')
            x--;
        else
            d=(d+1)%4;
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    for(int p=1;p<=t;p++){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>l[i][j];
        for(int i=0;i<k;i++){
            a[x][y]=1;
            zou();
            a[x][y]=1;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(l[i][j]=='.'&&a[i][j]==1)
                    a[i][j]=0,v++;
        printf("%d\n",v);
    }
    return 0;
}
