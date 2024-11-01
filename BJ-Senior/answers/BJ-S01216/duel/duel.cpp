#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ll n,a[100001],b[100001]={},u=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    int s=n;
    int sum=0;
    for(int i=1;i<=N;i++){
        if(b[i]!=0){
            int no=0,us=b[i];
            int x=b[i];
            if(sum>=1){
                if(x>=sum){
                    s-=sum;
                    no=sum;
                    us=x-sum;
                }else{
                    s-=x;
                    no=x;
                    us=0;
                    sum=sum-x;
                }
            }
            if(us<no){
                s-=us;
                sum+=(no-us)+us;
            }else{
                s-=no;
                us=us-no;
                sum+=us+no;
            }
        }
    }
    cout<<s;
    return 0;
}
