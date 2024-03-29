#include <vector>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;
class Solution2
{
    // Missing Number
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int total = (n * (n + 1) / 2);
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }
        return total - sum;
    }
    // Find Smallest Letter Greater Than Target
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int t = 0;
        for (char i : letters)
        {
            int l = i;
            if (i > target)
            {
                t = l;
                break;
            }
        }
        if (t == 0)
            return letters[0];
        return (char)t;
    }
    // Find the Index of the First Occurrence in a String
public:
    int strStr(string haystack, string needle)
    {
        if (needle.length() > haystack.length())
            return -1;
        for (int i = 0; i <= haystack.length() - needle.length(); i++)
        {
            if (haystack.substr(i, needle.length()) == needle)
                return i;
        }
        return -1;
    }
    // Valid Palindrome
public:
    bool isPalindrome(string s)
    {
        string filter = "";
        for (char i : s)
        {
            if (isalpha(i) || isalnum(i))
                filter += tolower(i);
        }
        int start = 0;
        int end = filter.length() - 1;
        int x = 0;
        while (start <= end)
        {
            if (filter[start] != filter[end])
                x++;
            start++;
            end--;
        }
        if (x > 0)
            return false;
        return true;
    }
    // Reverse String
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }

    // Find town judge
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> trustee(n + 1), truster(n + 1);
        for (auto i : trust)
        {
            ++truster[i[0]];
            ++trustee[i[1]];
        }
        for (int i = 1; i <= n; ++i)
        {
            if (trustee[i] == n - 1 && truster[i] == 0)
                return i;
        }
        return -1;
    }
    // Valid Anagram
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int arr1[26];
        int arr2[26];
        for (int i = 0; i < s.length(); i++)
        {
            arr1[s[i] - 'a']++;
            arr2[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
    }

    // Contains Duplicate
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
                return true;
        }
        return false;
    }

    // Sort Even and Odd Indices Independently
public:
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        vector<int> odds;
        vector<int> evens;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
                evens.push_back(nums[i]);
            else
                odds.push_back(nums[i]);
        }
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end(), greater<int>());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                nums[i] = evens.front();
                evens.erase(evens.begin());
            }
            else
            {
                nums[i] = odds.front();
                odds.erase(odds.begin());
            }
        }
        return nums;
    }

    // Longest Subsequence With Limited Sum
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());
        vector<int> answer;
        vector<int> pre(nums.size());
        pre[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            pre[i] = nums[i] + pre[i - 1];
        }
        for (int i : queries)
        {
            int start = 0, end = nums.size() - 1;
            while (start < end)
            {
                int mid = start + (end - start) / 2;
                if (pre[mid] == i)
                {
                    start = mid;
                    break;
                }
                else if (pre[mid] > i)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            if (pre[start] > i)
                start--;
            answer.push_back(start + 1);
        }
        return answer;
    }
    // Find Target Indices After Sorting Array
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                ans.push_back(i);
        }
        return ans;
    }

    // Minimum Common Value
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        // First solution
        // for(int i=0;i<nums1.size();i++)
        // {
        //     int target=nums1[i];
        //     int start=0;
        //     int end=nums2.size()-1;
        //     while(start<=end){
        //         int mid=start+(end-start)/2;
        //         if(nums2[mid]==target)
        //             return target;
        //         else if(nums2[mid]>target)
        //             end=mid-1;
        //         else
        //             start=mid+1;
        //     }
        // }
        // Second Solution
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else
                return nums1[i];
        }
        return -1;
    }

    // Maximum Average Subarray I
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        int maxSum = sum;
        for (int i = k; i < nums.size(); i++)
        {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return (double)maxSum / k;
    }

    // Maximum Ascending subarray sum
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int sum = 0;
        int maxSum = sum;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int lastAdded = nums[i];
            while (i + 1 < nums.size() && nums[i] < nums[i + 1])
            {
                if (nums[i + 1] != lastAdded)
                {
                    sum += nums[i + 1];
                    lastAdded = nums[i + 1];
                }
                i++;
            }
            maxSum = max(sum, maxSum);
            sum = 0;
        }
        return maxSum;
    }

    // Length of Last word
public:
    int lengthOfLastWord(string s)
    {
        int len = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (len == 0 && s[i] != ' ')
            {
                len++;
            }
            else if (len > 0 && s[i] == ' ')
            {
                break;
            }
            else if (len > 0 && s[i] != ' ')
            {
                len++;
            }
        }
        return len;
    }

    // Most frequent even element
public:
    int mostFrequentEven(vector<int> &nums)
    {
        map<int, int> freq;
        for (int num : nums)
        {
            if (num % 2 == 0)
                freq[num]++;
        }
        int ans = -1;
        int maxFreq = 0;
        for (auto it : freq)
        {
            if (it.second > maxFreq)
            {
                ans = it.first;
                maxFreq = it.second;
            }
        }
        return ans;
    }

    // Maximum odd binary number
public:
    string maximumOddBinaryNumber(string s)
    {
        string ones;
        string zeros;
        for (char i : s)
        {
            if (i == '1')
                ones += i;
            else
                zeros += i;
        }
        zeros += ones[0];
        ones.erase(0, 1);
        return ones + zeros;
    }

    // Valid Parenthesis
