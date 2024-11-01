#include<bits/stdc++.h>
using namespace std;
int T;
const int N=1e5+5;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        string a[N];
        int n,m,k;
        int d,x,y;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int sum=0;
        while(k--){
            if(d==0){
                if(a[x][y+1]=='.'){
                    y+=1;
                    sum++;
                }else{
                    d+=1;
                    d%=4;
                    continue;
                }
            }
            if(d==1){
                if(a[x+1][y]=='.'){
                    x+=1;
                    sum++;
                }else{
                    d+=1;
                    d%=4;
                    continue;
                }
            }
            if(d==2){
                if(a[x][y-1]=='.'){
                    y-=1;
                    sum++;
                }else{
                    d+=1;
                    d%=4;
                    continue;
                }
            }
            if(d==3){
            if(a[x-1][y]=='.'){
                    x-=1;
                    sum++;
                }else{
                    d+=1;
                    d%=4;
                    continue;
                }
            }
        }
        cout<<sum+1<<endl;
    }
    return 0;
}
