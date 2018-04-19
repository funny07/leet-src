#include <stdio.h>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        bool same = false;
        vector<int>::iterator iter_cur = nums.begin();
        vector<int>::iterator iter = nums.begin();
        for (++iter; iter!=nums.end(); ++iter)
        {
            if(*iter == *iter_cur)
            {
                if (!same)
                    iter_cur++;
                same = true;
            }
            else{
                if (!same)
                    iter_cur++;
                else
                    *iter_cur = *iter;

                same = false;
            }
        }
        if (!same)
            ++iter_cur;
        nums.erase(iter_cur, iter);
        return nums.size();
    }
};

int main()
{
    Solution sln;
    vector<int> vec;
    int nums[] = {1,1,2,3};
    for (int i=0; i<sizeof(nums)/sizeof(int);i++)
        vec.push_back(nums[i]);

    int length = sln.removeDuplicates(vec);

    printf("vec.size() = %ld\n", vec.size());
    for (vector<int>::iterator iter = vec.begin(); iter!=vec.end(); ++iter)
    {
        printf("%d ", *iter);
    }
    printf("\n");
    return length;
}