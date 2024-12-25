#pragma once
#include<iostream>
#include<algorithm>
#include <sstream>
#include<vector>
#include <chrono>
using namespace std;

class MySort {
private:
	// 排序数据
	vector<int> data;
	// 运行时间
	double runTime;
	// 交换次数、比较次数、函数调用次数、循环次数
	int changeCount, compareCount, callCount, iterationCount;
	// 内存使用量
	double memoryUsage;
	// 稳定性
	bool stability;
	// 嵌套深度
	int deepth;
	// 算法名称
	string sname;
public:
	// 构造函数
	MySort() {
		runTime = 0;
		changeCount = compareCount = callCount = iterationCount = 0;
		memoryUsage = 0;
		stability = true;
		deepth = 0;
		sname = "";
	}
	MySort(vector<int>& data) {
		for (int i = 0; i < data.size(); i++) {
			this->data.push_back(data[i]);
		}
		memoryUsage = data.capacity();
		runTime = 0;
		changeCount = compareCount = callCount = iterationCount = 0;
		memoryUsage = 0;
		stability = true;
		deepth = 0;
		sname = "";
	}

	// 返回属性信息
	vector<int>& getData() {
		return data;
	}
	double getRunTime() {
		return runTime;
	}
	int getChangeCount() {
		return changeCount;
	}
	int getCompareCount() {
		return compareCount;
	}
	int getCallCount() {
		return callCount;
	}
	int getIterationCount() {
		return iterationCount;
	}
	double getMemoryUsage() {
		return memoryUsage;
	}
	bool getStability() {
		return stability;
	}
	int getDeepth() {
		return deepth;
	}
	// 为运行时间赋值
	void setRunTime(double time) {
		runTime = time;
	}
	// 为内存消耗赋值
	void setMemoryUsage(double memory) {
		memoryUsage = memory;
	}
	// 设置数据
	void setData(vector<int>& num) {
		for (int i = 0; i < num.size(); i++)
			data.push_back(num[i]);
	}
	// 设置算法名字
	void setName(string name) {
		sname = name;
	}

	// 冒泡排序
	void bubblingSort(bool greater = false, bool visual = false, int speed = 1000);
	
	// 选择排序
	void choiceSort(bool greater = false, bool visual = false, int speed = 1000);
	
	// 插入排序
	void insertSort(bool greater = false, bool visual = false, int speed = 1000);

	// 希尔排序
	void shellSort(bool greater = false, bool visual = false, int speed = 1000);
	
	// 归并排序(递归版)
	void merge(vector<int>&, const vector<int>&, const vector<int>&, bool greater);
	void mergeSort(vector<int>&, bool greater = false);
	// 归并排序(非递归版)
	void mergeSortNonR(vector<int>&, bool greater = false, int speed = 1000);

	// 快速排序
	void quickSort(vector<int>&, int, int, bool greater = false, bool visual = false, int speed = 1000);

	// 堆排序
	void siftDown(vector<int>&, int, int, bool greater, bool visual = false, int speed = 1000);
	void HeapSort(vector<int>&, int, bool greater = false, bool visual = false, int speed = 1000);

	// 智能排序
	void autoSort(bool greater = false, bool visual = false, int speed = 1000);

	// 可视化显示
	friend void display(MySort&);

	// 比较指数比较
	friend void compareAlgorithm(MySort* arr, int, int);
};