#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <string>
#include <limits>

using std::vector;
using std::cout;
using std::setw;
using std::right;
using std::left;
using std::rand;
using std::string;
using std::fixed;
using std::setprecision;
using std::chrono::steady_clock;

class SortingAlgorithms
{
public:
    vector<int> CreateTestVector(int size = 1000, int order = 0)
    {
        vector<int> testVector;

        for(int i = 0; i < size; i++)
        {
            if(order == 1)
            {
                testVector.push_back(i);
            }
            else if(order == 2)
            {
                testVector.push_back(size-i-1);
            }
            else if(order == 3)
            {
                testVector.push_back(rand()%5);
            }
            else
            {
                testVector.push_back(rand()%size);
            }
        }

        return testVector;
    }



    void BubbleSort(vector<int>& vect)
    {
        Sorted = false;
        sortedItems = 0;

        while(!Sorted)
        {
            Sorted = true;

            for(int i = 0; i < (int)vect.size() - sortedItems - 1; i++)
            {
                if(vect[i] > vect[i+1])
                {
                    int tmp = vect[i];
                    vect[i] = vect[i+1];
                    vect[i+1] = tmp;
                    Sorted = false;
                }
            }

            sortedItems += 1;
        }
    }

    void SelectionSort(vector<int>& vect)
    {
        for(int i = 0; i < (int)vect.size() - 1; i++)
        {
            int smallestIndex = i;

            for(int j = i+1; j < (int)vect.size(); j++)
            {
                if(vect[j] < vect[smallestIndex])
                {
                    smallestIndex = j;
                }
            }

            int tmp = vect[i];
            vect[i] = vect[smallestIndex];
            vect[smallestIndex] = tmp;
        }
    }

    void InsertionSort(vector<int>& vect)
    {
        for(int i = 1; i < (int)vect.size(); i++)
        {
            int currentItem = vect[i];
            int j = i-1;

            while(j >= 0 && vect[j] > currentItem)
            {
                vect[j+1] = vect[j];
                j--;
            }

            vect[j+1] = currentItem;
        }
    }

    void MergeSort(vector<int>& vect, int l, int r)
    {
        if(l < r)
        {
            int m = l + (r - l) / 2;

            MergeSort(vect, l, m);
            MergeSort(vect, m+1, r);

            merge(vect, l, m, r);
        }
    }

    void merge(vector<int>& vect, int l, int m, int r)
    {
        int leftLen = m-l+1, rightLen = r-m;
        vector<int> leftV, rightV;

        for(int i = 0; i < leftLen; i++)
        {
            leftV.push_back(vect[i+l]);
        }
        for(int i = 0; i < rightLen; i++)
        {
            rightV.push_back(vect[i+m+1]);
        }

        int leftIndex = 0, rightIndex = 0;
        int mergeIndex = l;
        while(leftIndex < leftLen && rightIndex < rightLen)
        {
            if(leftV[leftIndex] <= rightV[rightIndex])
            {
                vect[mergeIndex++] = leftV[leftIndex++];
            }
            else
            {
                vect[mergeIndex++] = rightV[rightIndex++];
            }
        }

        while(leftIndex < leftLen)
        {
            vect[mergeIndex++] = leftV[leftIndex++];
        }

        while(rightIndex < rightLen)
        {
            vect[mergeIndex++] = rightV[rightIndex++];
        }
    }

    void QuickSort(vector<int>& vect, int l, int r)
    {
        if(l >= r)
        {
            return;
        }

        int leftIndex = l, rightIndex = r;
        int pivot = vect[l + (r-l) / 2];

        while(leftIndex <= rightIndex)
        {
            while(vect[leftIndex] < pivot)
            {
                leftIndex++;
            }
            while(vect[rightIndex] > pivot)
            {
                rightIndex--;
            }

            if(leftIndex <= rightIndex)
            {
                int tmp = vect[leftIndex];
                vect[leftIndex] = vect[rightIndex];
                vect[rightIndex] = tmp;
                leftIndex++;
                rightIndex--;
            }
        }

        if(l < rightIndex)
        {
            QuickSort(vect, l, rightIndex);
        }
        if(leftIndex < r)
        {
            QuickSort(vect, leftIndex, r);
        }
    }

    void HeapSort(vector<int>& vect)
    {
        int size = (int)vect.size();

        for(int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(vect, size, i);
        }

        for(int i = size - 1; i > 0; i--)
        {
            int tmp = vect[0];
            vect[0] = vect[i];
            vect[i] = tmp;

            heapify(vect, i, 0);
        }
    }

    void heapify(vector<int>& vect, int size, int root)
    {
        int largestIndex = root;
        int leftChild = root*2+1, rightChild = root*2+2;

        if(leftChild < size && vect[leftChild] > vect[largestIndex])
        {
            largestIndex = leftChild;
        }
        if(rightChild < size && vect[rightChild] > vect[largestIndex])
        {
            largestIndex = rightChild;
        }

        if(largestIndex != root)
        {
            int tmp = vect[root];
            vect[root] = vect[largestIndex];
            vect[largestIndex] = tmp;

            heapify(vect, size, largestIndex);
        }
    }

    void ShellSort(vector<int>& vect)
    {
        for(int gap = (int)vect.size() / 2; gap > 0; gap /= 2)
        {
            for(int i = gap; i < (int)vect.size(); i++)
            {
                int currentItem = vect[i];
                int j = i;

                while(j >= gap && vect[j-gap] > currentItem)
                {
                    vect[j] = vect[j-gap];
                    j -= gap;
                }

                vect[j] = currentItem;
            }
        }
    }

