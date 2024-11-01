#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
char pf[4] = {'D','C','H','S'};
char pn[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int n,m=0,c=0;
string p[52];
string pl;
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
cin >> n;
for (int i = 0 ; i < n ; i ++){
        cin >> pl;
        for (int j = 0 ; j < i ; j++){
            if ( pl == p[j] ){
                c++;
            }
        }
        if (c == 0){
            m ++;
            p[i]=pl;
        }
        c = 0;
}
cout << 52-m;
return 0;

}