#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,a[100001],b[100001];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int cnt=0;int mx=-1,mn=1e6+7;
    for(int i=0;i<n;i++)mx=max(mx,a[i]);
    for(int i=0;i<n;i++)mn=min(mn,a[i]);
    if(mx<=2){
        for(int i=0;i<n;i++){
            if(a[i]==2)cnt++;
        }cout<<max(cnt,n-cnt);
    }
    else{
        for(int i=0;i<n;i++)b[a[i]]+=1;
        int ans=0,ans1=0;int q[100001]={0},q1[100001]={0};
        memset(q,0,sizeof(q));
        ans+=b[mx];int pre=mx;
        for(int i=mx-1;i>=mn;i--){
            if(b[i]==0)continue;
            else{
                q[mx-i]=max(0,max(0,max(b[pre]-b[i],b[i]-b[pre]))-q[mx-pre]);
                ans+=q[mx-i];pre=i;
            }
        }ans1+=b[mn];int pre1=mn;
        for(int i=mn+1;i<=mx;i++){
            if(b[i]==0)continue;
            else{
                q1[i]=max(0,max(0,max(b[pre]-b[i],b[i]-b[pre]))-q[pre]);
                ans1+=q1[i];pre=i;
            }
        }
        cout<<min(ans,ans1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
