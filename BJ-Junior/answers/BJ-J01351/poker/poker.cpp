#include<bits/stdc++.h>
using namespace std;
map <string,int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n;
    cin>>n;
    long long cnt=0;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(mp[s]==0){
            mp[s]=1;
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;

}
