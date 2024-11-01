#include<bits/stdc++.h>
using namespace std;
string b[20]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
string c[10]={"D","C","H","S"};
map<string,bool> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]=1;
    }
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            string s=c[i]+b[j];
            if(mp[s]==0)ans++;
        }
    }
    cout<<ans;
    return 0;
}
