#inclde<bits/stdc++.h>
using namespace std;
int n,sum = 0,t;
string s;
int main(){
    feropen("sticks.in","r",stdin);
    feropen("sticks.ont","w",stdout);
    for(int i = 0;i < t;i++){
        cin>>n;
        if(n <= 2){
            cout<<"-1"<<endl;
        }
        for(int i = 1;;i++){
            sum = 0;
            s = to_string(i);
            for(int i = 0;i < s.size();i++){
                if(s[i] == '0') sum += 6;
                else if(s[i] == '1') sum += 2;
                else if(s[i] == '2') sum += 5;
                else if(s[i] == '3') sum += 5;
                else if(s[i] == '4') sum += 4;
                else if(s[i] == '5') sum += 5;
                else if(s[i] == '6') sum += 6;
                else if(s[i] == '7') sum += 3;
                else if(s[i] == '8') sum += 7;
                else if(s[i] == '9') sum += 6;
            }
            if(sum = n){
                cout<<s<<endl;
            }
        }
    }
    return 0;
}