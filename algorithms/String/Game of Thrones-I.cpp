#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    vector<int> f(26, 0);
    for(auto c:s)
    {
        f[c - 'a']++;
    }
    int flag = 0;
    for(auto n:f)
    {
        if(n % 2 != 0)
        {
           flag++;
        }
        if(flag == 2)
        return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
