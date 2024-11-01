#include<bits/stdc++.h>
using namespace std;

string s[55];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(s[i]==s[j]){
                sum++;
            }
        }
    }
    int x=n-sum;
    cout<<52-x<<endl;

    return 0;
}
