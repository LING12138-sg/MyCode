#include"MySort.h"
#include<iomanip>
#include<cmath>
#include<thread>
#include<chrono>

// 定义 ANSI 颜色
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"  // 重置颜色

// 冒泡排序,参数依次为数组，大小，排序方式(默认升序)，是否可视化，显示速度
void MySort::bubblingSort(bool greater, bool visual, int speed) {
	if (visual) {
		cout << "\033[2J";  // 清屏，仅初始化时调用
		cout << "\033[?25l";  // 隐藏光标
	}
	const int len = data.size();
	if (len == 0)
		return;
	for (int i = 0; i < len - 1; i++) {
		iterationCount++;
		for (int j = 0; j < len - i - 1; j++) {
			iterationCount++;
			if (greater) { // 升序
				compareCount++;
				if (data[j] > data[j + 1]) {
					swap(data[j], data[j + 1]);
					changeCount++;
					// 可视化
					if (visual) {
						cout << "\033[H";  // 光标移动到屏幕顶部
						cout << "排序过程:" << endl;
						display(*this);
						this_thread::sleep_for(chrono::milliseconds(speed));
					}
				}
			}
			else { // 降序
				compareCount++;
				if (data[j] < data[j + 1]) {
					swap(data[j], data[j + 1]);
					changeCount++;
					if (visual) {
						cout << "\033[H";  // 光标移动到屏幕顶部
						cout << "排序过程:" << endl;
						display(*this);
						this_thread::sleep_for(chrono::milliseconds(speed));
					}
				}
			}
		}
	}
	deepth++; // 递归次数
	callCount++;
	stability = true;
	if(visual)
		cout << "\033[?25h";  // 恢复光标
}

// 选择排序
void MySort::choiceSort(bool greater, bool visual, int speed) {
	if (visual) {
		cout << "\033[2J";  // 清屏，仅初始化时调用
		cout << "\033[?25l";  // 隐藏光标
	}
	const int len = data.size();
	if (len == 0)
		return;
	if (greater) {  // 升序
		for (int i = 0; i < len; i++) {
			iterationCount++;
			int min = i;
			for (int j = i + 1; j < len; j++) {
				iterationCount++;
				if (data[j] < data[min]) {
					min = j;
				}
				compareCount++;
			}
			swap(data[i], data[min]);
			changeCount++;
			if (visual) {
				cout << "\033[H";  // 光标移动到屏幕顶部
				cout << "排序过程:" << endl;
				display(*this);
				this_thread::sleep_for(chrono::milliseconds(speed));
			}
		}
	}
	else {  // 降序
		for (int i = 0; i < len; i++) {
			iterationCount++;
			int max = i;
			for (int j = i + 1; j < len; j++) {
				iterationCount++;
				if (data[j] > data[max]) {
					max = j;
				}
				compareCount++;
			}
			swap(data[i], data[max]);
			changeCount++;
			if (visual) {
				cout << "\033[H";  // 光标移动到屏幕顶部
				cout << "排序过程:" << endl;
				display(*this);
				this_thread::sleep_for(chrono::milliseconds(speed));
			}
		}
	}
	deepth++; // 递归次数
	callCount++;
	stability = true;
	if (visual)
		cout << "\033[?25h";  // 恢复光标
}

