#include<bits/stdc++.h>
using namespace std;
string poker[54];
int n,now=0,ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int j=0;
    string poke;
    for(int i=0;i<n;i++){
        cin>>poke;
        j=0;
        for(j=0;j<now;j++) if(poke==poker[j]) break;
        if(j==now){
            poker[now]=poke;
            now++;
        }
    }
    ans=52-now;
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
