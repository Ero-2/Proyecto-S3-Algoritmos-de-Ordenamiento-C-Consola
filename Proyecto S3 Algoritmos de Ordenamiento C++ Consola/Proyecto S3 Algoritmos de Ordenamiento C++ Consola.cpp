#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;




int main()
{
    vector<int> array = { 64, 34, 25, 12, 22, 11, 90 };

    std::cout << "Array original: " << std::endl;
    PrintArray(array);

    // Bubble Sort
    BubbleSort(array);
    cout << "\nArray after Bubble Sort: ";
    PrintArray(array);

    // Bucket Sort
    int maxVal = array[0];
    for (const auto& val : array) {
        if (val > maxVal) {
            maxVal = val;
        }
    }
    BucketSort(array, maxVal);
    cout << "\nArray after Bucket Sort: ";
    PrintArray(array);

    // Binary Tree Sort
    BinaryTreeSort(array);
    cout << "\nArray after Binary Tree Sort: ";
    PrintArray(array);

    // Quick Sort
    QuickSort(array, 0, array.size() - 1);
    cout << "\nArray after Quick Sort: ";
    PrintArray(array);

    // Cocktail Sort
    CocktailSort(array);
    cout << "\nArray after Cocktail Sort: ";
    PrintArray(array);

    // Merge Direct Sort
    MergeDirectSort(array, 0, array.size() - 1);
    cout << "\nArray after Merge Direct: ";

    NaturalMergeSort(array);
    std::cout << "\nArray después de Natural Merge Sort: " << std::endl;
    PrintArray(array);

    // Merge Sort
    MergeSort(array);
    std::cout << "\nArray after Merge Sort: " << std::endl;
    PrintArray(array);

    // Radix Sort
    RadixSort(array);
    std::cout << "\nArray after Radix Sort: " << std::endl;
    PrintArray(array);

    // Shell Sort
    ShellSort(array);
    std::cout << "\nArray after Shell Sort: " << std::endl;
    PrintArray(array);

    // Pigeonhole Sort
    PigeonholeSort(array);
    std::cout << "\nArray after Pigeonhole Sort: " << std::endl;
    PrintArray(array);

    //Gnome Sort
    GnomeSort(array);
    std::cout << "\nArray after Gnome Sort: " << std::endl;
        PrintArray(array);


      //Comb Sort
      CombSort(array);
     std::cout << "\nArray after Comb Sort: " << std::endl;
      PrintArray(array);

      //Selection Sort
      SelectionSort(array);
      std::cout << "\nArray after Selection Sort: " << std::endl;
      PrintArray(array);

      //Selection Sort
      HeapSort(array);
      std::cout << "\nArray after Heap Sort: " << std::endl;
      PrintArray(array);

      //Selection Sort
      SelectionSort(array);
      std::cout << "\nArray after Heap Sort: " << std::endl;
      PrintArray(array);

    return 0;


}

void PrintArray(const vector<int>& array) {
    for (const auto& element : array) {
        cout << element << " ";
    }
    cout << endl;
}

void BubbleSort(vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void BucketSort(vector<int>& array, int maxVal) {
    vector<int> bucket(maxVal + 1, 0);
    for (const auto& val : array) {
        bucket[val]++;
    }

    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (bucket[i] > 0) {
            array[index++] = i;
            bucket[i]--;
        }
    }
}

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void Insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    if (value < root->data) {
        Insert(root->left, value);
    }
    else {
        Insert(root->right, value);
    }
}

void InorderTraversal(Node* root, vector<int>& sortedArray) {
    if (root) {
        InorderTraversal(root->left, sortedArray);
        sortedArray.push_back(root->data);
        InorderTraversal(root->right, sortedArray);
    }
}

void BinaryTreeSort(vector<int>& array) {
    Node* root = nullptr;

    for (const auto& value : array) {
        Insert(root, value);
    }

    array.clear();
    InorderTraversal(root, array);
}

int Partition(vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[high]);
    return i + 1;
}

void QuickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        int pi = Partition(array, low, high);

        QuickSort(array, low, pi - 1);
        QuickSort(array, pi + 1, high);
    }
}

void CocktailSort(vector<int>& array) {
    int n = array.size();
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = false;
        end--;

        for (int i = end - 1; i >= start; i--) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }

        start++;
    }
}

void Merge(std::vector<int>& array, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }

    for (int j = 0; j < n2; j++) {
        rightArray[j] = array[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void NaturalMergeSort(std::vector<int>& array) {
    int n = array.size();
    int left = 0;
    int middle = 0;
    int right = 0;

    while (left < n - 1) {
        // Encuentra la primera secuencia ordenada
        while (middle < n - 1 && array[middle] <= array[middle + 1]) {
            middle++;
        }

        // Encuentra la siguiente secuencia ordenada
        right = middle + 1;
        while (right < n - 1 && array[right] <= array[right + 1]) {
            right++;
        }

        // Llama a Merge con los parámetros apropiados
        Merge(array, left, middle, right);

        // Actualiza el índice de inicio para la próxima iteración
        left = right + 1;
        middle = left;
    }
}

void MergeDirectSort(vector<int>& array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        MergeDirectSort(array, left, middle);
        MergeDirectSort(array, middle + 1, right);

        Merge(array, left, middle, right);
    }
}

void MergeSort(vector<int>& array) {
    int n = array.size();
    for (int currSize = 1; currSize <= n - 1; currSize = 2 * currSize) {
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            int mid = min(leftStart + currSize - 1, n - 1);
            int rightEnd = min(leftStart + 2 * currSize - 1, n - 1);

            Merge(array, leftStart, mid, rightEnd);
        }
    }
}

void CountingSort(vector<int>& array, int exp) {
    int n = array.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (const auto& val : array) {
        count[(val / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

void RadixSort(vector<int>& array) {
    int maxVal = array[0];
    for (const auto& val : array) {
        if (val > maxVal) {
            maxVal = val;
        }
    }

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        CountingSort(array, exp);
    }
}

void ShellSort(vector<int>& array) {
    int n = array.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void PigeonholeSort(vector<int>& array) {
    int minVal = array[0];
    int maxVal = array[0];
    int range, i, j, index;

    for (const auto& val : array) {
        if (val < minVal) {
            minVal = val;
        }
        if (val > maxVal) {
            maxVal = val;
        }
    }

    range = maxVal - minVal + 1;
    vector<int> pigeonhole(range, 0);

    for (const auto& val : array) {
        pigeonhole[val - minVal]++;
    }

    index = 0;
    for (i = 0; i < range; i++) {
        while (pigeonhole[i]--) {
            array[index++] = i + minVal;
        }
    }
}

void Swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}



// Implementación de GnomeSort
void GnomeSort(int arr[], int n) {
    int index = 0;

    while (index < n) {
        if (index == 0) {
            index++;
        }

        if (arr[index] >= arr[index - 1]) {
            index++;
        }
        else {
            Swap(arr, index, index - 1);
            index--;
        }
    }
}

// Implementación de CombSort
void CombSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = max(1, static_cast<int>(gap / 1.3));
        swapped = false;

        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                Swap(arr, i, i + gap);
                swapped = true;
            }
        }
    }
}

// Implementación de SelectionSort
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        Swap(arr, i, minIndex);
    }
}

// Función de ayuda para Heapify
void Heapify(int arr[], int n, int i) {
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != i) {
        Swap(arr, i, largest);
        Heapify(arr, n, largest);
    }
}

// Implementación de HeapSort
void HeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        Swap(arr, 0, i);
        Heapify(arr, i, 0);
    }
}

// Implementación de CountingSort
void CountingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max + 1] = { 0 };

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

