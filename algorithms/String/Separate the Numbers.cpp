#include <bits/stdc++.h>

using namespace std;

// Complete the separateNumbers function below.
bool Isbeautiful(string s, int n)
{
    int x = stoi(s.substr(0, n));
    int i;
    for(i = n; i < s.length(); i = i + n)
    {
        //cout<<x<<" ";
        if(i+n-1> s.length())
        return false;
        int temp = stoi(s.substr(i, n));
        if((x + 1) != temp)
        {
            if(i + n > s.length())
            return false;
            int t = stoi(s.substr(i, n + 1));
            if(x + 1 != t)
            return false;
            x = t;
            n = n+1;
        }
        else
        {
            x = temp;
        }
    }
    //cout<<x<<" "<<i<<" "<<s.substr(s.length() - n);
    if(to_string(x) == s.substr(s.length() - n))
    return true;
    else
    return false;
}
void separateNumbers(string s) {
    cout<<s.length();
    /*for(int i = 1; i <= s.length()/2; i++)
    {
        if(Isbeautiful(s, i))
        {
            cout<<"YES"<<" "<<s.substr(0, i)<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;*/
    if(Isbeautiful(s, 10))
    cout<<"YES";
    else
    cout<<"NO";
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
