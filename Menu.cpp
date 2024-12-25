#include"Menu.h"

// ���� ANSI ��ɫ
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"  // ������ɫ

// ���˵�
void Menu::startMenu() {
	// ��������
	cout << "\033[2J\033[1;1H";
	// �ļ���ȡ������
	string filename;
	srand(time(0));  // �����������
	int randomValue = rand() % 16;  // ���� 0 �� 15 ֮��������
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./������/" + filename);

	cout << "-----------------------------------------" << endl;
	cout << "|         ��ӭ����ling������ϵͳ        |" << endl;
	cout << "|          ��ѡ����Ҫʵ�ֵĹ���         |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|           1. �Զ�����������           |" << endl;
	cout << "|           2. �����������             |" << endl;
	cout << "|           3. ���ӻ��Զ�����������     |" << endl;
	cout << "|           4. ���ӻ������������       |" << endl;
	cout << "|           5. �������㷨�Ƚ�           |" << endl;
	cout << "|           6. ϵͳ���                 |" << endl;
	cout << "|           7. �㷨���                 |" << endl;
	cout << "|           0. �˳�                     |" << endl;
	cout << "-----------------------------------------" << endl;
}


// �����˵�
void Menu::secondChoiceMenu(string choice) {
	// ��������
	cout << "\033[2J\033[1;1H";
	// �ļ���ȡ������
	string filename;
	srand(time(0));  // �����������
	int randomValue = rand() % 16;  // ���� 0 �� 15 ֮��������
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./������/" + filename);

	cout << "-----------------------------------------" << endl;
	cout << "|           ��ѡ�������ݷ�ʽ          |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|             1. �ֶ�����               |" << endl;
	cout << "|             2. �ı�����               |" << endl;
	cout << "|             3. �ı�����˵��*          |" << endl;
	cout << "|             0. ������һ��             |" << endl;
	cout << "-----------------------------------------" << endl;
}

// ����˵�
void Menu::sortMenu() {
	// ��������
	cout << "\033[2J\033[1;1H";
	// �ļ���ȡ������
	string filename;
	srand(time(0));  // �����������
	int randomValue = rand() % 16;  // ���� 0 �� 15 ֮��������
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./������/" + filename);

	cout << "-----------------------------------------" << endl;
	cout << "|           ��ѡ������ʽ              |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|             1. ð������(default)      |" << endl;
	cout << "|             2. ��������               |" << endl;
	cout << "|             3. ѡ������               |" << endl;
	cout << "|             4. ϣ������               |" << endl;
	cout << "|             5. �鲢����               |" << endl;
	cout << "|             6. ��������               |" << endl;
	cout << "|             7. ������                 |" << endl;
	cout << "|             8. ��������               |" << endl;
	cout << "|             0. ������һ��             |" << endl;
	cout << "-----------------------------------------" << endl;
}

// ���򷽷�ѡ��˵�
void Menu::sortMethodMenu() {
	cout << "-----------------------------------------" << endl;
	cout << "|           ��ѡ�������ǽ���          |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|             1. ����(default)          |" << endl;
	cout << "|             0. ����                   |" << endl;
	cout << "-----------------------------------------" << endl;
}

// �ٶ�ѡ��˵�
void Menu::speedMenu() {
	cout << "-----------------------------------------" << endl;
	cout << "|             ��ѡ�񲥷��ٶ�            |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|               1. ����                 |" << endl;
	cout << "|               2. ����(defaul)         |" << endl;
	cout << "|               3. ����                 |" << endl;
	cout << "-----------------------------------------" << endl;
}

// ������Ϣ����˵�
void Menu::outputMenu(MySort& mysort) {
	int len = mysort.getData().size();
	// ���������Ԫ��
	cout << "������Ԫ��Ϊ:";
	for (int i = 0; i < len; i++) {
		if (i % 20 == 0)
			cout << endl;
		cout << mysort.getData()[i] << " ";
	}
	cout << endl;
	cout << "����ʱ��:" << mysort.getRunTime() << "s" << endl;
	cout << "ѭ������:" << mysort.getIterationCount() << "��" << endl;
	cout << "��������:" << mysort.getChangeCount() << "��" << endl;
	cout << "�Ƚϴ���:" << mysort.getCompareCount() << "��" << endl;
	cout << "�������ô���:" << mysort.getCallCount() << "��" << endl;
	cout << "�ڴ�ʹ����:" << mysort.getMemoryUsage() << "MB" << endl;
	cout << "�㷨�ȶ���:";
	if (mysort.getStability())
		cout << "�ȶ�" << endl;
	else
		cout << "���ȶ�" << endl;
	cout << "Ƕ�����:" << mysort.getDeepth() << "��" << endl;
	cout << endl;
}