// 插入排序
void MySort::insertSort(bool greater, bool visual, int speed) {
	if (visual) {
		cout << "\033[2J";  // 清屏，仅初始化时调用
		cout << "\033[?25l";  // 隐藏光标
	}
	const int len = data.size();
	if (len == 0)
		return;
	for (int i = 1; i < len; i++) {
		iterationCount++;
		if (greater) { // 升序
			compareCount++;
			if (data[i] < data[i - 1]) {
				int j = i - 1;
				int temp = data[i];
				while (j >= 0 && temp < data[j]) {
					compareCount++;
					iterationCount++;
					data[j + 1] = data[j];
					j--;
				}
				data[j + 1] = temp;
				changeCount++;
				if (visual) {
					cout << "\033[H";  // 光标移动到屏幕顶部
					cout << "排序过程:" << endl;
					display(*this);
					this_thread::sleep_for(chrono::milliseconds(speed));
				}
			}
		}
		else {  // 降序
			compareCount++;
			if (data[i] > data[i - 1]) {
				int j = i - 1;
				int temp = data[i];
				while (j >= 0 && temp > data[j]) {
					compareCount++;
					iterationCount++;
					data[j + 1] = data[j];
					j--;
				}
				data[j + 1] = temp;
				changeCount++;
				if (visual) {
					cout << "\033[H";  // 光标移动到屏幕顶部
					cout << "排序过程:" << endl;
					display(*this);
					this_thread::sleep_for(chrono::milliseconds(speed));
				}
			}
		}
	}
	deepth++; // 递归次数
	callCount++;
	stability = false;
	if (visual)
		cout << "\033[?25h";  // 恢复光标
}

// 希尔排序
void MySort::shellSort(bool greater, bool visual, int speed) {
	if (visual) {
		cout << "\033[2J";  // 清屏，仅初始化时调用
		cout << "\033[?25l";  // 隐藏光标
	}
	const int len = data.size();
	if (len == 0)
		return;
	if (greater) {
		for (int gap = len / 2; gap >= 1; gap /= 2) {
			iterationCount++;
			for (int i = gap; i < len; i++) {
				iterationCount++;
				int temp = data[i]; // 暂存当前元素
				int j = i;
				while (j >= gap && temp < data[j - gap]) {
					iterationCount++;
					compareCount++;
					data[j] = data[j - gap]; // 元素后移
					j -= gap;
				}
				data[j] = temp;
				changeCount++;
				if (visual) {
					cout << "\033[H";  // 光标移动到屏幕顶部
					cout << "排序过程:" << endl;
					display(*this);
					this_thread::sleep_for(chrono::milliseconds(speed));
				}
			}
		}
	}
	else {
		for (int gap = len / 2; gap >= 1; gap /= 2) {
			iterationCount++;
			for (int i = gap; i < len; i++) {
				iterationCount++;
				int temp = data[i];
				int j = i;
				while (j >= gap && temp > data[j - gap]) {
					iterationCount++;
					compareCount++;
					data[j] = data[j - gap]; // 后移元素
					j -= gap;
				}
				data[j] = temp;
				changeCount++;
				if (visual) {
					cout << "\033[H";  // 光标移动到屏幕顶部
					cout << "排序过程:" << endl;
					display(*this);
					this_thread::sleep_for(chrono::milliseconds(speed));
				}
			}
		}
	}
	deepth++; // 递归次数
	callCount++;
	stability = false;
	if (visual)
		cout << "\033[?25h";  // 恢复光标
}


// 归并排序(递归版)
void MySort::merge(vector<int>& arr, const vector<int>& left, const vector<int>& right, bool greater) {
	int i = 0, j = 0, k = 0;
	int leftLen = left.size(), rightLen = right.size();

	// 比较两个子数组并合并
	while (i < leftLen && j < rightLen) {
		iterationCount++;
		if (greater) {  // 升序
			compareCount++;
			changeCount++;
			if (left[i] <= right[j])
				arr[k++] = left[i++];
			else
				arr[k++] = right[j++];
		}
		else {  // 降序
			compareCount++;
			changeCount++;
			if (left[i] >= right[j])
				arr[k++] = left[i++];
			else
				arr[k++] = right[j++];
		}
	}


	// 将剩余元素拷贝到结果数组
	while (i < leftLen) {
		iterationCount++;
		arr[k++] = left[i++];
	}

	while (j < rightLen) {
		iterationCount++;
		arr[k++] = right[j++];
	}
}
void MySort::mergeSort(vector<int>& arr, bool greater) {
	const int len = arr.size();
	if (len <= 1)
		return;

	// 分割数组
	int mid = len / 2;
	vector<int> left(arr.begin(), arr.begin() + mid);
	memoryUsage += left.size();
	vector<int> right(arr.begin() + mid, arr.end());
	memoryUsage += right.size();



	// 递归排序
	callCount++;
	mergeSort(left, greater);

	callCount++;
	mergeSort(right, greater);

	// 合并排序后的子数组
	merge(arr, left, right, greater);

	callCount++;
	deepth++;
	stability = true;
}

