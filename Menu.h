#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include"MySort.h"
#include"File.h"
using namespace std;
class Menu {
public:
	// 开始菜单
	static void startMenu();

	// 二级选项菜单
	static void secondChoiceMenu(string choice);

	// 排序方式菜单
	static void sortMenu();

	// 排序方式菜单
	static void sortMethodMenu();

	// 排序速度菜单
	static void speedMenu();

	// 输出排序后的元素及相应信息
	static void outputMenu(MySort& mysort);

	// 算法简介说明
	static void sortAlgorithmMenu();

	// 文本导入说明
	static void fileExplain();

	// 算法比较菜单
	static void compareMenu();

	// 系统简介
	static void sysInfo();
};