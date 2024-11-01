#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    string s[60];
    int n;
    cin >>n;
    int x = n;
    for (int  i = 1;i<=n;i++){
        cin >> s[i];
    }
    for (int i = 1;i<=n;i++){
        bool flag = 0;
        int f = 0;
        for (int j = 1;j<=n;j++){
            //cout << s[i] <<" "<< s[j] <<endl;
            if (s[i]==s[j]&&i!=j &&s[i]!="*"&&s[j]!="*"){
                flag = 1;
                f++;
                s[j] ="*";
            }
        }
        x-=f;

    }
    cout <<52-x;
    return 0;
}
