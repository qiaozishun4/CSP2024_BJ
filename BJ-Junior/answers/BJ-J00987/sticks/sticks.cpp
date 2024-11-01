#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("sticks.in","r",stdin);
freopen("sticks.out","w",stdout);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%7==0){
            while(n){
                n-=7;
                cout<<"8";
            }
        }else cout<<"-1";
        cout<<endl;
    }

fclose(stdin);
fclose(stdout);
    return 0;
}

