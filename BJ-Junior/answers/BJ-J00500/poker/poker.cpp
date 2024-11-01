#include<iostream>
#include<cstdio>
using namespace std;
string a[55];
int n,cnt=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        string p;
        cin>>p;
        int f=1;
        for(int j=0;j<52;j++){
            if(p==a[j]){
                f=0;break;
            }
        }
        if(f){
            cnt++;
            a[i]=p;
        }
    }
    cout<<52-cnt;
    return 0;
}
