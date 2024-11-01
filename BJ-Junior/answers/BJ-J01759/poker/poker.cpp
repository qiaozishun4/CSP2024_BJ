#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream fin;
ofstream fout;
bool card[4][13] = {};
char map1[14] = "A23456789TJQK";
char map2[5] = "DCHS";
int Value(char c)
{
    for(int a = 0; a < 13; a++)
        if(c == map1[a])
            return a;
    for(int a = 0; a < 4; a++)
        if(c == map2[a])
            return a;
}
int main()
{
    fin.open("poker.in");
    fout.open("poker.out");
    int n;
    fin >> n;
    for(int a = 0; a < n; a++)
    {
        string str;
        fin >> str;
        card[Value(str[0])][Value(str[1])] = true;
    }
    int ans = 0;
    for(int a = 0; a < 4; a++)
    {
        for(int b = 0; b < 13; b++)
            if(!card[a][b]) ans++;
    }
    fout << ans;
    return 0;
}
