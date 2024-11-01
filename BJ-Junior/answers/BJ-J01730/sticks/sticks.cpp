#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n=0;
        cin>>n;
        int k=n/7;
        for(int i=0;i>k;i++){
            cout<<"8";
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
