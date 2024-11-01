#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>> n;
    string s;
    for(int i=0;i<n;i++){
        cin>> s;
        if(m[s]==0) ans--;
        m[s]++;
    }
    cout<< ans;
    return 0;
}
