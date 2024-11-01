#include<bits/stdc++.h>
using namespace std;
int n;
char p[52][2];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int ans=52-n;
    for(int i=1;i<=n;i++) cin>>p[i][1]>>p[i][2];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(p[i][1]==p[j][1] && p[i][2]==p[j][2]) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}