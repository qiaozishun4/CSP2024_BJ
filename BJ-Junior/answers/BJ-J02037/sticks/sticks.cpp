#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,sum;
long long cc[100],aa[100],se[11]={6,2,5,5,4,5,6,3,7,6};
string s;
void ParseIn(){
    ifstream inFile("sticks.in");
    inFile>>a;
    for(int i=1;i<=a;i++){
        inFile>>cc[i];
    }
    inFile.close();
}
void Core(){
}
void WriteOut(){
ofstream outFile("sticks.out");
for(int i=1;i<=a;i++){
        if(cc[i]%7==0){
            b=cc[i]/7;
            for(int j=1;j<=b;j++){
                outFile<<8;
            }
            outFile<<endl;
        }
        else if(cc[i]==1){
            outFile<<"-1"<<endl;
        }
        else{
            for(int l=1;l<=2147483646;l++){
                c=l;
                sum=0;
                while(c>0){
                    d=c%10;
                    c/=10;
                    sum+=se[d];
                }
                if(sum==cc[i]){
                    outFile<<l<<endl;
                    break;
                }
            }
        }
    }
outFile.close();
}
int main(){
ParseIn();
Core();
WriteOut();
return 0;
}