#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cassert>
using namespace std;

typedef set<string> Users;
map<string,Users> UserCache;
string space = "     ";

void init() {
    string line;
    while (getline(cin, line) && line.substr(0,3) == "MTA") {
        stringstream ss(line);
        string mta; ss >> mta; ss >> mta;
        int n; ss >> n;
        
        while (n--) {
            string user; ss >> user;
            if (UserCache.count(mta)) UserCache[mta].insert(user);
            else UserCache[mta] = {user};
        }
    }
}

void print_user_cache() {
    for (map<string,Users>::iterator it = UserCache.begin(); it != UserCache.end(); it++) {
        cout << it->first << ":";
        for (Users::iterator j = (it->second).begin(); j != (it->second).end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
}

string extract_info(const string& s, int op) {
    int i;
    for (i = 0; i < s.length(); i++)
        if (s[i] == '@') break;
    assert(s.length() > i + 1);

    if (op)
        return s.substr(i + 1, s.length() - i - 1);
    else
        return s.substr(0, i);
}

void communicate(const string& sndr, vector<string> rcvers, vector<string> msg) {
    string sndr_mta = extract_info(sndr, 1);

    map<string,vector<string> > recv_map; vector<string> mtas; 
    map<string,set<string> > names;
    for (auto& addr: rcvers) {
        string name = extract_info(addr, 0);
        string mta = extract_info(addr, 1);
        if (!recv_map.count(mta))
            mtas.push_back(mta);
        
        if (!names[mta].count(name)) {
            recv_map[mta].push_back(name);
            names[mta].insert(name);
        }
    }

    for (auto& mta: mtas) {
        cout << "Connection between " << sndr_mta << " and " << mta << endl;
        cout << space << "HELO " << sndr_mta << endl << space << "250\n";
        cout << space << "MAIL FROM:<" << sndr << ">\n" << space << "250\n";

        int nmemb = 0;
        for (auto& recv: recv_map[mta]) {
            cout << space << "RCPT TO:<" << recv << "@" << mta << ">\n";
            if (UserCache[mta].count(recv)) { cout << space << "250\n"; nmemb++; }
            else cout << space << "550\n";
        }

        if (nmemb) {
            cout << space << "DATA\n" << space << "354\n";
            for (auto& line: msg) cout << space << line << endl;
            cout <<  space << ".\n" << space << "250\n";
        }
        cout << space << "QUIT\n" << space << "221\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("./UVa814.fin", "r", stdin);
#endif
    
    init();
    // print_user_cache();
    string line;
    while (getline(cin, line) && line[0] != '*') {
        // Get sender's info.
        stringstream ss(line);
        string sender; ss >> sender;
        // Get receivers' info.
        vector<string> receivers; string user;
        while (ss >> user) receivers.push_back(user);
        // Get the message.
        getline(cin, line); assert(line[0] == '*'); // skip the asterisk
        vector<string> msg;
        while (getline(cin, line) && line[0] != '*') 
            msg.push_back(line);

        communicate(sender, receivers, msg);
    }

    return 0;
}