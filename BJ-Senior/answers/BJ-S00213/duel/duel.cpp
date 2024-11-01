#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long r[N]={};
long long a[N]={};
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n,maxn=INT_MIN,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        a[r[i]]++;
        if(r[i]>=maxn) maxn=r[i];
    }
    int num=0;
    for(int i=maxn;i>=1;i--){
        if(a[i]!=0){
            if((a[i]-num)>=0){
                cnt+=a[i]-num;
                num=a[i];
            }
            else num=a[i]+abs(num-a[i]);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
