/*
Breanna was bored. The power had gone out in her neighborhood (again). No power, no router, no internet. 
She had taken to playing paper-and-pencil games with her brother to pass the time. Even that could only entertain them for so long. 
Suddenly, her brother wrote down a sequence of integers.
"If you could write each of these numbers once to combine them into a larger one, what is the greatest number you could form," he asked. 
Maybe he could distract her for a while. They started with the numbers 1, 2, 3, 4, 5 through. 
Breanna could easily see that the answer was 54321. But the questions became tougher as the sequences became longer. Could you solve these puzzles too?
*/

/*
Input Format

The input will begin with a line containing an integer T, denoting the number of test cases. 
Each case will consist of two integers A and B, representing the sequence of integers from A to B. There will be a space separating those values.
*/

/*
Output Format

The output will consist of one line for each test case. 
Each line will have the form Case #X: Y, where X indicates the case number and Y indicates the maximum number that can be produced by concatenating the numbers in the given sequence. 
The order of the results must follow the same order in which the test cases are provided.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool f(string s1, string s2){
    string t1 = s1+s2, t2 = s2+s1;
    
    //if (t1.length() != t2.length()) cout << "!!!!!";
    for (int i = 0; i < t1.length(); i++)
        if (t1[i] > t2[i]) return 1;
        else if (t2[i] > t1[i]) return 0;
 
    return (s1+s2) > (s2+s1);
    //return t1[t1.length()-1] == t2[t2.length()-1];
}

int main() {
    int test, a, b, mi, ma, num;
    string temp;
    vector<string> nums;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> test;
    
    for(int t = 1; t <= test; t++){
        cin >> a >> b;
        
        mi = min(a, b); ma = max(a, b);
        nums.clear();
        
        for (int i = mi; i <= ma; i++){
            num = i;
            temp = "";
            
            if (!num) temp = "0";
            
            while (num){
                temp += (num%10)+'0';
                num /= 10;
            }
            
            reverse(temp.begin(), temp.end());
            nums.push_back(temp);
            //cout << temp << " ";
        } 
        sort(nums.begin(), nums.end(), f);
        
        cout << "Case #" << t << ": "; for (int i = 0; i < nums.size(); i++) cout << nums[i]; cout << "\n";
    }
    
    return 0;
}
