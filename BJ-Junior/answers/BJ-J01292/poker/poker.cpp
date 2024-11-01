#include<bits/stdc++.h>
using namespace std;
int n;
map<string,bool> a;
int jyl;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string x;
        cin>>x;
        if(a[x]==0) jyl++;
        a[x]=1;
    }
    cout<<52-jyl;
    return 0;
}
