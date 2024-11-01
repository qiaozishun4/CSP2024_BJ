#include<iostream>
#include<algorithm>
#define M 100005
using namespace std;
int n,p[M],ans,j=1;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    sort(p+1,p+1+n);
    for(int i = 1;i<=n;i++){
        if(p[j]<p[i])ans--,j++;
    }
    cout<<ans<<endl;
    return 0;
}

