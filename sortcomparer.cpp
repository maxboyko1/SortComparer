#include "sortcomparer.hpp"

/*
 * All sort algorithms (implemented below) that will be tested in this program
 */
const AlgoTable kSortAlgorithms = {
    {"Bubble Sort", BubbleSort},
    {"Cocktail Sort", CocktailSort},
    {"Comb Sort", CombSort},
    {"Cycle Sort", CycleSort},
    {"Gnome Sort", GnomeSort},
    {"Heap Sort", HeapSort},
    {"Insertion Sort", InsertionSort},
    {"Merge Sort", MergeSort},
    {"Odd-Even Sort", OddEvenSort},
    {"Quick Sort", QuickSort},
    {"Selection Sort", SelectionSort},
    {"Shell Sort", ShellSort},
    {"Strand Sort", StrandSort},
    {"Tim Sort", TimSort},
    {"Tree Sort", TreeSort}
};

/****************************** SORT ALGORITHMS ******************************/

/**
 * BUBBLE SORT
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 * Repeatedly swap adjacent elements to "bubble up" the largest element to the
 * last position, then the second-largest element to the second-last position,
 * and so on.
 */
void BubbleSort (vector<long>& values, size_t N) {
    for (int k = N - 1; k >= 0; --k)
        for (int i = 0; i < k; ++i)
            if (values[i] > values[i + 1])
                swap(values[i], values[i + 1]);
}

/**
 * COCKTAIL SORT
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 * Variation on bubble sort which instead traverses the array in both
 * directions at each iteration, moving the largest element to the end, then
 * the smallest element to the beginning, second-largest element to position
 * second from the end, and so on until values is fully sorted.
 */
void CocktailSort (vector<long>& values, size_t N) {
    bool swapOccurred(true);
    size_t start(0), finish(N - 1);

    while (swapOccurred) {
        // Forward iteration
        swapOccurred = false;
        for (size_t i = start; i < finish; ++i) {
            if (values[i] > values[i + 1]) {
                swap(values[i], values[i + 1]);
                swapOccurred = true;
            }
        }
        --finish;
        // If no swap occurred then array is sorted, done
        if (!swapOccurred)
            return;
        // Backward iteration
        swapOccurred = false;
        for (size_t i = finish; i > start; --i) {
            if (values[i - 1] > values[i]) {
                swap(values[i - 1], values[i]);
                swapOccurred = true;
            }
        }
        ++start;
    }
}

/**
 * COMB SORT
 * Time Complexity: O(n^2) worst case, Omega(n^2/2^p) on average where p is
 *                  the length of the gap sequence
 * Space Complexity: O(1)
 *
 * Variation on bubble sort which uses a gradually decreasing sequence of gap
 * sizes between elements to compare, with the gap shrinking by a factor of 1.3
 * before each iteration, before finishing with an iteration using gap size 1
 * (regular bubble sort). The goal of the iterations prior to gap size 1 is to
 * bring very out-of-place elements closer to their final sorted position using
 * fewer overall swaps, improving performance.
 */
void CombSort (vector<long>& values, size_t N) {
    bool swapOccurred = true;
    size_t gap = N;

    while (gap != 1 || swapOccurred) {
        // Shrink gap size by factor of 1.3
        gap = max(static_cast<size_t>(1), (gap * 10) / 13);

        swapOccurred = false;
        for (size_t i = 0; i < N - gap; ++i) {
            if (values[i] > values[i + gap]) {
                swap(values[i], values[i + gap]);
                swapOccurred = true;
            }
        }
    }
}

/**
 * CYCLE SORT
 * Time Complexity: Theta(n^2)
 * Space Complexity: Theta(1)
 *
 * At each iteration, check if element at current position is at its proper
 * final position in the sorted array, and if not create a "cycle" from there
 * to its proper position and swap, and from there to that element's proper
 * position, and so on until we are back to the cycle start. Then advance to
 * find the next cycle, and so on until fully sorted.
 */
void CycleSort (vector<long>& values, size_t N) {
    for (size_t cycStart = 0; cycStart < N - 1; ++cycStart) {
        long item = values[cycStart];
        size_t pos = cycStart;

        // Find proper position for item (after any elements smaller than it)
        for (size_t i = cycStart + 1; i < N; ++i)
            if (values[i] < item)
                ++pos;

        // If item is already in the right position, move on
        if (pos == cycStart)
            continue;

        // Move past any duplicates
        while (values[pos] == item)
            ++pos;

        // Move item to proper position
        if (pos != cycStart)
            swap(values[pos], item);

        // Repeat above process for item whose place it took, and so on until
        // every element in this "cycle" is in the right position
        while (pos != cycStart) {
            pos = cycStart;
            for (size_t i = cycStart + 1; i < N; ++i)
                if (values[i] < item)
                    ++pos;
            while (values[pos] == item)
                ++pos;
            if (values[pos] != item)
                swap(values[pos], item);
        }
    }
}

