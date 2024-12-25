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
	// ���˵�
	while (true) {
		Menu::startMenu();
		string choice;
		cout << "����������>>> ";
		cin >> choice;
		if (choice == "0") {
			// �˳�����
			exit(0);
		}
		// ֱ�����������Ϣ��������ӻ�
		else if (choice == "1") {
			while (true) {
				MySort mysort;
				Menu::secondChoiceMenu(choice);
				string option;
				cout << "����������>>> ";
				cin >> option;
				if (option == "0")
					break;
				// ʵ���Լ���������
				else if (option == "1") {
					// ������ʵ����������
					int size;
					cout << "����������Ԫ�ظ���>>> ";
					cin >> size;

					// ����������Ƿ�ʧ��
					if (cin.fail()) {
						// ������Ч����������־�����������������
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
						cerr << "*****������Ч!������һ������!*****" << endl;
						continue;
					}
					else {
						cout << "��������������Ԫ��>>> ";
						double memoryUsage = 0;
						for (int i = 0; i < size; i++) {
							int n;
							cin >> n;
							// ����������Ƿ�ʧ��
							if (cin.fail()) {
								// ������Ч����������־�����������������
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
								cerr << "*****������Ч!������һ������!*****" << endl;
								cout << "���������ַ�����....";
								// �ȴ��س�
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
						cout << "����������>>> ";
						cin >> chose;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
							cerr << "*****������Ч!������һ������!*****" << endl;
							cout << "���������ַ�����....";
							// �ȴ��س�
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
							cout << "����������>>> ";
							cin >> greater;
							if (cin.fail()) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
								cerr << "*****������Ч!������һ������!*****" << endl;
								cout << "���������ַ�����....";
								// �ȴ��س�
								char ch;
								cin.get(ch);
								cin.ignore();
								continue;
							}
							// ��¼��ʼʱ��
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
								// ����ѡ���㷨����
								mysort.autoSort(greater);
								break;
							default:
								mysort.bubblingSort(greater);
							}
							// ��¼����ʱ��
							auto end = chrono::high_resolution_clock::now();
							// �������ʱ��
							chrono::duration<double> duration = end - start;
							mysort.setRunTime(duration.count());
							// ���������Ԫ��
							Menu::outputMenu(mysort);
							cout << "���������ַ�����....";
							// �ȴ��س�
							char ch;
							cin.get(ch);
							cin.ignore();
						}
						break;
					}
				}

				// ʵ���ı���������
				else if (option == "2") {
					string filename;
					cout << "�������ļ�λ��>>> ";
					cin >> filename;
					File file;
					// �����ļ�
					file.loadFile(filename, mysort.getData());
					if (mysort.getData().empty())
						break;
					int memoryUsage = mysort.getData().capacity();
					mysort.setMemoryUsage(memoryUsage);

					Menu::sortMenu();
					int chose;
					cout << "����������>>> ";
					cin >> chose;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
						cerr << "*****������Ч!������һ������!*****" << endl;
						cout << "���������ַ�����....";
						// �ȴ��س�
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
						cout << "����������>>> ";
						cin >> greater;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
							cerr << "*****������Ч!������һ������!*****" << endl;
							cout << "���������ַ�����....";
							// �ȴ��س�
							char ch;
							cin.get(ch);
							cin.ignore();
							continue;
						}
						// ��¼��ʼʱ��
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
							// ����ѡ���㷨����
							mysort.autoSort(greater);
							break;
						default:
							mysort.bubblingSort(greater);
						}
						// ��¼����ʱ��
						auto end = chrono::high_resolution_clock::now();
						// �������ʱ��
						chrono::duration<double> duration = end - start;
						mysort.setRunTime(duration.count());
						// ���������Ԫ��
						Menu::outputMenu(mysort);
						size_t dotPos = filename.find('.');  // �ҵ� '.' ��λ��
						if (dotPos != string::npos) {
							filename = filename.substr(0, dotPos) + "_temp" + filename.substr(dotPos);
						}
						else {
							// ���û�� '.'��ֱ��׷�� "_temp"
							filename += "_temp.txt";
						}
						cout << "�ѽ�����õ�Ԫ�ر��浽�ļ� " << filename << " ��" << endl;

						file.saveFile(filename, mysort.getData());
						cout << "���������ַ�����....";
						// �ȴ��س�
						char ch;
						cin.get(ch);
						cin.ignore();
					}
					break;
				}
				
				// �ı�����˵��
				else if (option == "3"){
					Menu::fileExplain();
					cout << "���������ַ�����....";
					// �ȴ��س�
					char chr;
					cin.get(chr);
					cin.ignore();
				}
				else {
					cerr << "*****��ѡ��Ĺ��ܲ�����!����������!*****" << endl;
					cout << "���������ַ�����....";
					// �ȴ��س�
					char ch;
					cin.get(ch);
					cin.ignore();
				}
			}
		}
		else if (choice == "2") {
			while (true) {
				MySort mysort;
				// ʵ�������������
				// ���������������
				random_device rd;
				// ʹ��÷ɭ��ת�㷨
				mt19937 gen(rd());
				// ������ΧΪ-99999-999999�������
				uniform_int_distribution<> dis(-99999, 99999);

				// ���ڴ��������,������Ϊ12000
				double memoryUsage = 0;
				for (int i = 0; i < 12000; i++) {
					mysort.getData().push_back(dis(gen));
					memoryUsage++;
				}
				mysort.setMemoryUsage(memoryUsage);

				// ��ӡǰʮ���Ԫ��
				cout << "���������12000�����ݣ�ǰ15������Ϊ:";
				for (int i = 0; i < 15; i++)
					cout << mysort.getData()[i] << " ";
				cout << endl;
				cout << "���������ַ�����....";
				// �ȴ��س�
				char ch;
				cin.get(ch);
				cin.ignore();

				Menu::sortMenu();
				int chose;
				cout << "����������>>> ";
				cin >> chose;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
					cerr << "*****������Ч!������һ������!*****" << endl;
					cout << "���������ַ�����....";
					// �ȴ��س�
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
					cout << "����������>>> ";
					cin >> greater;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
						cerr << "*****������Ч!������һ������!*****" << endl;
						cout << "���������ַ�����....";
						// �ȴ��س�
						char ch;
						cin.get(ch);
						cin.ignore();
						break;
					}
					// ��¼��ʼʱ��
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
						// ����ѡ���㷨����
						mysort.autoSort(greater);
						break;
					default:
						mysort.bubblingSort(greater);
					}
					// ��¼����ʱ��
					auto end = chrono::high_resolution_clock::now();
					// �������ʱ��
					chrono::duration<double> duration = end - start;
					mysort.setRunTime(duration.count());
					Menu::outputMenu(mysort);
					cout << "���������ַ�����....";
					// �ȴ��س�
					char chr;
					cin.get(chr);
					cin.ignore();
				}
				break;
			}
		}
		// ���ӻ�ͼ�����򣬰��������ٶȵĹ���
		else if (choice == "3") {
			while (true) {
				MySort mysort;
				Menu::secondChoiceMenu(choice);
				string option;
				cout << "����������>>> ";
				cin >> option;
				if (option == "0")
					break;
				// ʵ���Լ���������
				else if (option == "1") {
					// ������ʵ����������
					int size;
					cout << "����������Ԫ�ظ���>>> ";
					cin >> size;

					// ����������Ƿ�ʧ��
					if (cin.fail()) {
						// ������Ч����������־�����������������
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
						cerr << "*****������Ч!������һ������!*****" << endl;
						cout << "���������ַ�����....";
						// �ȴ��س�
						char ch;
						cin.get(ch);
						cin.ignore();
						continue;
					}
					else {
						cout << "��������������Ԫ��>>> ";
						double memoryUsage = 0;
						for (int i = 0; i < size; i++) {
							int n;
							cin >> n;
							// ����������Ƿ�ʧ��
							if (cin.fail()) {
								// ������Ч����������־�����������������
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
								cerr << "*****������Ч!������һ������!*****" << endl;
								cout << "���������ַ�����....";
								// �ȴ��س�
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
						cout << "����������>>> ";
						cin >> chose;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
							cerr << "*****������Ч!������һ������!*****" << endl;
							continue;
						}
						else if (chose == 0)
							break;
						else {
							Menu::sortMethodMenu();
							int greater = 0;
							cout << "����������>>> ";
							cin >> greater;
							if (cin.fail()) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
								cerr << "*****������Ч!������һ������!*****" << endl;
								cout << "���������ַ�����....";
								// �ȴ��س�
								char ch;
								cin.get(ch);
								cin.ignore();
								continue;
							}
							Menu::speedMenu();
							// �����ٶ�
							int speed = 2;
							cout << "����������>>> ";
							cin >> speed;
							if (cin.fail()) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
								cerr << "*****������Ч!������һ������!*****" << endl;
								cout << "���������ַ�����....";
								// �ȴ��س�
								char ch;
								cin.get(ch);
								cin.ignore();
								continue;
							}
							// ѡ�񲥷��ٶ�
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
							// ��¼��ʼʱ��
							auto start = chrono::high_resolution_clock::now();
							// ����ʾ
							system("cls");
							cout << "ԭʼ����:" << endl;
							display(mysort);
							// ����ͣһ��
							this_thread::sleep_for(chrono::seconds(1));
							cout << "�������:" << endl;
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
								cout << "\033[?25l";  // ���ع��
								mysort.mergeSortNonR(mysort.getData(), greater, speed);
								cout << "\033[?25h";  // �ָ����
								break;
							case 6:
								mysort.quickSort(mysort.getData(), 0, mysort.getData().size() - 1, greater, true, speed);
								break;
							case 7:
								mysort.HeapSort(mysort.getData(), mysort.getData().size(), greater, true, speed);
								break;
							case 8:
								// ����ѡ���㷨����
								mysort.autoSort(greater, true, speed);
								break;
							default:
								mysort.bubblingSort(greater, true, speed);
							}
							// ��¼����ʱ��
							auto end = chrono::high_resolution_clock::now();
							// �������ʱ��
							chrono::duration<double> duration = end - start;
							mysort.setRunTime(duration.count());
							// ���������Ԫ��
							Menu::outputMenu(mysort);
							cout << "���������ַ�����....";
							// �ȴ��س�
							char chr;
							cin.get(chr);
							cin.ignore();
						}
						break;
					}
				}

				// ʵ���ı�����
				else if (option == "2") {
					string filename;
					cout << "�������ļ�λ��>>> ";
					cin >> filename;
					File file;
					// �����ļ�
					file.loadFile(filename, mysort.getData());
					if (mysort.getData().empty())
						break;
					int memoryUsage = mysort.getData().capacity();
					mysort.setMemoryUsage(memoryUsage);

					Menu::sortMenu();
					int chose;
					cout << "����������>>> ";
					cin >> chose;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
						cerr << "*****������Ч!������һ������!*****" << endl;
						cout << "���������ַ�����....";
						// �ȴ��س�
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
						cout << "����������>>> ";
						cin >> greater;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
							cerr << "*****������Ч!������һ������!*****" << endl;
							cout << "���������ַ�����....";
							// �ȴ��س�
							char ch;
							cin.get(ch);
							cin.ignore();
							continue;
						}
						Menu::speedMenu();
						// �����ٶ�
						int speed = 2;
						cout << "����������>>> ";
						cin >> speed;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
							cerr << "*****������Ч!������һ������!*****" << endl;
							cout << "���������ַ�����....";
							// �ȴ��س�
							char ch;
							cin.get(ch);
							cin.ignore();
							continue;
						}
						// ѡ�񲥷��ٶ�
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
						// ��¼��ʼʱ��
						auto start = chrono::high_resolution_clock::now();
						// ����ʾ
						system("cls");
						cout << "ԭʼ����:" << endl;
						display(mysort);
						// ����ͣһ��
						this_thread::sleep_for(chrono::seconds(1));
						cout << "�������:" << endl;
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
							cout << "\033[?25l";  // ���ع��
							mysort.mergeSortNonR(mysort.getData(), greater, speed);
							cout << "\033[?25h";  // �ָ����
							break;
						case 6:
							mysort.quickSort(mysort.getData(), 0, mysort.getData().size() - 1, greater, true, speed);
							break;
						case 7:
							mysort.HeapSort(mysort.getData(), mysort.getData().size(), greater, true, speed);
							break;
						case 8:
							// ����ѡ���㷨����
							mysort.autoSort(greater, true, speed);
							break;
						default:
							mysort.bubblingSort(greater, true, speed);
						}
						// ��¼����ʱ��
						auto end = chrono::high_resolution_clock::now();
						// �������ʱ��
						chrono::duration<double> duration = end - start;
						mysort.setRunTime(duration.count());
						// ���������Ԫ��
						Menu::outputMenu(mysort);
						size_t dotPos = filename.find('.');  // �ҵ� '.' ��λ��
						if (dotPos != string::npos) {
							filename = filename.substr(0, dotPos) + "_temp" + filename.substr(dotPos);
						}
						else {
							// ���û�� '.'��ֱ��׷�� "_temp"
							filename += "_temp.txt";
						}
						cout << "�ѽ�����õ�Ԫ�ر��浽�ļ� " << filename << " ��" << endl;

						file.saveFile(filename, mysort.getData());
						cout << "���������ַ�����....";
						// �ȴ��س�
						char chr;
						cin.get(chr);
						cin.ignore();
					}
					break;
				}
				// �ı�����˵��
				else if (option == "3") {
					Menu::fileExplain();
					cout << "���������ַ�����....";
					// �ȴ��س�
					char chr;
					cin.get(chr);
					cin.ignore();
				}
				else {
					cerr << "*****��ѡ��Ĺ��ܲ�����!����������!*****" << endl;
					cout << "���������ַ�����....";
					// �ȴ��س�
					char ch;
					cin.get(ch);
					cin.ignore();
				}
			}
		}
		else if (choice == "4") {
			// ʵ������������ݿ��ӻ�
			while (true) {
				MySort mysort;
				// ʵ�������������
				// ���������������
				random_device rd;
				// ʹ��÷ɭ��ת�㷨
				mt19937 gen(rd());
				// ������ΧΪ-10000-10000�������
				uniform_int_distribution<> dis(-10000, 10000);

				// ���ڴ��������,������Ϊ20
				double memoryUsage = 0;
				for (int i = 0; i < 20; i++) {
					mysort.getData().push_back(dis(gen));
					memoryUsage++;
				}
				mysort.setMemoryUsage(memoryUsage);

				// ��ӡ���ʮ��Ԫ��
				cout << "������ɵ�20������Ϊ:";
				for (int i = 0; i < 20; i++)
					cout << mysort.getData()[i] << " ";
				cout << endl;
				cout << "���������ַ�����....";
				// �ȴ��س�
				char ch;
				cin.get(ch);
				cin.ignore();

				Menu::sortMenu();
				int chose;
				cout << "����������>>> ";
				cin >> chose;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
					cerr << "*****������Ч!������һ������!*****" << endl;
					cout << "���������ַ�����....";
					// �ȴ��س�
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
					cout << "����������>>> ";
					cin >> greater;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
						cerr << "*****������Ч!������һ������!*****" << endl;
						cout << "���������ַ�����....";
						// �ȴ��س�
						char ch;
						cin.get(ch);
						cin.ignore();
						break;
					}
					Menu::speedMenu();
					// �����ٶ�
					int speed = 2;
					cout << "����������>>> ";
					cin >> speed;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
						cerr << "*****������Ч!������һ������!*****" << endl;
						cout << "���������ַ�����....";
						// �ȴ��س�
						char ch;
						cin.get(ch);
						cin.ignore();
						break;
					}
					// ѡ�񲥷��ٶ�
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
					// ��¼��ʼʱ��
					auto start = chrono::high_resolution_clock::now();
					// ����ʾ
					cout << "\033[2J\033[1;1H";
					cout << "ԭʼ����:" << endl;
					display(mysort);
					// ����ͣһ��
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
						cout << "\033[?25l";  // ���ع��
						mysort.mergeSortNonR(mysort.getData(), greater, speed);
						cout << "\033[?25h";  // �ָ����
						break;
					case 6:
						cout << "\033[?25l";  // ���ع��
						mysort.quickSort(mysort.getData(), 0, mysort.getData().size() - 1, greater, true, speed);
						cout << "\033[?25h";  // �ָ����
						break;
					case 7:
						mysort.HeapSort(mysort.getData(), mysort.getData().size(), greater, true, speed);
						break;
					case 8:
						// ����ѡ���㷨����
						mysort.autoSort(greater, true, speed);
						break;
					default:
						mysort.bubblingSort(greater, true, speed);
					}
					// ��¼����ʱ��
					auto end = chrono::high_resolution_clock::now();
					// �������ʱ��
					chrono::duration<double> duration = end - start;
					mysort.setRunTime(duration.count());
					// ���������Ԫ��
					Menu::outputMenu(mysort);
					cout << "���������ַ�����....";
					// �ȴ��س�
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
				cout << "���������ɵ������������>>> ";
				cin >> num;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
					cerr << "*****������Ч!������һ������!*****" << endl;
					cout << "���������ַ�����...." << endl;
					// �ȴ��س�
					char ch;
					cin.get(ch);
					cin.ignore();
					continue;
				}

				if (num <= 1) {
					cerr << "***********����������Ϊ2��***********" << endl;
					cout << "���������ַ�����....";
					// �ȴ��س�
					char ch;
					cin.get(ch);
					cin.ignore();
					continue;
				}

				// 0-8����������㷨:bubblingS, insertS, choiceS, shellS, mergeS, quickS, heapS, autoS
				MySort mysort[8];
				const int len = 8;
				// ʵ�������������
				// ���������������
				random_device rd;
				// ʹ��÷ɭ��ת�㷨
				mt19937 gen(rd());
				// ������ΧΪ-3000-3000�������
				uniform_int_distribution<> dis(-3000, 3000);
				vector<int> number;
				for (int i = 0; i < num; i++) {
					number.push_back(dis(gen));
				}

				// ���ڴ��������,������Ϊ12000
				for (int i = 0; i < len; i++) {
					// Ϊ���㷨����洢�����
					mysort[i].setData(number);
					mysort[i].setMemoryUsage(number.size());
				}

				// ��ӡ������
				cout << "��������������ɵ���......" << endl;
				cout << "[ ";
				for (int i = 0; i < 12; i++) {
					cout << string(i, '#');
					cout << "\033[K";  // �����ǰ������
					this_thread::sleep_for(chrono::milliseconds(500));
					// ǿ��ˢ��
					cout.flush();
				}
				cout << " ] Done!" << endl;


				cout << endl;
				cout << "���������׼�������������������ַ���ʼ����....";
				// �ȴ��س�
				char ch;
				cin.get(ch);
				cin.ignore();

				// ����
				for (int i = 0; i < len; i++) {
					// ��¼��ʼʱ��
					auto start = chrono::high_resolution_clock::now();
					switch (i) {
					case 0:
						mysort[i].setName("ð������");
						mysort[i].bubblingSort();
						break;
					case 1:
						mysort[i].setName("��������");
						mysort[i].insertSort();
						break;
					case 2:
						mysort[i].setName("ѡ������");
						mysort[i].choiceSort();
						break;
					case 3:
						mysort[i].setName("ϣ������");
						mysort[i].shellSort();
						break;
					case 4:
						mysort[i].setName("�鲢����");
						mysort[i].mergeSort(mysort[i].getData());
						break;
					case 5:
						mysort[i].setName("��������");
						mysort[i].quickSort(mysort[i].getData(), 0, mysort[i].getData().size() - 1);
						break;
					case 6:
						mysort[i].setName("������");
						mysort[i].HeapSort(mysort[i].getData(), mysort[i].getData().size());
						break;
					case 7:
						mysort[i].setName("��������");
						mysort[i].autoSort();
						break;
					default:
						break;
					}
					// ��¼����ʱ��
					auto end = chrono::high_resolution_clock::now();
					// �������ʱ��
					chrono::duration<double> duration = end - start;
					mysort[i].setRunTime(duration.count());
				}

				// �Ƚ�ָ��ѡ��
				Menu::compareMenu();
				int option;
				cout << "����������>>> ";
				cin >> option;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������ǰ�е������ַ�
					cerr << "*****������Ч!������һ������!*****" << endl;
					cout << "���������ַ�����....";
					// �ȴ��س�
					char ch;
					cin.get(ch);
					cin.ignore();
					break;
				}
				if (option == 0)
					break;
				else {
					compareAlgorithm(mysort, len, option);
					cout << "���������ַ�����....";
					// �ȴ��س�
					char ch;
					cin.get(ch);
					cin.ignore();
					break;
				}
			}
		}
		else if (choice == "6") {
			Menu::sysInfo();
			cout << "���������ַ�����....";
			// �ȴ��س�
			char chr;
			cin.get(chr);
			cin.ignore();
		}
		else if (choice == "7") {
			Menu::sortAlgorithmMenu();
			cout << "���������ַ�����....";
			// �ȴ��س�
			char chr;
			cin.get(chr);
			cin.ignore();
		}
		else {
			cerr << "*****��ѡ��Ĺ��ܲ�����!����������!*****" << endl;
			cout << "���������ַ�����....";
			// �ȴ��س�
			char ch;
			cin.get(ch);
			cin.ignore();
		}
	}
}