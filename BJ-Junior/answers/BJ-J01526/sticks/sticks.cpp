#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("sticks.in");
ofstream fout("sticks.out");
int main(){
    int n,m;
    bool flag=false;
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>m;
        if(m==1){
            fout<<"-1"<<endl;
        }else if(m%7==0){
            for(int j=1;j<=m/7;j++){
                fout<<"8";
            }
        }else if(m%7==1){
            for(int j=1;j<=m/7-1;j++){
                fout<<"8";
            }
            fout<<"01";
        }else if(m%7==2){
            for(int j=1;j<=m/7;j++){
                fout<<"8";
            }
            fout<<"1";
        }else if(m%7==3){
            for(int j=1;j<=m/7;j++){
                fout<<"8";
            }
            fout<<"7";
        }else if(m%7==4){
            for(int j=1;j<=m/7;j++){
                fout<<"8";
            }
            fout<<"4";
        }else if(m%7==5){
            for(int j=1;j<=m/7;j++){
                fout<<"8";
            }
            fout<<"2";
        }else if(m%7==6){
            for(int j=1;j<=m/7;j++){
                fout<<"8";
            }
            fout<<"6";
        }
        fout<<endl;
    }
    return 0;
}
