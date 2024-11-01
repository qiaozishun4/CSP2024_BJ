#include<bits/stdc++.h>
using namespace std;
int n;
string ans;


int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
       cin>>n;
       if(n<2) cout<<"-1";
       else{
            if((n%7)==0){
                for(int i=1;i<=n/7;i++){
                    cout<<"8";
                }
            }
            if((n-1)%7==0){
                for(int i=1;i<=n/7-1;i++){
                    cout<<"8";
                }cout<<"01";
            }
       }

        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
