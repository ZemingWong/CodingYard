#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // write your code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>> pq;
        for (int i = 0; i < k; ++i) {
        	pq.push(matrix[0][i]);
        }
        while(pq.top() != null && k >= 0) {
        	--k;
        	pq.top()
        }
 
    }


    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        for (int i = 0, j = 0, sum = 0, minSize = 0; i < nums.size(); ++i) {
        	while(sum < s && j < nums.size()) {
        		sum += nums[j++];
        	}

        	if(sum >=s && (j - i) > minSize) {
        		minSize = j - i;
        		++i;
        	}
        }
        return minSize;
    }

    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        // write your code here
        if (s == null)
        	return 0;

        bool[256] map;
        for (int i = 0, i < 256, ++i) map[i] = 0;
        for (int i = 0, j = 0, lenLongestSubstr = 0; i < s.size(); ++i) {
        	while (j < s.size() && map(s[j]) == 0) {
        		map(s[j++]) = 1;
        	}
        	lenLongestSubstr = lenLongestSubstr > (j - i) ? lenLongestSubstr : (j - i);

        	if (j == s.zise())
        		return lenLongestSubstr;

        	while (s[i++] != s[j]);
        }
    }

    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        if(s == null || k == 0)
        	return 0;

        bool[256] map;
        for (int i = 0; i < 256; ++i) map[i] = 0;
        for (int i = 0, int j = 0, int nDistinctChar = 0, int lenLongestSubstrKDsitinct = 0; i < s.size(); ++i) {
        	while (j < s.size() && nDistinctChar <= k) {
        		if (map[s[j]] == 0)
        			++nDistinctChar;
        		++ map[s[j++]];
        	}

        	lenLongestSubstrKDsitinct = lenLongestSubstrKDsitinct > (j - i) ? lenLongestSubstrKDsitinct : (j - i);
        	if (j = s.size())
        		return lenLongestSubstrKDsitinct;

        	while ((--map[s[i++]]) > 0);
        	--nDistinctChar;
        }
    }

    /**
     * @param A: an integer arrays sorted in ascending order
     * @param B: an integer arrays sorted in ascending order
     * @param k: An integer
     * @return: An integer
     */
    public int kthSmallestSum(int[] A, int[] B, int k) {
        // write your code here
        if (k <= 0)
        	return NULL;

        int i = 0, j = 0;
        while (k > 0) {
        	if (A[i] == '\0' && B[j] == '\0')
        		break;
        	else if (A[i] == '\0' && B[j] != '\0')
        		++j;
        	else if (A[i] != '\0' && B[j] == '\0')
        		++i;
        	else
        		if (A[i] <= B[j])
        			++i;
        		else 
        			++j;
        	--k;
        }
        if (k == 0)
        	return A[i] + B[j];
        else 
        	return NULL;
    }

    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        if (nums == NULL || n <= 0 || n > nums.size())
        	return NULL;

        int tempInt = 0; 
        for (int i = 0; i < n; ++i) {
        	for (j = i + 1; j < nums.size(); ++j) {
        		if (nums[j] > nums[i]) {
        			tempInt = nums[i];
        			nums[i] = nums[j];
        			nums[j] = tempInt;
        		}
        	}
        }
        return nums[n];
    }

    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        if (S == NULL || S.zise() < 3)
        	return NULL;

        //先排序；

        int triangleCnt = 0;
        for (int i = 0; i < S.size() - 2; ++i) {
        	for (int j = i + 1, int k = i + 2; (j < S.size() - 1) && (k < S.size()); ++j) {
        		while (S[i] + S[j] > S[k++]);
        		triangleCnt += (k - j);
        	}
        }
    }

    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        // write your code here
    	unordered_map<char, int> umap;
    	for (int i = 0; i < target.size(); ++i)
    		umap[target[i]] = 0;

    	bool containsAll = true;
    	int minWindowSize = source.size() + 1;
    	int minWindowBegin = 0;
    	int minWindowEnd = 0;
    	for (int i = 0, j = 0; i < source.size() && j < source.size(); ++i) {
    		++umap[target[j++]];

    		containsAll = true;
    		for (int k = 0; k < target.size(); ++k) {
    			if (umap[target[k]] == 0) {
    				containsAll = false;
    				break;
    			}
    		}
    		if (containsAll) {
    			while (umap[target[i]] > 1)
    				++i;
    			if (minWindowSize > (j - i)) {
    				minWindowSize =  j - i;
    				minWindowBegin = i;
    				minWindowEnd = j;
    			}
    		}
    	}
    	return source.substr(minWindowBegin, minWindowEnd - minWindowBegin);
    }
};

int main(int argc, char const *argv[])
{
	string source( "ADOBECODEBANC" );
	string target( "ABC" );

	Solution s;
	string result = s.minWindow(source, target);
	cout << result << endl;
	cout << &source << ',' << &result << endl;


	target( "ABC" );

	string result = s.minWindow(source, target);
	cout << result << endl;
	cout << &source << ',' << &result << endl;
	
	return 0;
}