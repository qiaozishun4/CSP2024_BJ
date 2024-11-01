#include<iostream>
using namespace  std;
 char a1[1000] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
 char b1[1000] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
 char c1[1000] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
 char d1[1000] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,num1=0,num2=0,num3=0,num4=0;
    cin >> n;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        if(s[0]=='D'){
            for(int i=0;i<12;i++){
                if(s[1]==a1[i]){
                   num1++;
                   a1[i]='Z';
                    continue;
                }
            }
        }else if(s[0]=='C'){
            for(int i=0;i<12;i++){
                if(s[1]==b1[i]){
                   num2++;
                   b1[i]='Z';
                continue;
                }

            }
        }else if(s[0]=='H'){
            for(int i=0;i<12;i++){
                if(s[1]==c1[i]){
                   num3++;
                   c1[i]='Z';
                continue;
                }

            }

        }else if(s[0]=='S'){
            for(int i=0;i<12;i++){
                if(s[1]==d1[i]){
                   num4++;
                   d1[i]='Z';
                continue;
                }

            }
        }
    }
    int sum=num1+num2+num3+num4;
    if(sum>=52){
        cout << 0;
       return 0;
    }
   cout << 52-sum;
    fclose(stdin);
    fclose(stdout);
}