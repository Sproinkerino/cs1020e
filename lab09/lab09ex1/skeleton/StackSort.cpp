//=====================================================================
// FILE: StackSort.cpp
//=====================================================================

//=====================================================================
// STUDENT NAME: Ng Wei Feng
// MATRIC NO.  : A0122477E
// NUS EMAIL   : NgWeiFeng@u.nus.edu    
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


// Add more functions if necessary.


int main() {

    int T;
    bool succ;
    cin >> T;

    while (T-- > 0) { //run then minus
        int N;
        cin >> N;
        vector<int> arr;
        arr.clear();

        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        succ = true;
        
        stack<int> junc;
        vector<int> arr2;
        int last = 0;
        
        junc.push(arr[0]);
        
        for(int i = 1; i < N; i++)
        {
            
            while( !junc.empty() && succ && arr[i] > junc.top())
            {   
                
                if(last > junc.top())
                {
            
                    succ = false;
                }
                last = junc.top();
                
                arr2.push_back(last);
                
                junc.pop();
                
            }
            
            junc.push(arr[i]);
        }
        
        while(!junc.empty() && succ)
        {
            
            if(last > junc.top())
                {
                    succ = false;
                }
                arr2.push_back(junc.top());
                last = junc.top();
                junc.pop();
        }
            
    


        // Add your code here.


        if (succ) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }

    return 0;
}