// 归并排序(非递归版)
// 归并排序非递归实现
void MySort::mergeSortNonR(vector<int>& arr, bool greater, int speed)
{
	cout << "\033[2J";  // 清屏，仅初始化时调用
	cout << "\033[?25l";  // 隐藏光标

	const int len = arr.size();
	if (len == 0)
		return;

	// 创建辅助数组
	vector<int> tmp(arr);
	memoryUsage += len;

	//初始化每组的元素个数为1
	int gap = 1;
	while (gap < len)//gap为len时就只有一个序列了，所以gap<len
	{
		iterationCount++;
		// 归并每两组归并一次
		int index = 0; // 记录tmp数组中的元素下标
		for (int i = 0; i < len; i += 2 * gap)//两组中的元素个数为2*gap
		{
			iterationCount++;
			// 控制两组边界
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// 当原数组中元素个数不是2^len时，最后两组组会出现元素不匹配的情况
			// end1>=len或begin2>=len,即最后两组中只有一组有元素，则不需归并
			compareCount++;
			if (end1 >= len || begin2 >= len)
			{
				break;
			}
			// end2>=len，即最后两组中，第二组元素个数小于第一组，则需要调整第二组边界
			if (end2 >= len)
			{
				end2 = len - 1;
			}

			// 打印
			cout << "\033[H";  // 光标移动到屏幕顶部
			cout << "排序过程:" << endl;
			display(*this);
			this_thread::sleep_for(chrono::milliseconds(speed));

			// 归并过程
			while (begin1 <= end1 && begin2 <= end2)
			{
				iterationCount++;
				compareCount++;
				if (greater ? arr[begin1] < arr[begin2] : arr[begin1] > arr[begin2])
				{
					tmp[index++] = arr[begin1++];
					cout << "\033[H";  // 光标移动到屏幕顶部
					cout << "排序过程:" << endl;
					display(*this);
					this_thread::sleep_for(chrono::milliseconds(speed));
				}
				else
				{
					tmp[index++] = arr[begin2++];
					cout << "\033[H";  // 光标移动到屏幕顶部
					cout << "排序过程:" << endl;
					display(*this);
					this_thread::sleep_for(chrono::milliseconds(speed));
				}
				changeCount++;
			}

			while (begin1 <= end1)
			{
				iterationCount++;
				tmp[index++] = arr[begin1++];
				cout << "\033[H";  // 光标移动到屏幕顶部
				cout << "排序过程:" << endl;
				display(*this);
				this_thread::sleep_for(chrono::milliseconds(speed));
			}

			while (begin2 <= end2)
			{
				iterationCount++;
				tmp[index++] = arr[begin2++];
				cout << "\033[H";  // 光标移动到屏幕顶部
				cout << "排序过程:" << endl;
				display(*this);
				this_thread::sleep_for(chrono::milliseconds(speed));
			}
		}
		// 一趟排完后，将归并后的有序序列拷贝到原数组中
		for (int j = 0; j < index; j++)
		{
			iterationCount++;
			arr[j] = tmp[j];
			changeCount++;
			cout << "\033[H";  // 光标移动到屏幕顶部
			cout << "排序过程:" << endl;
			display(*this);
			this_thread::sleep_for(chrono::milliseconds(speed));
		}
		// 每次循环每组元素个数增大2倍
		gap *= 2;
	}

	cout << "\033[H";  // 光标移动到屏幕顶部
	cout << "排序过程:" << endl;
	display(*this);
	this_thread::sleep_for(chrono::milliseconds(speed));

	callCount++;
	deepth++;
	stability = true;
	cout << "\033[?25h";  // 恢复光标
}