/**
 * GNOME SORT
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 * Compare element at current position to the previous one, stepping forward
 * if current one is greater than or equal to the previous, otherwise swap them
 * and step backward. If there is no previous element then step forward, if
 * we're at the end and no swap is necessary then we are done.
 */
void GnomeSort (vector<long>& values, size_t N) {
    size_t pos = 0;
    while (pos < N) {
        if (pos == 0)
            ++pos;
        if (values[pos - 1] <= values[pos])
            ++pos;
        else {
            swap(values[pos - 1], values[pos]);
            --pos;
        }
    }
}

/**
 * HEAP SORT
 * Time Complexity: O(nlogn)
 * Space Complexity O(1)
 *
 * Build a max heap on values, move the max element to "sorted" end of the
 * array, then reheapify and repeat the process until fully sorted.
 */
void HeapSort (vector<long>& values, size_t N) {
    // Build initial max heap
    for (int i = N / 2 - 1; i >= 0; --i)
        Heapify(values, N, i);
    // Move max element to "sorted" end of array and re-heapify
    for (int i = N - 1; i >= 0; --i) {
        swap(values[0], values[i]);
        Heapify(values, i, 0);
    }
}

/**
 * INSERTION SORT
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 * Divide the array into a sorted and unsorted portion and repeatedly swap to
 * place each "unsorted" element in its proper position in the sorted portion of
 * values, until the values is fully sorted.
 */
void InsertionSort (vector<long>& values, size_t N) {
    InsertionSortInRange(values, 0, N - 1);
}

/**
 * MERGE SORT
 * Time Complexity: O(nlogn) worst case, Theta(nlogn) on average
 * Space Complexity: O(n)
 *
 * Recursively split values in half until it cannot be divided further (only
 * one element in each of the two subarrays left), then merge the two
 * subarrays into one sorted array, and so on until values is fully sorted.
 */
void MergeSort (vector<long>& values, size_t N) {
    MergeSortInRange(values, 0, N - 1);
}

/**
 * ODD-EVEN SORT
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 * Variation on bubble sort which bubbles up one odd-indexed element, then one
 * even-indexed element on each pass, repeating until fully sorted.
 */
void OddEvenSort (vector<long>& values, size_t N) {
    const vector<size_t> kStartIndices = {1, 0};
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (const size_t startIdx : kStartIndices) {
            for (size_t i = startIdx; i <= N - 2; i += 2) {
                if (values[i] > values[i + 1]) {
                    swap(values[i], values[i + 1]);
                    isSorted = false;
                }
            }
        }
    }
}

/**
 * QUICK SORT
 * Time Complexity: O(n^2) worst case, O(nlogn) on average
 * Space Complexity: O(logn), in call stack space
 *
 * Partition values into elements less than and greater than (or equal to) a
 * selected pivot element (value at median index in range will beused here),
 * then recursively quick sort each partition until values is fully sorted.
 */
void QuickSort (vector<long>& values, size_t N) {
    QuickSortInRange(values, 0, N - 1);
}

/**
 * SELECTION SORT
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 * Divide the array into a sorted and unsorted portion and repeatedly search
 * for the minimum element remaining in the unsorted part of the list, then
 * move it to the end of the sorted portion. Repeat until fully sorted.
 */
void SelectionSort (vector<long>& values, size_t N) {
    for (int i = 0; i < N - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < N; ++j)
            if (values[j] < values[minIdx])
                minIdx = j;
        swap(values[i], values[minIdx]);
    }
}

/**
 * SHELL SORT
 * Time Complexity: O(n^2) worst case, about O(nlogn) on average
 * Space Complexity: O(1)
 *
 * Variation of insertion sort which at each iteration sorts all elements at a
 * specified distance away from each other in values, with the gap gradually
 * decreasing towards 1 (regular insertion sort). The goal is to minimize the
 * overall number of swaps necessary for elements whose final sorted position
 * is far away from its starting position.
 *
 * The sequence used in the implementation below is h_k = ceil(h'_k), where
 * h'_k = 2.25*h'_{k-1} + 1, with h'_0 = 1. This is known as Tokuda's sequence
 * and has been found to be among the best performing ones for Shell Sort in
 * practice (no one knows why).
 */
void ShellSort (vector<long>& values, size_t N) {
    size_t gap = N;
    while (gap != 1) {
        gap = max(static_cast<size_t>(1), static_cast<size_t>((gap - 1) / 2.25));
        for (size_t i = gap; i < N; ++i)
            for (long long j = i; j >= gap && values[j - gap] > values[j]; j -= gap)
                swap(values[j], values[j - gap]);
    }
}

