#include<iostream>
#include<stack>
typedef long long ll;
using namespace std;
stack<ll> ans;
ll stick[15]={6,2,5,5,4,5,6,3,7,6,0};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll t,n;
    cin>>t;
    while(t--){
        while(!ans.empty()){
            ans.pop();
        }
        cin>>n;
        if(n==1){
            cout<<"-1"<<endl;
            continue;
        }
        while(n>=7){
            n-=7;
            ans.push(8);
        }
        if(n==0){
            while(!ans.empty()){
                cout<<ans.top();
                ans.pop();
            }
            cout<<endl;
            continue;
        }
        ll i=1,j=0;
        if(!ans.empty()){
            n+=7;
            ans.pop();
            while((n-stick[i])<=1||(n-stick[i])>7){
                i++;
            }
            while(stick[j]!=(n-stick[i])){
                j++;
            }
            cout<<i<<j;
        }
        else{
            while(n!=stick[i]){
                i++;
            }
            cout<<i;
        }
        while(!ans.empty()){
            cout<<ans.top();
            ans.pop();
        }
        cout<<endl;
    }
    return 0;
}
