#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<thread>
#include<chrono>
#include<fstream>
using namespace std;

class File {
public:
	// ��ȡ�ļ�
	void loadFile(string, vector<int>&);
	// �����ļ�
	void saveFile(string, vector<int>&);

	// �ļ���ȡ������
	static void loadArtWord(string);
};