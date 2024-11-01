
#include<bits/stdc++.h>
using namespace std;
int w;
char a;
int mx[4]={1,0,-1,0};
int my[4]={0,-1,0,1};
int b[2000][2000];
int main()
{
   freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
    cin>>w;
    while(w--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a;
                if(a=='.'){
                    b[i][j]=0;
                }
                else{
                    b[i][j]=1;
                }
            }
        }
        b[x][y]=2;
        while(k--){
            if(x+mx[d]>n||x+mx[d]<=0||y+my[d]<=0||y+my[d]>m||b[x+mx[d]][y+my[d]]==1){
                d++;
                d=d%4;
            }
            else{
                b[x+mx[d]][y+my[d]]=2;
                x=x+mx[d];
                y=y+my[d];
            }
        }
        int w=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==2){
                        w++;
                }

            }
        }
        cout<<w<<'\n';
    }
    return 0;
}
