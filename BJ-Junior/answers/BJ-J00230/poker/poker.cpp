#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    char a,b,s,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>t;
        if(a==b) continue;
        ans-=1;
        a=s;
        b=t;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
