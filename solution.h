#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol759
{
  struct Interval
  {
    int start;
    int end;
    Interval(int start, int end) : start(start), end(end) {}
  };

  class Solution
  {
  private:
  public:
    static vector<Interval> freeTime(vector<vector<Interval>> &schedule);
  };

}
#endif