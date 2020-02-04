#include <iostream>
#include <algorithm>
#include <fstream>
#include <ostream>
#include <vector>
using namespace std;
//int startingIndex;
int findFreq(int arr[], int n, int leftBound, int rightBound)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= leftBound && arr[i] <= rightBound)
        {
            count++;
        }
    }
    //cout << "Count for " << leftBound << "-" << rightBound << ": " << count << endl;
    return count;
}
void printHistogram(int arr[], int n, ofstream&out)
{
    int freqArr[10];
    int l = 0;
    int r = 9;
    for(int k = 0; k < 10; k++)
    {

        freqArr[k] = findFreq(arr, n, l, r);
        l += 10;
        r += 10;
    }
    int maxEl = *std::max_element(std::begin(freqArr), std::end(freqArr));
    if(maxEl > 10)
    {
        for(int p = 0; p < 10; p++)
        {
            freqArr[p] = freqArr[p]/2.0;
        }
    }
    for(int i = 10; i > 0; i--)
    {
        out << i;
        if(i == 10)
        {
            out << "| ";
        } else
        {
            out << " | ";
        }
        for(int j = 0; j < 10; j++)
        {
            if(freqArr[j] >= i)
            {
                out << " *" "\t""\t";
            } else
            {
                out << "  " "\t""\t";
            }
        }
        out << endl;
    }

    out << "  |-----------------------------------------------------------------------------" << endl;
    out << "\t" << "0-9 " << "\t" << "10-19" <<"\t" << "20-29" <<"\t" << "30-39" <<"\t" << "40-49" <<"\t"
    << "50-59" << "\t" << "60-69" << "\t" << "70-79" << "\t" << "80-89" << "\t" << "90-99" << endl;
}

int main(int argc, char * argv[]) {
    //argv[1] = input file containing histogram data
    //argv[2] = output file where histogram will be printed
    ifstream inputFile;
    ofstream outFile;
    inputFile.open(argv[1]);
    int val =0;
    vector<int> temp;
    while(inputFile >> val)
    {
        temp.push_back(val);
    }
    inputFile.close();
    int arr[temp.size()];
    for(int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    outFile.open(argv[2]);

    //int arr[10] = { 10, 19, 12, 34, 55, 72, 88, 95, 33, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr+n);
    printHistogram(arr, n, outFile);
    outFile.close();
    return 0;

}
