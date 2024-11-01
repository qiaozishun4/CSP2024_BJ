#include<bits/stdc++.h>
using namespace std;

map<string,int>a;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    string s;
    cin>>n;
    int ans=52;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(a[s]==0){
            ans--;
            a[s]++;
        }
    }
    cout<<ans;
    return 0;
}
