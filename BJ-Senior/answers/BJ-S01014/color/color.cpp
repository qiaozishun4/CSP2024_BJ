#include<iostream>
#include<cstdio>
using namespace std;

int T;

void color(int n){
    int ans=0;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=n-1;i>0;i--)
        for(int j=n-2;j>=0;j--)
            if(a[i]==a[j]){
                ans+=a[j];
                break;
            }

    cout<<ans<<endl;
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        color(n);
    }

    return 0;
}
