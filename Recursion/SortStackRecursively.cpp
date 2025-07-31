/*
    Approach:
    ---------
    We use recursion to sort the stack without using any extra data structure.
    
    1. The main function `SortedStack` pops all elements recursively until the stack is empty.
    2. Then, while returning from recursion, it uses the helper function `insertp` to insert elements back in sorted order.
    3. The `insertp` function inserts the current element `temp` into the correct position in the sorted stack.
    
    This is analogous to insertion sort applied recursively on a stack.

    Time Complexity:
 
    O(n^2) - For each element, we may end up traversing the remaining stack to insert it in the correct position.

    Space Complexity:
   
    O(n) - Due to the recursive call stack.
*/

#include <iostream>
#include <stack>
using namespace std;

void insertp(stack<int>& st, int temp) {
    if (st.empty() || st.top() < temp) {
        st.push(temp);
        return;
    }

    int elem = st.top();
    st.pop();
    insertp(st, temp);
    st.push(elem);
}

void SortedStack(stack<int>& st) {
    if (st.empty()) return;

    int temp = st.top();
    st.pop();
    SortedStack(st);
    insertp(st, temp);
}
