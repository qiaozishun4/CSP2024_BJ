#include<bits/stdc++.h>
#include<fstream>

using namespace std;

//check your file cin!!!!!!!!!!!!!!!
//ifstream ofstream!!!!

ifstream fin("sticks.in");
ofstream fout("sticks.out");

int t,n;
int a[20];
int main(){
    a[2] = 1;
    a[3] = 7;
    a[4] = 4;
    a[5] = 2;
    a[6] = 0;
    a[7] = 8;
    fin >> t;
    while(t --){
        fin >> n;
        if(n < 2){
            fout << "-1" << endl;
            continue;
        }
        if(n <= 7){
            fout << a[n] << endl;
            continue;
        }
        if(n % 7 == 0){
            int cnt = n / 7;
            for(int i = 1;i <= cnt;i ++){
                fout << "8" ;
            }
            fout << endl;
            continue;
        }
        if(n % 7 == 1){
            fout << "10" ;
            int cnt = n / 7 - 1;
            for(int i = 1;i <= cnt;i ++){
                fout << "8" ;
            }
            fout << endl;
            continue;
        }
        if(n % 7 == 2){
            fout << "1";
            for(int i = 1;i <= n / 7;i ++){
                fout << "8" ;
            }
        } else if(n % 7 == 3){
            fout << "200";
            for(int i = 1;i <= (n / 7 - 2);i ++){
                fout << "8" ;
            }
        } else if(n % 7 == 4){
            fout << "20";
            for(int i = 1;i <= (n / 7 - 1);i ++){
                fout << "8" ;
            }
        } else if(n % 7 == 5){
            fout << "2";
            for(int i = 1;i <= n / 7;i ++){
                fout << "8" ;
            }
        } else if(n % 7 == 6){
            fout << "6" ;
            for(int i = 1;i <= n / 7;i ++){
                fout << "8" ;
            }
        }
        fout << endl;
    }
    return 0;
}