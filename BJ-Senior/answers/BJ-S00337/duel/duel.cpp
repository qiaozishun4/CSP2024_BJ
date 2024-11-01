#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,a[N],b[N],len,ma,cnt,s[N],c[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        b[++len]=a[i];
    }
    sort(b+1,b+len+1);
    len=unique(b+1,b+len+1)-b-1;
    for(int i = 1;i <= n;i++){
        a[i]=lower_bound(b+1,b+len+1,a[i])-b;
        c[a[i]]++;
        ma=max(ma,a[i]);
    }
    //for(int i = 1;i <= ma;i++) cout<<c[i]<<endl;
    for(int i = ma+1;i >= 2;i--){
        s[i]+=c[i];
        if(c[i-1]>=s[i]) cnt+=(c[i-1]-s[i]);
        else s[i-1]=s[i]-c[i-1];
        //cout<<c[i-1]<<" "<<s[i]<<" "<<cnt<<endl;
    }
    cout<<cnt;
    return 0;
}
