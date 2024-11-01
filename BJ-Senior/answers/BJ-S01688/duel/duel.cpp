#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N];
struct node{
    int val;
    int cnt;
    int rem;
}b[N];
int k=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int tmp=1;
    while(tmp<=n){
        k++;
        b[k].val=a[tmp];
        b[k].cnt=1;
        while(a[tmp]==a[tmp+1]){
            tmp++;
            b[k].cnt++;
        }
        tmp++;
    }
    for(int i=1;i<=k;i++){
        b[i].rem=b[i].cnt;
    }
    int tot=0,now=1;
    for(int i=1;i<=k;i++){
        // cout<<b[i].cnt<<endl;
        while(b[i].cnt>0){
            if(b[now].val>b[i].val){
                // cout<<now<<' '<<b[i].cnt<<' '<<' '<<b[now].rem<<'\n';
                int rrd=min(b[now].rem,b[i].cnt);
                b[now].rem-=rrd;
                b[i].cnt-=rrd;
                // cout<<b[i].cnt<<' '<<b[now].rem<<'\n';
            }
            if(b[i].cnt==0){
                break;
            }
            if(b[now].val<=b[i].val||b[now].rem==0){
                now++;
            }
            if(now==k+1){
                // cout<<"fk1\n";
                break;
            }
        }
        if(now==k+1){
            // cout<<"fk2\n";
            break;
        }
        // cout<<i<<":\n";
        // for(int j=1;j<=k;j++){
        //     cout<<b[j].val<<' '<<b[j].cnt<<' '<<b[j].rem<<endl;
        // }
        // cout<<now<<endl;
    }
    // for(int i=1;i<=k;i++){
    //     cout<<b[i].cnt<<' '<<b[i].rem<<endl;
    // }
    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=b[i].cnt;
    }
    cout<<ans<<'\n';
    return 0;
}