    void RunSort(vector<int>& vect, int algorithm)
    {
        switch(algorithm)
        {
            case 0: BubbleSort(vect); break;
            case 1: SelectionSort(vect); break;
            case 2: InsertionSort(vect); break;
            case 3: MergeSort(vect, 0, (int)vect.size() - 1); break;
            case 4: QuickSort(vect, 0, (int)vect.size() - 1); break;
            case 5: HeapSort(vect); break;
            case 6: ShellSort(vect); break;
        }
    }

    void PrintVector(const vector<int>& vect)
    {
        for(int i = 0; i < (int)vect.size(); i++)
        {
            if((i+1) % 10 == 0 || i == (int)vect.size() - 1)
            {
                cout << setw(5) << right << vect[i] << '\n';
            }
            else
            {
                cout << setw(5) << right << vect[i] << ", ";
            }
        }
    }

private:
    bool Sorted;
    int sortedItems;
};


const int sortCount = 7;
const char* sortNames[sortCount] = {
    "BubbleSort", "SelectionSort", "InsertionSort", "MergeSort",
    "QuickSort", "HeapSort", "ShellSort"
};

int RunTests()
{
    SortingAlgorithms Sort;
    vector<vector<int>> testVectors = {
        {}, {7}, {2, 1}, {1, 2}, {4, 4, 4, 4},
        {0, -8, 5, -3, 5, 0},
        {std::numeric_limits<int>::min(), std::numeric_limits<int>::max(),
         0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()}
    };

    for(int size = 0; size <= 64; size++)
    {
        for(int order = 0; order < 4; order++)
        {
            vector<int> testVector = Sort.CreateTestVector(size, order);
            if(order == 0)
            {
                for(int i = 0; i < size; i++)
                {
                    testVector[i] -= size / 2;
                }
            }
            testVectors.push_back(testVector);
        }
    }
    for(int order = 0; order < 4; order++)
    {
        testVectors.push_back(Sort.CreateTestVector(1000, order));
    }

    bool allCorrect = true;
    for(int i = 0; i < sortCount; i++)
    {
        int passed = 0;
        for(int j = 0; j < (int)testVectors.size(); j++)
        {
            vector<int> sortedVector = testVectors[j];
            vector<int> expectedVector = testVectors[j];
            std::sort(expectedVector.begin(), expectedVector.end());
            Sort.RunSort(sortedVector, i);

            if(sortedVector == expectedVector)
            {
                passed++;
            }
            else
            {
                cout << sortNames[i] << " failed on test " << j+1 << "\n";
                allCorrect = false;
            }
        }

        cout << left << setw(18) << sortNames[i] << passed << "/"
             << testVectors.size() << " tests passed\n";
    }

    return allCorrect ? 0 : 1;
}

void PrintUsage()
{
    cout << "Usage: ./prac1 [size] [random|sorted|reversed|duplicates]\n";
    cout << "Size must be between 0 and 10000. Defaults to 1000 random items.\n";
    cout << "Vectors are printed when there are 30 items or fewer.\n";
    cout << "Use ./prac1 --test to check all the sorting algorithms.\n";
}

int main(int argc, char* argv[])
{
    int size = 1000, order = 0;
    string pattern = "random";

    if(argc == 2 && string(argv[1]) == "--test")
    {
        return RunTests();
    }
    if(argc == 2 && string(argv[1]) == "--help")
    {
        PrintUsage();
        return 0;
    }
    if(argc > 3)
    {
        PrintUsage();
        return 1;
    }
    if(argc >= 2)
    {
        std::istringstream sizeInput(argv[1]);
        if(!(sizeInput >> size) || !sizeInput.eof() || size < 0 || size > 10000)
        {
            cout << "Invalid vector size.\n";
            PrintUsage();
            return 1;
        }
    }
    if(argc == 3)
    {
        pattern = argv[2];
        if(pattern == "sorted")
        {
            order = 1;
        }
        else if(pattern == "reversed")
        {
            order = 2;
        }
        else if(pattern == "duplicates")
        {
            order = 3;
        }
        else if(pattern != "random")
        {
            cout << "Unknown input pattern.\n";
            PrintUsage();
            return 1;
        }
    }

    SortingAlgorithms Sort;
    vector<int> unsortedVector = Sort.CreateTestVector(size, order);
    vector<int> expectedVector = unsortedVector;
    std::sort(expectedVector.begin(), expectedVector.end());

    cout << ">>> Comparing " << size << " " << pattern << " items <<<\n";
    if(size <= 30)
    {
        cout << "\n>>> Unsorted vector <<<\n";
        Sort.PrintVector(unsortedVector);
    }

    bool allCorrect = true;
    cout << "\n" << left << setw(18) << "Algorithm" << right
         << setw(12) << "Time (ms)" << setw(12) << "Correct" << "\n";

    for(int i = 0; i < sortCount; i++)
    {
        vector<int> sortedVector = unsortedVector;
        steady_clock::time_point start = steady_clock::now();
        Sort.RunSort(sortedVector, i);
        steady_clock::time_point finish = steady_clock::now();
        double time = std::chrono::duration<double, std::milli>(finish-start).count();

        bool correct = sortedVector == expectedVector;
        if(!correct)
        {
            allCorrect = false;
        }

        cout << left << setw(18) << sortNames[i] << right
             << fixed << setprecision(3) << setw(12) << time
             << setw(12) << (correct ? "yes" : "no") << "\n";

        if(size <= 30)
        {
            Sort.PrintVector(sortedVector);
            cout << "\n";
        }
    }

    return allCorrect ? 0 : 1;
}
