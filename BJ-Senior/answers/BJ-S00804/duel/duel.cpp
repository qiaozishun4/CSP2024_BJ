#include<bits/stdc++.h>
using namespace std;
long long n,x,max1,max2;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x==1) max1++;
        else max2++;
    }cout<<max(max1,max2);
    return 0;
}
