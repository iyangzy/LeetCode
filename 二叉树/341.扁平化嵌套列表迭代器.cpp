#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
class NestedIterator
{
private:
    stack<NestedInteger> st;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++)
        {
            st.push(*iter);
        }
    }

    int next()
    {
        auto t = st.top();
        st.pop();
        return t.getInteger();
    }

    bool hasNext()
    {
        while (!st.empty())
        {
            auto cur = st.top();
            if (cur.isInteger())
                return true;
            st.pop();
            auto curList = cur.getList();
            for (auto iter = curList.rbegin(); iter != curList.rend(); iter++)
            {
                st.push(*iter);
            }
        }
        return false;
    }
};