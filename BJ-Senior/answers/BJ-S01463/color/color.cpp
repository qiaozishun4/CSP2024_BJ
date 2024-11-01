#include<bits/stdc++.h>
using namespace std;
int t,m,k=1,l,ans;
long long n,a[200010],s[200010],r[100010],r1[100010];
bool b[200010];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(s,0,sizeof(s));
        memset(b,0,sizeof(b));
        ans=0;
        k=1;
        m=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(s[a[i]]!=0){
                if(b[a[i]]==0){
                    r[k]=a[s[a[i]]];
                    k++;
                    for(int j=i;j>=s[a[i]];j--){
                        b[j]=1;
                    }
                    ans+=a[i];
                    r[k]=a[i];
                    k++;
                }
                s[a[i]]=0;
            }
            s[a[i]]=i;
        }
        k=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=r[k]){
                r1[m]=a[i];
                m++;
            }
            else k++;
        }
        for(int i=2;i<m;i++){
            if(r1[i]==r1[i-1]) ans+=r1[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
