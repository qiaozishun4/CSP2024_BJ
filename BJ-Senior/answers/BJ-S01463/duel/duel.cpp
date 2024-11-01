#include<bits/stdc++.h>
using namespace std;
long long a[100010],n,help[100010],l=1;
long long x,y;
bool o=1;
stack<long long> q;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1&&a[i]!=2) o=0;
    }
    if(o==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1) x++;
            else y++;
        }
        if(x<=y) cout<<y;
        else cout<<x;
        return 0;
    }
    sort(a+1,a+n+1);
    q.push(a[1]);
    for(int i=2;i<=n;i++){
        if(q.top()<a[i]){
            q.pop();
            while((!q.empty())&&q.top()<a[i]){
                help[l]=q.top();
                q.pop();
                l++;
            }
            q.push(a[i]);
            for(int j=l-1;j>=1;j--){
                q.push(help[j]);
            }
            l=1;
        }
        else q.push(a[i]);
    }
    cout<<q.size()<<endl;
    return 0;
}
