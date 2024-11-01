#include<iostream>
using namespace std;
int main(){
    int num;
    int sum=0;
    string p[53]={"E","a"};
    string n;
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>num;
    sum=num;
    for(int i=1;i<=num;i++){
        cin>>n;
        p[i]=n;
        for(int j=0;j<i;j++){
            if(p[i]==p[j]){
                sum--;
                p[j]=p[0];
            }
        }
    }
    cout<<52-sum;
    return 0;
}
