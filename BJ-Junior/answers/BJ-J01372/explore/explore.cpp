#include<bits/stdc++.h>
using namespace std;
char s[110][110];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>s[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='.'&&(s[i][j+1]=='.'||s[i][j-1]=='.'||s[i-1][j]=='.'||s[i+1][j]=='.')){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
