#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","w",stdout);
    string p[60]={};
    map <string,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
        m[p[i]]=1;
    }
    cout<<52-m.size();
    return 0;
}