#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef queue<int> Queue;

int main() {
#ifdef LOCAL
    freopen("./UVa540.fin", "r", stdin);
#endif

    int n, kase = 1;
    while (cin >> n && n) {
        cout << "Scenario #" << kase++ << endl;
        map<int,int> IDCache; // Maps People's ID to his/her teamID.
        vector<Queue> QCache; // An array of teams ordered by teamID.
        queue<int> teamQueue; // The team queue.

        // Initialize IDCache and QCache.
        while (n--) {
            QCache.push_back(Queue());
            int TID = QCache.size() - 1, p; cin >> p;
            
            while (p--) {
                int PID; cin >> PID;
                IDCache[PID] = TID;
            }
        }

        // Simulate the operations.
        string op;
        while (cin >> op && op != "STOP") {
            int PID;
            if (op[0] == 'E') {
                cin >> PID; int TID = IDCache[PID];
                if (QCache[TID].empty())
                    teamQueue.push(TID);
                QCache[TID].push(PID);
            
            } else {
                int TID = teamQueue.front();
                int res = QCache[TID].front(); 
                cout << res << endl;
                
                QCache[TID].pop();
                if (QCache[TID].empty()) teamQueue.pop();
            }
        }

        cout << "\n";
    }

    return 0;
}