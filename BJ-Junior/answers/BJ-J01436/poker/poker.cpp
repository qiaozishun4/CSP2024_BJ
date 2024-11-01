#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,num=0;
    cin>>n;
    string s[60];
    for(int i=1;i<=n;i++){
        cin>>s[i];
        bool t=true;
        for(int j=1;j<i;j++){
            if(s[i]==s[j]){
                t=false;
                break;
            }
        }
        if(t)num++;
    }
    cout<<52-num<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
