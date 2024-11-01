#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char xs='a';
    cin>>n;
    string s[200];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int num=0,temp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                j+=1;
                continue;
            }
            if(s[i]==s[j]){
               s[j]=xs;
               xs++;
               temp++;
            }
        }
        num++;
    }
    num-=temp;
    cout<<52-num;

    fclose(stdin);
    fclose(stdout);
return 0;
}
