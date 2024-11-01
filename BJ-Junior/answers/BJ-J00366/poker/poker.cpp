#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
string a[4]={"D","C","H","S"};
string b[13]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        string x;cin>>x;
        m[x]++;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(m.find(a[i]+b[j])==m.end()) ans++;
        }
    }
    cout<<ans;
    return 0;
}
