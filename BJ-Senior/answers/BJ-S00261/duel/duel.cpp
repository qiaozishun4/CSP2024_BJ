#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1e5+5;
ull a[N];
ull n;
bool f1[N],f2[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    ull sum=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]>a[i]&&f1[i]==0&&f2[j]==0){
                f1[i]=1;
                f2[j]=1;
                sum--;
            }
        }
    }
    cout<<sum;
    return 0;
}