#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class FrequencyCount{
private:
    unordered_map<int, int> frequency_count;

public:
    FrequencyCount(const vector<int> &arr){
        for (int i = 0; i < arr.size(); i++){
            int ele = arr[i];
            if (frequency_count.find(ele) == frequency_count.end()){
                frequency_count[ele] = 1;
            }
            else{
                frequency_count[ele]++;
            }
        }
    }

    void DisplayFrequency() const{
        for (const auto &pair : frequency_count){
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    FrequencyCount count(arr);
    count.DisplayFrequency();
    return 0;
}
