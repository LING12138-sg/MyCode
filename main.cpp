#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<iomanip>
#include<chrono>
#include<thread>
#include"Menu.h"
#include"MySort.h"
#include"File.h"
using namespace std;

int main(void) {
	// 主菜单
	while (true) {
		Menu::startMenu();
		string choice;
		cout << "请输入数字>>> ";
		cin >> choice;
		if (choice == "0") {
			// 退出程序
			exit(0);
		}
		// 直接排序，输出信息，无需可视化
		else if (choice == "1") {
			while (true) {
				MySort mysort;
				Menu::secondChoiceMenu(choice);
				string option;
				cout << "请输入数字>>> ";
				cin >> option;
				if (option == "0")
					break;
				// 实现自己输入数据
				else if (option == "1") {
					// 初步仅实现整数排序
					int size;
					cout << "请输入排序元素个数>>> ";
					cin >> size;

					// 检查输入流是否失败
					if (cin.fail()) {
						// 输入无效，清除错误标志，并丢弃输入的内容
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
						cerr << "*****输入无效!请输入一个整数!*****" << endl;
						continue;
					}
					else {
						cout << "请输入参与排序的元素>>> ";
						double memoryUsage = 0;
						for (int i = 0; i < size; i++) {
							int n;
							cin >> n;
							// 检查输入流是否失败
							if (cin.fail()) {
								// 输入无效，清除错误标志，并丢弃输入的内容
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
								cerr << "*****输入无效!请输入一个整数!*****" << endl;
								cout << "输入任意字符继续....";
								// 等待回车
								char ch;
								cin.get(ch);
								cin.ignore();
								continue;
							}
							mysort.getData().push_back(n);
							memoryUsage++;
						}
						mysort.setMemoryUsage(memoryUsage);
						Menu::sortMenu();
						int chose;
						cout << "请输入数字>>> ";
						cin >> chose;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
							cerr << "*****输入无效!请输入一个整数!*****" << endl;
							cout << "输入任意字符继续....";
							// 等待回车
							char ch;
							cin.get(ch);
							cin.ignore();
							continue;
						}
						else if (chose == 0)
							break;
						else {
							Menu::sortMethodMenu();
							int greater = 0;
							cout << "请输入数字>>> ";
							cin >> greater;
							if (cin.fail()) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
								cerr << "*****输入无效!请输入一个整数!*****" << endl;
								cout << "输入任意字符继续....";
								// 等待回车
								char ch;
								cin.get(ch);
								cin.ignore();
								continue;
							}
							// 记录开始时间
							auto start = chrono::high_resolution_clock::now();
							switch (chose) {
							case 1:
								mysort.bubblingSort(greater);
								break;
							case 2:
								mysort.insertSort(greater);
								break;
							case 3:
								mysort.choiceSort(greater);
								break;
							case 4:
								mysort.shellSort(greater);
								break;
							case 5:
								mysort.mergeSort(mysort.getData(), greater);
								break;
							case 6:
								mysort.quickSort(mysort.getData(), 0, mysort.getData().size() - 1, greater);
								break;
							case 7:
								mysort.HeapSort(mysort.getData(), mysort.getData().size(), greater);
								break;
							case 8:
								// 智能选择算法排序
								mysort.autoSort(greater);
								break;
							default:
								mysort.bubblingSort(greater);
							}
							// 记录结束时间
							auto end = chrono::high_resolution_clock::now();
							// 算出消耗时间
							chrono::duration<double> duration = end - start;
							mysort.setRunTime(duration.count());
							// 输出排序后的元素
							Menu::outputMenu(mysort);
							cout << "输入任意字符继续....";
							// 等待回车
							char ch;
							cin.get(ch);
							cin.ignore();
						}
						break;
					}
				}

				// 实现文本导入数据
				else if (option == "2") {
					string filename;
					cout << "请输入文件位置>>> ";
					cin >> filename;
					File file;
					// 导入文件
					file.loadFile(filename, mysort.getData());
					if (mysort.getData().empty())
						break;
					int memoryUsage = mysort.getData().capacity();
					mysort.setMemoryUsage(memoryUsage);

					Menu::sortMenu();
					int chose;
					cout << "请输入数字>>> ";
					cin >> chose;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
						cerr << "*****输入无效!请输入一个整数!*****" << endl;
						cout << "输入任意字符继续....";
						// 等待回车
						char ch;
						cin.get(ch);
						cin.ignore();
						continue;
					}
					else if (chose == 0)
						break;
					else {
						Menu::sortMethodMenu();
						int greater = 0;
						cout << "请输入数字>>> ";
						cin >> greater;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
							cerr << "*****输入无效!请输入一个整数!*****" << endl;
							cout << "输入任意字符继续....";
							// 等待回车
							char ch;
							cin.get(ch);
							cin.ignore();
							continue;
						}
						// 记录开始时间
						auto start = chrono::high_resolution_clock::now();
						switch (chose) {
						case 1:
							mysort.bubblingSort(greater);
							break;
						case 2:
							mysort.insertSort(greater);
							break;
						case 3:
							mysort.choiceSort(greater);
							break;
						case 4:
							mysort.shellSort(greater);
							break;
						case 5:
							mysort.mergeSort(mysort.getData(), greater);
							break;
						case 6:
							mysort.quickSort(mysort.getData(), 0, mysort.getData().size() - 1, greater);
							break;
						case 7:
							mysort.HeapSort(mysort.getData(), mysort.getData().size(), greater);
							break;
						case 8:
							// 智能选择算法排序
							mysort.autoSort(greater);
							break;
						default:
							mysort.bubblingSort(greater);
						}
						// 记录结束时间
						auto end = chrono::high_resolution_clock::now();
						// 算出消耗时间
						chrono::duration<double> duration = end - start;
						mysort.setRunTime(duration.count());
						// 输出排序后的元素
						Menu::outputMenu(mysort);
						size_t dotPos = filename.find('.');  // 找到 '.' 的位置
						if (dotPos != string::npos) {
							filename = filename.substr(0, dotPos) + "_temp" + filename.substr(dotPos);
						}
						else {
							// 如果没有 '.'，直接追加 "_temp"
							filename += "_temp.txt";
						}
						cout << "已将排序好的元素保存到文件 " << filename << " 中" << endl;

						file.saveFile(filename, mysort.getData());
						cout << "输入任意字符继续....";
						// 等待回车
						char ch;
						cin.get(ch);
						cin.ignore();
					}
					break;
				}
				
				// 文本导入说明
				else if (option == "3"){
					Menu::fileExplain();
					cout << "输入任意字符继续....";
					// 等待回车
					char chr;
					cin.get(chr);
					cin.ignore();
				}
				else {
					cerr << "*****您选择的功能不存在!请重新输入!*****" << endl;
					cout << "输入任意字符继续....";
					// 等待回车
					char ch;
					cin.get(ch);
					cin.ignore();
				}
			}
		}
		else if (choice == "2") {
			while (true) {
				MySort mysort;
				// 实现随机生成数据
				// 创建随机数生成器
				random_device rd;
				// 使用梅森旋转算法
				mt19937 gen(rd());
				// 创建范围为-99999-999999的随机数
				uniform_int_distribution<> dis(-99999, 99999);

				// 用于储存随机数,数据量为12000
				double memoryUsage = 0;
				for (int i = 0; i < 12000; i++) {
					mysort.getData().push_back(dis(gen));
					memoryUsage++;
				}
				mysort.setMemoryUsage(memoryUsage);

				// 打印前十五个元素
				cout << "已随机生成12000个数据，前15个数字为:";
				for (int i = 0; i < 15; i++)
					cout << mysort.getData()[i] << " ";
				cout << endl;
				cout << "输入任意字符继续....";
				// 等待回车
				char ch;
				cin.get(ch);
				cin.ignore();

				Menu::sortMenu();
				int chose;
				cout << "请输入数字>>> ";
				cin >> chose;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
					cerr << "*****输入无效!请输入一个整数!*****" << endl;
					cout << "输入任意字符继续....";
					// 等待回车
					char ch;
					cin.get(ch);
					cin.ignore();
					break;
				}
				else if (chose == 0)
					break;
				else {
					Menu::sortMethodMenu();
					int greater = 0;
					cout << "请输入数字>>> ";
					cin >> greater;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
						cerr << "*****输入无效!请输入一个整数!*****" << endl;
						cout << "输入任意字符继续....";
						// 等待回车
						char ch;
						cin.get(ch);
						cin.ignore();
						break;
					}
					// 记录开始时间
					auto start = chrono::high_resolution_clock::now();
					switch (chose) {
					case 1:
						mysort.bubblingSort(greater);
						break;
					case 2:
						mysort.insertSort(greater);
						break;
					case 3:
						mysort.choiceSort(greater);
						break;
					case 4:
						mysort.shellSort(greater);
						break;
					case 5:
						mysort.mergeSort(mysort.getData(), greater);
						break;
					case 6:
						mysort.quickSort(mysort.getData(), 0, mysort.getData().size() - 1, greater);
						break;
					case 7:
						mysort.HeapSort(mysort.getData(), mysort.getData().size(), greater);
						break;
					case 8:
						// 智能选择算法排序
						mysort.autoSort(greater);
						break;
					default:
						mysort.bubblingSort(greater);
					}
					// 记录结束时间
					auto end = chrono::high_resolution_clock::now();
					// 算出消耗时间
					chrono::duration<double> duration = end - start;
					mysort.setRunTime(duration.count());
					Menu::outputMenu(mysort);
					cout << "输入任意字符继续....";
					// 等待回车
					char chr;
					cin.get(chr);
					cin.ignore();
				}
				break;
			}
		}
		// 可视化图形排序，包括调整速度的功能
		else if (choice == "3") {
			while (true) {
				MySort mysort;
				Menu::secondChoiceMenu(choice);
				string option;
				cout << "请输入数字>>> ";
				cin >> option;
				if (option == "0")
					break;
				// 实现自己输入数据
				else if (option == "1") {
					// 初步仅实现整数排序
					int size;
					cout << "请输入排序元素个数>>> ";
					cin >> size;

					// 检查输入流是否失败
					if (cin.fail()) {
						// 输入无效，清除错误标志，并丢弃输入的内容
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
						cerr << "*****输入无效!请输入一个整数!*****" << endl;
						cout << "输入任意字符继续....";
						// 等待回车
						char ch;
						cin.get(ch);
						cin.ignore();
						continue;
					}
					else {
						cout << "请输入参与排序的元素>>> ";
						double memoryUsage = 0;
						for (int i = 0; i < size; i++) {
							int n;
							cin >> n;
							// 检查输入流是否失败
							if (cin.fail()) {
								// 输入无效，清除错误标志，并丢弃输入的内容
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
								cerr << "*****输入无效!请输入一个整数!*****" << endl;
								cout << "输入任意字符继续....";
								// 等待回车
								char ch;
								cin.get(ch);
								cin.ignore();
								continue;
							}
							mysort.getData().push_back(n);
							memoryUsage++;
						}
						mysort.setMemoryUsage(memoryUsage);
						Menu::sortMenu();
						int chose;
						cout << "请输入数字>>> ";
						cin >> chose;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
							cerr << "*****输入无效!请输入一个整数!*****" << endl;
							continue;
						}
						else if (chose == 0)
							break;
						else {
							Menu::sortMethodMenu();
							int greater = 0;
							cout << "请输入数字>>> ";
							cin >> greater;
							if (cin.fail()) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
								cerr << "*****输入无效!请输入一个整数!*****" << endl;
								cout << "输入任意字符继续....";
								// 等待回车
								char ch;
								cin.get(ch);
								cin.ignore();
								continue;
							}
							Menu::speedMenu();
							// 播放速度
							int speed = 2;
							cout << "请输入数字>>> ";
							cin >> speed;
							if (cin.fail()) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
								cerr << "*****输入无效!请输入一个整数!*****" << endl;
								cout << "输入任意字符继续....";
								// 等待回车
								char ch;
								cin.get(ch);
								cin.ignore();
								continue;
							}
							// 选择播放速度
							switch (speed) {
							case 1:
								speed = 2000;
								break;
							case 2:
								speed = 1500;
								break;
							case 3:
								speed = 500;
								break;
							default:
								speed = 1500;
								break;
							}
							stringstream buffer;
							// 记录开始时间
							auto start = chrono::high_resolution_clock::now();
							// 先显示
							system("cls");
							cout << "原始数据:" << endl;
							display(mysort);
							// 先暂停一秒
							this_thread::sleep_for(chrono::seconds(1));
							cout << "排序过程:" << endl;
							switch (chose) {
							case 1:
								mysort.bubblingSort(greater, true, speed);
								break;
							case 2:
								mysort.insertSort(greater, true, speed);
								break;
							case 3:
								mysort.choiceSort(greater, true, speed);
								break;
							case 4:
								mysort.shellSort(greater, true, speed);
								break;
							case 5:
								cout << "\033[?25l";  // 隐藏光标
								mysort.mergeSortNonR(mysort.getData(), greater, speed);
								cout << "\033[?25h";  // 恢复光标
								break;
							case 6:
								mysort.quickSort(mysort.getData(), 0, mysort.getData().size() - 1, greater, true, speed);
								break;
							case 7:
								mysort.HeapSort(mysort.getData(), mysort.getData().size(), greater, true, speed);
								break;
							case 8:
								// 智能选择算法排序
								mysort.autoSort(greater, true, speed);
								break;
							default:
								mysort.bubblingSort(greater, true, speed);
							}
							// 记录结束时间
							auto end = chrono::high_resolution_clock::now();
							// 算出消耗时间
							chrono::duration<double> duration = end - start;
							mysort.setRunTime(duration.count());
							// 输出排序后的元素
							Menu::outputMenu(mysort);
							cout << "输入任意字符继续....";
							// 等待回车
							char chr;
							cin.get(chr);
							cin.ignore();
						}
						break;
					}
				}

				// 实现文本导入
				else if (option == "2") {
					string filename;
					cout << "请输入文件位置>>> ";
					cin >> filename;
					File file;
					// 导入文件
					file.loadFile(filename, mysort.getData());
					if (mysort.getData().empty())
						break;
					int memoryUsage = mysort.getData().capacity();
					mysort.setMemoryUsage(memoryUsage);

					Menu::sortMenu();
					int chose;
					cout << "请输入数字>>> ";
					cin >> chose;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
						cerr << "*****输入无效!请输入一个整数!*****" << endl;
						cout << "输入任意字符继续....";
						// 等待回车
						char ch;
						cin.get(ch);
						cin.ignore();
						continue;
					}
					else if (chose == 0)
						break;
					else {
						Menu::sortMethodMenu();
						int greater = 0;
						cout << "请输入数字>>> ";
						cin >> greater;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
							cerr << "*****输入无效!请输入一个整数!*****" << endl;
							cout << "输入任意字符继续....";
							// 等待回车
							char ch;
							cin.get(ch);
							cin.ignore();
							continue;
						}
						Menu::speedMenu();
						// 播放速度
						int speed = 2;
						cout << "请输入数字>>> ";
						cin >> speed;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
							cerr << "*****输入无效!请输入一个整数!*****" << endl;
							cout << "输入任意字符继续....";
							// 等待回车
							char ch;
							cin.get(ch);
							cin.ignore();
							continue;
						}
						// 选择播放速度
						switch (speed) {
						case 1:
							speed = 2000;
							break;
						case 2:
							speed = 1500;
							break;
						case 3:
							speed = 500;
							break;
						default:
							speed = 1500;
							break;
						}
						stringstream buffer;
						// 记录开始时间
						auto start = chrono::high_resolution_clock::now();
						// 先显示
						system("cls");
						cout << "原始数据:" << endl;
						display(mysort);
						// 先暂停一秒
						this_thread::sleep_for(chrono::seconds(1));
						cout << "排序过程:" << endl;
						switch (chose) {
						case 1:
							mysort.bubblingSort(greater, true, speed);
							break;
						case 2:
							mysort.insertSort(greater, true, speed);
							break;
						case 3:
							mysort.choiceSort(greater, true, speed);
							break;
						case 4:
							mysort.shellSort(greater, true, speed);
							break;
						case 5:
							cout << "\033[?25l";  // 隐藏光标
							mysort.mergeSortNonR(mysort.getData(), greater, speed);
							cout << "\033[?25h";  // 恢复光标
							break;
						case 6:
							mysort.quickSort(mysort.getData(), 0, mysort.getData().size() - 1, greater, true, speed);
							break;
						case 7:
							mysort.HeapSort(mysort.getData(), mysort.getData().size(), greater, true, speed);
							break;
						case 8:
							// 智能选择算法排序
							mysort.autoSort(greater, true, speed);
							break;
						default:
							mysort.bubblingSort(greater, true, speed);
						}
						// 记录结束时间
						auto end = chrono::high_resolution_clock::now();
						// 算出消耗时间
						chrono::duration<double> duration = end - start;
						mysort.setRunTime(duration.count());
						// 输出排序后的元素
						Menu::outputMenu(mysort);
						size_t dotPos = filename.find('.');  // 找到 '.' 的位置
						if (dotPos != string::npos) {
							filename = filename.substr(0, dotPos) + "_temp" + filename.substr(dotPos);
						}
						else {
							// 如果没有 '.'，直接追加 "_temp"
							filename += "_temp.txt";
						}
						cout << "已将排序好的元素保存到文件 " << filename << " 中" << endl;

						file.saveFile(filename, mysort.getData());
						cout << "输入任意字符继续....";
						// 等待回车
						char chr;
						cin.get(chr);
						cin.ignore();
					}
					break;
				}
				// 文本导入说明
				else if (option == "3") {
					Menu::fileExplain();
					cout << "输入任意字符继续....";
					// 等待回车
					char chr;
					cin.get(chr);
					cin.ignore();
				}
				else {
					cerr << "*****您选择的功能不存在!请重新输入!*****" << endl;
					cout << "输入任意字符继续....";
					// 等待回车
					char ch;
					cin.get(ch);
					cin.ignore();
				}
			}
		}
		else if (choice == "4") {
			// 实现随机生成数据可视化
			while (true) {
				MySort mysort;
				// 实现随机生成数据
				// 创建随机数生成器
				random_device rd;
				// 使用梅森旋转算法
				mt19937 gen(rd());
				// 创建范围为-10000-10000的随机数
				uniform_int_distribution<> dis(-10000, 10000);

				// 用于储存随机数,数据量为20
				double memoryUsage = 0;
				for (int i = 0; i < 20; i++) {
					mysort.getData().push_back(dis(gen));
					memoryUsage++;
				}
				mysort.setMemoryUsage(memoryUsage);

				// 打印这二十个元素
				cout << "随机生成的20个数字为:";
				for (int i = 0; i < 20; i++)
					cout << mysort.getData()[i] << " ";
				cout << endl;
				cout << "输入任意字符继续....";
				// 等待回车
				char ch;
				cin.get(ch);
				cin.ignore();

				Menu::sortMenu();
				int chose;
				cout << "请输入数字>>> ";
				cin >> chose;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
					cerr << "*****输入无效!请输入一个整数!*****" << endl;
					cout << "输入任意字符继续....";
					// 等待回车
					char ch;
					cin.get(ch);
					cin.ignore();
					break;
				}
				else if (chose == 0)
					break;
				else {
					Menu::sortMethodMenu();
					int greater = 0;
					cout << "请输入数字>>> ";
					cin >> greater;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
						cerr << "*****输入无效!请输入一个整数!*****" << endl;
						cout << "输入任意字符继续....";
						// 等待回车
						char ch;
						cin.get(ch);
						cin.ignore();
						break;
					}
					Menu::speedMenu();
					// 播放速度
					int speed = 2;
					cout << "请输入数字>>> ";
					cin >> speed;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
						cerr << "*****输入无效!请输入一个整数!*****" << endl;
						cout << "输入任意字符继续....";
						// 等待回车
						char ch;
						cin.get(ch);
						cin.ignore();
						break;
					}
					// 选择播放速度
					switch (speed) {
					case 1:
						speed = 2000;
						break;
					case 2:
						speed = 1500;
						break;
					case 3:
						speed = 500;
						break;
					default:
						speed = 1500;
						break;
					}
					// 记录开始时间
					auto start = chrono::high_resolution_clock::now();
					// 先显示
					cout << "\033[2J\033[1;1H";
					cout << "原始数据:" << endl;
					display(mysort);
					// 先暂停一秒
					this_thread::sleep_for(chrono::seconds(1));
					switch (chose) {
					case 1:
						mysort.bubblingSort(greater, true, speed);
						break;
					case 2:
						mysort.insertSort(greater, true, speed);
						break;
					case 3:
						mysort.choiceSort(greater, true, speed);
						break;
					case 4:
						mysort.shellSort(greater, true, speed);
						break;
					case 5:
						cout << "\033[?25l";  // 隐藏光标
						mysort.mergeSortNonR(mysort.getData(), greater, speed);
						cout << "\033[?25h";  // 恢复光标
						break;
					case 6:
						cout << "\033[?25l";  // 隐藏光标
						mysort.quickSort(mysort.getData(), 0, mysort.getData().size() - 1, greater, true, speed);
						cout << "\033[?25h";  // 恢复光标
						break;
					case 7:
						mysort.HeapSort(mysort.getData(), mysort.getData().size(), greater, true, speed);
						break;
					case 8:
						// 智能选择算法排序
						mysort.autoSort(greater, true, speed);
						break;
					default:
						mysort.bubblingSort(greater, true, speed);
					}
					// 记录结束时间
					auto end = chrono::high_resolution_clock::now();
					// 算出消耗时间
					chrono::duration<double> duration = end - start;
					mysort.setRunTime(duration.count());
					// 输出排序后的元素
					Menu::outputMenu(mysort);
					cout << "输入任意字符继续....";
					// 等待回车
					char chr;
					cin.get(chr);
					cin.ignore();
				}
				break;
			}
		}
		else if (choice == "5") {
			while (true) {
				int num;
				cout << "请输入生成的随机数数据量>>> ";
				cin >> num;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
					cerr << "*****输入无效!请输入一个整数!*****" << endl;
					cout << "输入任意字符继续...." << endl;
					// 等待回车
					char ch;
					cin.get(ch);
					cin.ignore();
					continue;
				}

				if (num <= 1) {
					cerr << "***********数据量至少为2！***********" << endl;
					cout << "输入任意字符继续....";
					// 等待回车
					char ch;
					cin.get(ch);
					cin.ignore();
					continue;
				}

				// 0-8代表的排序算法:bubblingS, insertS, choiceS, shellS, mergeS, quickS, heapS, autoS
				MySort mysort[8];
				const int len = 8;
				// 实现随机生成数据
				// 创建随机数生成器
				random_device rd;
				// 使用梅森旋转算法
				mt19937 gen(rd());
				// 创建范围为-3000-3000的随机数
				uniform_int_distribution<> dis(-3000, 3000);
				vector<int> number;
				for (int i = 0; i < num; i++) {
					number.push_back(dis(gen));
				}

				// 用于储存随机数,数据量为12000
				for (int i = 0; i < len; i++) {
					// 为各算法对象存储随机数
					mysort[i].setData(number);
					mysort[i].setMemoryUsage(number.size());
				}

				// 打印进度条
				cout << "随机数据正在生成当中......" << endl;
				cout << "[ ";
				for (int i = 0; i < 12; i++) {
					cout << string(i, '#');
					cout << "\033[K";  // 清除当前行内容
					this_thread::sleep_for(chrono::milliseconds(500));
					// 强制刷新
					cout.flush();
				}
				cout << " ] Done!" << endl;


				cout << endl;
				cout << "随机数据已准备就绪，请输入任意字符开始排序....";
				// 等待回车
				char ch;
				cin.get(ch);
				cin.ignore();

				// 排序
				for (int i = 0; i < len; i++) {
					// 记录开始时间
					auto start = chrono::high_resolution_clock::now();
					switch (i) {
					case 0:
						mysort[i].setName("冒泡排序");
						mysort[i].bubblingSort();
						break;
					case 1:
						mysort[i].setName("插入排序");
						mysort[i].insertSort();
						break;
					case 2:
						mysort[i].setName("选择排序");
						mysort[i].choiceSort();
						break;
					case 3:
						mysort[i].setName("希尔排序");
						mysort[i].shellSort();
						break;
					case 4:
						mysort[i].setName("归并排序");
						mysort[i].mergeSort(mysort[i].getData());
						break;
					case 5:
						mysort[i].setName("快速排序");
						mysort[i].quickSort(mysort[i].getData(), 0, mysort[i].getData().size() - 1);
						break;
					case 6:
						mysort[i].setName("堆排序");
						mysort[i].HeapSort(mysort[i].getData(), mysort[i].getData().size());
						break;
					case 7:
						mysort[i].setName("智能排序");
						mysort[i].autoSort();
						break;
					default:
						break;
					}
					// 记录结束时间
					auto end = chrono::high_resolution_clock::now();
					// 算出消耗时间
					chrono::duration<double> duration = end - start;
					mysort[i].setRunTime(duration.count());
				}

				// 比较指数选择
				Menu::compareMenu();
				int option;
				cout << "请输入数字>>> ";
				cin >> option;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃当前行的所有字符
					cerr << "*****输入无效!请输入一个整数!*****" << endl;
					cout << "输入任意字符继续....";
					// 等待回车
					char ch;
					cin.get(ch);
					cin.ignore();
					break;
				}
				if (option == 0)
					break;
				else {
					compareAlgorithm(mysort, len, option);
					cout << "输入任意字符继续....";
					// 等待回车
					char ch;
					cin.get(ch);
					cin.ignore();
					break;
				}
			}
		}
		else if (choice == "6") {
			Menu::sysInfo();
			cout << "输入任意字符继续....";
			// 等待回车
			char chr;
			cin.get(chr);
			cin.ignore();
		}
		else if (choice == "7") {
			Menu::sortAlgorithmMenu();
			cout << "输入任意字符继续....";
			// 等待回车
			char chr;
			cin.get(chr);
			cin.ignore();
		}
		else {
			cerr << "*****您选择的功能不存在!请重新输入!*****" << endl;
			cout << "输入任意字符继续....";
			// 等待回车
			char ch;
			cin.get(ch);
			cin.ignore();
		}
	}
}