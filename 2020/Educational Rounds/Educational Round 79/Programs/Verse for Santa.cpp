#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_elements, maximum_seconds;
    cin >> no_of_elements >> maximum_seconds;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <long long> sum_till(no_of_elements + 1, 0);
    vector <long long> max_till(no_of_elements + 1, 0);
    vector <long long> max_index(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum_till[i] = sum_till[i - 1] + A[i];
        
        if(A[i] > max_till[i - 1])
        {
            max_till[i] = A[i];
            max_index[i] = i;
        }
        else
        {
            max_till[i] = max_till[i - 1];
            max_index[i] = max_index[i - 1];
        }
    }
    
    if(sum_till[no_of_elements] <= maximum_seconds)
    {
        cout << "0\n";
        
        return;
    }
    
    for(int i = no_of_elements; i >= 1; i--)
    {
        if(sum_till[i] - max_till[i] <= maximum_seconds)
        {
            cout << max_index[i] << "\n";
            
            return;
        }
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
