#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct set {
    int size;
    vector<int> array;
    void makeset(int s);
    void Union(int x, int y);
    int find(int x);
};

void set::makeset(int s)
{
    size = s;
    array = vector<int>(size, -1);
}
int set::find(int x)
{
    if(x > size || x < 0)
    return -1;
    if(array[x] < 0)
    return x;
    else 
    return (array[x] = find(array[x]));
}

void set::Union(int x, int y)
{
    int root1, root2;
    root1 = find(x);
    root2 = find(y);
    if(root1 == root2)
    return;
    if(root1 == -1 || root2 == -1)
    return;
     array[root2] += array[root1];
     array[root1] = root2;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;
    cin>>N>>Q;
    set s;
    s.makeset(N+1);
    for(int i = 0; i < Q; i++)
    {
        char t;
        cin>>t;
        switch(t)
        {
           case 'Q':
           {
               int n;
               cin>>n;
               int root = s.find(n);
               cout<<-(s.array[root])<<endl;
           }
           break;
           case 'M':
           {
               int m, n;
               cin>>m>>n;
               s.Union(m, n);
           }
           break;
        }
    }   
    return 0;
}
