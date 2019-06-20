#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    vector< vector<int> > v;
    for(auto s:arr)
    {
        vector<int> f(26, 0);
        for(auto c:s)
        {
            f[c - 'a']++;
        }
        v.push_back(f);
    }
    int r = 0;
    for(int i = 0; i < 26; i++)
    {
        int flag = 0;
        for(int j = 0; j < v.size(); j++)
        {
            if(v[j][i] == 0)
            {
                flag++;
                break;
            }
        }
        if(flag == 0)
        r++;
    }
    return r;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
