#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int f(int x){
    int ans=0;
    while(x){
        int z=x%10;
        ans+=a[z];
        x/=10;
    }
    return ans;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=1){
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;;i++){
            if(f(i)==n){
                cout<<i<<endl;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