/**
 * STRAND SORT
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 *
 * Create sorted strands of elements from elements in the input list, removing
 * elements from input as they are added to a strand, then merge them together
 * one-by-one to create a fully sorted output list.
 */
void StrandSort (vector<long>& values, size_t N) {
    list<long> inList, outList;
    inList.assign(begin(values), end(values));
    ExtractAndMergeStrand(inList, outList);
    values.assign(begin(outList), end(outList));
}

/**
 * TIM SORT
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 *
 * Divide values into "runs" of maximum size 32, sort those runs using
 * insertion sort, merge the runs together into sorted subarrays of size 64,
 * and so on until all of values is sorted.
 */
void TimSort (vector<long>& values, size_t N) {
    // Sort individual runs of elements using insertion sort
    const size_t kRun = 32;
    for (size_t i = 0; i < N; i += kRun)
        InsertionSortInRange(values, i, min(i + kRun - 1, N - 1));

    // Merge sorted runs together until entire array is sorted
    for (size_t size = kRun; size < N; size *= 2) {
        for (size_t l = 0; l < N; l += size * 2) {
            size_t m = l + size - 1;
            size_t r = min(l + size * 2 - 1, N - 1);
            if (m < r)
                MergeSortedSubarrays(values, l, m, r);
        }
    }
}

/**
 * TREE SORT
 * Time Complexity: O(nlogn)
 * Space Complexity: Theta(n)
 *
 * Insert all elements in values into a (balanced) binary search tree, then
 * overwriting values array with the inorder traversal of this tree.
 */
void TreeSort (vector<long>& values, size_t N) {
    multiset<long> tree;
    for (const long elem : values)
        tree.insert(elem);
    size_t idx(0);
    for (auto iter = begin(tree); iter != end(tree); ++iter)
        values[idx++] = *iter;
}

/*************************** SORT ALGORITHM HELPERS ***************************/

/**
 * Helper function for StrandSort(). Create a sorted strand (linked list) of
 * elements from inList, merge the resulting strand with the existing outList,
 * and recurse until input list is empty.
 */
void ExtractAndMergeStrand (list<long>& inList, list<long>& outList) {
    // Done, nothing left to sort
    if (empty(inList))
        return;

    // Initialize sublist to first element in input list
    list<long> subList;
    subList.push_back(inList.front());
    inList.pop_front();

    // Create sorted strand by comparing each element remaining in input list
    // to sublist's current last element, and appending it if it's larger
    auto iter = begin(inList);
    while (iter != end(inList)) {
        if (*iter > subList.back()) {
            subList.push_back(*iter);
            iter = inList.erase(iter);
        } else {
            ++iter;
        }
    }
    // Merge sorted strand to existing output list
    outList.merge(subList);
    // Recursively extract next strand from remaining input list
    ExtractAndMergeStrand(inList, outList);
}

/**
 * Helper function for HeapSort(). Restore max heap property for subtree rooted
 * at i by repeatedly finding the max value among i and its children, then
 * move largest value to i and recursively heapify child subtree if necessary.
 */
void Heapify (vector<long>& values, size_t N, int i) {
    // Find largest value among element at i and its children in the heap
    int largest(i), left(2 * i + 1), right(2 * i + 2);
    if (left < N && values[left] > values[largest])
        largest = left;
    if (right < N && values[right] > values[largest])
        largest = right;
    if (largest != i) {
        // Swap element at i with its largest child
        swap(values[i], values[largest]);
        // Recursively heapify child subtree
        Heapify(values, N, largest);
    }
}

/**
 * Helper function for InsertionSort() and TimSort(). Perform an insertion sort
 * on range values[l..r].
 */
void InsertionSortInRange (vector<long>& values, size_t l, size_t r) {
    for (size_t i = l + 1; i <= r; ++i)
        for (size_t j = i; j > l && values[j - 1] > values[j]; --j)
            swap(values[j], values[j - 1]);
}

/**
 * Helper function for MergeSort(). Perform a merge sort on range values[l..r].
 */
void MergeSortInRange (vector<long>& values, size_t l, size_t r) {
    if (l < r) {
        size_t m = l + (r - l) / 2;
        MergeSortInRange(values, l, m);
        MergeSortInRange(values, m + 1, r);
        MergeSortedSubarrays(values, l, m, r);
    }
}

/**
 * Helper function for MergeSort() and TimSort(). Merge two (already sorted)
 * subarrays values[l..m] and values[(m+1)..r] to sort range values[l..r].
 */
