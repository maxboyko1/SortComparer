# Sort Comparer

Program that compares the performance of various sorting algorithms on the provided input values, read in via standard input.

Also provided is a program that prints a specified amount of random numbers to standard output, which can be used as test input for the sort comparer. However, any list of integers within the `long` integer data type range (-2<sup>31</sup> through 2<sup>31</sup> - 1) and separated by spaces will work.

Sorting algorithms tested include:
- Bubble Sort
- Cocktail Sort
- Comb Sort
- Cycle Sort
- Gnome Sort
- Heap Sort
- Insertion Sort
- Merge Sort
- Odd-Even Sort
- Quick Sort
- Selection Sort
- Shell Sort
- Strand Sort
- Tim Sort
- Tree Sort

Example usage in terminal below.

```
maxboyko:~/Documents/github/sortcomparer $ make
g++ -std=c++17 -Wall -c randomnumbers.cpp
g++ -std=c++17 -Wall -o randomnumbers randomnumbers.o
g++ -std=c++17 -Wall -c sortcomparer.cpp
g++ -std=c++17 -Wall -o sortcomparer sortcomparer.o
maxboyko:~/Documents/github/sortcomparer $ # Almost sorted input
maxboyko:~/Documents/github/sortcomparer $ seq -s ' ' 1 5100 >> test1.txt; seq -s ' ' 4900 10000 >> test1.txt
maxboyko:~/Documents/github/sortcomparer $ ./sortcomparer < test1.txt
Running Tree Sort... Done.
Running Strand Sort... Done.
Running Shell Sort... Done.
Running Tim Sort... Done.
Running Selection Sort... Done.
Running Bubble Sort... Done.
Running Comb Sort... Done.
Running Quick Sort... Done.
Running Insertion Sort... Done.
Running Heap Sort... Done.
Running Cocktail Sort... Done.
Running Cycle Sort... Done.
Running Odd-Even Sort... Done.
Running Merge Sort... Done.
Running Gnome Sort... Done.

SORT ALGORITHM PERFORMANCES ON INPUT (IN MICROSECONDS):
1) Insertion Sort: 155μs
2) Gnome Sort: 198μs
3) Tim Sort: 422μs
4) Shell Sort: 477μs
5) Quick Sort: 589μs
6) Comb Sort: 738μs
7) Heap Sort: 1520μs
8) Odd-Even Sort: 2528μs
9) Merge Sort: 2558μs
10) Strand Sort: 2896μs
11) Tree Sort: 4611μs
12) Cocktail Sort: 4868μs
13) Cycle Sort: 115338μs
14) Bubble Sort: 124880μs
15) Selection Sort: 133867μs
maxboyko:~/Documents/github/sortcomparer $ # Input sorted in descending order
maxboyko:~/Documents/github/sortcomparer $ seq -s ' ' 10000 1 > test2.txt
maxboyko:~/Documents/github/sortcomparer $ ./sortcomparer < test2.txt
Running Tree Sort... Done.
Running Strand Sort... Done.
Running Shell Sort... Done.
Running Tim Sort... Done.
Running Selection Sort... Done.
Running Bubble Sort... Done.
Running Comb Sort... Done.
Running Quick Sort... Done.
Running Insertion Sort... Done.
Running Heap Sort... Done.
Running Cocktail Sort... Done.
Running Cycle Sort... Done.
Running Odd-Even Sort... Done.
Running Merge Sort... Done.
Running Gnome Sort... Done.

SORT ALGORITHM PERFORMANCES ON INPUT (IN MICROSECONDS):
1) Shell Sort: 579μs
2) Quick Sort: 598μs
3) Comb Sort: 844μs
4) Tim Sort: 1138μs
5) Heap Sort: 1450μs
6) Merge Sort: 2511μs
7) Tree Sort: 3994μs
8) Selection Sort: 127424μs
9) Cycle Sort: 186319μs
10) Cocktail Sort: 244470μs
11) Bubble Sort: 247957μs
12) Odd-Even Sort: 249526μs
13) Insertion Sort: 262698μs
14) Gnome Sort: 386280μs
15) Strand Sort: 797331μs
maxboyko:~/Documents/github/sortcomparer $ # Randomized input
maxboyko:~/Documents/github/sortcomparer $ ./randomnumbers 10000 > test3.txt
maxboyko:~/Documents/github/sortcomparer $ ./sortcomparer < test3.txt
Running Tree Sort... Done.
Running Strand Sort... Done.
Running Shell Sort... Done.
Running Tim Sort... Done.
Running Selection Sort... Done.
Running Bubble Sort... Done.
Running Comb Sort... Done.
Running Quick Sort... Done.
Running Insertion Sort... Done.
Running Heap Sort... Done.
Running Cocktail Sort... Done.
Running Cycle Sort... Done.
Running Odd-Even Sort... Done.
Running Merge Sort... Done.
Running Gnome Sort... Done.

SORT ALGORITHM PERFORMANCES ON INPUT (IN MICROSECONDS):
1) Quick Sort: 1175μs
2) Tim Sort: 1234μs
3) Comb Sort: 1652μs
4) Heap Sort: 1853μs
5) Shell Sort: 1917μs
6) Merge Sort: 3021μs
7) Tree Sort: 4237μs
8) Strand Sort: 24359μs
9) Selection Sort: 121776μs
10) Insertion Sort: 130148μs
11) Gnome Sort: 191423μs
12) Cocktail Sort: 224292μs
13) Odd-Even Sort: 239778μs
14) Bubble Sort: 320156μs
15) Cycle Sort: 441840μs
```
