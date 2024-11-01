#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],k;
struct node{
    int r,sum;
}t[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int cnt=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
           cnt++;
        }else{
            k++;
            t[k].r=a[i-1];
            t[k].sum=cnt;
            cnt=1;
        }
    }
    k++,t[k].r=a[n],t[k].sum=cnt;
    cnt=0,cnt+=t[1].sum;
    int ans=n;
    //cout<<cnt;
    //for(int i=1;i<=k;i++) cout<<t[i].r<<" "<<t[i].sum<<endl;
    for(int i=2;i<=k;i++){
        if(t[i].sum>cnt){
            ans-=cnt;
            cnt=0;
        }else{
            cnt-=t[i].sum;
            ans-=t[i].sum;
        }
        cnt+=t[i].sum;
        //cout<<ans-cnt;
        //cout<<cnt<<" "<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
