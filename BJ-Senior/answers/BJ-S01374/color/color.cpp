#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200005];
int cnt[1000005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        long long ans=0;
        cin>>n;
        for(int i=0;i<n;i++)cnt[i]=0;
        int maxn=-1;int x1,x2;
        for(int i=0;i<n;i++){
            cin>>a[i];
            cnt[a[i]]++;
            if(cnt[a[i]]>=2&&a[i]>maxn){
                maxn=a[i];x2=i;
            }

        }
        if(maxn!=-1){
            for(int i=x2-1;i>=0;i--){
                if(a[i]==maxn){
                    x1=i;
                    break;
                }
            }
            ans+=a[x1];
            a[x1]=a[x2]=0;
        }else{
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<n;i++){
            if(a[i-1]!=0){
                if(a[i]==a[i-1])ans+=a[i];
            }else{
                int q=2;
                while(a[i-q]==0&&i-q>=0){
                    q++;
                }
                if(i-q<0)q--;
                if(a[i]==a[i-q])ans+=a[i];
                //cout<<"!"<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
