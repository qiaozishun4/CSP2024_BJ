#include <bits/stdc++.h>
using namespace std;
int n;
string p[55];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(p[i]==p[j]){
            	for(int k=j;k<n;k++){
            	    p[k]=p[k+1];
            	}
            	n--;
            }
        }
    }
    cout<<52-n;
    return 0;
}