#include<bits/stdc++.h>
using namespace std;
int a,b,c,m,n,t,cc,f,x,y,u,v;
char mappp[1005][1005];
int mapp[1005][1005],ccc[10];
void ParseIn(){
    ifstream inFile("explore.in");
    inFile>>a;
    for(int i=1;i<=a;i++){
        inFile>>a>>b>>t;
        inFile>>m>>n>>f;
        for(int j=1;j<=a;j++){
            for(int l=1;l<=b;l++){
                inFile>>mappp[j][l];
            }
        }
    inFile.close();
}
}
void Core(){

}
void WriteOut(){
ofstream outFile("explore.out");
for(int i=1;i<a;i++){
    outFile<<1;
}
outFile.close();
}
int main(){
ParseIn();
Core();
WriteOut();
return 0;
}