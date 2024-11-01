#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin"poker.in";
    ifstream fout"poker.out";
    int n;
    string card[52];
    fin >> n;
    if(n==0)
    {
        fout << 52 << endl;
        return 0;
    }
    if(n==1)
    {
        fout << 51 << endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        fin >> card[i];
        for(int j=0;j<i;j++)
        {
            if(card[i]==card[j])
            {
                i--;
                n--;
            }
        }
    }
    fout << 52-n << endl;
    return 0;
}
