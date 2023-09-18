// stats.cpp
#include "stats.hpp"
#include "p1_library.hpp"
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<double, int> > summarize(vector<double> v) {
  sort(v);
  vector<pair<double,int> > summ;
  double val = v[0];
  int freq = 0;
  // create a for loop to iterate through the vector
  for (int i = 0; i < v.size(); i++) {
    // if the value is the same as the previous value, increment the frequency
    if (v[i] == val) {
      freq ++;
    }
    // if the value is different, push the value and frequency to the vector
    else {
      summ.push_back({val,freq});
      val = v[i];
      freq = 1; 
    }
  }
  summ.push_back({val, freq});
  return summ;
}

int count(vector<double> v) {
  return v.size();
}

double sum(vector<double> v) {
  double sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  return sum;
}

double mean(vector<double> v) {
  return sum(v) / v.size();
}

double median(vector<double> v) {
  sort(v);
  int size = v.size();
  int middle = size / 2;
  // if the size is even, return the average of the two middle numbers
  if (size % 2 == 0) {
    return (v[middle - 1] + v[middle]) / 2.0; 
  }
  // if the size is odd, return the middle number
  return v[middle];
}

double mode(vector<double> v) {
  vector<pair<double,int> > summ = summarize(v);
  int freq = 0;
  double mode = 0;
  for (int i = 0; i < summ.size(); i++) {
    // if the frequency is greater than the current frequency, set the mode
    if (summ[i].second > freq) {
      freq = summ[i].second;
      mode = summ[i].first;
    }
  }
  return mode;
}

double min(vector<double> v) {
  sort(v);
  return v[0];
}

double max(vector<double> v) {
  sort(v);
  return v[v.size()-1];
}

double stdev(vector<double> v) {
  double diff = 0;
  for (int i = 0; i < v.size(); i++) {
    // calculate the sum of the squared differences
    diff += pow((v[i] - mean(v)),2);
  }
  return static_cast<double>(sqrt(diff / (v.size()-1)));
}

double percentile(vector<double> v, double p) {
  sort(v);
  double n = p * (v.size()-1) + 1;
  double k = 0;
  // modf returns the fractional part of n and stores the integer part in k
  double d = modf(n , &k);
  k--;

  // if the fractional part is 0, return the value at index k
  if (k == v.size()-1) {
    return v[k];
  }
  return v[k] + d * (v[k+1] - v[k]);
}