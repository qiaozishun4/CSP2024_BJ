#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,minn=INT_MAX,d[11]={6,2,5,5,4,5,6,3,7,6},d1[11]={0,0,1,7,4,2,6,8};
bool pd=1;
void dfs(int k,int sum){
    if(k<0||sum<0){
        return ;
    }
    if(k==0){
        minn=min(sum,minn);
        return ;
    }
    else{
        if(pd){
            pd=0;
            for(int i=1;i<10;i++){
                if(k-d[i]>=0){
                    dfs(k-d[i],sum*10+i);
                }
            }
        }
        else{
            for(int i=0;i<10;i++){
                if(k-d[i]>=0){
                    dfs(k-d[i],sum*10+i);
                }
            }
        }
    }
}
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        pd=1;
        minn=INT_MAX;
        int n;
        cin>>n;
        if(n<=40){
            dfs(n,0);
            if(minn==INT_MAX){
                cout<<-1<<endl;
                continue;
            }
            cout<<minn<<endl;
        }
        else{
            if(n%7==0){
                for(int i=1;i<=n/7;i++){
                    cout<<"8";
                }
            }
            if(n%7==1){
                cout<<"10";
                for(int i=1;i<=n/7-1;i++){
                    cout<<"8";
                }
            }
            if(n%7==2){
                cout<<"1";
                for(int i=1;i<=n/7;i++){
                    cout<<"8";
                }
            }
            if(n%7==3){
                cout<<"200";
                for(int i=1;i<=n/7-2;i++){
                    cout<<"8";
                }
            }
            if(n%7==4){
                cout<<"20";
                for(int i=1;i<=n/7-1;i++){
                    cout<<"8";
                }
            }
            if(n%7==5){
                cout<<"2";
                for(int i=1;i<=n/7;i++){
                    cout<<"8";
                }
            }
            if(n%7==6){
                cout<<"6";
                for(int i=1;i<=n/7;i++){
                    cout<<"8";
                }
            }
        }
    }
    return 0;
}
