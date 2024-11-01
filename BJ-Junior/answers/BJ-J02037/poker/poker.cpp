#include<bits/stdc++.h>
using namespace std;
int a,ccc,pp;
char p[3][100000];
void ParseIn(){
ifstream inFile("poker.in");
inFile>>a;
pp=52;
for(int i=0;i<a;i++){
    inFile>>p[0][i]>>p[1][i];
    ccc=0;
    for(int j=0;j<i;j++){
        if(p[0][i]==p[0][j]&&p[1][i]==p[1][j]){
            ccc=1;
        }
    }
    if(ccc==0){
        pp--;
    }
}
inFile.close();
}
void Core(){

}
void WriteOut(){
ofstream outFile("poker.out");
outFile<<pp;
outFile.close();
}
int main(){
ParseIn();
Core();
WriteOut();
return 0;
}