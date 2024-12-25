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
	// ��ʼ�˵�
	static void startMenu();

	// ����ѡ��˵�
	static void secondChoiceMenu(string choice);

	// ����ʽ�˵�
	static void sortMenu();

	// ����ʽ�˵�
	static void sortMethodMenu();

	// �����ٶȲ˵�
	static void speedMenu();

	// ���������Ԫ�ؼ���Ӧ��Ϣ
	static void outputMenu(MySort& mysort);

	// �㷨���˵��
	static void sortAlgorithmMenu();

	// �ı�����˵��
	static void fileExplain();

	// �㷨�Ƚϲ˵�
	static void compareMenu();

	// ϵͳ���
	static void sysInfo();
};