#include<bits/stdc++.h>
using namespace std;
char c;
int t,a[1000][1000],n,m,k,x,y,d,cnt;
bool f[1000][1000];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        x--;y--;
        cnt=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                f[i][j]=0;
            }
        }
        f[x][y]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c;
                if(c=='.'){
                    a[i][j]=0;
                }
                else{
                    a[i][j]=1;
                }
            }
        }
        while(k--){
            switch(d){
                case 0:{
                    if(y+1>=m)d=(d+1)%4;
                    else if(a[x][y+1]!=0)d=(d+1)%4;
                    else y++;
                    break;
                }
                case 1:{
                    if(x+1>=n)d=(d+1)%4;
                    else if(a[x+1][y]!=0)d=(d+1)%4;
                    else x++;
                    break;
                }
                case 2:{
                    if(y-1<0)d=(d+1)%4;
                    else if(a[x][y-1]!=0)d=(d+1)%4;
                    else y--;
                    break;
                }
                case 3:{
                    if(x-1<0)d=(d+1)%4;
                    else if(a[x-1][y]!=0)d=(d+1)%4;
                    else x--;
                    break;
                }
            }
            if(f[x][y]==0){
                cnt++;
                f[x][y]=1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
