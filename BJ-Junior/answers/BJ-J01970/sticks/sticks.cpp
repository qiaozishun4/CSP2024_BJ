#include<bits/stdc++.h>
using namespace std;
int u[15]={-1,-1,1,7,4,2,0,8,10,18,22,20,28,68,88};
long long int t,n,h;
map<long long int ,long long int > a;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        a[i];
        cin>>a[i];
    }
    for(int i=1;i<=t;i++){
        n=a[i];
        if(n<=14){
                if(n==6){
                    cout<<"6";
                    cout<<endl;
                }else{
                    cout<<u[n];
                    cout<<endl;
                }
            continue;
        }
        else{
            h=n/7-1;
            cout<<u[n%7+7];
            for(int j=1;j<=h;j++){
                cout<<"8";
            }
            cout<<endl;
        }
    }
    return 0;
}
