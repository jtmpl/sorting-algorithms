#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>

using std::vector;
using std::cout;
using std::setw;
using std::right;
using std::left;
using std::rand;

class SortingAlgorithms
{
public:
    vector<int> CreateTestVector(int size = 1000)
    {
        vector<int> testVector;

        for(int i = 0; i < size; i++)
        {
            testVector.push_back(rand()%size);
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


int main()
{
    SortingAlgorithms Sort;

    vector<int> unsortedVector = Sort.CreateTestVector();

    cout << ">>> BubbleSort <<<\n";
    vector<int> bsV = unsortedVector;
    Sort.BubbleSort(bsV);

    Sort.PrintVector(bsV);

    cout << "\n>>> SelectionSort <<<\n";
    vector<int> ssV = unsortedVector;
    Sort.SelectionSort(ssV);

    Sort.PrintVector(ssV);

    cout << "\n>>> InsertionSort <<<\n";
    vector<int> isV = unsortedVector;
    Sort.InsertionSort(isV);

    Sort.PrintVector(isV);

    cout << "\n>>> MergeSort <<<\n";

    vector<int> msV = unsortedVector;
    Sort.MergeSort(msV, 0, (int)msV.size() - 1);

    Sort.PrintVector(msV);

    cout << "\n>>> QuickSort <<<\n";
    vector<int> qsV = unsortedVector;
    Sort.QuickSort(qsV, 0, (int)qsV.size() - 1);

    Sort.PrintVector(qsV);

    cout << "\n";


    return 0;
}
