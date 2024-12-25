#include"File.h"

// 读文件
void File::loadFile(string filename, vector<int>& num) {
	ifstream file(filename);
	char ch;
	if (!file.is_open()) {
		cerr << "********打开文件失败!********" << endl;
		cerr << "********文件名称/位置不正确，无法找到文件!********" << endl;
		cout << "输入任意字符继续....";
		// 等待回车;
		cin.get(ch);
		cin.ignore();
		return;
	}
	string currentNum;
	char chr;
	try {
		while (file.get(chr)) {
			// 检查是否是中文字符（通过范围判断）
			if (static_cast<unsigned char>(chr) >= 0x80) {  // 中文字符在 UTF-8 中高位非零
				throw runtime_error("检测到中文字符或非 ASCII 字符！");
			}

			if (chr == '-')
				currentNum += chr;
			else if (isdigit(chr)) {  // 判断当前字符是否为数字
				currentNum += chr;  // 是则加入字符串
			}
			// 如果当前字符不为数字且字符串非空，存下来
			else if (!currentNum.empty()) {
				num.push_back(stoi(currentNum)); // 转为整型
				currentNum.clear();  // 清空当前字符串
			}
		}
		// 如果最后还有字符串，存储
		if (!currentNum.empty())
			num.push_back(stoi(currentNum));
	}catch (const invalid_argument& e) {
		cerr << "转换错误：无效的数字格式！" << endl;
		cout << "输入任意字符继续....";
		// 等待回车
		cin.get(ch);
		cin.ignore();
	}
	catch (const out_of_range& e) {
		cerr << "转换错误：数字超出范围！" << endl;
		cout << "输入任意字符继续....";
		// 等待回车
		cin.get(ch);
		cin.ignore();
	}
	catch (const runtime_error& e) {
		cerr << "运行时错误：" << e.what() << endl;
		cout << "输入任意字符继续....";
		// 等待回车
		cin.get(ch);
		cin.ignore();
	}
	catch (...) {
		cerr << "发生未知错误！" << endl;
		cout << "输入任意字符继续....";
		// 等待回车
		cin.get(ch);
		cin.ignore();
	}

	file.close();
}

void File::saveFile(string filename, vector<int>& arr) {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "********打开文件失败!********" << endl;
		cout << "输入任意字符继续....";
		// 等待回车
		char ch;
		cin.get(ch);
		cin.ignore();
		return;
	}
	cout << "----------保存中......----------" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	for (int i = 0; i < arr.size(); i++) {
		file << arr[i] << " ";
	}
	cout << "----------保存成功!----------" << endl;
	file.close();
}

void File::loadArtWord(string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "********打开文件失败!********" << endl;
		cout << "输入任意字符继续....";
		// 等待回车
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