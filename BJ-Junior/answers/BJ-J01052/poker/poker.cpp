#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string s;
    string a[53];
    int ans=0;
    bool flag=true;
    for(int i=0;i<n;i++){
        cin>>s;
        a[i]=s;
        for(int j=0;j<i;j++){
            if(a[i]==a[j]){
                flag=false;
            }
        }
        if(flag==true){
            ans++;
        }
    }
    cout<<52-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}