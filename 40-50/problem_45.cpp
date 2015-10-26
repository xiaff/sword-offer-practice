/*
    面试题45：圆圈中最后剩下的数字
    0,1，...n-1这n个数字排成一个圆圈，
    从数字0开始每次从这个圆圈里删除第m个数字，
    求出这个圆圈里剩下的最后一个数字。
*/

#include<list>

using namespace std;

class Solution
{
public:
    int lastRemaining(int n, int m) {
        if (n<1 || m<1) {
            return -1;
        }

        list<int> nums;
        for (int i = 0;i < n;i++) {
            nums.push_back(i);
        }

        list<int>::iterator it = nums.begin();
        list<int>::iterator next;
        while (nums.size() > 1) {
            for (int i = 0;i < m;i++) {
                it++;
                if (it == nums.end()) {
                    it = nums.begin();
                }
            }
            it++;
            next = it;
            if (next == nums.end()) {
                next = nums.begin();
            }
            it--;
            nums.erase(it);
            it = next;
        }
        return *it;
    }

    int lastRemaining_2(int n,int m){
       if(n<1 || m<1)
            return  -1;
     
        int last=0;
        for(int i=2;i<=n;i++){
            last=(last+m)%i;
        }
        return last;
    }
    
};