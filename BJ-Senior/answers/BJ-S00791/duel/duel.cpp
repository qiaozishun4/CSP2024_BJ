#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 100005
int n,a[MAXN],q[MAXN],l,r;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(l<=r){
            if(q[l]<a[i]) l++;
        }
        q[++r]=a[i];
    }
    cout<<r-l+1<<endl;
    return 0;
}