#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const int MAX_BAR_SIZE = 60;

int randNum(int maxVal, int minVal);
void arrayFill(int valCount[], int maxVal, int minVal, int nSamples);
void printSum(int valCount[], int maxVal, int minVal);
void printMean(int valCount[], int maxVal, int minVal);
int printMinMax(int valCount[], int maxVal, int minVal);
void printRange(int maxVal, int minVal);
void histPrint(int valCount[], int maxVal, int minVal, int max);

int main()
{
    srand(time(NULL)); //seeds random numbers

    int nSamples = 0;
    int maxVal = 0;
    int minVal = 0;
    int max;

    cout << "Enter number of samples (Must be greater than 10000): ";
    while(nSamples < 10000){ //takes number of samples
        cin >> nSamples;
        if(nSamples < 10000) cout << "Number of samples must be greater than 10000: ";
    }

    cout << "Enter maximum value (Must be greater than 0): ";
    while(maxVal <= 0){ //takes max sample value
        cin >> maxVal;
        if(maxVal <= 0) cout << "Maximum value must be greater than 0: ";
    }

    cout << endl;

    int valCount[(maxVal - minVal) + 1]; //array to store count of each value in the range

    arrayFill(valCount, maxVal, minVal, nSamples);

    /*for(int i = 0; i < ((maxVal - minVal) + 1); ++i){
        cout << "# of " << i << "'s: " << valCount[i] << endl;
    }*/

    printSum(valCount, maxVal, minVal);
    printMean(valCount, maxVal, minVal);
    max = printMinMax(valCount, maxVal, minVal);
    printRange(maxVal, minVal);

    cout << endl;

    histPrint(valCount, maxVal, minVal, max);

    return 0;
}

int randNum(int maxVal, int minVal){ //generates a random number within the range
    return (rand() % ((maxVal - minVal) + 1) + minVal);
}

void arrayFill(int valCount[], int maxVal, int minVal, int nSamples){
    int temp;

    for(int i = 0; i <= (maxVal - minVal) + 1; ++i){ //fills array with zeroes
        valCount[i] = 0;
    }

    for(int i = 0; i < nSamples; ++i){ //gets a count of the number of times each number within the range is generated
        temp = randNum(maxVal, minVal);
        ++valCount[temp];
    }
}

void printSum(int valCount[], int maxVal, int minVal){ //prints sum of frequencies
    int temp = 0;
    for(int i = 0; i < ((maxVal - minVal) + 1); ++i){ //takes sum
        temp += valCount[i];
    }
    cout << "Sum of frequencies: " << temp << endl;
}

void printMean(int valCount[], int maxVal, int minVal){ //prints mean of frequencies
    int temp = 0;
    for(int i = 0; i < ((maxVal - minVal) + 1); ++i){ //takes sum
        temp += valCount[i];
    }
    cout << "Mean of frequencies: " << static_cast<double>(temp) / ((maxVal - minVal) + 1) << endl;
}

int printMinMax(int valCount[], int maxVal, int minVal){ //find and print minimum and maximum values and their locations
    int min = valCount[0];
    int max = valCount[0];
    int atMax = 0;
    int atMin = 0;

    for(int i = 1; i < ((maxVal - minVal) + 1); ++i){ //finds min and max
        if(valCount[i] > max){
            max = valCount[i];
            atMax = i;
        }
        if(valCount[i] < min){
            min = valCount[i];
            atMin = i;
        }
    }

    cout << "Minimum value is " << min << " at " << atMin << endl;
    cout << "Maximum value is " << max << " at " << atMax << endl;
    return max;
}

void printRange(int maxVal, int minVal){ //prints range of numbers
    cout << "Range: " << minVal << " to " << maxVal << endl;
}

void histPrint(int valCount[], int maxVal, int minVal, int max){ //prints histogram and array
    int scaleFactor = max / MAX_BAR_SIZE;
    cout << "Scale: " << scaleFactor << " per *" << endl << endl;
    cout << "Index    Value Bar//Histogram Value" << endl;
    for(int i = 0; i < ((maxVal - minVal) + 1); ++i){
        cout << fixed << setw(5) << i << fixed << setw(9) << valCount[i] << " ";
        for(int j = 0; j < (valCount[i] / scaleFactor); ++j){
            cout << "*";
        }
        cout << endl;
    }
}