public:
    bool isValid(string s)
    {
        stack<int> brackets;
        for (char i : s)
        {
            if (i == '(')
                brackets.push(')');
            else if (i == '{')
                brackets.push('}');
            else if (i == '[')
                brackets.push(']');
            else if (brackets.empty())
                return false;
            else
            {
                char top = brackets.top();
                brackets.pop();
                if (i != top)
                    return false;
            }
        }
        return brackets.empty();
    }
    // Squares of a sorted array
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int &i : nums)
        {
            i *= i;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }

    // Search Insert position
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int val = nums[mid];
            if (val == target)
                return mid;
            else if (val > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start;
    }
    // Two Sum
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> yeah;
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (yeah.find(complement) != yeah.end())
            {
                ans[0] = yeah[complement];
                ans[1] = i;
                return ans;
            }
            yeah.inser t(make_pair(nums[i], i));
        }
        return ans;
    }

    // Divide an Array Into Subarrays With Minimum Cost I
public:
    int minimumCost(vector<int> &nums)
    {
        // int first=nums[0];
        // nums.erase(nums.begin());
        // sort(nums.begin(),nums.end());
        // first+=nums[0];
        // first+=nums[1];
        // return first;
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }

    // Linked List Cycle
public:
    bool hasCycle(ListNode *head)
    {
        // First Solution
        // unordered_map<ListNode*,int> values;
        // ListNode* i=head;
        // while(i!=nullptr){
        //     if(values.find(i)!=values.end())
        //         return true;
        //     values[i]++;
        //     i=i->next;
        // }
        // return false;

        // Second solution
        if (head == nullptr)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
    // Moving Zeroes
public:
    void moveZeroes(vector<int> &nums)
    {
        int initial = nums.size();
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        int after = nums.size();
        for (int i = 0; i < initial - after; i++)
        {
            nums.push_back(0);
        }
    }
    // Middle of the Linked List
public:
    ListNode *middleNode(ListNode *head)
    {
        // First Solution
        // ListNode* p=head;
        // int count=0;
        // while(p!=nullptr){
        //     count++;
        //     p=p->next;
        // }
        // count/=2;
        // p=head;
        // for(int i=0;i<count;i++){
        //     p=p->next;
        // }
        // return p;
        // Second Solution
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // Reverse Linked List
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode() : val(0), next(nullptr) {}
     *     ListNode(int x) : val(x), next(nullptr) {}
     *     ListNode(int x, ListNode *next) : val(x), next(next) {}
     * };
     */
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prevPtr = nullptr;
        ListNode *p = head;
        while (p != nullptr)
        {
            ListNode *dummy = new ListNode(p->val);
            dummy->next = prevPtr;
            prevPtr = dummy;
            p = p->next;
        }
        return prevPtr;
    }

    // Count elements with maximum frequency
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> myMap;
        int maxFreq = INT_MIN;
        for (int i : nums)
        {
            myMap[i]++;
            maxFreq = max(maxFreq, myMap[i]);
        }
        int ans = 0;
        for (const auto &pair : myMap)
        {
            if (pair.second == maxFreq)
                ans++;
        }
        ans *= maxFreq;
        return ans;
    }

    // Palindrome Linked List
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode() : val(0), next(nullptr) {}
     *     ListNode(int x) : val(x), next(nullptr) {}
     *     ListNode(int x, ListNode *next) : val(x), next(next) {}
     * };
     */

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *p = head;
        stack<int> q;
        while (p != nullptr)
        {
            q.push(p->val);
            cout << p->val << endl;
            // cout << q.top() << endl;
            p = p->next;
        }
        p = head;
        while (p->next != nullptr)
        {
            // cout << p->val << " " <<  q.top() << endl;
            if (q.top() != p->val)
                return false;
            q.pop();
            p = p->next;
        }
        return true;
    }
    // Intersection of two arrays
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        set<int> mySet;
        for (int i : nums1)
            mySet.insert(i);
        for (int i : nums2)
        {
            if (mySet.find(i) != mySet.end())
                ans.push_back(i);
            mySet.erase(i);
        }
        return ans;
    }

    // Find the pivot integer
    public:
    int pivotInteger(int n) {
        for(int i=1;i<=n;i++)
            if(i*(i+1)/2 == ((n-i+1)*(i+n))/2)
                return i;
        return -1;
    }
    // Sum of unique elements
    public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> myMap;
        for(int i:nums){
            myMap[i]++;
        }
        int sum=0;
        for(const auto& pair:myMap){
            if(pair.second==1)
                sum+=pair.first;
        }
        return sum;
    }
    // Apply operations to an array
    public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans(nums.size());
        int j=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
            if(nums[i]>0){
                ans[j]=nums[i];
                j++;
            }
        }
        ans[j]=nums[nums.size()-1];
        return ans;
    }
    // Smallest even multiple
public:
    int smallestEvenMultiple(int n) {
        return (n%2==0)? n : n*2;
    }
};