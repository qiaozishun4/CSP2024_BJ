#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    map<string,int> mp;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        mp[x]++;
    }
    cout<<52-mp.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}