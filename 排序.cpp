#include<iostream>
using namespace std;

// ��ӡ����Ԫ�صĺ���
// ���� arr Ϊ����ӡ�����飬n Ϊ����ĳ���
void print(int arr[], int n) {
    // ���������е�ÿ��Ԫ��
    for (int i = 0; i < n; i++) {
        // �����ǰԪ��
        cout << arr[i];
        // ����������һ��Ԫ�أ����һ���ո�ָ�
        if (i < n - 1) {
            cout << " ";
        }
    }
    // ������з���ʹ���������
    cout << endl;
}

// ð��������
// ���� arr Ϊ����������飬n Ϊ����ĳ���
void Bubble_Sort(int arr[], int n) {
    // ���ѭ������������������ܹ���Ҫ���� n - 1 ��
    for (int i = 0; i < n - 1; i++) {
        // �ڲ�ѭ�����ڱȽ�����Ԫ�ز�����λ��
        for (int j = 0; j < n - 1 - i; j++) {
            // �����ǰԪ�ش�����һ��Ԫ�أ��򽻻����ǵ�λ��
            if (arr[j] > arr[j + 1]) {
                // ��ʱ���� temp ���ڴ洢��ǰԪ�ص�ֵ
                int temp = arr[j];
                // ����һ��Ԫ�ص�ֵ������ǰԪ��
                arr[j] = arr[j + 1];
                // ����ʱ������ԭ��ǰԪ�ص�ֵ��������һ��Ԫ��
                arr[j + 1] = temp;
            }
        }
    }
}

// ѡ��������
// ���� arr Ϊ����������飬n Ϊ����ĳ���
void Selection_Sort(int arr[], int n) {
    // ���ѭ�����������򲿷ֵı߽磬��Ҫ���� n - 1 ��ѡ��
    for (int i = 0; i < n - 1; i++) {
        // ���赱ǰδ���򲿷ֵĵ�һ��Ԫ��Ϊ��Сֵ
        int min = i;
        // �ڲ�ѭ������δ���򲿷֣��ҵ���Сֵ������
        for (int j = i + 1; j < n; j++) {
            // ����ҵ��ȵ�ǰ��Сֵ��С��Ԫ��
            if (arr[j] < arr[min]) {
                // ������Сֵ������
                min = j;
            }
        }
        // ���ҵ�����Сֵ��δ���򲿷ֵĵ�һ��Ԫ�ؽ���λ��
        swap(arr[min], arr[i]);
    }
}

// ����������
// ���� arr Ϊ����������飬n Ϊ����ĳ���
void Insertion_Sort(int arr[], int n) {
    // �ӵڶ���Ԫ�ؿ�ʼ��������뵽ǰ��������Ĳ���
    for (int i = 1; i < n; i++) {
        // ��¼��ǰҪ�����Ԫ�ص�ֵ
        int key = arr[i];
        // ��¼�����򲿷ֵ����һ��Ԫ�ص�����
        int j = i - 1;
        // �������򲿷ֵ�Ԫ�ش���Ҫ�����Ԫ�أ���δԽ��ʱ
        while ((j >= 0) && (arr[j] > key)) {
            // �������򲿷ֵ�Ԫ�غ���һλ
            arr[j + 1] = arr[j];
            // ������ǰ�Ƚ�
            j--;
        }
        // ���������Ԫ�ز��뵽���ʵ�λ��
        arr[j + 1] = key;
    }
}

// ϣ��������
// ���� arr Ϊ����������飬n Ϊ����ĳ���
void Shell_Sort(int arr[], int n) {
    // ��ʼ���Ϊ���鳤�ȵ�һ��
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // ��ÿ��������в�������
        for (int i = gap; i < n; i++) {
            // ��¼��ǰҪ�����Ԫ�ص�ֵ
            int temp = arr[i];
            int j;
            // �Լ��Ϊ gap ��Ԫ�ؽ��в�������
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                // ��Ԫ�غ��� gap λ
                arr[j] = arr[j - gap];
            }
            // ���������Ԫ�ز��뵽���ʵ�λ��
            arr[j] = temp;
        }
    }
}

