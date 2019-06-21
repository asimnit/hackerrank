#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    int L = s.length();
    if(L % 2 != 0)
    return -1;
    string s1 = s.substr(0, L/2);
    string s2 = s.substr(L/2, L/2);
   cout<<s1<<endl<<s2<<endl;
    int count = 0;
    for(auto c:s1)
    {
        int n = s2.find(c);
        if(n < 0 || n > L/2)
        count++;
        else
        s2.erase(n, 1);
    }
    cout<<s1<<endl<<s2;
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
