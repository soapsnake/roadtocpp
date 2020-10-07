//
// Created by soapsnake@gmail.com on 1/10/20.
//
#include "queue"

using namespace std;

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {

    }

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000)
            q.pop();
        return q.size();
    }
};