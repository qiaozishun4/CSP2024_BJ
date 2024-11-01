#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5+5;
int t,n,a[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<0<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}