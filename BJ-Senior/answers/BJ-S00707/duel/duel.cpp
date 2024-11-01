#include<bits/stdc++.h>
using namespace std;
int n,t,num[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>t;
        num[t]++;
    }
    sort(num,num+100005);
    cout<<num[100005-1];
    return 0;
}
