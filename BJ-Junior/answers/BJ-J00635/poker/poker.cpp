#include<bits/stdc++.h>
using namespace std;
int n,ans;
string a[53];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n!=52){
        ans+=(52-n);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
