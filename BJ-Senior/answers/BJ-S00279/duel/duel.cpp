#include<bits/stdc++.h>
using namespace std;
struct m{
    int r;
    bool f;
};
m a[100050];
bool cmp(m x,m y){
    return x.r<y.r;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].r;
        a[i].f=true;
    }
    sort(a+1,a+1+n,cmp);
    int newdeathpos=1;
    for(int i=1;i<=n;i++){
        cout<<a[i].r<<' '<<a[newdeathpos].r<<endl;
        if(a[i].r>a[newdeathpos].r){
            a[newdeathpos].f=false;
            newdeathpos++;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        cout<<a[i].f<<' ';
        cnt+=a[i].f;
    }
    cout<<cnt;
    return 0;
}
