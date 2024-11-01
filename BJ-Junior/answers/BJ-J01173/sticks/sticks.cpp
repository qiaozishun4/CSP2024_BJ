#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int hcb[]={6,2,5,5,4,5,6,3,7,6};
int T;
int n[maxn],ans[maxn];
bool flag=false,f=0;
void solve3(int n){
    int num[]={-1,-1,1,7,4,2,0,8,-1,-1};
    int sum=0,ans=1e9;
    for(int i=2;i<=7;i++){
        for(int j=2;j<=7;j++){
            for(int k=2;k<=7;k++){
                if(i+j+k==n){
                    if(num[i]==0) num[i]=6;
                    flag=true;
                    sum=num[i]*100+num[j]*10+num[k];
                    ans=min(ans,sum);

                }
            }
        }
    }
    if(!flag) cout<<-1<<endl;
    else cout<<ans<<endl;
}
void solve2(int n){
    int num[]={-1,-1,1,7,4,2,0,8,-1,-1};
    int sum=0,ans=1e9;
    for(int i=2;i<=7;i++){
        for(int j=2;j<=7;j++){
            if(i+j==n){
                if(num[i]==0) num[i]=6;
                flag=true;
                sum=num[i]*10+num[j];
                ans=min(ans,sum);
            }
        }
    }
    if(!flag) cout<<-1<<endl;
    else cout<<ans<<endl;
}
void solve1(int n){
    int num[]={-1,-1,1,7,4,2,0,8,-1,-1};
    int sum=0,ans=1e9;
    for(int i=2;i<=7;i++){
        if(i==n){
            if(num[i]==0) num[i]=6;
            flag=true;
            sum=num[i];
            ans=min(ans,sum);
        }
    }
    if(!flag) cout<<-1<<endl;
    else cout<<ans<<endl;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n[i];
    }
    for(int i=0;i<T;i++){
        if(n[i]<=7) solve1(n[i]);
        else if(n[i]>7 && n[i]<=13) solve2(n[i]);
        else if(n[i]>13) solve3(n[i]);
    }
    return 0;
}
