#include<bits/stdc++.h>
using namespace std;
string p[55];
int n,cnt=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    cnt=52-n;
    sort(p+1,p+1+n);
    for(int i=1;i<n;i++){
        if(p[i]==p[i+1])cnt++;
    }
    cout<<cnt;
    return 0;
}
