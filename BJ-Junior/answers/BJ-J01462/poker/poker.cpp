#include<bits/stdc++.h>
using namespace std;
char aa[4]={'D','C','H','S'},bb[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
bool jde[4][13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        char a,b;
        cin>>a>>b;
        for(int j=0;j<4;++j) for(int k=0;k<13;++k) if(a==aa[j]&&b==bb[k]) jde[j][k]=true;
    }
    for(int j=0;j<4;++j) for(int k=0;k<13;++k) if(!jde[j][k]) ans++;
    cout<<ans;
    return 0;
}