#include <bits/stdc++.h>
using namespace std;
int t;
stack<char>s;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        while(n/7>=1){
            n-=7;
            s.push('8');
        }
        if(n==1){
            s.pop();
            s.push('0');
            s.push('1');
        }else if(n==2){
            s.push('1');
        }else if(n==3){
            s.push('7');
        }else if(n==4){
            s.push('4');
        }else if(n==5){
            s.push('2');
        }else if(n==6){
            s.push('6');
        }
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}