#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

typedef deque<string> ins;

struct lock {
    int owner;
    int var;

    lock(int var=-1, int owner=-1) {
        this->owner = owner;
        this->var = var;
    }
} lock_t;

int n, quantum; 
int vars[26], exe_t[5];
map<string,int> op;
deque<int> ready_queue;
queue<int> block_queue;

void print_global(ins *progs) {
    cout << "n: " << n << endl;
    cout << "quantum: " << quantum << endl;

    cout << "ready queue:" << endl;
    for (deque<int>::iterator it = ready_queue.begin(); it != ready_queue.end(); it++)
        cout << *it << " ";
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "Program #" << i << ":\n";
        for (ins::iterator it = progs[i].begin(); it != progs[i].end(); it++)
            cout << *it << endl;
    }
}

void print_ready_queue() {
    cout << "ready queue:" << endl;
    for (deque<int>::iterator it = ready_queue.begin(); it != ready_queue.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void print_prog(ins *progs) {
    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "Program #" << i << ":\n";
        for (ins::iterator it = progs[i].begin(); it != progs[i].end(); it++)
            cout << *it << endl;
    }
}

int execute(const int& id, ins& instructions, int& acc) {
    string instruct = instructions.front();

    // cout << instruct << endl;
    
    stringstream ss(instruct);
    string idtf; ss >> idtf;

    if (idtf == "print") {
        ss >> idtf; char ch = idtf[0] - 'a';
        // if (lock_t.var == ch && lock_t.owner != id) 
        //     { block_queue.push(id); return 1; }
        // else 
            cout << id + 1 << ": " << vars[ch] << endl;
        
        instructions.pop_front();
        acc += exe_t[1];

    } else if (idtf == "lock") {
        if (lock_t.owner != -1)
            { block_queue.push(id); return 1; }

        instructions.pop_front();
        stringstream tmp(instructions.front());
        tmp >> idtf;
        if (idtf == "print") tmp >> idtf; 
        lock_t.var = idtf[0] - 'a';
        lock_t.owner = id;

        acc += exe_t[2];
    
    } else if (idtf == "unlock") {
        // assert(lock_t.owner != -1);

        instructions.pop_front();
        lock_t = lock();

        if (!block_queue.empty()) {
            ready_queue.push_front(block_queue.front());
            block_queue.pop();
        }
        acc += exe_t[3];
    
    } else if (idtf == "end") {
        instructions.pop_front();
        return 1;
    
    } else {
        char ch = idtf[0] - 'a';
        ss >> idtf; // skip the equal sign
        int constant; ss >> constant;
        // if (lock_t.var == ch && lock_t.owner != id)
        //     { block_queue.push(id); return 1; }
        // else
            vars[ch] = constant;
        
        instructions.pop_front();
        acc += exe_t[0];
    }

    return 0;
}

void init() {
    n = 0; quantum = 0; lock_t = lock();

    memset(vars, 0, sizeof(vars));
    memset(exe_t, 0 , sizeof(exe_t));
    
    op.clear();
    ready_queue = deque<int>(); 
    block_queue = queue<int>();
}

int main() {
#ifdef LOCAL
    freopen("./UVa210.fin", "r", stdin);
#endif

    int kase; cin >> kase;
    for (int k = 0; k < kase; k++) {
        if (k) cout << endl;

        // Initialization...
        init();

        cin >> n;
        for (int i = 0; i < 5; i++) cin >> exe_t[i]; cin >> quantum;

        ins progs[n]; getchar(); // skip the newline char
        for (int i = 0; i < n; i++) {
            progs[i] = ins();

            string line;
            while (getline(cin, line) && line != "end")
                progs[i].push_back(line);
            progs[i].push_back("end");

            ready_queue.push_back(i);
        }
        
        // print_global(progs);

        // Execution...
        while (!ready_queue.empty() || !block_queue.empty()) {

            int id = ready_queue.front(); ready_queue.pop_front();
            
            // cout << id << endl;

            int acc = 0, status = 0;
            while (acc < quantum) {
                status = execute(id, progs[id], acc);
                if (status) break;
            }

            if (!status) ready_queue.push_back(id);

            // print_prog(progs);
            // print_ready_queue();
            // cout << "size: " << block_queue.size() << endl;
        }
    }
    return 0;
}