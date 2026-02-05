#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        string s;

        cin >> n >> s;

        int l = 0;
        int r = n - 1;

        while (l < n && s[l] == '0')
            l++;

        while (r >= 0 && s[r] == '1')
            r--;

        if (r < l)
        {
            cout << 0 << "\n";
        }
        else
        {
            int count = 0;

            while (l < r)
            {
                if (s[l] == '1' && s[r] == '0')
                {
                    count++;
                    l++;
                    r--;
                }
                else if (s[l] == '0')
                {
                    l++;
                }
                else if (s[r] == '1')
                {
                    r--;
                }
            }

            cout << count << "\n";
        }
    }

    return 0;
}