#include <iostream>
using namespace std;
void bitStuffing(int N, int arr[])
{
    int brr[30];
    int i, j, k;
    i = 0;
    j = 0;
    while (i < N) {
        if (arr[i] == 1) {
            int count = 1;
            brr[j] = arr[i];
            for (k = i + 1;
                 arr[k] == 1 && k < N && count < 5; k++) {
                j++;
                brr[j] = arr[k];
                count++;
                if (count == 5) {
                    j++;
                    brr[j] = 0;
                }
                i = k;
            }
        }
        else {
            brr[j] = arr[i];
        }
        i++;
        j++;
    }
    for (i = 0; i < j; i++)
        cout << brr[i];
}
int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    bitStuffing(n, arr);
    return 0;
}