#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int a[N];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    sort(a+1,a+n+1);
    int i=1,j=2,ans=n;
    while(j<=n)
        a[i]<a[j]?i++,j++,ans--:j++;
    cout<<ans;

    return 0;
}
