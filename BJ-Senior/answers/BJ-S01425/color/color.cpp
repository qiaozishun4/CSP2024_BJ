#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int a[200005];
        int b[200005]={0};
        int cnt[1000005]={0};
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(cnt[a[i]]<=1)continue;
            b[i]=1;
            int flag=0;
            for(int j=i-1;j>=1;j--){
                if(a[j]==a[i]){
					flag=1;
				}
            }
            if(flag==0){
				b[i]=0;
				continue;
			}
            for(int j=i-1;j>=1;j--){
                if(a[i]==a[j]){
					b[j]=1;break;
				}
                if(b[j]==1){
                    if(a[i]*cnt[a[i]]>a[j]*cnt[a[j]]){
                        b[j]=0;
                    }
                    else if(a[i]*cnt[a[i]]==a[j]*cnt[a[j]]){
                        if(cnt[a[i]]<cnt[a[j]])b[j]=0;
                    }
                    else{
                        b[i]=0;
                        break;
                    }
                }
            }
        }
       for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(b[i]==b[j]){
                    if(a[i]==a[j]){
                        ans+=a[i];
                    }
                    break;
                }
            }
       }
       cout<<ans<<endl;
    }
    return 0;
}
