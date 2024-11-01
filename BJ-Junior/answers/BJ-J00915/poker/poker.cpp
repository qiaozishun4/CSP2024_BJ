#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map <string,int> mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>s,++mp[s];
    cout<<52-mp.size();
    return 0;
}

