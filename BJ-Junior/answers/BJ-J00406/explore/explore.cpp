#include<bits/stdc++.h>
using namespace std;
int ri(int a){
    if(a==3){
        return 0;
    }else{
        return a+1;
    }
}
int main(){
    freopen("explore","r",stdin);
    freopen("explore","w",stdout);
    int a;
    cin>>a;
    while(a--){
        int n,m,b,sum=0;
        cin>>n>>m>>b;
        int x,y,d;
        cin>>x>>y>>d;
        char map[n+2][m+2];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                map[i][j]='p';
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>map[i][j];
            }
        }
        for(int i=0;i<b;i++){
            if(d==0){
                if(map[x][y+1]=='.'){
                    sum++;
                    y+=1;
                    continue;
                }else{
                    d=ri(d);
                    continue;
                }
            }
            if(d==1){
                if(map[x+1][y]=='.'){
                    sum++;
                    x+=1;
                    continue;
                }else{
                    d=ri(d);
                    continue;
                }
            }
            if(d==2){
                if(map[x][y-1]=='.'){
                    sum++;
                    y-=1;
                    continue;
                }else{
                    d=ri(d);
                    continue;
                }
            }
            if(d==3){
                if(map[x-1][y]=='.'){
                    sum++;
                    x-=1;
                    continue;
                }else{
                    d=ri(d);
                    continue;
                }
            }
        }
        cout<<sum<<endl;

    }
    return 0;
}

