#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using std::priority_queue;

struct Worker {
  int id;
  long long next_free_time;
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;
  vector<int> assigned_workers_;
  vector<long long> start_times_;

  struct CompareWorker {
    bool operator()(const Worker& w1, const Worker& w2) const {
      if (w1.next_free_time == w2.next_free_time)
        return w1.id > w2.id;
      return w1.next_free_time > w2.next_free_time;
    }
  };

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());

    priority_queue<Worker, vector<Worker>, CompareWorker> queue;
    for (int i = 0; i < num_workers_; ++i)
      queue.push({i, 0});

    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      Worker work = queue.top();
      queue.pop();
      assigned_workers_[i] = work.id;
      start_times_[i] = work.next_free_time;
      work.next_free_time += duration;
      queue.push(work);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}

