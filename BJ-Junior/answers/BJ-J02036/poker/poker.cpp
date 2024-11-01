#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++){
        string c;
        cin>>c;
        a[i]=c;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]==a[j]) a[j]="nn";
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]!="nn") ans++;

    }
    cout<<52-ans;
}
