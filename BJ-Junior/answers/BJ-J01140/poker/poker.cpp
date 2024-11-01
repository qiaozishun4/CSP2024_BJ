#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=52;
    string p[52];
    for(int i=0;i<52;i++) p[i]="0";
    cin>>n;
    for(int i=1;i<=n;i++){
        string q;
        cin>>q;
        bool f=1;
        for(int j=0;j<52;j++){
            if(p[j]=="0"){
                p[j]=q;
                break;
            }
            if(p[j]==q){
                f=0;
                break;
            }
        }
        if(f)ans--;
    }
    cout<<ans;
    return 0;
}
