#include <fstream>
using namespace std;

bool hav[4][14];

int main()
{
    ifstream fin("poker.in");
    ofstream fout("poker.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; i++)
    {
        char op, num;
        fin >> op >> num;

        int oop;
        switch(op)
        {
            case 'D':
            oop = 0;
            break;
            case 'S':
            oop = 1;
            break;
            case 'H':
            oop = 2;
            break;
            case 'C':
            oop = 3;
            break;
        }

        int nnum;
        if (num >= '0' && num <= '9')
        {
            nnum = num - '0';
        }
        else
        {
            nnum = (num == 'T' ? 10 : (num == 'J' ? 11 : (num == 'Q' ? 12 : (num == 'K' ? 13 : 1))));
        }

        hav[oop][nnum] = true;
    }

    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            ans += hav[i][j];
        }
    }
    fout << 52 - ans << endl;
}