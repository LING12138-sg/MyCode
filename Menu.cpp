#include"Menu.h"

// 定义 ANSI 颜色
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"  // 重置颜色

// 主菜单
void Menu::startMenu() {
	// 清屏操作
	cout << "\033[2J\033[1;1H";
	// 文件读取艺术字
	string filename;
	srand(time(0));  // 设置随机种子
	int randomValue = rand() % 16;  // 生成 0 到 15 之间的随机数
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./艺术字/" + filename);

	cout << "-----------------------------------------" << endl;
	cout << "|         欢迎来到ling的排序系统        |" << endl;
	cout << "|          请选择需要实现的功能         |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|           1. 自定义数据排序           |" << endl;
	cout << "|           2. 随机数据排序             |" << endl;
	cout << "|           3. 可视化自定义数据排序     |" << endl;
	cout << "|           4. 可视化随机数据排序       |" << endl;
	cout << "|           5. 各排序算法比较           |" << endl;
	cout << "|           6. 系统简介                 |" << endl;
	cout << "|           7. 算法简介                 |" << endl;
	cout << "|           0. 退出                     |" << endl;
	cout << "-----------------------------------------" << endl;
}


// 二级菜单
void Menu::secondChoiceMenu(string choice) {
	// 清屏操作
	cout << "\033[2J\033[1;1H";
	// 文件读取艺术字
	string filename;
	srand(time(0));  // 设置随机种子
	int randomValue = rand() % 16;  // 生成 0 到 15 之间的随机数
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./艺术字/" + filename);

	cout << "-----------------------------------------" << endl;
	cout << "|           请选择导入数据方式          |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|             1. 手动输入               |" << endl;
	cout << "|             2. 文本导入               |" << endl;
	cout << "|             3. 文本导入说明*          |" << endl;
	cout << "|             0. 返回上一级             |" << endl;
	cout << "-----------------------------------------" << endl;
}

// 排序菜单
void Menu::sortMenu() {
	// 清屏操作
	cout << "\033[2J\033[1;1H";
	// 文件读取艺术字
	string filename;
	srand(time(0));  // 设置随机种子
	int randomValue = rand() % 16;  // 生成 0 到 15 之间的随机数
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./艺术字/" + filename);

	cout << "-----------------------------------------" << endl;
	cout << "|           请选择排序方式              |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|             1. 冒泡排序(default)      |" << endl;
	cout << "|             2. 插入排序               |" << endl;
	cout << "|             3. 选择排序               |" << endl;
	cout << "|             4. 希尔排序               |" << endl;
	cout << "|             5. 归并排序               |" << endl;
	cout << "|             6. 快速排序               |" << endl;
	cout << "|             7. 堆排序                 |" << endl;
	cout << "|             8. 智能排序               |" << endl;
	cout << "|             0. 返回上一级             |" << endl;
	cout << "-----------------------------------------" << endl;
}

// 排序方法选择菜单
void Menu::sortMethodMenu() {
	cout << "-----------------------------------------" << endl;
	cout << "|           请选择升序还是降序          |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|             1. 升序(default)          |" << endl;
	cout << "|             0. 降序                   |" << endl;
	cout << "-----------------------------------------" << endl;
}

// 速度选择菜单
void Menu::speedMenu() {
	cout << "-----------------------------------------" << endl;
	cout << "|             请选择播放速度            |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|               1. 慢速                 |" << endl;
	cout << "|               2. 正常(defaul)         |" << endl;
	cout << "|               3. 快速                 |" << endl;
	cout << "-----------------------------------------" << endl;
}

// 排序信息输出菜单
void Menu::outputMenu(MySort& mysort) {
	int len = mysort.getData().size();
	// 输出排序后的元素
	cout << "排序后的元素为:";
	for (int i = 0; i < len; i++) {
		if (i % 20 == 0)
			cout << endl;
		cout << mysort.getData()[i] << " ";
	}
	cout << endl;
	cout << "运行时间:" << mysort.getRunTime() << "s" << endl;
	cout << "循环次数:" << mysort.getIterationCount() << "次" << endl;
	cout << "交换次数:" << mysort.getChangeCount() << "次" << endl;
	cout << "比较次数:" << mysort.getCompareCount() << "次" << endl;
	cout << "函数调用次数:" << mysort.getCallCount() << "次" << endl;
	cout << "内存使用量:" << mysort.getMemoryUsage() << "MB" << endl;
	cout << "算法稳定性:";
	if (mysort.getStability())
		cout << "稳定" << endl;
	else
		cout << "不稳定" << endl;
	cout << "嵌套深度:" << mysort.getDeepth() << "层" << endl;
	cout << endl;
}

