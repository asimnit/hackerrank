#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct heap
{
   vector<int> array;
   int size;
   int count;
   void insert(int v);
   void Delete(int v);
   int print();
   private:
   void percolatedown(int i);
};

void heap::percolatedown(int i)
{
    if(i < 0 || i >= count)
    return;
    int l = 2*i + 1;
    int r = 2*i + 2;
    int min;
    if(l < count && array[l] < array[i])
    min = l;
    else
    min = i;
    if(r < count && array[r] < array[min])
    min = r;
    if(i != min)
    {
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
        percolatedown(min);
    }
}

void heap::insert(int v)
{
    array[count] = v;
    count++;
    int i = count - 1;
    while((i-1)/2 >= 0)
    {
        if(array[i] < array[(i-1)/2])
        {
            int temp = array[i];
            array[i] = array[(i-1)/2];
            array[(i-1)/2] = temp;
            i =  (i - 1)/2;
        }
        else
        break;
    }
}

void heap::Delete(int v)
{
    int i;
    if(count == 0)
    return;
    for(i = 0; i < count; i++)
    {
        if(v == array[i])
        {
            array[i] = array[count - 1];
            count--;
            percolatedown(i);
            break;
        }
    }
}

int heap::print()
{
    return array[0];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int Q;
    cin>>Q;
    heap h;
    h.array = vector<int>(Q);
    h.count = 0;
    h.size = Q;
    for(int i = 0; i < Q; i++)
    {
        int t;
        cin>>t;
        switch(t)
        {
            case 1:
            {
                int v;
                cin>>v;
                h.insert(v);
                break;
            }
            case 2:
            {
                int v;
                cin>>v;
                h.Delete(v);
                break;
            }
            case 3:
            {
                cout<<h.print()<<endl;
                break;
            }
        }
    }
    return 0;
}
