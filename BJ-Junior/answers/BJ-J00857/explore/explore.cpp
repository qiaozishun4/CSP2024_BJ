#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,k,x,y,d,s=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(char j=1;j<=n;j++){
            for(char l=1;l<=m;l++){
                cin>>a[j][l];
            }
        }
        for(int j=1;j<=k;j++){
            if(d==2&&y-1<=0||d==3&&x-1<=0||d==0&&y+1>=n||d==1&&x+1>=n||d==0&&a[x][y+1]=='x'||d==1&&a[x+1][y]=='x'||d==2&&a[x][y-1]=='x'||d==3&&a[x-1][y]=='x'){
                cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
