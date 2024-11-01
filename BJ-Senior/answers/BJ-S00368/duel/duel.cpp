#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[100001];
bool f[100001];
int t[100001];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int l=1,r=n;
        int ans=-1;
        while(l<r){
            int mid=(l+r+1)/2;
            if(a[i]>a[mid]){
                l=mid;
                if(t[a[mid]]>0) ans=mid;
            }else r=mid-1;
        }
        if(ans==-1) ;
        t[a[ans]]--;
    }
    for(int i=1;i<=100000;i++){
        sum+=t[i];
    }
    cout<<sum;
    return 0;
}