#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <string>
#include <queue>
using namespace sol759;
using namespace std;

/*takeaways
  - collect all the intervals from all the employees
    - employees are out of the picture now
  - sort all the intervals by start time and scan
    through them from the earliest interval
    - if you find any gap between two intervals record
      them
      - why? the intervals are coming from all the employees
        so if there is a gap than means it's a free time for
        everyone
    - conceptually we are merging two intervals; in reality
      we just need to keep the max end time of the two whether
      there is a gap or not
*/

vector<Interval> Solution::freeTime(vector<vector<Interval>> &schedule)
{
  /* collect all intervals and sort them by start time  */
  auto intervals = vector<Interval>();
  /* collect intervals from each employee */
  for (const auto e : schedule)
    intervals.insert(intervals.end(), e.begin(), e.end());

  sort(intervals.begin(), intervals.end(), [](auto &i1, auto &i2)
       { return i1.start < i2.start; });

  auto result = vector<Interval>();

  auto end = intervals[0].end;

  for (auto i = intervals.begin() + 1; i < intervals.end(); i++)
  {
    auto test = (*i);
    /* find free time; record it */
    if (test.start > end)
      /*C++ notes
        - Use emplace_back as Interval doesn't
          have a default constructor
        - you can use push_back as well;
          just create an instance of
          interval explicitly
      */
      result.emplace_back(end, test.start);

    /*
      - cover two cases:
        [1,3] then [1,2] -> end = 3
        [1,2] then [3,4] -> end = 4
      - you can think of this as merging two intervals
        into a longer one:
        [1,3] then [1,2] -> same as [1,3]
        [1,2] then [3,4] -> record the gap [2,3] and then
                            merge these two to [1,4]
    */

    end = max(end, test.end);
  }

  return result;
}
