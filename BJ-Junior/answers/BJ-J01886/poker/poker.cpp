#include<bits/stdc++.h>
using namespace std;
bool d[4][13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string s;
    int n;
    cin>>n;
    for(int i=0;i<n*2;i+=2){
        cin>>s[i]>>s[i+1];
        if(s[i]=='S'){
            if(s[i+1]=='A'){
                d[0][0]=true;
            }
            else if(s[i+1]=='K'){
                d[0][12]=true;
            }
            else if(s[i+1]=='Q'){
                d[0][11]=true;
            }
            else if(s[i+1]=='J'){
                d[0][10]=true;
            }
            else if(s[i+1]=='T'){
                d[0][9]=true;
            }
            else if(s[i+1]>='2'&&s[i+1]<='9'){
                d[0][s[i]-50]=true;
            }
        }
        if(s[i]=='H'){
            if(s[i+1]=='A'){
                d[1][0]=true;
            }
            else if(s[i+1]=='K'){
                d[1][12]=true;
            }
            else if(s[i+1]=='Q'){
                d[1][11]=true;
            }
            else if(s[i+1]=='J'){
                d[1][10]=true;
            }
            else if(s[i+1]=='T'){
                d[1][9]=true;
            }
            else if(s[i+1]>='2'&&s[i+1]<='9'){
                d[1][s[i]-50]=true;
            }
        }
        if(s[i]=='D'){
            if(s[i+1]=='A'){
                d[2][0]=true;
            }
            else if(s[i+1]=='K'){
                d[2][12]=true;
            }
            else if(s[i+1]=='Q'){
                d[2][11]=true;
            }
            else if(s[i+1]=='J'){
                d[2][10]=true;
            }
            else if(s[i+1]=='T'){
                d[2][9]=true;
            }
            else if(s[i+1]>='2'&&s[i+1]<='9'){
                d[2][s[i]-50]=true;
            }
        }
        if(s[i]=='C'){
            if(s[i+1]=='A'){
                d[3][0]=true;
            }
            else if(s[i+1]=='K'){
                d[3][12]=true;
            }
            else if(s[i+1]=='Q'){
                d[3][11]=true;
            }
            else if(s[i+1]=='J'){
                d[3][10]=true;
            }
            else if(s[i+1]=='T'){
                d[3][9]=true;
            }
            else if(s[i+1]>='2'&&s[i+1]<='9'){
                d[3][s[i]-50]=true;
            }
        }
    }
    int sum=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(!d[i][j])sum++;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
