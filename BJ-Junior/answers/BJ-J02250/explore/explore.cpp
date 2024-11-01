#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d0,kl=0;
    cin>>t;
    int answer[t+1];
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k>>x>>y>>d0;
        string a1;
        char a[n+1][m+1],b[n+1][m+1];
        for(int j=1;j<=n;j++){
            cin>>a1;
            for(int j1=1;j1<=m;j1++){
                a[j][j1]=a1[j1-1];
                b[j][j1]=0;
            }
        }
        int num=0;
        for(int j2=1;j2<=k;j2++){
            b[x][y]=1;
            if(d0==0&&a[x][y+1]=='.'){
                y=y+1;
            }else if(d0==1&&a[x+1][y]=='.'){
                x+=1;
            }else if(d0==2&&a[x][y-1]=='.'){
                y-=1;
            }else if(d0==3&&a[x-1][y]=='.'){
                x-=1;
            }else{
                d0=(d0+1)%4;kl+=1;
            }
            b[x][y]=1;
        }
        for(int p=1;p<=n;p++){
            for(int p1=1;p1<=m;p1++){
                if(b[p][p1]==1){
                    num+=1;
                }
            }
        }
        answer[i]=num;
    }

    for(int i=1;i<=t;i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}

