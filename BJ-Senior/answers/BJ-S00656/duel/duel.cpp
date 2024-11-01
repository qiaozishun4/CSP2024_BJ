#include<iostream>
#include<algorithm>
using namespace std;
long long n;
int a[1000001];
long long maxn=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);
    long long flag=1;
    long long ans=0;
    for(long long i=2;i<=n+1;i++){
        if(a[i]==a[i-1]){
            flag++;
        }else{
            if(flag>maxn){
                ans+=(flag-maxn);
                maxn=flag;

            }
            flag=1;

        }

    }

    cout<<ans;
    return 0;
}
