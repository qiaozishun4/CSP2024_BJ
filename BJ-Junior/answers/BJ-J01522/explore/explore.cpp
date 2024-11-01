#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool a[10005][10005];
bool explore [10005][10005]={0};

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t>0){
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            char p[10005];
            cin>>p;
            for(int j=1;j<=m;j++){
                a[i][j]=(p[j-1]=='.');
                explore[i][j]=0;
            }
        }
        int ans=0;
        while(k>0){
         //   cout<<x<<" "<<y<<" "<<explore[x][y]<<endl;
            if(explore[x][y]==0){
                ans++;
                explore[x][y]=1;
            }
            if((d==0&y+1<=m)&&a[x][y+1]){
                y++;
                k--;
            }
            else if((d==1&x+1<=n)&&a[x+1][y]){
                x++;
                k--;
            }
            else if((d==2&y-1>0)&&a[x][y-1]){
                y--;
                k--;
            }
            else if((d==3&x-1>0)&&a[x-1][y]){
                x--;
                k--;
            }
            else{
                k--;
                d=(d+1)%4;
            }

        }
        if(explore[x][y]==0){
            ans++;
            explore[x][y]=1;
        }
        cout<<ans<<endl;
        t--;
    }
    return 0;
}
