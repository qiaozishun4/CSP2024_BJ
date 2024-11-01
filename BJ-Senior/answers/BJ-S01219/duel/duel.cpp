#include<bits/stdc++.h>
using namespace std;
int a[100010];
int f[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans=0,flag=0;
    cin>>n;
    int i=1;
    for(;i<=n;i++){
        cin>>a[i];
        if(a[i]>2) break;
    }
    if(i<=n){
        flag=1;
        i++;
        for(;i<=n;i++){
            cin>>a[i];
        }
    }
    if(n<=30){
        sort(a+1,a+1+n);
        int begins=1;
        for(int i=1;i<=n;i++){
            if(a[i]==a[begins]){
                continue;
            }
            int j=begins;
            while(a[j]<a[i]&&i!=j) j++;
            j--;
            ans++;
            a[j]=0;
            sort(a+1,a+1+n);
            begins++;
        }
        cout<<n-ans;
        return 0;
    }else if(!flag){
        int ans=0;
        for(int i=1;i<=n;i++) if(a[i]==2) ans++;
        cout<<ans+(((n-2*ans)>0)?(n-2*ans):0);
    }else{
        for(int i=1;i<=n;i++) f[a[i]]++;
        int ans=0;
        for(int i=1;i<=100005;i++){
            while(f[i]==0&&i<=100002) i++;
            if(i>100002) break;
            int beater=f[i];
            int j=i-1;
            while(j>=1&&beater>0){
                while(f[j]==0&&j>=1) j--;
                if(j==0) break;
                beater-=f[j];
                f[j]=0;
                if(beater<0) f[j]+=-beater;
            }
        }
        for(int i=1;i<=100005;i++) ans+=f[i];
        cout<<ans;
        return 0;
    }

}
