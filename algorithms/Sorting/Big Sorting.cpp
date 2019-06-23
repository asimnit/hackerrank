#include <bits/stdc++.h>

using namespace std;

// Complete the bigSorting function below.
bool compare(string s1, string s2)
{
    if(s2.length() > s1.length())
    return true;
    else if(s1.length() > s2.length())
    return false;
    else
    {
        for(int i = 0; i < s2.length(); i++)
        {
            if(s2[i] > s1[i])
            return true;
            if(s2[i] < s1[i])
            return false;
        }
    }
    return true;
}
vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), compare);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
