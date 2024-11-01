#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=1e5+5;
int n,ans,a[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ans=n;
    sort(a,a+n);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[j]&&a[i]>a[j]){
                ans--;
                a[j]=0;
                break;
            }
        }
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}