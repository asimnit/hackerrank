#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    vector<int> f(26, 0);
    char a;
    for(auto c:s)
    {
        if(isalpha(c))
        {
          if(isupper(c))
          {
            a = 'A';
          }
          else 
          {
            a = 'a';
          }
           f[c - a]++;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        cout<<i<<"-"<<f[i]<<endl;
        if(f[i] == 0)
          return "not pangram";
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
