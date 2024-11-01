#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,cnt;
struct card{
    int id,r,sign;
}a[100005];
queue <card>q;
bool cmp(card x,card y){
    return x.r<y.r;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    cnt=n;
    for(int i=1;i<=n;i++){
        a[i].id=i,a[i].sign=0;
        cin>>a[i].r;
    }
    sort(a+1,a+n+1,cmp);
    q.push(a[1]);
    for(int i=2;i<=n;i++){
        if(a[i].r==q.front().r)q.push(a[i]);
        else if(a[i].r>q.front().r){
            a[i].sign=1;
            q.pop();
            cnt--;
            q.push(a[i]);
        }
    }
    cout << cnt << endl;
}

