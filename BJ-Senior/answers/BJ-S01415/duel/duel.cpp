#include<bits/stdc++.h>
using namespace std;
    int b[100001];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int a,c;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>c;
        b[c]++;
    }
    int m=0;
    for(int i=1;i<=100001;i++){
        m=max(b[i],m);
    }
    cout<<m;
return 0;
}
