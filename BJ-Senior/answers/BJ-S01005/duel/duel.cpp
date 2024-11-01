#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m%2!=0){
        m=n-1;
    }
    else{
        m=n;
    }
    sort(a+1,a+n+1);
    if(a[m/2]!=a[m/2+1]){
            if(n%2==1){
                if(a[m/2+1]<a[n]){
                    cout<<m/2);
                    return 0;
                }
                else{
                    cout<<m/2+1;
                    return 0;
                    }
                }
                else{
                    cout<<m/2;
                }
            }
        else{
                int lr=d[m/2];
            if(a[n]==a[i]){
                cout<<m;
            }
            else if(m%2==1){
                if(a[m-1]==a[i]){
                    cout<<n-1;
                }
                else if(a[n]!=lr){
                    int t=0;
                    for(int i=1;i<=n;i++){
                        if(a[i]==a[m]){
                            t++;
                        }
                        else if(t>0){
                            break;
                        }
                    }
                    if(t<=m/2){
                        cout<<m/2-1;
                    }
                    else{
                        cout<<t-1;
                    }
                }
            }
        }
    return 0;
}
