#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int cl = 0; //common length
    int sl = s.length();
    int tl = t.length();
    for(int i = 0; i < min(sl, tl); i++)
    {
        if(s[i] == t[i])
        cl++;
        else
        break;
    }
    int mor = sl + tl - (2 * cl); // Minimum operation required
    if(mor > k) //case 1
    return "No";
    else if(mor % 2 == k % 2) //case 2
    return "Yes";
    else if(sl + tl < k) // case 3
    return "Yes";
    else //default
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
