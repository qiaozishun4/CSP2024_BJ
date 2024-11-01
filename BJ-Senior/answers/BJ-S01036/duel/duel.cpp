#include<bits/stdc++.h>
using namespace std;
struct Node{
    int sh,xl,gj=1;
}a[100010];
bool cmp(Node a,Node b){
    return a.sh<=b.sh;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans;
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>a[i].sh;
        a[i].xl=a[i].sh;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i].xl>0&&a[j].xl>0&&a[j].gj==1&&a[j].sh>a[i].sh){
                a[i].xl=0;
                a[j].gj=0;
                ans--;
            }
        }
    }
    cout<<ans;
    return 0;
}
