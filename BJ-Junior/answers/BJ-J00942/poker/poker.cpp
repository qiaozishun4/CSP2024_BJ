#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string s;
map<string,bool>m;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>s;
        if(!m[s]){
            m[s]=1;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}