#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);

    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    map<char,char>mp;
    for(int i=1;i<=n;i++){
            string s;
        cin>>s;
        if(mp[s[0]]!=s[1]){
            cnt++;
            mp[s[0]]=s[1];
        }
    }
    cout<<52-cnt;
    return 0;
}
