#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int,vector<int>,greater<int> > a,b;
//a beisha b sharen
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a.push(x);b.push(x);
    }
    while(!b.empty()){
        int x=a.top(),y=b.top();
        if(y<=x) b.pop();
        else a.pop(),b.pop();
    }
    cout<<a.size();
    return 0;
}
