#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
queue<int> q;
int a[MAXN];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)   cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(!q.empty()){
            int tmp=q.front();
            if(tmp<a[i]){
                ans++;
                q.pop();
            }
        }
        q.push(a[i]);
    }
    cout<<n-ans<<endl;
    return 0;
}
