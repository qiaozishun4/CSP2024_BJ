#include<bits/stdc++.h>
using namespace std;
set<int> st[10];
int id(char c){
    if(c=='A'){
        return 1;
    }
    if(c=='T'){
        return 10;
    }
    if(c=='J'){
        return 11;
    }
    if(c=='Q'){
        return 12;
    }
    if(c=='K'){
        return 13;
    }
    else{
        return c-'0';
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        if(a=='D'){
            st[1].insert(id(b));
        }
        else if(a=='C'){
            st[2].insert(id(b));
        }
        else if(a=='H'){
            st[3].insert(id(b));
        }
        else{
            st[4].insert(id(b));
        }
    }
    int sum=0;
    for(int i=1;i<=4;i++){
        sum+=st[i].size();
    }
    cout<<52-sum;
    return 0;
}
