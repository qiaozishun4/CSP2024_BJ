#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string arr[100];
    int f=1;
    bool flag=false;
    string a;
    int sum=52;
    for(int i=0;i<n;i++){
        cin>>a;
        flag=false;
        for(int i=1;i<f;i++){
            if(arr[i]==a){
                flag=true;
                break;
            }
        }
        if(!flag){
            sum--;
            arr[f]=a;
            f++;
        }
    }
    cout<<sum;
    return 0;
}
