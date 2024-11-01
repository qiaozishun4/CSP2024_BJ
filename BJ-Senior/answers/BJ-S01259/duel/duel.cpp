#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10086;
ll a[N];
int main(){
    //freopen("duel.in","r",stdin);
    //freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int sum=0;
    for(int i=1;i<=n;i+=2){
        sum++;
    }
    cout<<sum<<endl;

    return 0;
}
