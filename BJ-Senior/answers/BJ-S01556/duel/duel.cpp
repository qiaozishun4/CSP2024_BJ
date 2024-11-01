#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],cnt;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    queue<int> q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cnt=n;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q.push(a[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i]>q.front()){
            q.pop();
            cnt--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
