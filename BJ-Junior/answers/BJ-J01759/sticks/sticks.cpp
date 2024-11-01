#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
ifstream fin("sticks.in");
ofstream fout("sticks.out");
const int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int m = 200000000;
string str;
void divide(int length, int n, int now = 0)
{
    if(now == length && n == 0)
        m = (stoi(str) < m ? stoi(str) : m);
    else
    {
        for(int a = 0; a < 10; a++)
        {
            if(now == 0)
                a = (a == 0 ? 1 : a);
            if(n >= num[a])
            {
                str += a + '0';
                divide(length, n - num[a], now + 1);
                str.pop_back();
            }
        }
    }

}
int main()
{
    int T;
    fin >> T;
    for(int t = 0; t < T; t++)
    {
        int n;
        m = 200000000;
        vector<int>vec;
        fin >> n;
        int temp = n;
        for(int a = 0; a < n / 7; a++)
            vec.push_back(8);
        n %= 7;
        for(int a = 0; a < n / 6; a++)
            vec.push_back(0);
        n %= 6;
        for(int a = 0; a < n / 5; a++)
            vec.push_back(2);
        n %= 5;
        for(int a = 0; a < n / 4; a++)
            vec.push_back(4);
        n %= 4;
        for(int a = 0; a < n / 3; a++)
            vec.push_back(7);
        n %= 3;
        for(int a = 0; a < n / 2; a++)
            vec.push_back(1);
        n = temp;
        int length = vec.size();
        if(length == 0)
            fout << -1 << endl;
        else
        {
            divide(length, n);
            fout << m << endl;
        }


    }
    return 0;
}
