#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int arraySum(int a[], int n)
    {
        int initial_sum = 0;
        return accumulate(a, a + n, initial_sum);
    }
    int min_element_values(int A[], int N)
    {
        int m_e = -1;
        for (int i = 0; i < N; i++)
        {
            if (m_e <= A[i])
            {
                m_e = A[i];
            }
        }
        return m_e;
    }
    int isvalid(int A[], int N, int M, int max_pages_to_a_student)
    {
        int no_of_student = 1;
        long long int k = 0;
        for (int i = 0; i < N; i++)
        {
            k = k + A[i];
            if (k > max_pages_to_a_student)
            {
                no_of_student++;
                k = A[i];
            }
            if (no_of_student > M)
            {
                return false;
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M)
    {
        if (M > N)
        {
            return -1;
        }

        int m_e = min_element_values(A, N);
        long long int sm_of_arr = arraySum(A, N);
        int start = m_e, end = sm_of_arr, target = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isvalid(A, N, M, mid))
            {
                target = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        };
        return target;
    }
};
int main()
{
    return 0;
}