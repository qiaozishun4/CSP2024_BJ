#include<bits/stdc++.h>
using namespace std;
map<string,bool> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(mp[s]==0){
            mp[s]=1;
            cnt++;
        }
    }
    cout<<52-cnt<<endl;
    return 0;
}
