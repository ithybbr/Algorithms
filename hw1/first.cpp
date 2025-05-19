#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'groupSort' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 void merge(vector<vector<int>>& arr, int f, int m, int l){
     int fsize = m - f + 1;
     int lsize = l - m;
     vector<vector<int>> L(fsize, vector<int>(2)), R(lsize, vector<int>(2));
     
     for(int i = 0; i < fsize; i++){
         for(int j = 0; j < 2; j++){
             L[i][j] = arr[f+i][j];
         }
     }
     for(int i = 0; i < lsize; i++){
         for(int j = 0; j < 2; j++){
             R[i][j] = arr[m+1+i][j];
         }
     }
     int i = 0;
     int j = 0;
     int k = f;
     while(i < fsize && j <lsize){
         if(L[i][1] > R[j][1]){
             arr[k][0] = L[i][0];
             arr[k][1] = L[i][1];
             cout << "forst" << endl;
             cout << arr[k][0] << arr[k][1] << endl;
             i++;
         }
         else if(L[i][1] == R[j][1]){
             if(L[i][0] < R[j][0]){
                 arr[k][0] = L[i][0];
                 arr[k][1] = L[i][1];
                cout << "second" << endl;
                cout << arr[k][0] << arr[k][1] << endl;
                 i++;
             }
            else {
                arr[k][0] = R[j][0];
                arr[k][1] = R[j][1];
                j++;
            }
         }
         else{
                 arr[k][0] = R[j][0];
                 arr[k][1] = R[j][1];
                 cout << "thord" << endl;
             cout << arr[k][0] << arr[k][1] << endl;
                 j++;
             }
         k++;
     }
     while(i < fsize){
         arr[k][0] = L[i][0];
         arr[k][1] = L[i][1];
         i++;
         k++;
     }
     while(j < lsize){
         arr[k][0] = R[j][0];
         arr[k][1] = R[j][1];
         j++;
         k++;
     }
        cout << "arrr:" << endl;
     for(int ms = 0; ms < k; ms++){
        cout << arr[ms][0] << arr[ms][1] << endl;
     }
}
void mergeSort(vector<vector<int>>& arr, int f, int l){
    if(f < l){
        int m = f + (l-f) / 2;
        mergeSort(arr,f,m);
        mergeSort(arr, m + 1, l);
        cout << "clear";
        merge(arr, f, m, l);
    }
}
vector<vector<int>> groupSort(vector<int> arr){
    unordered_map<int, int> freq;
    for(int num: arr){
        freq[num]++;
    }
    vector<vector<int>> sorted;
    for(auto it = freq.begin(); it != freq.end(); ++it){
        sorted.push_back({it->first, it->second});
    }
    for(int i = 0; i < sorted.size(); i++){
        cout << sorted[i][0] << " freq: " << sorted[i][1] << endl;
    }
    mergeSort(sorted, 0, sorted.size() - 1);
    return sorted;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(4);
    vector<vector<int>> sorted = groupSort(arr);
    cout << "Sorted Array: " << endl;
        for (const auto& pair : sorted) {
            cout << pair[0] << " : " << pair[1] << endl;
        }
    return 0;
}
