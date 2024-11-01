#include<bits/stdc++.h>
using namespace std;
const int INF=9999999;
bool flagdie[100005]={false},flagattacked[100005]={false};
int main(){
    bool teshuqingkuang=true,flag2=true;
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n,a[100005];
    long long ans=0,num2=0;
    scanf("%lld",&n);
    ans=n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]>2)flag2=false;
        if(a[i]==2)num2++;
        if(i>1&&a[i]!=a[i-1]){
            teshuqingkuang=false;
        }
    }
    if(teshuqingkuang){
        puts("1");
        return 0;
    }
    if(flag2==true){
        cout<<num2<<endl;
        return 0;
    }
    if(n<=30){
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]>a[i]&&flagattacked[j]==false&&flagdie[j]==false){
                    flagattacked[j]=true;
                    flagdie[i]=true;
                    ans--;
                }
            }
        }
        printf("%lld",ans);
    }
    else if(n>30){
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]>a[i]&&flagattacked[j]==false&&flagdie[j]==false){
                    flagattacked[j]=true;
                    flagdie[i]=true;
                    ans--;
                }
            }
        }
        printf("%lld",ans);
    }
    return 0;
}
