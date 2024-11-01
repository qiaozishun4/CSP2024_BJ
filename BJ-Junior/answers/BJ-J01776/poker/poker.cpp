#include<bits/stdc++.h>
using namespace std;
map<string,bool> m;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(m[s]==0){
            m[s]=1;
            ans++;
        }
    }
    cout<<52-ans;
    return 0;
}
