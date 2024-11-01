#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

int n;
int a[maxn];

int r,l;
int sum;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    sum=n;
    l=r=1;
    while(a[r]==a[1])r++;
    while(r<=n){
        if(a[r]>a[l])l++,sum--;
        r++;
    }
    cout<<sum;
    return 0;
}
