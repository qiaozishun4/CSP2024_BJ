#include <bits/stdc++.h>
using namespace std;
long long n,a[100010],T,str[20],ans,cnt,t[1000010];
void k(){
    str[1]++;
    for(int i=1;i<=n;i++)
        if(str[i]>1){
            str[i]=0;
            str[i+1]++;
        }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=20){
            cnt=0;
            memset(str,0,sizeof(str));
            for(int i=1;i<=n;i++)
                cin>>a[i];
            for(int i=1;i<=(1<<n);i++){
                ans=0;
                k();
                for(int j=1;j<=n;j++){
                    for(int k=j-1;k>=1;k--)
                        if(str[k]==str[j]){
                            if(a[k]==a[j])
                                ans+=a[j];
                            break;
                        }
                }
                cnt=max(cnt,ans);
            }
            cout<<cnt<<"\n";
        }
        else{
            memset(t,0,sizeof(t));
            for(int i=1;i<=n;i++){
                cin>>a[i];
                if(a[i]==a[i-1])
                    ans+=a[i];
                else if(t[a[i]])
                    ans+=a[i],t[a[i]]=0;
                else
                    t[a[i]]=1;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
