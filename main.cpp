// main.cpp
#include "stats.hpp"
#include "p1_library.hpp"
#include <iostream>
using namespace std;
int main() {
  string file_name = "";
  cout << "enter a filename" << endl;
  cin >> file_name;

  string column_name = "";
  cout << "enter a column name" << endl;
  cin >> column_name;

  cout << "reading column " + column_name + " from " + file_name << endl;
  vector<double> v;
  v = extract_column(file_name,column_name);

  cout << "Summary (value: frequency)" << endl;
  vector<pair<double,int> > summ;
  summ = summarize(v);
  for (int i = 0; i < summ.size(); i++) {
    pair <double,int> p = summ[i];
    cout << p.first << ": " << p.second << endl;
 }

  cout << "count = " << count(v) << endl;
  cout << "sum = " << sum(v) << endl;
  cout << "mean = " << mean(v) << endl;
  cout << "stdev = " << stdev(v) << endl;
  cout << "median = " << median(v) << endl;
  cout << "mode = " << mode(v) << endl;
  cout << "min = " << min(v) << endl;
  cout << "max = " << max(v) << endl;
  cout << "  0th percentile = " << percentile(v,0) << endl;
  cout << " 25th percentile = " << percentile(v,0.25) << endl;
  cout << " 50th percentile = " << percentile(v,0.50) << endl;
  cout << " 75th percentile = " << percentile(v,0.75) << endl;
  cout << "100th percentile = " << percentile(v,1) << endl;
}
