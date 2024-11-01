#include<bits/stdc++.h>
#define int long long

using namespace std;

int a[100005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("duel.in" ,"r",stdin);
    freopen("duel.out","w",stdout);

    int n; cin>>n;

    queue <int> q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){
        if(q.empty()){
           q.push(a[i]);
           continue;
        }

        if(q.front()<a[i]){
            q.pop();
            q.push(a[i]);
        }
        else{
            q.push(a[i]);
        }

        //  cout<<q.size()<<" "<<q.front()<<endl;
    }

    cout<<q.size();
    return 0;
}
