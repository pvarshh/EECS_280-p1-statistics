/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

// Add prototypes for you test functions here.
void test_summarize_small_data_set();
void test_count_small_data_set();
void test_sum_small_data_set();
void test_mean_small_data_set();
void test_median_small_data_set();
void test_mode_small_data_set();
void test_min_small_data_set();
void test_max_small_data_set();
void test_stdev_small_data_set();
void test_percentile_small_data_set();

int main() {
  // Call your test functions here
  test_summarize_small_data_set();
  test_count_small_data_set();
  test_sum_small_data_set();
  test_mean_small_data_set();
  test_median_small_data_set();
  test_mode_small_data_set();
  test_min_small_data_set();
  test_max_small_data_set();
  test_stdev_small_data_set();
  test_percentile_small_data_set();

  return 0;
}

const double epsilon = 0.01;

// Add the test function implementations here.
void test_summarize_small_data_set() {
  cout << endl << "test_summarize_small_data_set" << endl;
  
  vector<double> sortedVector {1.0, 1.0, 2.0, 2.0, 2.0, 3.0};
  vector<pair<double, int>> result2 = summarize(sortedVector);
  assert(result2[0] == make_pair(1.0, 2));
  assert(result2[1] == make_pair(2.0, 3));
  assert(result2[2] == make_pair(3.0, 1));

  vector<double> unsortedVector {2.0, 1.0, 3.0, 2.0, 1.0};
  vector<pair<double, int>> result3 = summarize(unsortedVector);
  assert(result3[0] == make_pair(1.0, 2));
  assert(result3[1] == make_pair(2.0, 2));
  assert(result3[2] == make_pair(3.0, 1));

  vector<double> randomVector {5.0, 2.0, 2.0, 3.0, 5.0, 2.0, 1.0};
  vector<pair<double, int>> result4 = summarize(randomVector);
  assert(result4[0] == std::make_pair(1.0, 1));
  assert(result4[1] == std::make_pair(2.0, 3));
  assert(result4[2] == std::make_pair(3.0, 1));
  assert(result4[3] == std::make_pair(5.0, 2));

  cout << "All test cases passed!" << endl;  
}


void test_count_small_data_set() {
  cout << endl << "test_count_small_data_set" << endl;

  vector<double> test_one {1,2,3};
  assert(count(test_one) == 3);

  vector<double> test_two {1,2,3,4,5,6,7,8,9};
  assert(count(test_two) == 9);

  cout << "All test cases passed!" << endl;  
}

void test_sum_small_data_set() {
  cout << endl << "test_sum_small_data_set" << endl;

  vector<double> test_one {1,2,3};
  assert(sum(test_one) == 6);

  vector<double> test_two {100,23,37};
  assert(sum(test_two) == 160);

  cout << "All test cases passed!" << endl;  
}

void test_mean_small_data_set() {
  cout << endl << "test_mean_small_data_set" << endl;

  vector<double> test_one {1,2,3};
  assert(mean(test_one) == 2);

  vector<double> test_two {100,23,27};
  assert(mean(test_two) == 50);

  cout << "All test cases passed!" << endl;  
}

void test_median_small_data_set() {
  cout << endl << "test_median_small_data_set" << endl;

  vector<double> test_one {1,5,2,5,3};
  assert(median(test_one) == 3);

  vector<double> test_two {10,1,11,3,7,5};
  assert(median(test_two) == 6);

  vector<double> test_three {1.1};
  assert(median(test_three) == 1.1);

  cout << "All test cases passed!" << endl;  
}

void test_mode_small_data_set() {
  cout << endl << "test_mode_small_data_set" << endl;

  vector<double> test_one {1,5,2,5,3};
  assert(mode(test_one) == 5);

  vector<double> test_two {10,1,11,3,7,5};
  cout << mode(test_two) << endl;
  assert(mode(test_two) == 1);

  vector<double> test_three {2,4,3,10,10,5,6,5,1,2};
  cout << mode(test_three) << endl;
  assert(mode(test_three) == 2);

  cout << "All test cases passed!" << endl;  
}

void test_min_small_data_set() {
  cout << endl << "test_min_small_data_set" << endl;

  vector<double> test_one {1,5,2,5,3,0};
  assert(min(test_one) == 0);

  vector<double> test_two {10,1,11,1,3,7,5};
  assert(min(test_two) == 1);

  cout << "All test cases passed!" << endl;  
}

void test_max_small_data_set() {
  cout << endl << "test_max_small_data_set" << endl;

  vector<double> test_one {1,5,2,5,3,0};
  assert(max(test_one) == 5);

  vector<double> test_two {10,1,11,1,3,7,5};
  assert(max(test_two) == 11);

  cout << "All test cases passed!" << endl;  
}

void test_stdev_small_data_set() {
  cout << endl << "test_stdev_small_data_set" << endl;
  
  
  vector<double> test_one {1,5,2,5,3,0};
  assert((abs(stdev(test_one) - 2.06559)) < epsilon);

  vector<double> test_two {10,1,11,1,3,7,5};
  assert((abs(stdev(test_two) - 4.07664)) < epsilon);

  vector<double> test_three {2,4,3,10,10,5,6,5,1,2};
  assert((abs(stdev(test_three) - 3.15524)) < epsilon);

  vector<double> test_four {1.8,10.2,4,4,6.9,8,9,1};
  assert((abs(stdev(test_four) - 3.39934)) < epsilon);

  cout << "All test cases passed!" << endl;  
}

void test_percentile_small_data_set() {
  cout << endl << "test_percentile_small_data_set" << endl;
  
  vector<double> test_one {1,5,2,5,3,0}; 
  assert(abs(percentile(test_one,0) - 0) < epsilon);    

  vector<double> test_two {10,1,11,1,3,7,5};
  assert(abs(percentile(test_two,0.25) - 2) < epsilon);

  vector<double> test_three {2,4,3,10,10,5,6,5,1,2};
  assert(abs(percentile(test_three,0.75) - 5.75) < epsilon);

  vector<double> test_four {2,4,3,10,21,5,6,5,1,2,33,9,4};
  assert(abs(percentile(test_four,0.50) - 5) < epsilon);

  vector<double> test_five{2,4,3,10,21,5,6,5,10,1,11,1,3,7,5};
  assert(abs(percentile(test_five,1.00) - 21) < epsilon);
  
  cout << "All test cases passed!" << endl;  
}
