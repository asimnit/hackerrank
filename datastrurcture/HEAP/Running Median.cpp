#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
 struct lower {
   vector<double> array;
   int size;
   int count;
   void insert(double v);
   double Delete_max();
 private:
   void percolatedown(int i);
 };

 void lower::percolatedown(int i) {
   if (i < 0 || i >= count)
     return;
   int l = 2 * i + 1;
   int r = 2 * i + 2;
   int max;
   if (l < count && array[l] > array[i])
     max = l;
   else
     max = i;
   if (r < count && array[r] > array[max])
     max = r;
   if (i != max) {
     int temp = array[i];
     array[i] = array[max];
     array[max] = temp;
     percolatedown(max);
   }
 }

double lower::Delete_max()
{
  int i;
  if (count == 0)
  return -1;
  double t = array[0];
  array[0] = array[count - 1];
  count--;
  percolatedown(0);
  return t;
}

void lower::insert(double v) {
  array[count] = v;
  count++;
  int i = count - 1;
  while ((i - 1) / 2 >= 0) {
    if (array[i] > array[(i - 1) / 2]) {
      int temp = array[i];
      array[i] = array[(i - 1) / 2];
      array[(i - 1) / 2] = temp;
      i = (i - 1) / 2;
    } 
    else
      break;
  }
}

struct higher {
  vector<double> array;
  int size;
  int count;
  void insert(double v);
  double Delete_min();

private:
  void percolatedown(int i);
};

void higher::percolatedown(int i) {
  if (i < 0 || i >= count)
    return;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int min;
  if (l < count && array[l] < array[i])
    min = l;
  else
    min = i;
  if (r < count && array[r] < array[min])
    min = r;
  if (i != min) {
    int temp = array[i];
    array[i] = array[min];
    array[min] = temp;
    percolatedown(min);
  }
}

void higher::insert(double v) {
  array[count] = v;
  count++;
  int i = count - 1;
  while ((i - 1) / 2 >= 0) {
    if (array[i] < array[(i - 1) / 2]) {
      double temp = array[i];
      array[i] = array[(i - 1) / 2];
      array[(i - 1) / 2] = temp;
      i = (i - 1) / 2;
    } 
    else
      break;
  }
}

double higher::Delete_min()
{
  int i;
  if (count == 0)
    return -1;
  double t = array[0];
  array[0] = array[count - 1];
  count--;
  percolatedown(0);
  return t;
}

int Signum(lower l, higher h)
{
    if(l.count == h.count)
    return 0;
    else if(l.count > h.count)
    return -1;
    else 
    return 1;
}
vector<double> runningMedian(vector<int> a) {
    /*
     * Write your code here.
     */
     vector<double> v;
    int n = a.size();
    lower l;
    higher h;
    l.array = vector<double>(n, -1);
    h.array = vector<double>(n, -1);
    l.count = 0;
    h.count = 0;
    l.size = n;
    h.size = n;
    for(int i = 0; i < n; i++)
    {
      double e = a[i];
      int s = Signum(l, h);
      switch(s)
      {
          case 0:
          {
             if(e < l.array[0])
             {
                 l.insert(e);
                 v.push_back(l.array[0]);
             }
             else{
                 h.insert(e);
                 v.push_back(h.array[0]);
             }
          }
          break;
          case 1:
          {
              if(e < l.array[0])
              {
                  l.insert(e);
              }
              else
              {
                  h.insert(e);
                  double p = h.Delete_min();
                  l.insert(p);
              }
              v.push_back((l.array[0] + h.array[0])/2);
          }
          break;
          case -1:
          {
              if(e < l.array[0])
              {
                  l.insert(e);
                  double p = l.Delete_max();
                  h.insert(p);
              }
              else
              {
                  h.insert(e);
              }
              v.push_back((l.array[0] + h.array[0])/2);
          }
          break;
      }
    }
    return v; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout<< fixed << setprecision(1) << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
