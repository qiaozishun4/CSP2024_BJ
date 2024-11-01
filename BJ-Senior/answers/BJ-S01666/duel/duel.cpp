#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    int b[100005];
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    int c=0;
    for(int i=2;i<100005;i++){
        c+=b[i-1];
        c=max(0,c-b[i]);
    }
    cout<<c;
}
