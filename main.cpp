#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include "Lecture.h"
#include "MajorFunction.h"

#define HASH_SIZE 100

using namespace std;

int main() {

	// �ѱ� �����ڵ� ����� ���� wstring�� ���
	// cin -> wcin, cout -> wcout ���
	locale::global(locale("ko_KR.UTF-8"));
	setlocale(LC_ALL, "korean");

	// ����
	Major M1(L"�������α׷���", 3, L"", false, false);	// L"~"�� ���·� ���
	Major M2(L"���������", 3, L"", true, false);
	Major M3(L"â�������м���", 3, L"", true, false);
	Major M4(L"�̻걸��", 3, L"", true, false);
	Major M5(L"��ȭ���α׷���", 3, L"�������α׷���", false, false);
	Major M6(L"��ü������ͽǽ�", 3, L"�������α׷���", false, false);
	Major M7(L"�ڷᱸ���ͽǽ�", 3, L"�������α׷���", true, false);
	Major M8(L"��ǻ�ͱ���", 3, L"�̻걸��", true, false);
	Major M9(L"�����α׷���", 3, L"��ü������ͽǽ�", false, false);
	Major M10(L"��ü���������������α׷���", 3, L"��ü������ͽǽ�", false, false);
	Major M11(L"���α׷��־���", 3, L"�������α׷���", false, false);
	Major M12(L"�ý��ۼ���Ʈ����ͽǽ�", 3, L"�ڷᱸ���ͽǽ�", true, false);
	Major M13(L"����SW������Ʈ", 3, L"â�������м���", true, false);
	Major M14(L"�ΰ���ǻ�ͻ�ȣ�ۿ�ý���", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M15(L"��ǻ�ͱ׷��Ƚ��Թ�", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M16(L"�����ͺ��̽��ý���", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M17(L"���ľ��", 3, L"�̻걸��", false, false);
	Major M18(L"�ü��", 3, L"�ý��ۼ���Ʈ����ͽǽ�", false, false);
	Major M19(L"��ǻ�;˰�����ǽ�", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M20(L"����Ʈ������а���", 3, L"��ü������ͽǽ�", false, false);
	Major M21(L"����������Թ�", 3, L"�������α׷���", false, false);
	Major M22(L"�����ͺ��̽����α׷���", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M23(L"��ǻ�ͱ���", 3, L"��ǻ�ͱ���", false, false);
	Major M24(L"�����Ϸ�����", 3, L"���ľ��", false, false);
	Major M25(L"�Ӻ�������Ʈ�����Թ�", 3, L"�ü��", false, false);
	Major M26(L"�ΰ�����", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M27(L"��ü���⼳�������", 3, L"��ü������ͽǽ�", false, false);
	Major M28(L"S/Wǰ���������׽���", 3, L"", false, false);
	Major M29(L"��ǻ�ͺ���", 3, L"", false, false);
	Major M30(L"���ü����α׷���", 3, L"", false, false);
	Major M31(L"��ǻ�ͳ�Ʈ��ŷ", 3, L"", false, false);
	Major M32(L"����ǽ�", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M33(L"���̿������ͺм�Ư��", 3, L"", false, false);
	Major M34(L"���ü�κ���", 3, L"", false, false);
	Major M35(L"�繰���ͳ�", 3, L"�Ӻ�������Ʈ�����Թ�", false, false);
	Major M36(L"�ӽŷ���", 3, L"�ΰ�����", false, false);
	Major M37(L"�������ǻ��", 3, L"", false, false);
	Major M38(L"��ȣ�а���Ʈ��ũ����", 3, L"", false, false);
	Major M39(L"SW�����Ͻ���â��", 3, L"", false, false);
	Major M40(L"��ũ�������������̼�", 3, L"", false, false);
	Major M41(L"Ŭ������ǻ��", 3, L"", false, false);
	Major M42(L"�κ����α׷���", 3, L"", false, false);
	Major M43(L"���̿������ͺм��˰���", 3, L"", false, false);
	Major M44(L"��ť���ڵ�", 3, L"", false, false);
	Major M45(L"�����ͺм�", 3, L"", false, false);
	Major M46(L"��ǻ�Ͱ������ռ���1", 3, L"����SW������Ʈ", true, false);
	Major M47(L"��ǻ�Ͱ������ռ���2", 3, L"����SW��ǻ�Ͱ������ռ���1", true, false);
	Major M48(L"��������1", 1, L"", true, false);
	Major M49(L"��������2", 1, L"", true, false);
	Major M50(L"��������3", 1, L"", false, false);
	Major M51(L"Ŀ������丵", 3, L"", false, false);
	Major M52(L"������ĸ���������", 3, L"", false, false);
	Major M53(L"â��ĸ���������1", 3, L"", false, false);
	Major M54(L"â��ĸ���������2", 3, L"", false, false);
	Major M55(L"�����ȸ������������Ʈ1", 3, L"", false, false);
	Major M56(L"�����ȸ������������Ʈ2", 3, L"", false, false);

	// ��� ���� ��ü�� ���� ���͸� ����(Ž���� ���� �Լ��� �Ķ���ͷ� ����)
	vector<Major> majorList;
	majorList.push_back(M1);
	majorList.push_back(M2);
	majorList.push_back(M3);
	majorList.push_back(M4);
	majorList.push_back(M5);
	majorList.push_back(M6);
	majorList.push_back(M7);
	majorList.push_back(M8);
	majorList.push_back(M9);
	majorList.push_back(M10);
	majorList.push_back(M11);
	majorList.push_back(M12);
	majorList.push_back(M13);
	majorList.push_back(M14);
	majorList.push_back(M15);
	majorList.push_back(M16);
	majorList.push_back(M17);
	majorList.push_back(M18);
	majorList.push_back(M19);
	majorList.push_back(M20);
	majorList.push_back(M21);
	majorList.push_back(M22);
	majorList.push_back(M23);
	majorList.push_back(M24);
	majorList.push_back(M25);
	majorList.push_back(M26);
	majorList.push_back(M27);
	majorList.push_back(M28);
	majorList.push_back(M29);
	majorList.push_back(M30);
	majorList.push_back(M31);
	majorList.push_back(M32);
	majorList.push_back(M33);
	majorList.push_back(M34);
	majorList.push_back(M35);
	majorList.push_back(M36);
	majorList.push_back(M37);
	majorList.push_back(M38);
	majorList.push_back(M39);
	majorList.push_back(M40);
	majorList.push_back(M41);
	majorList.push_back(M42);
	majorList.push_back(M43);
	majorList.push_back(M44);
	majorList.push_back(M45);
	majorList.push_back(M46);
	majorList.push_back(M47);
	majorList.push_back(M48);
	majorList.push_back(M49);
	majorList.push_back(M50);
	majorList.push_back(M51);
	majorList.push_back(M52);
	majorList.push_back(M53);
	majorList.push_back(M54);
	majorList.push_back(M55);
	majorList.push_back(M56);

	vector<Major> freshman1 = { M1, M2 };
	vector<Major> freshman2 = { M3, M4, M5 };
	vector<Major> sophomore1 = { M6, M7, M8 };
	vector<Major> sophorore2 = { M9, M10, M11, M12 };
	vector<Major> junior1 = { M13, M14, M15, M16, M17, M18, M19 };
	vector<Major> junior2 = { M20, M21, M22, M23, M24, M25, M26 };
	vector<Major> senior1 = { M46, M27, M28, M29, M30, M31, M32, M33, M34, M35, M36 };
	vector<Major> senior2 = { M47, M37, M38, M39, M40, M41, M42, M43, M44, M45, M46, M47 };
	vector<Major> engineering = { M48, M49, M50, M51, M52, M53, M54, M55, M56 };

	vector<vector<Major>> tempInfo;

	tempInfo.push_back(freshman1); tempInfo.push_back(freshman2);
	tempInfo.push_back(sophomore1); tempInfo.push_back(sophorore2);
	tempInfo.push_back(junior1); tempInfo.push_back(junior2);
	tempInfo.push_back(senior1); tempInfo.push_back(senior2);
	tempInfo.push_back(engineering);


	// �ʼ�����
	Liberal L1("���ǻ�Ǻ���", 1, true, false);
	Liberal L2("�ұ����ΰ�", 2, true, false);
	Liberal L3("��������ۼ��׹�ǥ", 3, true, false);
	Liberal L4("�ھƿ͸��1", 1, true, false);
	Liberal L5("�ھƿ͸��2", 1, true, false);
	Liberal L6("EAS1", 3, true, false);
	Liberal L8("EAS2", 3, true, false);
	Liberal L9("�ҼȾ�Ʈ�������ʽʰ�������", 2, false, false);
	Liberal L10("�۷ι���Ʈ�������ʽʰ�������", 2, false, false);
	Liberal L11("��ũ���Ʈ�������ʽʰ�������", 2, false, false);

	// MSC
	Liberal L12("�������й׿���1", 3, true, false);
	Liberal L13("Ȯ���������", 3, true, false);
	Liberal L14("���м��������", 3, true, false);
	Liberal L15("�������й׿���2", 3, false, false);
	Liberal L16("���м���1", 3, false, false);
	Liberal L17("��ġ�ؼ��׽ǽ�", 3, false, false);
	Liberal L18("�������", 3, false, false);
	Liberal L19("�Ϲݹ����й׽���1", 4, false, false);
	Liberal L20("�Ϲݹ����й׽���2", 4, false, false);
	Liberal L21("�Ϲ�ȭ�й׽���1", 4, false, false);
	Liberal L22("�Ϲ�ȭ�й׽���2", 4, false, false);
	Liberal L23("�Ϲݻ����й׽���1", 4, false, false);
	Liberal L24("�Ϲݻ����й׽���2", 4, false, false);
	Liberal L25("�����а���", 3, false, false);
	Liberal L26("ȭ�а���", 3, false, false);
	Liberal L27("�����а���", 3, false, false);
	Liberal L28("����ȯ�����", 3, false, false);

	// �⺻�Ҿ�
	Liberal L29("���â����Ư��", 3, false, false);
	Liberal L30("���а���", 3, false, false);
	Liberal L31("��������", 3, false, false);
	Liberal L32("�������ȸ", 3, false, false);
	Liberal L33("���Ӱ����ѹ������ΰ�", 3, false, false);

	int year, semester;

	// ���� �Է�
	wifstream fin("input.txt"); // ������ ��ü������ ��� txt

	// ���� �Է� ����
	if (fin.fail()) {
		cerr << "������ �ҷ��� �� �����ϴ�." << endl;
		exit(100);
	}

	wstring line_m;		// wstring ������ �ӽ� ���� �б� ���� ���		
	vector <wstring> input_major; // ������ ���� ������� ��� ����

	vector<vector<Major>> majorInfo[3]; // Ž���� ���� ������� ���͸� ���� 2���� ���� ����
	vector<Major> output_major[3]; // ������ ���� ������� ��� ����
	vector<Major> replace_major[3]; // ��ü ���� ������� ��� ����

	fin >> year >> semester;
	while (getline(fin, line_m))	// wstring������ ������ �о�� �ؼ� �ٲ�
	{
		input_major.push_back(line_m);
	}

	// [1] ���� Ž�� �� ��õ���� ����Ʈ ����
	linearSearch(majorList, input_major);
	make2Dvector(majorList, tempInfo, majorInfo[0]);
	subjectExtraction(year, semester, majorInfo[0], input_major, output_major[0], replace_major[0]);

	// [2] ���� Ž�� �� ��õ���� ����Ʈ ����
	BinarySearch(majorList, input_major);
	make2Dvector(majorList, tempInfo, majorInfo[1]);
	subjectExtraction(year, semester, majorInfo[1], input_major, output_major[1], replace_major[1]);


	// [3] �Է� ���� ������ hashŽ���Ͽ� ��õ���� ����Ʈ ����
	// ��� ���� ��ü�� ���� �ؽ� ���̺� ����
	//vector<Major> majorHash[HASH_SIZE];
	//make_HT(majorHash, majorList);

	//set_Complete_Hash(majorHash, input_major);
	//make2Dvector(majorList, tempInfo, majorInfo[2]);
	//subjectExtraction(year, semester, majorInfo[2], input_major, output_major[2], replace_major[2]);

	//for (int i = 0; i < output_major[2].size(); i++) {
	//	wcout << output_major[2][i].getName() << endl;
	//}

	
	// ���� ���
	wofstream fout("output.txt"); // ������ ��ü������ ��� txt

	// ���� �Է� ����
	if (fout.fail()) {
		cerr << "������ �ҷ��� �� �����ϴ�." << endl;
		exit(100);
	}

	// ��� ��� Ȯ��([1])
	fout << "Recommend:" << endl;

	for (int i = 0; i < output_major[0].size(); i++) {
		fout << output_major[0][i].getName() << endl;
	}

	fout << endl << "Replaceable:" << endl;

	for (int i = 0; i < replace_major[0].size(); i++) {
		fout << replace_major[0][i].getName() << endl;
	}

	fout.close();
	

	return 0;
}