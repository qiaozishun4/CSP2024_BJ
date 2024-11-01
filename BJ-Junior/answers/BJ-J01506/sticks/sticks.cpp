#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("sticks.in");
    ofstream fout("sticks.out");

    int t;
    fin >> t;
    while (t--)
    {
        int n;
        fin >> n;
        int dt = n / 7;
        if (n % 7 != 0)
        {
            dt++;
        }
        
        int d = 7 * dt - n;
        string ans;
        if (d == 1)
        {
            ans = "6";
        }
        else if (d == 2)
        {
            ans = "2";
        }
        else if (d == 3)
        {
            if (dt == 1)
            {
                ans = "4";
            }
            else
            {
                ans = "20";
                dt--;
            }
        }
        else if (d == 4)
        {
            if (dt == 1)
            {
                ans = "7";
            }
            else if (dt == 2)
            {
                ans = "22";
                dt--;
            }
            else
            {
                ans = "200";
                dt -= 2;
            }
        }
        else if (d == 5)
        {
            ans = "1";
        }
        else
        {
            if (dt == 1)
            {
                fout << -1 << endl;
                continue;
            }
            else
            {
                ans = "10";
                dt--;
            }
        }

        for (int i = 1; i < dt; i++)
        {
            ans += "8";
        }
        fout << ans << endl;
    }
}