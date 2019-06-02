#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int g(int n)
{
    if(n == 1)
    return 5;
    return (g(n-1)/2)*3;
}

int viralAdvertising(int n) {
    if(n == 1)
    return 2;
    return viralAdvertising(n - 1) + (((g(n - 1) / 2) * 3) / 2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
