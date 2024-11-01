#include <bits/stdc++.h>
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
            int tmp=n/7;
            while(tmp--){
                cout<<"8";
           }
           cout<<endl;
        }else{
            cout<<"10";
            n-=8;
            while(n!=0){
                cout<<"8";
                n-=7;
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
