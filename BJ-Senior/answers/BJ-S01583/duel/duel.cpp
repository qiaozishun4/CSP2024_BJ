#include<bits/stdc++.h>
using namespace std;
int p[100000],n,x,maxx;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>x;
        p[x]++;
    }
    for(int i=0;i<=100000;i++)
        maxx=max(p[i],maxx);
    cout<<maxx;
    return 0;
}
