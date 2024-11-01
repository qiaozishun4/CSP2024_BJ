#include<bits/stdc++.h>
using namespace std;
bool flag[100001];
int decode(string x){
    char a=x[0],b=x[1];
    return int(a)*256+int(b);
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;cin>>n;
    for(int i=1;i<=n;i++){
        string a;cin>>a;
        int pos=decode(a);
        if(flag[pos]==0)ans--;
        flag[pos]=1;
    }
    cout<<ans;
    return 0;
}