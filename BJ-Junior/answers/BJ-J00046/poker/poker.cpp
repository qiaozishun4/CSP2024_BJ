#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n;
map <string,bool> q;
int cnt=0;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        if(q[s]==false){
            cnt++;
            q[s]=true;
        }
    }
    cout<<52-cnt<<endl;
    return 0;
}