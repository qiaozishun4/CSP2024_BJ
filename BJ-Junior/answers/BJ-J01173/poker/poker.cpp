#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s[55];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    ans=52-n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(s[i]==s[j]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
