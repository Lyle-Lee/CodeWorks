/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> table;
        for (Employee* emp: employees) {
            table[emp->id] = emp;
        }
        stack<int> stk;
        stk.push(id);
        int ans = 0;
        while (!stk.empty()) {
            int cur = stk.top();
            stk.pop();
            ans += table[cur]->importance;
            for (int sub: table[cur]->subordinates) stk.push(sub);
        }
        return ans;
    }
};
