#include<iostream>
using namespace std;
char a[1005];
char b[1005];

string s[1005];
int num=52;
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        s[i]=a[i]+b[i];
        if(i==0){
            num--;
        }else{
            for(int j=0;j<i-1;j++){
            if(s[i]!=s[j]){
                num--;
            }

            }
        }

    }
    cout<<num;
    return 0;
}
