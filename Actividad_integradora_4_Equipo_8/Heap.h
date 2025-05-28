#ifndef _HEAP_H_
#define _HEAP_H_

#include <vector>
#include <utility>
#include <algorithm>

// Max-heap: push O(log n), pop O(log n), top O(1)
template <typename T>
class Heap {
private:
    std::vector<T> data;
    bool cmp(const T& a, const T& b) const {
        return a < b; // b tiene más prioridad si b > a
    }

public:
    void push(const T& v) {
        data.push_back(v);                // O(1)
        int i = data.size() - 1;
        while (i > 0) {                   // O(log n)
            int p = (i - 1) / 2;
            if (cmp(data[p], data[i])) {
                std::swap(data[p], data[i]);
                i = p;
            } else {
                break;
            }
        }
    }

    const T& top() const {               // O(1)
        return data.front();
    }

    void pop() {
        std::swap(data.front(), data.back());
        data.pop_back();                  // O(1)
        int i = 0;
        int n = data.size();
        while (true) {                    // O(log n)
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int mx = i;
            if (l < n && cmp(data[mx], data[l])) mx = l;
            if (r < n && cmp(data[mx], data[r])) mx = r;
            if (mx == i) {
                break;
            }
            std::swap(data[i], data[mx]);
            i = mx;
        }
    }

    bool empty() const {                 // O(1)
        return data.empty();
    }
};

#endif 