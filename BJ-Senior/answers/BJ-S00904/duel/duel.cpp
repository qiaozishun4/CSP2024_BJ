#include<bits/stdc++.h>
using namespace std;
int n;
int r[100005];
int t[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>r[i];
        ++t[r[i]];
    }
    int sum=0;//向下攻击次数
    int ans=0;
    for(int i=100000;i>=1;--i){
        int tmp=t[i];
        if(sum>=t[i]){
            sum-=t[i];
            t[i]=0;
        }else{
            t[i]-=sum;
            ans+=t[i];
            sum=0;
        }
        sum+=tmp;
        //if(tmp)cout<<i<<" "<<tmp<<" "<<t[i]<<" "<<sum<<endl;
    }
    cout<<ans;
    return 0;
}