// 快速排序
void MySort::quickSort(vector<int>& arr, int begin, int end, bool greater, bool visual, int speed) {
	if (visual) {
		cout << "\033[2J";  // 清屏，仅初始化时调用
	}
	int i, j, t, pivot;
	if (begin > end)  // 递归结束条件
		return;
	pivot = arr[begin]; // 基准数
	i = begin;
	j = end;
	while (i != j) {
		iterationCount++;
		if (greater) {
			// 从右向左找比基准小的数
			while (arr[j] >= pivot && i < j) {
				iterationCount++;
				compareCount++;
				j--;
			}
			// 从左向右找比基准大的数
			while (arr[i] <= pivot && i < j) {
				iterationCount++;
				compareCount++;
				i++;
			}
			if (i < j) {
				//交换两数的位置
				swap(arr[i], arr[j]);
				changeCount++;
				if (visual) {
					cout << "\033[H";  // 光标移动到屏幕顶部
					cout << "排序过程:" << endl;
					display(*this);
					this_thread::sleep_for(chrono::milliseconds(speed));
				}
			}
		}
		else {
			// 从右向左找比基准小的数
			while (arr[j] <= pivot && i < j) {
				iterationCount++;
				compareCount++;
				j--;
			}
			// 从左向右找比基准大的数
			while (arr[i] >= pivot && i < j) {
				iterationCount++;
				compareCount++;
				i++;
			}
			if (i < j) {
				//交换两数的位置
				swap(arr[i], arr[j]);
				changeCount++;
				if (visual) {
					cout << "\033[H";  // 光标移动到屏幕顶部
					cout << "排序过程:" << endl;
					display(*this);
					this_thread::sleep_for(chrono::milliseconds(speed));
				}
			}
			if (visual) {
				cout << "\033[H";  // 光标移动到屏幕顶部
				cout << "排序过程:" << endl;
				display(*this);
				this_thread::sleep_for(chrono::milliseconds(speed));
			}
		}
	}

	// 将基准数归位
	arr[begin] = arr[i];
	if (visual) {
		cout << "\033[H";  // 光标移动到屏幕顶部
		cout << "排序过程:" << endl;
		display(*this);
		this_thread::sleep_for(chrono::milliseconds(speed));
	}
	arr[i] = pivot;
	if (visual) {
		cout << "\033[H";  // 光标移动到屏幕顶部
		cout << "排序过程:" << endl;
		display(*this);
		this_thread::sleep_for(chrono::milliseconds(speed));
	}

	// 继续处理左边和右边
	callCount++;
	quickSort(arr, begin, i - 1, greater);
	if (visual) {
		cout << "\033[H";  // 光标移动到屏幕顶部
		cout << "排序过程:" << endl;
		display(*this);
		this_thread::sleep_for(chrono::milliseconds(speed));
	}
	callCount++;
	quickSort(arr, i + 1, end, greater);
	if (visual) {
		cout << "\033[H";  // 光标移动到屏幕顶部
		cout << "排序过程:" << endl;
		display(*this);
		this_thread::sleep_for(chrono::milliseconds(speed));
	}
	callCount++;
	deepth++;
	stability = false;
}

