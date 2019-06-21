#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {
    vector<int> f1(26, 0);
    vector<int> f2(26, 0);
    for(auto c:s1)
    {
        f1[c - 'a']++;
    }
    for(auto c:s2)
    {
        f2[c - 'a']++;
    }
    int c = 0;
    for(int i = 0; i < 26; i++)
    {
        c = c + abs(f1[i] - f2[i]);
    }
    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
