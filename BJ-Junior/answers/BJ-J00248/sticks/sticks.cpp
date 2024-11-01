#include<iostream>
#include<string>
using namespace std;
#define int long long
const int maxn=2e5+10;
int t,n;
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        string ans;
        if(n==1){
            cout<<"-1\n";
            continue;
        }
        if(n%7==0)for(int i=1;i<=n/7;i++)ans+='8';
        else if(n%7==1){
            ans="10";
            for(int i=1;i<n/7;i++)ans+='8';
        }
        else if(n%7==2){
            ans="1";
            for(int i=1;i<=n/7;i++)ans+='8';
        }
        else if(n%7==3){
            if(n==3)ans="7";
            else if(n==10)ans="22";
            else{
                ans="200";
                for(int i=1;i<n/7-1;i++)ans+='8';
            }
        }
        else if(n%7==4){
            if(n==4)ans="4";
            else{
                ans="20";
                for(int i=1;i<n/7;i++)ans+='8';
            }
        }
        else if(n%7==5){
            ans="2";
            for(int i=1;i<=n/7;i++)ans+='8';
        }
        else{
            ans="6";
            for(int i=1;i<=n/7;i++)ans+='8';
        }
        cout<<ans<<'\n';
    }
}