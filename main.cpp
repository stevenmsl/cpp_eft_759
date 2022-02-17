#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol759;

string toString(vector<Interval> input)
{
  string result = "[";
  for (auto e : input)
  {
    const auto i = "[" +
                   to_string(e.start) + "," +
                   to_string(e.end) + "],";
    result += i;
  }
  /* remove the last comma */
  if (result.back() == ',')
    result.pop_back();
  result += "]";
  return result;
}

/*
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
*/
tuple<vector<vector<Interval>>, vector<Interval>> testFixture1()
{
  return make_tuple<vector<vector<Interval>>, vector<Interval>>(
      {{Interval(1, 2), Interval(5, 6)}, {Interval(1, 3)}, {Interval(4, 10)}},
      {Interval(3, 4)});
}

/*
Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
*/
tuple<vector<vector<Interval>>, vector<Interval>> testFixture2()
{
  return make_tuple<vector<vector<Interval>>, vector<Interval>>(
      {{Interval(1, 3), Interval(6, 7)},
       {Interval(2, 4)},
       {Interval(2, 5), Interval(9, 12)}},
      {Interval(5, 6), Interval(7, 9)});
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << toString(get<1>(f)) << endl;
  auto dict = get<0>(f);
  auto result = Solution::freeTime(get<0>(f));
  cout << "result: " << toString(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << toString(get<1>(f)) << endl;
  auto dict = get<0>(f);
  auto result = Solution::freeTime(get<0>(f));
  cout << "result: " << toString(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}