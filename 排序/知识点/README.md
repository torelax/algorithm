# 排序 Sorting

## 常见排序算法

| 算法 | 平均时间复杂度 | 空间复杂度 | 稳定性 |
|------|--------------|-----------|--------|
| 冒泡排序 | O(n²) | O(1) | 稳定 |
| 选择排序 | O(n²) | O(1) | 不稳定 |
| 插入排序 | O(n²) | O(1) | 稳定 |
| 归并排序 | O(n log n) | O(n) | 稳定 |
| 快速排序 | O(n log n) | O(log n) | 不稳定 |
| 堆排序 | O(n log n) | O(1) | 不稳定 |
| 计数排序 | O(n + k) | O(k) | 稳定 |

## 快速排序
```cpp
void quickSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int pivot = arr[l], i = l, j = r;
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;
        while (i < j && arr[i] <= pivot) i++;
        swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[i]);
    quickSort(arr, l, i - 1);
    quickSort(arr, i + 1, r);
}
```

## 归并排序
```cpp
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    // merge arr[l..mid] and arr[mid+1..r]
    vector<int> tmp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
        else tmp.push_back(arr[j++]);
    }
    while (i <= mid) tmp.push_back(arr[i++]);
    while (j <= r) tmp.push_back(arr[j++]);
    for (int k = l; k <= r; k++) arr[k] = tmp[k - l];
}
```

## 二分查找
```cpp
int binarySearch(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
```
