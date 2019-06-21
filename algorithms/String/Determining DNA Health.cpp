#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int Count(string s1, string s)
{
    int c = 0;
    int L = s.length();
    int n = s.find(s1);
    while(n < L && n >= 0)
    {
        c++;
        s.erase(0, n + 1);
        n = s.find(s1);
        L = s.length();
    }
    return c;
}

long TotalHealth(string d, int first, int last, vector<string> genes, vector<int> health)
{
    long h = 0;
    for(int i = first; i <= last; i++)
    {
        int n = Count(genes[i], d);
        h = h + (n * health[i]);
    }
    return h;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string genes_temp_temp;
    getline(cin, genes_temp_temp);

    vector<string> genes_temp = split_string(genes_temp_temp);

    vector<string> genes(n);

    for (int i = 0; i < n; i++) {
        string genes_item = genes_temp[i];

        genes[i] = genes_item;
    }

    string health_temp_temp;
    getline(cin, health_temp_temp);

    vector<string> health_temp = split_string(health_temp_temp);

    vector<int> health(n);

    for (int i = 0; i < n; i++) {
        int health_item = stoi(health_temp[i]);

        health[i] = health_item;
    }

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    long MIN = LONG_MAX;
    long MAX = LONG_MIN;
    for (int s_itr = 0; s_itr < s; s_itr++) {
        string firstLastd_temp;
        getline(cin, firstLastd_temp);

        vector<string> firstLastd = split_string(firstLastd_temp);

        int first = stoi(firstLastd[0]);

        int last = stoi(firstLastd[1]);

        string d = firstLastd[2];
        long w = TotalHealth(d, first, last, genes, health);
        if(MIN > w)
        MIN = w;
        if(MAX < w)
        MAX = w;
    }
    cout<<MIN<<" "<<MAX;
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
