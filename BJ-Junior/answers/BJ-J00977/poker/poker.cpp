#include<bits/stdc++.h>
using namespace std;
long long n;
map <string,int> mp;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        mp[s]=1;
    }
    cout<<52-(mp.size())<<endl;
    return 0;
}
