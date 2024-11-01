#include<iostream>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN],cnt[MAXN];
int n,v=1e5,sum,maxl;
int main(){
    ios::sync_with_stdio(false);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    for(int i=1;i<=v;i++){
        //cout<<cnt[i]<<endl;
        if(sum>=cnt[i]){
            //sum-=cnt[i];
            maxl+=cnt[i];
        }
        else{
            maxl+=sum;
            sum=cnt[i];
        }
        //cout<<"sum:"<<sum<<endl;
    }
    return cout<<n-maxl,0;
}