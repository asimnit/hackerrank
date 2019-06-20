#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b) {
    int x = b.find("010");
    int l = b.size();
    int L = l;
    while(x < l && x >= 0)
    {
        b.replace(x, 3, "");
        x = b.find("010");
        l = b.length();
    }
    return ((L - b.length())/3);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}
