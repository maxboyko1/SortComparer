#ifndef SORTCOMPARER_H_
#define SORTCOMPARER_H_

#include <algorithm>
#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using std::ceil;
using std::cerr;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::time_point;
using std::cin;
using std::copy_n;
using std::cout;
using std::endl;
using std::function;
using std::greater;
using std::is_sorted;
using std::list;
using std::max;
using std::min;
using std::multiset;
using std::priority_queue;
using std::size_t;
using std::string;
using std::swap;
using std::unordered_map;
using std::vector;

struct AlgoWithTime {
    string algoName;
    unsigned long long execTime;

    bool operator> (const AlgoWithTime& other) const {
        return execTime > other.execTime;
    }
};

using AlgoMinHeap = priority_queue<AlgoWithTime, vector<AlgoWithTime>, greater<>>;
using AlgoTable = unordered_map<string, function<void(vector<long>&, size_t)>>;

/****************************** SORT ALGORITHMS ******************************/

void BubbleSort (vector<long>& values, size_t N);
void CocktailSort (vector<long>& values, size_t N);
void CombSort (vector<long>& values, size_t N);
void CycleSort (vector<long>& values, size_t N);
void GnomeSort (vector<long>& values, size_t N);
void HeapSort (vector<long>& values, size_t N);
void InsertionSort (vector<long>& values, size_t N);
void MergeSort (vector<long>& values, size_t N);
void OddEvenSort (vector<long>& values, size_t N);
void QuickSort (vector<long>& values, size_t N);
void SelectionSort (vector<long>& values, size_t N);
void ShellSort (vector<long>& values, size_t N);
void StrandSort (vector<long>& values, size_t N);
void TimSort (vector<long>& values, size_t N);
void TreeSort (vector<long>& values, size_t N);

/*************************** SORT ALGORITHM HELPERS ***************************/

void ExtractAndMergeStrand (list<long>& inList, list<long>& outList);
void Heapify (vector<long>& values, size_t N, int i);
void InsertionSortInRange (vector<long>& values, size_t l, size_t r);
void MergeSortInRange (vector<long>& values, size_t l, size_t r);
void MergeSortedSubarrays (vector<long>& values, size_t l, size_t m, size_t r);
void QuickSortInRange (vector<long>& values, long long l, long long r);

/****************************** DRIVER FUNCTIONS ******************************/

int ReadInValues (vector<long>& values);
int RunSortAlgorithms (const vector<long>& values, AlgoMinHeap& sortAlgoMinHeap);
void PrintResults (AlgoMinHeap& sortAlgoMinHeap);

#endif // SORTCOMPARER_H_
