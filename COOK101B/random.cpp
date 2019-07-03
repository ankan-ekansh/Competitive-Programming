    #include<bits/stdc++.h>

    using namespace std;

    int main() {
      ios_base::sync_with_stdio(false);
      int testCases;
      cin >> testCases;
      for (int i = 0; i < testCases; ++i) {
        int days;
        cin >> days;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> proc;
        while (days--) {
          pair<int, int> temp;
          cin >> temp.first >> temp.second;//day and problems
          proc.push(temp);
        }
        int summer = 0, sched[32] = {0};
        while (!proc.empty()) {
          //pop first
          pair<int, int> temp;
          temp = proc.top();
          proc.pop();
          //add to cum sum
          summer += temp.second;
          //assign to day popped
          sched[temp.first] = summer;
        }
        int temp = sched[0];
        for (int i = 1; i < 32; ++i) {
          if (sched[i] > temp)
            temp = sched[i];
          sched[i] = temp;
        }
        //TESTING
        for (int i = 0; i < 32; ++i)
          cout << i << " " << sched[i] << "\n";

        int queries;
        cin >> queries;
        while (queries--) {
          int day, prob;
          cin >> day >> prob;
          if (sched[day] >= prob)
            cout << "Go Camp\n";
          else
            cout << "Go Sleep\n";
        }
      }
      return 0;
    }
