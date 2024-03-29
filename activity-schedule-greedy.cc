//  Activity Schedule Greedy Algorithm
// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

// You are given n activities with their start and finish times. Select the
// maximum number of activities that can be performed by a single person,
// assuming that a person can only work on a single activity at a time. Example:
//
// Example 1 : Consider the following 3 activities sorted by
// by finish time.
//      start[]  =  {10, 12, 20};
//      finish[] =  {20, 25, 30};
// A person can perform at most two activities. The
// maximum set of activities that can be executed
// is {0, 2} [ These are indexes in start[] and
// finish[] ]
//
// Example 2 : Consider the following 6 activities
// sorted by by finish time.
//      start[]  =  {1, 3, 0, 5, 8, 5};
//      finish[] =  {2, 4, 6, 7, 9, 9};
// A person can perform at most four activities. The
// maximum set of activities that can be executed
// is {0, 1, 3, 4} [ These are indexes in start[] and
// finish[] ]
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// this is a test

int getMaxSchedule(int start[], int finish[], int n, int limit) {
	if(n <= 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	int ans = 1;
	int lastF = finish[0];
	int tempN = 0;
	for(int i = 1; i < n; i++){
		if(lastF <= start[i]){
			lastF = finish[i];
			ans++;
		}
	}
	return min(limit,ans);
}

int main() {
  int start[]  =  {1, 3, 0, 5, 8, 5};
  int finish[] =  {2, 4, 6, 7, 9, 9};
  int n = sizeof(start) / sizeof(int);
  cout << "getMaxSchedule returns " << getMaxSchedule(start, finish, n, n)
       << endl;
  cout << "getMaxSchedule returns " << getMaxSchedule(start, finish, n, 4)
       << endl;
  return 0;
}
