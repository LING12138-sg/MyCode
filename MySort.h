#pragma once
#include<iostream>
#include<algorithm>
#include <sstream>
#include<vector>
#include <chrono>
using namespace std;

class MySort {
private:
	// ��������
	vector<int> data;
	// ����ʱ��
	double runTime;
	// �����������Ƚϴ������������ô�����ѭ������
	int changeCount, compareCount, callCount, iterationCount;
	// �ڴ�ʹ����
	double memoryUsage;
	// �ȶ���
	bool stability;
	// Ƕ�����
	int deepth;
	// �㷨����
	string sname;
public:
	// ���캯��
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

	// ����������Ϣ
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
	// Ϊ����ʱ�丳ֵ
	void setRunTime(double time) {
		runTime = time;
	}
	// Ϊ�ڴ����ĸ�ֵ
	void setMemoryUsage(double memory) {
		memoryUsage = memory;
	}
	// ��������
	void setData(vector<int>& num) {
		for (int i = 0; i < num.size(); i++)
			data.push_back(num[i]);
	}
	// �����㷨����
	void setName(string name) {
		sname = name;
	}

	// ð������
	void bubblingSort(bool greater = false, bool visual = false, int speed = 1000);
	
	// ѡ������
	void choiceSort(bool greater = false, bool visual = false, int speed = 1000);
	
	// ��������
	void insertSort(bool greater = false, bool visual = false, int speed = 1000);

	// ϣ������
	void shellSort(bool greater = false, bool visual = false, int speed = 1000);
	
	// �鲢����(�ݹ��)
	void merge(vector<int>&, const vector<int>&, const vector<int>&, bool greater);
	void mergeSort(vector<int>&, bool greater = false);
	// �鲢����(�ǵݹ��)
	void mergeSortNonR(vector<int>&, bool greater = false, int speed = 1000);

	// ��������
	void quickSort(vector<int>&, int, int, bool greater = false, bool visual = false, int speed = 1000);

	// ������
	void siftDown(vector<int>&, int, int, bool greater, bool visual = false, int speed = 1000);
	void HeapSort(vector<int>&, int, bool greater = false, bool visual = false, int speed = 1000);

	// ��������
	void autoSort(bool greater = false, bool visual = false, int speed = 1000);

	// ���ӻ���ʾ
	friend void display(MySort&);

	// �Ƚ�ָ���Ƚ�
	friend void compareAlgorithm(MySort* arr, int, int);
};