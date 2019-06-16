#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    int L = s.length();
    int low = floor(sqrt(L));
    int up = ceil(sqrt(L));
    int row, col;
    if(up == low)
    {
        row = up;
        col = up;
    }
    else {
          if(low*low >= L)
          {
              row = low;
              col = low;
          }
          else if(low*up >= L)
          {
              row = low;
              col = up;
          }
          else
          {
              row = up;
              col = up;
          }
    }
    string w;
    for(int i = 0; i < col; i++)
    {
        int count = row;
        int j = i;
        while(count)
        {
            if(j < L)
            w.push_back(s[j]);
            else
            break;
            j = j + col;
            count--;
        }
        w.push_back(' ');
    }
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
