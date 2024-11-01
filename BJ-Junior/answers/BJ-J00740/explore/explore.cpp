#include<iostream>
using namespace std;
char a[1005][1005];
int n,m,k;
int t;
int d,x,y;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        k--;
        while(k--){
            int c,b;
            if(d==0)c=x,b=y+1;
            else if(d==1)c=x+1,b=y;
            else if(d==2)c=x,b=y-1;
            else c=x-1,b=y;
            if((c>=1 && c<=n) && (b>=1 && b<=m)){
                if(a[c][b]=='.')x=c,y=b,ans++;
                else d=(d+1)%4;
            }
            else d=(d+1)%4;
        }
        cout<<ans<<endl;
    }
    return 0;
}