// �鲢����ĺϲ����������ںϲ���������������
// ���� arr Ϊ���ϲ������飬left Ϊ�����������ʼ������mid Ϊ�м�������right Ϊ��������Ľ�������
void merge(int arr[], int left, int mid, int right) {
    // ������������ĳ���
    int n1 = mid - left + 1;
    // ������������ĳ���
    int n2 = right - mid;

    // ��ʱ���� L ���ڴ洢��������
    int L[n1];
    // ��ʱ���� R ���ڴ洢��������
    int R[n2];

    // �����������Ԫ�ظ��Ƶ���ʱ���� L ��
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    // �����������Ԫ�ظ��Ƶ���ʱ���� R ��
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // ��������ĵ�ǰ����
    int i = 0;
    // ��������ĵ�ǰ����
    int j = 0;
    // �ϲ�������ĵ�ǰ����
    int k = left;

    // �Ƚ������������Ԫ�أ�����С��Ԫ�����η���ԭ����
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

    // ������������ʣ���Ԫ�ظ��Ƶ�ԭ����
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // ������������ʣ���Ԫ�ظ��Ƶ�ԭ����
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// �鲢������
// ���� arr Ϊ����������飬left Ϊ�������ʼ������right Ϊ����Ľ�������
void Merge_Sort(int arr[], int left, int right) {
    // ��������С��������ʱ��˵�����黹���Լ����ָ�
    if (left < right) {
        // �����м�����
        int mid = left + (right - left) / 2;

        // �ݹ�������������
        Merge_Sort(arr, left, mid);
        // �ݹ�������������
        Merge_Sort(arr, mid + 1, right);

        // �ϲ���������������
        merge(arr, left, mid, right);
    }
}

// ��������ķ������������ڽ������Ϊ������
// ���� arr Ϊ�����������飬low Ϊ�������ʼ������high Ϊ����Ľ�������
int partition(int arr[], int low, int high) {
    // ѡ�����һ��Ԫ����Ϊ��׼ֵ
    int pivot = arr[high];
    // ��ʼ��С�ڻ�׼ֵ��Ԫ�صı߽�
    int i = low - 1;

    // �������飬��С�ڻ�׼ֵ��Ԫ�ؽ��������
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // ����׼ֵ�ŵ���ȷ��λ��
    swap(arr[i + 1], arr[high]);
    // ���ػ�׼ֵ������λ��
    return i + 1;
}

// ����������
// ���� arr Ϊ����������飬low Ϊ�������ʼ������high Ϊ����Ľ�������
void Quick_Sort(int arr[], int low, int high) {
    // ����ʼ����С�ڽ�������ʱ��˵�����黹���Լ�������
    if (low < high) {
        // ���з����������õ���׼ֵ������λ��
        int pi = partition(arr, low, high);

        // �ݹ������׼ֵ��ߵ�������
        Quick_Sort(arr, low, pi - 1);
        // �ݹ������׼ֵ�ұߵ�������
        Quick_Sort(arr, pi + 1, high);
    }
}

// ������Ķѵ������������ڽ��� i Ϊ������������Ϊ����
// ���� arr Ϊ�����������飬n Ϊ����ĳ��ȣ�i Ϊ��ǰ���ڵ������
void heapify(int arr[], int n, int i) {
    // ���赱ǰ���ڵ�Ϊ���ֵ
    int largest = i;
    // �������ӽڵ������
    int left = 2 * i + 1;
    // �������ӽڵ������
    int right = 2 * i + 2;

    // ������ӽڵ�����Ҵ��ڵ�ǰ���ֵ
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // ������ӽڵ�����Ҵ��ڵ�ǰ���ֵ
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // ������ֵ���ǵ�ǰ���ڵ�
    if (largest != i) {
        // �������ڵ�����ֵ�ڵ�
        swap(arr[i], arr[largest]);
        // �ݹ���������ֵ�ڵ�Ϊ��������
        heapify(arr, n, largest);
    }
}

// ��������
// ���� arr Ϊ����������飬n Ϊ����ĳ���
void Heap_Sort(int arr[], int n) {
    // ��������
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // ���ν��Ѷ�Ԫ�أ����ֵ�������һ��Ԫ�ؽ�������������
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ����������
// ���� arr Ϊ����������飬n Ϊ����ĳ���
void Counting_Sort(int arr[], int n) {
    // �ҵ������е����ֵ
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // ��ʼ���������飬���ڼ�¼ÿ��Ԫ�صĳ��ִ���
    int count[max_val + 1] = {0};
    // ͳ��ÿ��Ԫ�صĳ��ִ���
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // ������������
    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

// Ͱ����Ĳ������������������ڶ�Ͱ��Ԫ�ؽ�������
// ���� bucket Ϊ�������Ͱ��size ΪͰ��Ԫ�ص�����
void insertionSort(int bucket[], int size) {
    // �ӵڶ���Ԫ�ؿ�ʼ��������뵽ǰ��������Ĳ���
    for (int i = 1; i < size; i++) {
        // ��¼��ǰҪ�����Ԫ�ص�ֵ
        int key = bucket[i];
        // ��¼�����򲿷ֵ����һ��Ԫ�ص�����
        int j = i - 1;
        // �������򲿷ֵ�Ԫ�ش���Ҫ�����Ԫ�أ���δԽ��ʱ
        while (j >= 0 && bucket[j] > key) {
            // �������򲿷ֵ�Ԫ�غ���һλ
            bucket[j + 1] = bucket[j];
            // ������ǰ�Ƚ�
            j--;
        }
        // ���������Ԫ�ز��뵽���ʵ�λ��
        bucket[j + 1] = key;
    }
}

// Ͱ������
// ���� arr Ϊ����������飬n Ϊ����ĳ���
void Bucket_Sort(int arr[], int n) {
    // �ҵ������е����ֵ
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // ����Ͱ������
    int num_buckets = 10;
    // ��ά���� buckets ���ڴ洢ÿ��Ͱ��Ԫ��
    int buckets[num_buckets][1005];
    // ���� bucket_size ���ڼ�¼ÿ��Ͱ��Ԫ�ص�����
    int bucket_size[num_buckets] = {0};

    // ��Ԫ�ط��䵽��ͬ��Ͱ��
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] * num_buckets) / (max_val + 1);
        buckets[bucket_index][bucket_size[bucket_index]++] = arr[i];
    }

    // ��ÿ��Ͱ�ڵ�Ԫ�ؽ��в������򣬲��ϲ����
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        insertionSort(buckets[i], bucket_size[i]);
        for (int j = 0; j < bucket_size[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// ��������ĸ������������ڻ�ȡ�������������λ��
// ���� arr Ϊ����������飬n Ϊ����ĳ���
int getMax(int arr[], int n) {
    // �ҵ������е����ֵ
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    // �������ֵ��λ��
    int digits = 0;
    while (max_val > 0) {
        digits++;
        max_val /= 10;
    }
    return digits;
}

// ����������
// ���� arr Ϊ����������飬n Ϊ����ĳ���
void Radix_Sort(int arr[], int n) {
    // ��ȡ�������������λ��
    int max_digits = getMax(arr, n);
    // ��ʼ����ǰ�����λ��
    int exp = 1;
    // ��ʱ���� output ���ڴ洢������
    int output[1005];
    // �������� count ���ڼ�¼ÿ����λ�����ֵĳ��ִ���
    int count[10] = {0};

    // ��ÿһλ���м�������
    for (int i = 0; i < max_digits; i++) {
        // ��ʼ����������
        for (int j = 0; j < 10; j++) {
            count[j] = 0;
        }

        // ͳ��ÿ����λ�����ֵĳ��ִ���
        for (int j = 0; j < n; j++) {
            count[(arr[j] / exp) % 10]++;
        }

        // ����ÿ����λ�����ֵ��ۻ����ִ���
        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }

        // �����ۻ����ִ�����Ԫ�ط�����ʱ���� output ��
        for (int j = n - 1; j >= 0; j--) {
            output[count[(arr[j] / exp) % 10] - 1] = arr[j];
            count[(arr[j] / exp) % 10]--;
        }

        // ����ʱ���� output �е�Ԫ�ظ��ƻ�ԭ����
        for (int j = 0; j < n; j++) {
            arr[j] = output[j];
        }

        // ������һλ
        exp *= 10;
    }
}

int main() {
    // ������� n ���ڴ洢����ĳ���
    int n;
    // �ӱ�׼�����ȡ����ĳ���
    cin >> n;
    // �������� arr ���ڴ洢�����Ԫ��
    int arr[1005];
    // �ӱ�׼�����ȡ�����Ԫ��
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ѡ��Ҫʹ�õ������㷨��ȡ����Ӧע�ͼ���ʹ��
    // Bubble_Sort(arr, n);  //ð��
    // Selection_Sort(arr, n); //ѡ��
    // Insertion_Sort(arr, n); //����
    // Shell_Sort(arr, n); //ϣ��
    // Merge_Sort(arr, 0, n - 1); //�鲢
    // Quick_Sort(arr, 0, n - 1); //����
    // Heap_Sort(arr, n); //����
    // Counting_Sort(arr, n); //����
    // Bucket_Sort(arr, n); //Ͱ��
    Radix_Sort(arr, n); //����

    // ���� print �����������������
    print(arr, n);

    return 0;
}
