#include <iostream>
#define int long long
using namespace std;
int a[100005]={6,2,5,5,4,5,6,3,7,6};
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=10;i<=100000;i++){
        a[i]=a[i/10]+a[i%10];
    }
    while(t--){
        bool flag=false;
        int n;
        cin>>n;
        for(int i=1;i<=100000;i++){
            if(a[i]==n){
                flag=true;
                cout<<i<<endl;
                break;
            }
        }
        if(!flag) cout<<-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
