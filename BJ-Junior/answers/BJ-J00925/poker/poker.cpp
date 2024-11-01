#include<iostream>
using namespace std;
int n;
string a[55];
int l;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string c;
        cin>>c;
        bool f=true;
        for(int j=1;j<=l;j++){
            if(c==a[j]){
                f=false;
                break;
            }
        }
        if(f){
            l++;
            a[l]=c;
        }
    }
    cout<<52-l;
    return 0;
}
