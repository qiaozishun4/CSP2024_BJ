#include<iostream>
using namespace std;
int n,v[100005],r,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>r;
        v[r]++;
        if(ans<v[r])ans=v[r];
    }
    cout<<ans;
}
