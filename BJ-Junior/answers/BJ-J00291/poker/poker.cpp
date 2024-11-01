#include<bits/stdc++.h>
using namespace std;
map<string,bool>a;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        if(!(a[tmp])){
            a[tmp]=true;
            ans--;
        }
    }

    cout<<ans;
    return 0;
}
