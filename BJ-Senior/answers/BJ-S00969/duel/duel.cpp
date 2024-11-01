#include<bits/stdc++.h>
using namespace std;
int n,a[100010],ans,now,sum,sum2=1;
struct Node{
    int r,cnt;
}b[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    now=a[1];
    for(int i=1;i<=n;i++){
        if(a[i]==now) sum++;
        else{
            b[sum2].cnt=sum;
            b[sum2].r=now;
            now=a[i];
            sum=1;
            sum2++;
        }
    }
    b[sum2].cnt=sum;
    b[sum2].r=now;
    for(int i=2;i<=sum2;i++){
        int  live=b[i].cnt;
        for(int j=i-1;j>=1;j--){
            if(b[j].cnt<=live){
                live-=b[j].cnt;
                b[j].cnt=0;
            }else{
                b[j].cnt-=live;
                live=0;
                break;
            }
        }
    }
    for(int i=1;i<=sum2;i++){
        ans+=b[i].cnt;
    }
    cout<<ans;
    return 0;
}
