#include<bits/stdc++.h>
using namespace std;
int n,mypokerans=52;
string s;
map<string,int>mp;
int main(){
    freopen("poker.in","r",stdin),freopen("poker.out","w",stdout),scanf("%d",&n);
    while(n--)cin>>s,((!mp[s])?(mypokerans--):0),mp[s]++;
    cout<<mypokerans<<endl;
    return 0;
}