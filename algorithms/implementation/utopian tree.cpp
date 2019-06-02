#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
int power(int n, int a)
{
    int r = 1;
    for(int i = 0; i < n; i++)
    r = r*a;
    return r;
}
int utopianTree(int n) {
    if(n % 2 != 0)
    return 2*(power((n+1)/2, 2) - 1);
    else
    return utopianTree(n-1) + 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = utopianTree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
