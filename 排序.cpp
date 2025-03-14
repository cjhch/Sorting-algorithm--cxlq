#include<iostream>
using namespace std;

// 打印数组元素的函数
// 参数 arr 为待打印的数组，n 为数组的长度
void print(int arr[], int n) {
    // 遍历数组中的每个元素
    for (int i = 0; i < n; i++) {
        // 输出当前元素
        cout << arr[i];
        // 如果不是最后一个元素，输出一个空格分隔
        if (i < n - 1) {
            cout << " ";
        }
    }
    // 输出换行符，使输出更美观
    cout << endl;
}

// 冒泡排序函数
// 参数 arr 为待排序的数组，n 为数组的长度
void Bubble_Sort(int arr[], int n) {
    // 外层循环控制排序的轮数，总共需要进行 n - 1 轮
    for (int i = 0; i < n - 1; i++) {
        // 内层循环用于比较相邻元素并交换位置
        for (int j = 0; j < n - 1 - i; j++) {
            // 如果当前元素大于下一个元素，则交换它们的位置
            if (arr[j] > arr[j + 1]) {
                // 临时变量 temp 用于存储当前元素的值
                int temp = arr[j];
                // 将下一个元素的值赋给当前元素
                arr[j] = arr[j + 1];
                // 将临时变量（原当前元素的值）赋给下一个元素
                arr[j + 1] = temp;
            }
        }
    }
}

// 选择排序函数
// 参数 arr 为待排序的数组，n 为数组的长度
void Selection_Sort(int arr[], int n) {
    // 外层循环控制已排序部分的边界，需要进行 n - 1 次选择
    for (int i = 0; i < n - 1; i++) {
        // 假设当前未排序部分的第一个元素为最小值
        int min = i;
        // 内层循环遍历未排序部分，找到最小值的索引
        for (int j = i + 1; j < n; j++) {
            // 如果找到比当前最小值更小的元素
            if (arr[j] < arr[min]) {
                // 更新最小值的索引
                min = j;
            }
        }
        // 将找到的最小值与未排序部分的第一个元素交换位置
        swap(arr[min], arr[i]);
    }
}

// 插入排序函数
// 参数 arr 为待排序的数组，n 为数组的长度
void Insertion_Sort(int arr[], int n) {
    // 从第二个元素开始，将其插入到前面已排序的部分
    for (int i = 1; i < n; i++) {
        // 记录当前要插入的元素的值
        int key = arr[i];
        // 记录已排序部分的最后一个元素的索引
        int j = i - 1;
        // 当已排序部分的元素大于要插入的元素，且未越界时
        while ((j >= 0) && (arr[j] > key)) {
            // 将已排序部分的元素后移一位
            arr[j + 1] = arr[j];
            // 继续向前比较
            j--;
        }
        // 将待插入的元素插入到合适的位置
        arr[j + 1] = key;
    }
}

// 希尔排序函数
// 参数 arr 为待排序的数组，n 为数组的长度
void Shell_Sort(int arr[], int n) {
    // 初始间隔为数组长度的一半
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个间隔进行插入排序
        for (int i = gap; i < n; i++) {
            // 记录当前要插入的元素的值
            int temp = arr[i];
            int j;
            // 对间隔为 gap 的元素进行插入排序
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                // 将元素后移 gap 位
                arr[j] = arr[j - gap];
            }
            // 将待插入的元素插入到合适的位置
            arr[j] = temp;
        }
    }
}

