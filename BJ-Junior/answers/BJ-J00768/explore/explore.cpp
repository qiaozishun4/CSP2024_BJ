#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,ans=0;
string h;
int main(){
    freopen("explore1.in","r",stdin);
    freopen("explore1.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>n>>m>>k>>x>>y>>d;
        int ans=0;
        string g[n+2][m+2];
        for(int l=0;l<n;l++){
			cin>>h;
			for(int j=0;j<m;j++){
				g[i][j]=h[j];
			}
		}
        for(int j=1;j<=k;j++){
            if(d==0){
                if(x>=0&&x<n&&y+1>=0&&y+1<m&&g[x][y+1]!="x"){
                    g[x][y]=1;
                    y++;
                }
                else d=(d+1)%4;
            }
            else if(d==1){
                if(x+1>=0&&x+1<n&&y>=0&&y<m&&g[x+1][y]!="x"){
                    g[x][y]=1;
                    x++;
                }
                else d=(d+1)%4;
            }
            else if(d==2){
                if(x>=0&&x<n&&y-1>=0&&y-1<m&&g[x][y-1]!="x"){
                    g[x][y]=1;
                    y--;
                }
                else d=(d+1)%4;
            }
            else if(d==3){
                if(x-1>=0&&x-1<n&&y>=0&&y<m&&g[x-1][y]!="x"){
                    g[x][y]=1;
                    x--;
                }
                else d=(d+1)%4;
            }
        }
        for(int l=0;l<n;l++)for(int j=0;j<m;j++)if(g[i][j]=="1")ans++;
        cout<<ans+1<<endl;
    }
    return 0;
}
