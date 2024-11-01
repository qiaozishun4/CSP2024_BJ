#include<bits/stdc++.h>
using namespace std;
int t;
char a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        if(n<=100&&m<=100&&k==1){
            if(d==0){
                if(y+1<=m&&a[x][y+1]=='.')cout<<"2"<<endl;
                else cout<<"1"<<endl;
            }
            else if(d==1){
                if(x+1<=n&&a[x+1][y]=='.')cout<<"2"<<endl;
                else cout<<"1"<<endl;
            }
            else if(d==2){
                if(y-1>=1&&a[x][y-1]=='.')cout<<"2"<<endl;
                else cout<<"1"<<endl;
            }
            else if(d==3){
                if(x-1>=1&&a[x-1][y]=='.')cout<<"2"<<endl;
                else cout<<"1"<<endl;
            }
        }
    }
    return 0;
}