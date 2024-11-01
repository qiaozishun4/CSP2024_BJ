#include<bits/stdc++.h>
using namespace std;
int ans[1000][1000];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int q;
    cin>>q;
    for(int l=1;l<=q;l++){
        int n,m,k,x,y,d,num=;
        cin>>n>>m>>k>>x0>>y0>>d0;
        memset(ans,0,sizeof(ans));
        ans[x][y]=1;
        int mp[n+1][m+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char qk;
                cin>>qk;
                mp[i][j]=qk;
            }
        }
        for(int i=1;i<=k;i++){
            if(d==0){
                if(y+1>n || mp[x][y+1]=='x') d=(d+1)%4;
                else {y+=1;ans[x][y]=1}

    }
            else if(d==1){
                if(x+1>m || mp[x+1][y]=='x') d=(d+1)%4;
                else {x+=1;ans[x][y]=1}
    }
            else if(d==3){
                if(x-1<1|| mp[x-1][y]=='x') d=(d+1)%4;
               else {x-=1;ans[x][y]=1}
    }
            else if(d==2){
        if(y-1<1|| mp[x][y-1]=='x') d=(d+1)%4;
        else {y-=1;ans[x][y]=1}
    }
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j]==1) num++;
        }
    }
        cout<<num<<endl;


    }


    fclose(stdin);
   fclose(stdout);
   return 0;

}
