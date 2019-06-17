#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
bool checkAlt(char c1, char c2, string s) // whether c1 and c2 alternate in s
{
    int m = s.find(c1);
    int n = s.find(c2);
    int p;
    char prev;
    if(m < n)
    {
        p = m;
        prev = c1;
    }
    else 
    {
        p = n;
        prev = c2;
    }
    for(int i = p+1; i < s.length(); i++)
    {
        if(s[i] == c1 || s[i] == c2)
        {
            if(prev == s[i])
            return false;
            prev = s[i];
        }
    }
    return true;
}
int alternate(string s) {
    vector<int> f(25, 0); //frequency of the letters in s
    string d; //contains all distict letters of s
    int r = 0;
    for(auto n:s)
    {
        if(f[n - 'a'] == 0)
        d.push_back(n);
        f[n - 'a']++;
    }
    for(int i = 0; i < d.length(); i++)
    {
        for(int j = i + 1; j < d.length(); j++)
        {
            char c1 = d[i];
            char c2 = d[j];
            if(checkAlt(c1, c2, s))
            {
                if(r < f[c1 - 'a'] + f[c2 - 'a'])
                  r = f[c1 - 'a'] + f[c2 - 'a'];
            }
        }
    }
    cout<<d;
    return r;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
