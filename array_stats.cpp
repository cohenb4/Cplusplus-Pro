#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int maxBarSize = 60;

int minimum(int *v, int range);
int maximum(int *v, int range);
int sum(int *v, int range);
double mean(int sum, int range);
void printChart(int *v, int range, int scale);

int main() {
  srand(time(NULL));
  int range;
  int samples;

  cout << "Enter End Range: " << endl;
  cin >> range;

  cout << "Enter number of Samples: " << endl;
  cin >> samples;

  int* v = new int[range];

  for (int i = 0; i <= range; i++) {
    v[i] = 0;
    int randomsample;
      for (int j = 0; j < samples; j++) {
        randomsample = rand(); //random number 0 to 100
        v[randomsample] += 1;
      }
  }

  int min = minimum(v, range);
  int max = maximum(v, range);
  int sum1 = sum(v, range);
  double avg = mean(samples, range);
  double scale = ceil(max/maxBarSize);
  printChart(v, range, scale);

  cout << "Scale: " << scale << " per *" << endl;
  cout << "Range: 0 to " << range << endl;
  cout << "Sample Count: " << samples << endl;
  cout << "Min Value: " << min << endl;
  cout << "Max Value: " << max << endl;
  cout << "Sum Value: " << sum1 << endl;
  cout << "Mean Value: " << avg << endl;


  return 0;
}

int minimum(int *v, int range) {
  int min = v[0];
  for (int i = 0; i <= range; i++)
  {
    if (min > v[i])
      min = v[i];
  }
  return min;
}

int maximum(int *v, int range) {
  int max = v[0];
  for (int i = 0; i <= range; i++)
  {
    if (max < v[i])
      max = v[i];
  }
  return max;
}

int sum(int *v, int range) {
  int sum = 0;
  for (int i = 0; i <= range; i++)
  {
    sum += v[i];
  }
  return sum;
}

double mean(int sum, int range) {
  return (double (sum) / (range + 1));
}

void histo(int *v, int range, int scale) {
  cout <<" Index\tValue Bar" << endl;
  for (int i = 0; i <= range; ++i)
  {
    cout << " " << i << "\t" << v[i] << " ";
      for (int j = 0; j < v[i]; j += scale)
      {
        cout << "*" << endl;
      }
  }
}