void MergeSortedSubarrays (vector<long>& values, size_t l, size_t m, size_t r) {
    size_t sizeA = m - l + 1;
    size_t sizeB = r - m;
    long A[sizeA], B[sizeB];

    // Copy elements from each half of values into A and B arrays
    copy_n(begin(values) + l, sizeA, A);
    copy_n(begin(values) + m + 1, sizeB, B);

    // Iterate through (already sorted) left and right arrays and overwrite
    // values with the smalonger of the two elements at each step
    size_t i(0), j(0), k(l);
    while (i < sizeA && j < sizeB) {
        if (A[i] <= B[j])
            values[k++] = A[i++];
        else
            values[k++] = B[j++];
    }

    // Overwrite values with the remaining elements in left or right
    while (i < sizeA)
        values[k++] = A[i++];
    while (j < sizeB)
        values[k++] = B[j++];
}


/**
 * Helper function for QuickSort(). Performs quick sort on range values[l..r].
 */
void QuickSortInRange (vector<long>& values, long long l, long long r) {
    if (l < r) {
        // Select median index in range as pivot
        size_t pivotIdx = l + (r - l) / 2;

        // Move pivot element to end of range temporarily
        swap(values[pivotIdx], values[r]);

        // Partition subarray
        long long i = l - 1;
        for (long long j = l; j < r; ++j)
            if (values[j] < values[r])
                swap(values[++i], values[j]);

        // Move pivot element back to proper position in range
        swap(values[i + 1], values[r]);

        // Recursively quick sort each partition
        QuickSortInRange(values, l, i);
        QuickSortInRange(values, i + 2, r);
    }
}

/****************************** DRIVER FUNCTIONS ******************************/

/**
 * Read integers from standard input and insert them into values vector.
 * Return 0 on success, 1 on error.
 */
int ReadInValues (vector<long>& values) {
    long val;
    while (cin >> val && size(values) < values.max_size())
        values.push_back(val);
    if (!cin.eof()) {
        cerr << "ERROR: Program input must be space-separated list of integers "
             << "in range [-2^31, 2^31-1]" << endl;
        return 1;
    } else if (size(values) == values.max_size()) {
        cerr << "ERROR: Input size limit exceeded" << endl;
        return 1;
    }
    return 0;
}

/**
 * Run each sorting algorithm defined above on (a copy of) the input values,
 * measure their execution times in microseconds, and store them in a min heap
 * ordered on said execution time. Return 0 if all sort algorithms sorted the
 * input properly, 1 if any of them failed.
 */
int RunSortAlgorithms (const vector<long>& values, AlgoMinHeap& sortAlgoMinHeap) {
    high_resolution_clock::time_point startTime, finishTime;
    unsigned long long execTimeUs;
    vector<long> valuesCopy;

    for (auto iter = begin(kSortAlgorithms); iter != end(kSortAlgorithms); ++iter) {
        // Create copy of values to sort
        valuesCopy.assign(begin(values), end(values));
        cout << "Running " << iter->first << "...";

        // Execute sorting algorithm here
        startTime = high_resolution_clock::now();
        iter->second(valuesCopy, size(valuesCopy));
        finishTime = high_resolution_clock::now();

        // Verify that output of algorithm is sorted
        if (!is_sorted(begin(valuesCopy), end(valuesCopy))) {
            cerr << "ERROR: " << iter->first << " did not sort properly" << endl;
            return 1;
        }

        cout << " Done." << endl;
        execTimeUs = duration_cast<microseconds>(finishTime - startTime).count();
        sortAlgoMinHeap.emplace(AlgoWithTime{iter->first, execTimeUs});
    }
    cout << endl;
    return 0;
}

/**
 * Print an explanation of the performance results of each sorting algorithm
 * measured, in order from best to worst performing on the given input.
 */
void PrintResults (AlgoMinHeap& sortAlgoMinHeap) {
    cout << "SORT ALGORITHM PERFORMANCES ON INPUT (IN MICROSECONDS):" << endl;
    int rank(0);
    while (!empty(sortAlgoMinHeap)) {
        auto [algo, time] = sortAlgoMinHeap.top();
        sortAlgoMinHeap.pop();
        cout << ++rank << ") " << algo << ": " << time << "\u03BCs" << endl;
    }
}


/**
 * Read in a series of integers from standard input, measure the performance
 * of each of the 15 sorting algorithms defined above on the input, and report
 * the results.
 */
int main() {
    vector<long> values;
    if (ReadInValues(values))
        return 1;
    AlgoMinHeap sortAlgoMinHeap;
    if (RunSortAlgorithms(values, sortAlgoMinHeap))
        return 1;
    PrintResults(sortAlgoMinHeap);
    return 0;
}
