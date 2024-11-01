#include<bits/stdc++.h>
using namespace std;
int T,n;
int stick[10]={7,6,5,4,3,2},cnt[10],a[10]={0,4,3,2,5,1},sum;
void dfs(int *cnt,int sum){
    for(int t=0,i=a[0];t<6;t++,i=a[t]){
        cnt[i]-=1;
        n+=stick[i];
        if(i!=2)cnt[a[t+1]]+=n/stick[a[t+1]];
        else continue;
        n%=stick[a[t+1]];
        if(n!=0)return;
    }
    int tsum=0;
    for(int i=0;i<10;i++)tsum+=cnt[i];
    if(tsum>sum)return;
    dfs(cnt,tsum);
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        sum=0;
        cin>>n;
        int t=n;
        memset(cnt,0,sizeof(cnt));
        if(n==1){
            cout<<-1;
            continue;
        }
        for(int i=0;i<6;i++){
            cnt[i]=n/stick[i];
            n%=stick[i];
        }
        while(n){
            for(int i=0;i<6;i++){
                cnt[i]-=1;
                n+=stick[i];
                if(i!=2)cnt[i+1]+=n/stick[i+1];
                else continue;
                n%=stick[i+1];
                if(n==0)break;
            }
        }
        for(int i=0;i<10;i++)sum+=cnt[i];
        dfs(cnt,sum);
        if(cnt[1]){
            if(cnt[5]){cout<<1;cnt[5]--;}
            else if(cnt[2]){cout<<2;cnt[2]--;}
            else if(cnt[3]){cout<<4;cnt[3]--;}
            else  {cout<<6;cnt[1]--;}
        }
        while(cnt[1]--)
        {
            cout<<0;
        }
        while(cnt[5]--)cout<<1;
        while(cnt[2]--)cout<<2;
        while(cnt[3]--)cout<<4;
        while(cnt[4]--)cout<<7;
        while(cnt[0]--)cout<<8;
        cout<<'\n';
    }
    return 0;
}
