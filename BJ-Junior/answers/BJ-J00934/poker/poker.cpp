#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
map<string,int>a;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(a[s]==0) ans++;
        a[s]++;
    }
    printf("%d\n",52-ans);
    return 0;
}
