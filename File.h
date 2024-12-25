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
	// 读取文件
	void loadFile(string, vector<int>&);
	// 保存文件
	void saveFile(string, vector<int>&);

	// 文件读取艺术字
	static void loadArtWord(string);
};