// 算法简介界面
void Menu::sortAlgorithmMenu() {
	// 清屏操作
	cout << "\033[2J\033[1;1H";
	// 文件读取艺术字
	string filename;
	srand(time(0));  // 设置随机种子
	int randomValue = rand() % 16;  // 生成 0 到 15 之间的随机数
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./艺术字/" + filename);
	cout << endl;
	
	cout << "=====================================算法排序简介====================================" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	// 打印表格头部
	cout << left << setw(22) << "算法"
		<< setw(15) << "时间复杂度"
		<< setw(15) << "稳定性"
		<< setw(25) << "适用场景" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;

	// 打印表格内容
	cout << left << setw(22) << "冒泡排序(BubbleSort)"
		<< setw(15) << "O(n^2)"
		<< setw(15) << "稳定"
		<< setw(25) << "小规模数据集" << endl;

	cout << left << setw(22) << "插入排序(InsertSort)"
		<< setw(15) << "O(n^2)"
		<< setw(15) << "稳定"
		<< setw(25) << "数据基本有序" << endl;

	cout << left << setw(22) << "选择排序(SelectSort)"
		<< setw(15) << "O(n^2)"
		<< setw(15) << "不稳定"
		<< setw(25) << "大规模数据集" << endl;

	cout << left << setw(22) << "快速排序(QuickSort)"
		<< setw(15) << "O(nlogn)"
		<< setw(15) << "不稳定"
		<< setw(25) << "大规模数据集" << endl;

	cout << left << setw(22) << "归并排序(MergeSort)"
		<< setw(15) << "O(nlogn)"
		<< setw(15) << "稳定"
		<< setw(25) << "稳定排序需求" << endl;

	cout << left << setw(22) << "堆排序(HeapSort)"
		<< setw(15) << "O(nlogn)"
		<< setw(15) << "不稳定"
		<< setw(25) << "大规模数据集，无额外空间需求" << endl;

	cout << left << setw(22) << "希尔排序(ShellSort)"
		<< setw(15) << "O(n^(3/2))"
		<< setw(15) << "不稳定"
		<< setw(25) << "中等规模数据集" << endl;

	cout << left << setw(22) << "智能排序(SmartSort)"
		<< setw(15) << "O(?)"
		<< setw(15) << "稳定"
		<< setw(25) << "根据数据特征选择合适的排序方式" << endl;

	cout << "-------------------------------------------------------------------------------------" << endl;
}

// 文本导入说明
void Menu::fileExplain() {
	// 清屏操作
	cout << "\033[2J\033[1;1H";
	// 文件读取艺术字
	string filename;
	srand(time(0));  // 设置随机种子
	int randomValue = rand() % 16;  // 生成 0 到 15 之间的随机数
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./艺术字/" + filename);

	cout << "-----------------------------------------" << endl;
	cout << "|              文本导入说明             |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|1. 文本导入形式为"; cout << RED << "文件路径"; cout << RESET << "，相对路径或者| " << endl;
	cout << "|绝对路径。                             |" << endl;
	cout << "|2. 文本内容为"; cout << RED << "整数"; cout << RESET << "，并用"; cout << RED << "分隔符"; cout << RESET << "分开，目前| " << endl;
	cout << "|仅支持"; cout << RED << "英文分隔符"; cout << RESET << "。                     | " << endl;
	cout << "|3. 排序后的元素保存路径为当前文件夹，文|" << endl;
	cout << "|件名为当前文件名"; cout << RED << "_temp.txt"; cout << RESET << "，请确保当前文| " << endl;
	cout << "|件夹下无此文件。                       |" << endl;
	cout << "|4. 若要实现文本导入排序可视化操作，请尽|" << endl;
	cout << "|量确保"; cout << RED << "排序元素不要超过20个";cout << RESET << "，否则可视化 | " << endl;
	cout << "|过程可能不会太清晰。                   |" << endl;
	cout << "-----------------------------------------" << endl;
}

// 算法比较菜单
void Menu::compareMenu() {
	// 清屏操作
	cout << "\033[2J\033[1;1H";
	// 文件读取艺术字
	string filename;
	srand(time(0));  // 设置随机种子
	int randomValue = rand() % 16;  // 生成 0 到 15 之间的随机数
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./艺术字/" + filename);

	cout << "-----------------------------------------" << endl;
	cout << "|            请选择比较指数             |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|             1.运行时间                |" << endl;
	cout << "|             2.循环次数                |" << endl;
	cout << "|             3.交换次数                |" << endl;
	cout << "|             4.比较次数                |" << endl;
	cout << "|             5.函数调用次数            |" << endl;
	cout << "|             6.内存使用量              |" << endl;
	cout << "|             7.嵌套深度                |" << endl;
	cout << "|             0.返回上一级              |" << endl;
	cout << "-----------------------------------------" << endl;
}

// 系统简介
void Menu::sysInfo() {
	// 清屏操作
	cout << "\033[2J\033[1;1H";
	// 文件读取艺术字
	string filename;
	srand(time(0));  // 设置随机种子
	int randomValue = rand() % 16;  // 生成 0 到 15 之间的随机数
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./艺术字/" + filename);

	cout << "**************************************************" << endl;
	cout << "|                关于 Ling Stor                  |" << endl;
	cout << "**************************************************" << endl;
	cout << "|1. 本系统是由ling开发的算法排序系统，提供了各种 |" << endl;
	cout << "|常见的排序算法，包括冒泡排序、选择排序、希尔排序|" << endl;
	cout << "|、快速排序、堆排序等。                          |" << endl;
	cout << "|2. 提供自定义数据、文本导入数据以及随机生成数据 |" << endl;
	cout << "|等多种加载数据的方式。                          |" << endl;
	cout << "|3. 提供了可视化模块，能够清晰地看到每一步排序过 |" << endl;
	cout << "|程，帮助您更好理解该算法的原理。                |" << endl;
	cout << "|4. 也能够对各种算法进行比较，并提供智能排序，能 |" << endl;
	cout << "|够根据数据的特征选择相应的算法进行高效排序。    |" << endl;
	cout << "**************************************************" << endl;
}