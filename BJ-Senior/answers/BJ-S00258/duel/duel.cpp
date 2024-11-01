#include<iostream>
using namespace std;
const int N=1e5+1000;
int box[N],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        box[a]++;
    }
    for(int i=1;i<=1e5+10;i++){
        ans=max(0,ans-box[i]);
        ans+=box[i];
    }
    cout<<ans<<endl;
}
