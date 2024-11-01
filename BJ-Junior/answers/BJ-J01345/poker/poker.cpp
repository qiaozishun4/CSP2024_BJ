#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    map<string,int> mp;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    cout<<52-mp.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}