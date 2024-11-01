#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int cnt[100010];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    int ans=0;
    for(int i=1;i<=100000;i++){
        if(cnt[i-1]==0)cnt[i]=cnt[i-1]+a[i];
        else {
            if(a[i]>=cnt[i-1])cnt[i]=a[i],ans=a[i];
            else cnt[i]=cnt[i-1],ans=cnt[i-1]-a[i];
        }
    }
    /*
    for(int i=1;i<=5;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=5;i++)
        cout<<cnt[i]<<" ";
    cout<<endl;
    */
    cout<<ans;
    return 0;
}

