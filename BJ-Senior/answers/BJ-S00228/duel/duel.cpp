//BJ-J00275 BJ12Z LMX Grade 8 Class 1
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int a[114514];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int maxr=0;
    int minn=0x7fffffff;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        maxr=max(maxr,x);
        minn=min(minn,x);
        a[x]++;
    }

    int last=minn;
    int sum_alive=a[last];
    for(int i=minn+1;i<=maxr;i++)
        if(a[i]!=0){
            int t=max(0,a[i]-sum_alive);
            sum_alive=max(0,sum_alive-a[i]);
            sum_alive+=a[i];
        }
    cout<<sum_alive;
    return 0;
}
