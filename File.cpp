#include"File.h"

// ���ļ�
void File::loadFile(string filename, vector<int>& num) {
	ifstream file(filename);
	char ch;
	if (!file.is_open()) {
		cerr << "********���ļ�ʧ��!********" << endl;
		cerr << "********�ļ�����/λ�ò���ȷ���޷��ҵ��ļ�!********" << endl;
		cout << "���������ַ�����....";
		// �ȴ��س�;
		cin.get(ch);
		cin.ignore();
		return;
	}
	string currentNum;
	char chr;
	try {
		while (file.get(chr)) {
			// ����Ƿ��������ַ���ͨ����Χ�жϣ�
			if (static_cast<unsigned char>(chr) >= 0x80) {  // �����ַ��� UTF-8 �и�λ����
				throw runtime_error("��⵽�����ַ���� ASCII �ַ���");
			}

			if (chr == '-')
				currentNum += chr;
			else if (isdigit(chr)) {  // �жϵ�ǰ�ַ��Ƿ�Ϊ����
				currentNum += chr;  // ��������ַ���
			}
			// �����ǰ�ַ���Ϊ�������ַ����ǿգ�������
			else if (!currentNum.empty()) {
				num.push_back(stoi(currentNum)); // תΪ����
				currentNum.clear();  // ��յ�ǰ�ַ���
			}
		}
		// ���������ַ������洢
		if (!currentNum.empty())
			num.push_back(stoi(currentNum));
	}catch (const invalid_argument& e) {
		cerr << "ת��������Ч�����ָ�ʽ��" << endl;
		cout << "���������ַ�����....";
		// �ȴ��س�
		cin.get(ch);
		cin.ignore();
	}
	catch (const out_of_range& e) {
		cerr << "ת���������ֳ�����Χ��" << endl;
		cout << "���������ַ�����....";
		// �ȴ��س�
		cin.get(ch);
		cin.ignore();
	}
	catch (const runtime_error& e) {
		cerr << "����ʱ����" << e.what() << endl;
		cout << "���������ַ�����....";
		// �ȴ��س�
		cin.get(ch);
		cin.ignore();
	}
	catch (...) {
		cerr << "����δ֪����" << endl;
		cout << "���������ַ�����....";
		// �ȴ��س�
		cin.get(ch);
		cin.ignore();
	}

	file.close();
}

void File::saveFile(string filename, vector<int>& arr) {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "********���ļ�ʧ��!********" << endl;
		cout << "���������ַ�����....";
		// �ȴ��س�
		char ch;
		cin.get(ch);
		cin.ignore();
		return;
	}
	cout << "----------������......----------" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	for (int i = 0; i < arr.size(); i++) {
		file << arr[i] << " ";
	}
	cout << "----------����ɹ�!----------" << endl;
	file.close();
}

void File::loadArtWord(string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "********���ļ�ʧ��!********" << endl;
		cout << "���������ַ�����....";
		// �ȴ��س�
		char ch;
		cin.get(ch);
		cin.ignore();
		return;
	}
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}

	file.close();
}