// 堆排序
void MySort::siftDown(vector<int>& arr, int low, int high, bool greater, bool visual, int speed) {
	int i = low;
	int j = 2 * i + 1;
	int temp = arr[i];
	while (j <= high) {
		iterationCount++;

		// 根据排序顺序选择比较逻辑
		if (greater) {
			compareCount++;
			if (j < high && arr[j] < arr[j + 1])
				j++;
			compareCount++;
			if (temp < arr[j]) {
				arr[i] = arr[j];
				i = j;
				j = 2 * i + 1;
			}
			else {
				break;
			}
		}

		else {
			compareCount++;
			if (j < high && arr[j] > arr[j + 1])
				j++;
			compareCount++;
			if (temp > arr[j]) {
				arr[i] = arr[j];
				i = j;
				j = 2 * i + 1;
			}
			else {
				break;
			}
		}

		if (visual) {
			cout << "\033[H";  // 光标移动到屏幕顶部
			cout << "排序过程:" << endl;
			display(*this);
			this_thread::sleep_for(chrono::milliseconds(speed));
		}
	}
	arr[i] = temp;

	if (visual) {
		cout << "\033[H";  // 光标移动到屏幕顶部
		cout << "排序过程:" << endl;
		display(*this);
		this_thread::sleep_for(chrono::milliseconds(speed));
	}

	changeCount++;
}
void MySort::HeapSort(vector<int>& arr, int n, bool greater, bool visual, int speed) {
	if (visual) {
		cout << "\033[2J";  // 清屏，仅初始化时调用
		cout << "\033[?25l";  // 隐藏光标
	}
	for (int i = n / 2 - 1; i >= 0; i--) {
		iterationCount++;
		siftDown(arr, i, n - 1, greater);
		if (visual) {
			cout << "\033[H";  // 光标移动到屏幕顶部
			cout << "排序过程:" << endl;
			display(*this);
			this_thread::sleep_for(chrono::milliseconds(speed));
		}
	}
	for (int i = n - 1; i > 0; i--) {
		iterationCount++;
		changeCount++;
		swap(arr[0], arr[i]);
		siftDown(arr, 0, i - 1, greater);
		if (visual) {
			cout << "\033[H";  // 光标移动到屏幕顶部
			cout << "排序过程:" << endl;
			display(*this);
			this_thread::sleep_for(chrono::milliseconds(speed));
		}
	}

	if (visual) {
		cout << "\033[H";  // 光标移动到屏幕顶部
		cout << "排序过程:" << endl;
		display(*this);
		this_thread::sleep_for(chrono::milliseconds(speed));
	}
	callCount++;
	deepth++;
	stability = false;
	if (visual)
		cout << "\033[?25h";  // 恢复光标
}

// 智能排序
void MySort::autoSort(bool greater, bool visual, int speed) {
	const int len = data.size();
	if (len == 0)
		return;
	int upCount = 0, downCount = 0; // 统计升序度和降序度
	for (int i = 1; i < len; i++) {
		if (data[i] < data[i - 1])
			downCount++;
		else
			upCount++;
	}
	if (upCount > data.size() / 4) {  // 接近升序
		// 插入排序
		this->insertSort(greater, visual, speed);
	}
	else if (downCount > data.size() / 4 ){ // 接近降序
		// 小规模时，归并排序
		if (data.size() < 1000)
			if (visual)
				this->mergeSortNonR(data, greater, speed);
			else
				this->mergeSort(data, greater);
		// 大规模时，堆排序
		else
			this->HeapSort(data, data.size(), greater, visual, speed);
	}
	else { // 基本无序
		if (data.size() < 1000) { // 数据量较小的时候，插入排序
			this->insertSort(greater, visual, speed);
		}
		else {  // 数据量较大的时候，快速排序
			if (visual) {
				cout << "\033[?25l";  // 隐藏光标
			}
			this->quickSort(data, 0, data.size() - 1, greater, visual, speed);
			if (visual) {
				cout << "\033[?25h";  // 恢复光标
			}
		}
	}
}

// 双缓冲机制可视化函数
void display(MySort& mysort) {
	const int max_scale = 100;  // 符号最多显示的数量

	// 找出数据的最大绝对值
	int max_val = 0;
	for (int num : mysort.data) {
		if (abs(num) > max_val) {
			max_val = abs(num);
		}
	}

	// 如果最大值为 0，直接返回
	if (max_val == 0) {
		cout << "\033[2;1H";  // 将光标移动到屏幕第二行
		cout << "***********所有数据都是0，无需打印***********" << endl;
		return;
	}

	// 按行打印，不清除整个屏幕
	int row = 2;  // 从第二行开始打印
	for (int num : mysort.data) {
		cout << "\033[" << row << ";1H";  // 将光标移动到指定行
		cout << "\033[K";  // 清除当前行内容

		int normalized_length = (abs(num) * max_scale) / max_val;
		if (num != 0 && normalized_length == 0) {
			normalized_length = 1;  // 确保最小长度为 1
		}

		if (num > 0) {
			cout << left << GREEN << setw(5) << num << "  ";
			for (int i = 0; i < normalized_length; i++) {
				cout << "■";
			}
		}
		else if (num < 0) {
			cout << left << RED << setw(5) << num << "  ";
			for (int i = 0; i < normalized_length; i++) {
				cout << "■";
			}
		}
		else {
			cout << left << RESET << setw(5) << num << "  ";
		}
		cout << RESET;
		row++;  // 移动到下一行
	}

	cout << endl;
	cout.flush();  // 强制刷新缓冲区，确保内容实时显示
}


