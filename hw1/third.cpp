#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'countBetween' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY low
 *  3. INTEGER_ARRAY high
 */
int partition(vector<int>& arr, int l, int h){
    int pivot = arr[h];
    int pos = l-1;
    for(int i = 0; i < h; i++){
        if(arr[i] < pivot){
            pos++;
            swap(arr[i],arr[pos]);
        }
    }
    swap(arr[pos+1],arr[h]);
    return(pos+1);
}
void quickSort(vector<int>& arr, int l, int h){
    if(l < h){
        int p = partition(arr,l,h);
        quickSort(arr, l, p-1);
        quickSort(arr,p+1,h);
    }
}
int binarySearch(vector<int> arr, int f, int l, int t){
    if(f <= 1){
        int m = (f + l) / 2;
        if(arr[m] == t){
            return m;
        }
        if(arr[m] > t){
            return binarySearch(arr, f, m - 1, t);
        }
        return binarySearch(arr, m+1, l, t);
    }
    return -1;
}
vector<int> countBetween(vector<int> arr, vector<int> low, vector<int> high) {
    vector<int> counted;
    if(!arr.empty() && !low.empty() && low.size() == high.size()){
        quickSort(arr, 0, arr.size()-1);
        for(int i = 0; i < low.size(); i++){
            int l = low[i];
            int h = high[i];
            int ih = binarySearch(arr,0,arr.size()-1, h);
            int il = binarySearch(arr,0,arr.size()-1, l);
                counted.push_back(ih - il);
            }
        }
    return counted;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    string low_count_temp;
    getline(cin, low_count_temp);

    int low_count = stoi(ltrim(rtrim(low_count_temp)));

    vector<int> low(low_count);

    for (int i = 0; i < low_count; i++) {
        string low_item_temp;
        getline(cin, low_item_temp);

        int low_item = stoi(ltrim(rtrim(low_item_temp)));

        low[i] = low_item;
    }

    string high_count_temp;
    getline(cin, high_count_temp);

    int high_count = stoi(ltrim(rtrim(high_count_temp)));

    vector<int> high(high_count);

    for (int i = 0; i < high_count; i++) {
        string high_item_temp;
        getline(cin, high_item_temp);

        int high_item = stoi(ltrim(rtrim(high_item_temp)));

        high[i] = high_item;
    }

    vector<int> result = countBetween(arr, low, high);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