// �㷨������
void Menu::sortAlgorithmMenu() {
	// ��������
	cout << "\033[2J\033[1;1H";
	// �ļ���ȡ������
	string filename;
	srand(time(0));  // �����������
	int randomValue = rand() % 16;  // ���� 0 �� 15 ֮��������
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./������/" + filename);
	cout << endl;
	
	cout << "=====================================�㷨������====================================" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	// ��ӡ���ͷ��
	cout << left << setw(22) << "�㷨"
		<< setw(15) << "ʱ�临�Ӷ�"
		<< setw(15) << "�ȶ���"
		<< setw(25) << "���ó���" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;

	// ��ӡ�������
	cout << left << setw(22) << "ð������(BubbleSort)"
		<< setw(15) << "O(n^2)"
		<< setw(15) << "�ȶ�"
		<< setw(25) << "С��ģ���ݼ�" << endl;

	cout << left << setw(22) << "��������(InsertSort)"
		<< setw(15) << "O(n^2)"
		<< setw(15) << "�ȶ�"
		<< setw(25) << "���ݻ�������" << endl;

	cout << left << setw(22) << "ѡ������(SelectSort)"
		<< setw(15) << "O(n^2)"
		<< setw(15) << "���ȶ�"
		<< setw(25) << "���ģ���ݼ�" << endl;

	cout << left << setw(22) << "��������(QuickSort)"
		<< setw(15) << "O(nlogn)"
		<< setw(15) << "���ȶ�"
		<< setw(25) << "���ģ���ݼ�" << endl;

	cout << left << setw(22) << "�鲢����(MergeSort)"
		<< setw(15) << "O(nlogn)"
		<< setw(15) << "�ȶ�"
		<< setw(25) << "�ȶ���������" << endl;

	cout << left << setw(22) << "������(HeapSort)"
		<< setw(15) << "O(nlogn)"
		<< setw(15) << "���ȶ�"
		<< setw(25) << "���ģ���ݼ����޶���ռ�����" << endl;

	cout << left << setw(22) << "ϣ������(ShellSort)"
		<< setw(15) << "O(n^(3/2))"
		<< setw(15) << "���ȶ�"
		<< setw(25) << "�еȹ�ģ���ݼ�" << endl;

	cout << left << setw(22) << "��������(SmartSort)"
		<< setw(15) << "O(?)"
		<< setw(15) << "�ȶ�"
		<< setw(25) << "������������ѡ����ʵ�����ʽ" << endl;

	cout << "-------------------------------------------------------------------------------------" << endl;
}

// �ı�����˵��
void Menu::fileExplain() {
	// ��������
	cout << "\033[2J\033[1;1H";
	// �ļ���ȡ������
	string filename;
	srand(time(0));  // �����������
	int randomValue = rand() % 16;  // ���� 0 �� 15 ֮��������
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./������/" + filename);

	cout << "-----------------------------------------" << endl;
	cout << "|              �ı�����˵��             |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|1. �ı�������ʽΪ"; cout << RED << "�ļ�·��"; cout << RESET << "�����·������| " << endl;
	cout << "|����·����                             |" << endl;
	cout << "|2. �ı�����Ϊ"; cout << RED << "����"; cout << RESET << "������"; cout << RED << "�ָ���"; cout << RESET << "�ֿ���Ŀǰ| " << endl;
	cout << "|��֧��"; cout << RED << "Ӣ�ķָ���"; cout << RESET << "��                     | " << endl;
	cout << "|3. ������Ԫ�ر���·��Ϊ��ǰ�ļ��У���|" << endl;
	cout << "|����Ϊ��ǰ�ļ���"; cout << RED << "_temp.txt"; cout << RESET << "����ȷ����ǰ��| " << endl;
	cout << "|�������޴��ļ���                       |" << endl;
	cout << "|4. ��Ҫʵ���ı�����������ӻ��������뾡|" << endl;
	cout << "|��ȷ��"; cout << RED << "����Ԫ�ز�Ҫ����20��";cout << RESET << "��������ӻ� | " << endl;
	cout << "|���̿��ܲ���̫������                   |" << endl;
	cout << "-----------------------------------------" << endl;
}

// �㷨�Ƚϲ˵�
void Menu::compareMenu() {
	// ��������
	cout << "\033[2J\033[1;1H";
	// �ļ���ȡ������
	string filename;
	srand(time(0));  // �����������
	int randomValue = rand() % 16;  // ���� 0 �� 15 ֮��������
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./������/" + filename);

	cout << "-----------------------------------------" << endl;
	cout << "|            ��ѡ��Ƚ�ָ��             |" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|             1.����ʱ��                |" << endl;
	cout << "|             2.ѭ������                |" << endl;
	cout << "|             3.��������                |" << endl;
	cout << "|             4.�Ƚϴ���                |" << endl;
	cout << "|             5.�������ô���            |" << endl;
	cout << "|             6.�ڴ�ʹ����              |" << endl;
	cout << "|             7.Ƕ�����                |" << endl;
	cout << "|             0.������һ��              |" << endl;
	cout << "-----------------------------------------" << endl;
}

// ϵͳ���
void Menu::sysInfo() {
	// ��������
	cout << "\033[2J\033[1;1H";
	// �ļ���ȡ������
	string filename;
	srand(time(0));  // �����������
	int randomValue = rand() % 16;  // ���� 0 �� 15 ֮��������
	filename = "artWord" + to_string(randomValue) + ".txt";
	File::loadArtWord("./������/" + filename);

	cout << "**************************************************" << endl;
	cout << "|                ���� Ling Stor                  |" << endl;
	cout << "**************************************************" << endl;
	cout << "|1. ��ϵͳ����ling�������㷨����ϵͳ���ṩ�˸��� |" << endl;
	cout << "|�����������㷨������ð������ѡ������ϣ������|" << endl;
	cout << "|���������򡢶�����ȡ�                          |" << endl;
	cout << "|2. �ṩ�Զ������ݡ��ı����������Լ������������ |" << endl;
	cout << "|�ȶ��ּ������ݵķ�ʽ��                          |" << endl;
	cout << "|3. �ṩ�˿��ӻ�ģ�飬�ܹ������ؿ���ÿһ������� |" << endl;
	cout << "|�̣����������������㷨��ԭ��                |" << endl;
	cout << "|4. Ҳ�ܹ��Ը����㷨���бȽϣ����ṩ���������� |" << endl;
	cout << "|���������ݵ�����ѡ����Ӧ���㷨���и�Ч����    |" << endl;
	cout << "**************************************************" << endl;
}