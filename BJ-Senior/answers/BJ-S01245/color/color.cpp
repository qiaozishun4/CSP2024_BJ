#include <fstream>
using namespace std;

int a[200001];

int main()
{
    ifstream fin("color.in");
    ofstream fout("color.out");

    int t;
    fin >> t;
    while (t--)
    {
        int n;
        fin >> n;
        for (int i = 0; i < n; i++)
        {
            fin >> a[i];
        }

        if (n <= 15)
        {
            int up = 1;
            for (int i = 0; i < n; i++)
            {
                up *= 2;
            }

            bool color[20];
            int ans = 0;
            for (int i = 0; i < up; i++)
            {
                int total = 0;

                int nw = i;
                for (int j = 0; j < n; j++)
                {
                    color[j] = nw % 2;
                    nw /= 2;
                }

                for (int j = 0; j < n; j++)
                {
                    for (int k = j - 1; k >= 0; k--)
                    {
                        if (color[k] == color[j] && a[k] == a[j])
                        {
                            total += a[j];
                            break;
                        }
                    }
                }
                ans = max(ans, total);
            }
            fout << ans << endl;
        }
    }
}