// 算法比较
void compareAlgorithm(MySort* arr, int len, int option) {
	if (option == 1) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - i - 1; j++) {
				if (arr[j].runTime > arr[j + 1].runTime)
					swap(arr[j], arr[j + 1]);
			}
		}
		cout << "各算法比较时间如下:" << endl;
		for (int i = 0; i < len; i++) {
			if (i == 0)
				cout << arr[i].runTime;
			else
				cout << "   " << arr[i].runTime;
		}
		cout << endl;
	}
	else if (option == 2) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - i - 1; j++) {
				if (arr[j].iterationCount > arr[j + 1].iterationCount)
					swap(arr[j], arr[j + 1]);
			}
		}
		cout << "各算法循环次数如下:" << endl;
		for (int i = 0; i < len; i++) {
			if (i == 0)
				cout << arr[i].iterationCount;
			else
				cout << "   " << arr[i].iterationCount;
		}
		cout << endl;
	}
	else if (option == 3) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - i - 1; j++) {
				if (arr[j].changeCount > arr[j + 1].changeCount)
					swap(arr[j], arr[j + 1]);
			}
		}
		cout << "各算法交换次数如下:" << endl;
		for (int i = 0; i < len; i++) {
			if (i == 0)
				cout << arr[i].changeCount;
			else
				cout << "   " << arr[i].changeCount;
		}
		cout << endl;
	}
	else if (option == 4) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - i - 1; j++) {
				if (arr[j].compareCount > arr[j + 1].compareCount)
					swap(arr[j], arr[j + 1]);
			}
		}
		cout << "各算法比较次数如下:" << endl;
		for (int i = 0; i < len; i++) {
			if (i == 0)
				cout << arr[i].compareCount;
			else
				cout << "   " << arr[i].compareCount;
		}
		cout << endl;
	}
	else if (option == 5) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - i - 1; j++) {
				if (arr[j].callCount > arr[j + 1].callCount)
					swap(arr[j], arr[j + 1]);
			}
		}
		cout << "各算法函数调用次数如下:" << endl;
		for (int i = 0; i < len; i++) {
			if (i == 0)
				cout << arr[i].callCount;
			else
				cout << "   " << arr[i].callCount;
		}
		cout << endl;
	}
	else if (option == 6) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - i - 1; j++) {
				if (arr[j].memoryUsage > arr[j + 1].memoryUsage)
					swap(arr[j], arr[j + 1]);
			}
		}
		cout << "各算法内存占用如下:" << endl;
		for (int i = 0; i < len; i++) {
			if (i == 0)
				cout << arr[i].memoryUsage;
			else
				cout << "   " << arr[i].memoryUsage;
		}
		cout << endl;
	}
	else if (option == 7) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - i - 1; j++) {
				if (arr[j].deepth > arr[j + 1].deepth)
					swap(arr[j], arr[j + 1]);
			}
		}
		cout << "各算法递归深度如下:" << endl;
		for (int i = 0; i < len; i++) {
			if (i == 0)
				cout << arr[i].deepth;
			else
				cout << "   " << arr[i].deepth;
		}
		cout << endl;
	}
	cout << endl;

	cout << "算法优劣性比较如下：" << endl;
	for (int i = 0; i < len; i++) {
		if (i == 0)
			cout << arr[i].sname;
		else
			cout << " > " << arr[i].sname;
	}
	cout << endl;
}