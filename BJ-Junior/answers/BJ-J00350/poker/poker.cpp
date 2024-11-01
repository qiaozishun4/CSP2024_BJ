#include <bits/stdc++.h>
using namespace std;

int n,m,ans;

map<string,int> h;

string s;

int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s;
        if(h[s]==0){
            h[s]=1;
            ++m;
        }
    }

    cout<<52-m<<endl;

    return 0;
}
