#include <iostream>
#include <vector>
using namespace std;

void print_array(const vector<int>& arr)
{
    for (auto& num : arr)
    {
        cout << num << ", ";
    }
    cout << endl;
}

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
/* bubble sort */
void bubble_sort(vector<int> nums, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool swapped = false;
        for (int j = 1; j < size - i; j++)
        {
            if (nums[j] < nums[j - 1])
            {
                swap(nums[j], nums[j - 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    cout << "bubble sort result:" << endl;
    print_array(nums);
}

/* selection sort */
void selection_sort(vector<int> nums, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (nums[j] < nums[min]) min = j;
        }
        swap(nums[i], nums[min]);
    }
    cout << "selection sort result:" << endl;
    print_array(nums);
}

/* insertion sort */
void insertion_sort(vector<int> nums, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; j--)
        {
            swap(nums[j], nums[j - 1]);
        }
    }

    cout << "insertion sort result:" << endl;
    print_array(nums);
}

/* shell sort */
void shell_sort(vector<int> nums, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int j = i;
            int current = nums[i];
            while (j - gap >= 0 && current < nums[j - gap])
            {
                nums[j] = nums[j - gap];
                j -= gap;
            }
            nums[j] = current;
        }
    }
    cout << "shell sort result:" << endl;
    print_array(nums);
}

/* merge sort */
void merge_sort(vector<int>& nums, int l, int r, vector<int>& temp)
{
    if (l + 1 >= r) return;
    // divide
    int m = l + (r - l) / 2;
    merge_sort(nums, l, m, temp);
    merge_sort(nums, m, r, temp);
    // conquer
    int p = l, q = m, i = l;
    while (p < m || q < r)
    {
        temp[i++] = (q >= r || (nums[p] <= nums[q] && p < m)) ? nums[p++] : nums[q++];
    }
    for (int i = l; i < r; i++)
    {
        nums[i] = temp[i];
    }
}

/* quick sort */
void quick_sort(vector<int>& nums, int l, int r)
{
    if (l + 1 >= r) return;
    int first = l, last = r - 1, key = nums[first];
    while (first < last)
    {
        while (first < last && nums[last] >= key) last--;
        nums[first] = nums[last];
        while (first < last && nums[first] <= key) first++;
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}

void heapify(vector<int>& nums, int size, int index)
{
    int left = 2 * index + 1, right = 2 * index + 2;
    int largest = index;
    if (left < size && nums[left] > nums[largest]) largest = left;
    if (right < size && nums[right] > nums[largest]) largest = right;
    if (largest != index)
    {
        swap(nums[largest], nums[index]);
        heapify(nums, size, largest);
    }
}

void build_max_heap(vector<int>& nums, int size)
{
    for (int i = size / 2; i >= 0; i--)
    {
        heapify(nums, size, i);
    }
}

/* heap sort */
void heap_sort(vector<int> nums, int size)
{
    build_max_heap(nums, size);
    for (int i = size - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]);
        heapify(nums, --size, 0);
    }

    cout << "heap sort result:" << endl;
    print_array(nums);
}

void sort()
{
    vector<int> nums = {1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8, 7, 6, 0, 3, 5, 9, 4, 1, 0};
    vector<int> temp(nums.size());
    auto nums1 = nums;
    quick_sort(nums1, 0, nums1.size());
    cout << "quick sort result:" << endl;
    print_array(nums1);
    nums1 = nums;
    merge_sort(nums1, 0, nums1.size(), temp);
    cout << "merge sort result:" << endl;
    print_array(nums1);

    heap_sort(nums, nums.size());
    shell_sort(nums, nums.size());
    insertion_sort(nums, nums.size());
    bubble_sort(nums, nums.size());
    selection_sort(nums, nums.size());

    cout << "built-in sort result:" << endl;
    sort(nums.begin(), nums.end());
    print_array(nums);
}

int main()
{
    sort();
    return 0;
}