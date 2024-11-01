#include <bits/stdc++.h>
using namespace std;

string arr[53];

bool D[14],C[14],H[14],S[14];
string s={" A23456789TJQK"};

int getIndex(char a){
    for (int i=1;i<=13;i++){
        if (s[i]==a){
            return i;
        }
    }
}

int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin>>n;

    int ans=0;

    for (int i=1;i<=n;i++){
        string a;
        cin>>a;
        if (a[0]=='D'){
            if (D[getIndex(a[1])]==0){
                ans++;
            }
            D[getIndex(a[1])]=1;
        }else if (a[0]=='C'){
            if (C[getIndex(a[1])]==0){
                ans++;
            }
            C[getIndex(a[1])]=1;
        }else if (a[0]=='H'){
            if (H[getIndex(a[1])]==0){
                ans++;
            }
            H[getIndex(a[1])]=1;
        }else if (a[0]=='S'){
            if (S[getIndex(a[1])]==0){
                ans++;
            }
            S[getIndex(a[1])]=1;
        }
    }

    cout<<52-ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
