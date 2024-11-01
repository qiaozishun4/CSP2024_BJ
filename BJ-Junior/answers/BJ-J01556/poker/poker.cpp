#include<bits/stdc++.h>
using namespace std;
int n;
string s[100000];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int ans=52;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        ans--;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(s[i]==s[j])
              ans++;
        }
    }
    cout<<ans;
    return 0;
}
