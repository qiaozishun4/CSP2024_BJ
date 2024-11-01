#include<bits/stdc++.h>
using namespace std;
int num[]={6,2,5,5,4,5,6,3,7,6};
string haha[]={"0","1","2","3","4","5","6","7","8","9"};
string themin="#";
void domin(string A){
    if (A[A.size()-1]=='0'){
        return;
    }
    if (themin=="#"){
        themin=A;
        return;
    }
    if (A.size()!=themin.size()){
        if (A.size()<themin.size()){
            themin=A;
        }
        return;
    }
    for (int i=A.size()-1;i>=0;i--){
        if (A[i]!=themin[i]){
            if (A[i]<themin[i]){
                themin=A;
            }
            return;
        }
    }
    return;
}
void dfs(int let,string s){
    if (let==0){
        domin(s);
        return;
    }
    for (int i=0;i<10;i++){
        if (let>=num[i]){
            dfs(let-num[i],s+haha[i]);
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<"\n";
        }
        else if (n%7==0){
            for (int i=1;j<=n/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else if (n%7==1){
            cout<<10;
            for (int i=2;i<=n/7;i++){
                cout<<8;
            }
            cout<<"\n";
        }
        else{
            dfs(n,"");
            reverse(themin.begin(),themin.end());
            cout<<themin<<"\n";
        }
        themin="#";
    }
    return 0;
}