// 归并排序的合并函数，用于合并两个有序子数组
// 参数 arr 为待合并的数组，left 为左子数组的起始索引，mid 为中间索引，right 为右子数组的结束索引
void merge(int arr[], int left, int mid, int right) {
    // 计算左子数组的长度
    int n1 = mid - left + 1;
    // 计算右子数组的长度
    int n2 = right - mid;

    // 临时数组 L 用于存储左子数组
    int L[n1];
    // 临时数组 R 用于存储右子数组
    int R[n2];

    // 将左子数组的元素复制到临时数组 L 中
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    // 将右子数组的元素复制到临时数组 R 中
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 左子数组的当前索引
    int i = 0;
    // 右子数组的当前索引
    int j = 0;
    // 合并后数组的当前索引
    int k = left;

    // 比较左右子数组的元素，将较小的元素依次放入原数组
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 将左子数组中剩余的元素复制到原数组
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 将右子数组中剩余的元素复制到原数组
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序函数
// 参数 arr 为待排序的数组，left 为数组的起始索引，right 为数组的结束索引
void Merge_Sort(int arr[], int left, int right) {
    // 当左索引小于右索引时，说明数组还可以继续分割
    if (left < right) {
        // 计算中间索引
        int mid = left + (right - left) / 2;

        // 递归排序左子数组
        Merge_Sort(arr, left, mid);
        // 递归排序右子数组
        Merge_Sort(arr, mid + 1, right);

        // 合并两个有序子数组
        merge(arr, left, mid, right);
    }
}

// 快速排序的分区函数，用于将数组分为两部分
// 参数 arr 为待分区的数组，low 为数组的起始索引，high 为数组的结束索引
int partition(int arr[], int low, int high) {
    // 选择最后一个元素作为基准值
    int pivot = arr[high];
    // 初始化小于基准值的元素的边界
    int i = low - 1;

    // 遍历数组，将小于基准值的元素交换到左边
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // 将基准值放到正确的位置
    swap(arr[i + 1], arr[high]);
    // 返回基准值的最终位置
    return i + 1;
}

// 快速排序函数
// 参数 arr 为待排序的数组，low 为数组的起始索引，high 为数组的结束索引
void Quick_Sort(int arr[], int low, int high) {
    // 当起始索引小于结束索引时，说明数组还可以继续排序
    if (low < high) {
        // 进行分区操作，得到基准值的最终位置
        int pi = partition(arr, low, high);

        // 递归排序基准值左边的子数组
        Quick_Sort(arr, low, pi - 1);
        // 递归排序基准值右边的子数组
        Quick_Sort(arr, pi + 1, high);
    }
}

// 堆排序的堆调整函数，用于将以 i 为根的子树调整为最大堆
// 参数 arr 为待调整的数组，n 为数组的长度，i 为当前根节点的索引
void heapify(int arr[], int n, int i) {
    // 假设当前根节点为最大值
    int largest = i;
    // 计算左子节点的索引
    int left = 2 * i + 1;
    // 计算右子节点的索引
    int right = 2 * i + 2;

    // 如果左子节点存在且大于当前最大值
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点存在且大于当前最大值
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是当前根节点
    if (largest != i) {
        // 交换根节点和最大值节点
        swap(arr[i], arr[largest]);
        // 递归调整以最大值节点为根的子树
        heapify(arr, n, largest);
    }
}

// 堆排序函数
// 参数 arr 为待排序的数组，n 为数组的长度
void Heap_Sort(int arr[], int n) {
    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 依次将堆顶元素（最大值）与最后一个元素交换，并调整堆
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 计数排序函数
// 参数 arr 为待排序的数组，n 为数组的长度
void Counting_Sort(int arr[], int n) {
    // 找到数组中的最大值
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // 初始化计数数组，用于记录每个元素的出现次数
    int count[max_val + 1] = {0};
    // 统计每个元素的出现次数
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 重新排列数组
    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

// 桶排序的插入排序辅助函数，用于对桶内元素进行排序
// 参数 bucket 为待排序的桶，size 为桶内元素的数量
void insertionSort(int bucket[], int size) {
    // 从第二个元素开始，将其插入到前面已排序的部分
    for (int i = 1; i < size; i++) {
        // 记录当前要插入的元素的值
        int key = bucket[i];
        // 记录已排序部分的最后一个元素的索引
        int j = i - 1;
        // 当已排序部分的元素大于要插入的元素，且未越界时
        while (j >= 0 && bucket[j] > key) {
            // 将已排序部分的元素后移一位
            bucket[j + 1] = bucket[j];
            // 继续向前比较
            j--;
        }
        // 将待插入的元素插入到合适的位置
        bucket[j + 1] = key;
    }
}

// 桶排序函数
// 参数 arr 为待排序的数组，n 为数组的长度
void Bucket_Sort(int arr[], int n) {
    // 找到数组中的最大值
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // 定义桶的数量
    int num_buckets = 10;
    // 二维数组 buckets 用于存储每个桶的元素
    int buckets[num_buckets][1005];
    // 数组 bucket_size 用于记录每个桶内元素的数量
    int bucket_size[num_buckets] = {0};

    // 将元素分配到不同的桶中
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] * num_buckets) / (max_val + 1);
        buckets[bucket_index][bucket_size[bucket_index]++] = arr[i];
    }

    // 对每个桶内的元素进行插入排序，并合并结果
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        insertionSort(buckets[i], bucket_size[i]);
        for (int j = 0; j < bucket_size[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// 基数排序的辅助函数，用于获取数组中最大数的位数
// 参数 arr 为待处理的数组，n 为数组的长度
int getMax(int arr[], int n) {
    // 找到数组中的最大值
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    // 计算最大值的位数
    int digits = 0;
    while (max_val > 0) {
        digits++;
        max_val /= 10;
    }
    return digits;
}

// 基数排序函数
// 参数 arr 为待排序的数组，n 为数组的长度
void Radix_Sort(int arr[], int n) {
    // 获取数组中最大数的位数
    int max_digits = getMax(arr, n);
    // 初始化当前处理的位数
    int exp = 1;
    // 临时数组 output 用于存储排序结果
    int output[1005];
    // 计数数组 count 用于记录每个数位上数字的出现次数
    int count[10] = {0};

    // 对每一位进行计数排序
    for (int i = 0; i < max_digits; i++) {
        // 初始化计数数组
        for (int j = 0; j < 10; j++) {
            count[j] = 0;
        }

        // 统计每个数位上数字的出现次数
        for (int j = 0; j < n; j++) {
            count[(arr[j] / exp) % 10]++;
        }

        // 计算每个数位上数字的累积出现次数
        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }

        // 根据累积出现次数将元素放入临时数组 output 中
        for (int j = n - 1; j >= 0; j--) {
            output[count[(arr[j] / exp) % 10] - 1] = arr[j];
            count[(arr[j] / exp) % 10]--;
        }

        // 将临时数组 output 中的元素复制回原数组
        for (int j = 0; j < n; j++) {
            arr[j] = output[j];
        }

        // 处理下一位
        exp *= 10;
    }
}

int main() {
    // 定义变量 n 用于存储数组的长度
    int n;
    // 从标准输入读取数组的长度
    cin >> n;
    // 定义数组 arr 用于存储输入的元素
    int arr[1005];
    // 从标准输入读取数组的元素
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 选择要使用的排序算法，取消相应注释即可使用
    // Bubble_Sort(arr, n);  //冒泡
    // Selection_Sort(arr, n); //选择
    // Insertion_Sort(arr, n); //插入
    // Shell_Sort(arr, n); //希尔
    // Merge_Sort(arr, 0, n - 1); //归并
    // Quick_Sort(arr, 0, n - 1); //快排
    // Heap_Sort(arr, n); //堆排
    // Counting_Sort(arr, n); //计数
    // Bucket_Sort(arr, n); //桶排
    Radix_Sort(arr, n); //基数

    // 调用 print 函数输出排序后的数组
    print(arr, n);

    return 0;
}
