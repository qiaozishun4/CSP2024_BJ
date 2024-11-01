#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k,x,y,d,ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        char e[n+1][m+1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>e[i][j];
        while(k--)
            switch(d){
                case 0:
                    if(y+1>m || e[x][y+1]=='x'){
                        d=(d+1)%4;
                        break;
                    }else{
                        y++;
                        ans++;
                    }
                    break;
                case 1:
                    if(x+1>m || e[x+1][y]=='x'){
                        d=(d+1)%4;
                        break;
                    }else{
                        x++;
                        ans++;
                    }
                    break;
                case 2:
                    if(y-1<1 || e[x][y-1]=='x'){
                        d=(d+1)%4;
                        break;
                    }else{
                        y--;
                        ans++;
                    }
                    break;
                case 3:
                    if(x-1>m || e[x-1][y]=='x'){
                        d=(d+1)%4;
                        break;
                    }else{
                        x--;
                        ans++;
                    }
                    break;
            }
        cout<<ans<<endl;
    }
    return 0;
}
