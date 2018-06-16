#define LOCAL
#include <iostream>
#include <set>
#include <queue>
using namespace std;

typedef long long LL;
int coeff[3] = {2, 3, 5};

int main() {
    set<LL> num_set = {1};
    priority_queue<LL, vector<LL>, greater<LL> > ugly_pq;
    ugly_pq.push(1);

    for (int i = 1; ; i++) {
        LL curr = ugly_pq.top(); ugly_pq.pop();
        if (i == 1500)
            { cout << "The 1500'th ugly number is " << curr << ".\n"; break; }
        
        for (auto& co: coeff) {
            LL new_num = curr * co;
            if (!num_set.count(new_num))
                { num_set.insert(new_num); ugly_pq.push(new_num); }
        }
    }

    return 0;
}