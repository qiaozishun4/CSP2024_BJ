#include <bits/stdc++.h>
using namespace std;
int n;
map<int,int> mp;
bool b;
int sum;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    for(auto i:mp){
        if(!b){
            b=true;
            sum=i.second;
        }
        else{
            if(i.second>sum) sum=i.second;
        }
    }
    cout<<sum;
    return 0;
}
