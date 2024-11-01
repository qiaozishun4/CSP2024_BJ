#include<bits/stdc++.h>
using namespace std;
int t,n,num[10]={6,2,5,5,4,5,6,3,7,6};
bool chk(long long x,int maxx){
    int cnt=0;
    while(x){
        int t=x%10;
        cnt+=num[t];
        x/=10;
    }
    return cnt==maxx;
}
void work(long long n,int sum){
    for(long long i=0;i<n;i++)
        if(chk(i,sum)){
            cout<<i<<"\n";
            return ;
        }
    cout<<"-1\n";
    return ;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        long long sum=pow(n,10);
        work(sum,n);
    }
    return 0;
}