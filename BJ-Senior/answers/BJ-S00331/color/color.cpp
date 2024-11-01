#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    srand(time(0));
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<rand()%(n+1)<<endl;
    }
    return 0;
}