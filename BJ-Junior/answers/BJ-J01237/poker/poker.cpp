#include<bits/stdc++.h>
using namespace std;
int n,ans;
string a[60];
map<string,int> t;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(t[a[i]]!=0)ans++;
        t[a[i]]++;
    }
    cout<<52-n+ans;
    return 0;
}
