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
	Major M1(L"�������α׷���", 3, L"", true, false);	// L"~"�� ���·� ���
	Major M2(L"���������", 3, L"", true, false);
	Major M3(L"â�������м���", 3, L"", true, false);
	Major M4(L"�̻걸��", 3, L"", true, false);
	Major M5(L"��ȭ���α׷���", 3, L"�������α׷���", false, false);
	Major M6(L"��ü������ͽǽ�", 3, L"�������α׷���", false, false);
	Major M7(L"�ڷᱸ���ͽǽ�", 3, L"�������α׷���", true, false);
	Major M11(L"��ǻ�ͱ���", 3, L"�̻걸��", true, false);
	Major M8(L"�����α׷���", 3, L"��ü������ͽǽ�", false, false);
	Major M9(L"��ü���������������α׷���", 3, L"��ü������ͽǽ�", false, false);
	Major M10(L"���α׷��־���", 3, L"�������α׷���", false, false);
	Major M12(L"�ý��ۼ���Ʈ����ͽǽ�", 3, L"�ڷᱸ���ͽǽ�", true, false);
	Major M13(L"����SW������Ʈ", 3, L"â�������м���", true, false);
	Major M14(L"�ΰ���ǻ�ͻ�ȣ�ۿ�ý���", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M15(L"��ǻ�ͱ׷��Ƚ��Թ�", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M16(L"�����ͺ��̽��ý���", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M17(L"���ľ��", 3, L"�̻걸��", false, false);
	Major M18(L"�ü��", 3, L"�ý��ۼ���Ʈ����ͽǽ�", false, false);
	Major M20(L"��ǻ�;˰�����ǽ�", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M21(L"����Ʈ������а���", 3, L"��ü������ͽǽ�", false, false);
	Major M22(L"����������Թ�", 3, L"�������α׷���", false, false);
	Major M23(L"�����ͺ��̽����α׷���", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M24(L"��ǻ�ͱ���", 3, L"��ǻ�ͱ���", false, false);
	Major M25(L"�����Ϸ�����", 3, L"���ľ��", false, false);
	Major M26(L"�Ӻ�������Ʈ�����Թ�", 3, L"�ü��", false, false);
	Major M27(L"�ΰ�����", 3, L"�ڷᱸ���ͽǽ�", false, false);
	Major M28(L"��ü���⼳�������", 3, L"��ü������ͽǽ�", false, false);
	Major M29(L"S/Wǰ���������׽���", 3, L"", false, false);
	Major M30(L"��ǻ�ͺ���", 3, L"", false, false);
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
	majorList.push_back(M11);
	majorList.push_back(M8);
	majorList.push_back(M9);
	majorList.push_back(M10);
	majorList.push_back(M12);
	majorList.push_back(M13);
	majorList.push_back(M14);
	majorList.push_back(M15);
	majorList.push_back(M16);
	majorList.push_back(M17);
	majorList.push_back(M18);
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

	//��� ���� ��ü�� ���� �ؽ� ���̺� ����
	vector<Major> majorHash[HASH_SIZE];
	make_HT(majorHash, majorList);

	//for (int i = 0; i < 100; i++) {
	//	wcout << majorHash[i].at(0).getName() << "\n";
	//}

	// �ʼ�����
	/*Liberal L1("���ǻ�Ǻ���", 1, true, false);
	Liberal L2("�ұ����ΰ�", 2, true, false);
	Liberal L3("��������ۼ��׹�ǥ", 3, true, false);
	Liberal L4("�ھƿ͸��1", 1, true, false);
	Liberal L5("�ھƿ͸��2", 1, true, false);
	Liberal L6("EAS1", 3, true, false);
	Liberal L8("EAS2", 3, true, false);
	Liberal L9("�ҼȾ�Ʈ�������ʽʰ�������", 2, false, false);
	Liberal L10("�۷ι���Ʈ�������ʽʰ�������", 2, false, false);
	Liberal L11("��ũ���Ʈ�������ʽʰ�������", 2, false, false);*/

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

	// ���� �Է�
	wifstream fmajor("input_major.txt"); // ������ ���������� ��� txt
	//ifstream fliberal("input_liberal.txt"); // ������ ��������� ��� txt

	// ���� �Է� ����
	if (fmajor.fail()) {
		cerr << "������ �ҷ��� �� �����ϴ�." << endl;
	}
	//if (fliberal.fail()) {
	//	cerr << "������ �ҷ��� �� �����ϴ�." << endl;
	//}

	//string line;

	wstring line_m;		// wstring ������ �ӽ� ���� �б� ���� ���
	//string line_l;		

	vector <wstring> input_major; // ������ ���� ������� ��� ����
	//vector <string> input_liberal; // ������ ���� ������� ��� ����

	//while (fmajor.peek() != EOF) {
	//	getline(fmajor, line);
	//	input_major.push_back(line);
	//}

	while (getline(fmajor, line_m))	// wstring������ ������ �о�� �ؼ� �ٲ�
	{
		input_major.push_back(line_m);
	}

	//while (fliberal.peek() != EOF) {
	//	getline(fliberal, line_l);
	//	input_liberal.push_back(line_l);
	//}

	// ���� Ž�� �� test print����
	//linearSearch(majorList, input_major);
	//for (int i = 0; i < majorList.size(); i++)
	//{
	//	if (majorList[i].getCompleted() == true)		// ���� ���� ���
	//		wcout << majorList[i].getName() << endl;
	//}

	// ���� Ž�� �� test print����
	//BinarySearch(majorList, input_major);
	//for (int i = 0; i < majorList.size(); i++)
	//{
	//	if (majorList[i].getCompleted() == true)		// ���� ���� ���
	//		wcout << majorList[i].getName() << endl;
	//}

	//�Է� ���� ������ hashŽ���Ͽ� complete 1�� ����
	set_Complete_Hash(majorHash, input_major);
	vector<Major>::iterator iter;
	for (int i = 0; i < HASH_SIZE; i++)
	{
		if (majorHash[i].size() > 0) {
			wcout << majorHash[i].size() << "\n";
			for (int j = 0; j < majorHash[i].size(); j++) {
				//if (majorHash[i].at(j).getCompleted())
					wcout << majorHash[i].at(j).getName() << "\n";
			}
		}
	}
	

	// test print
	wcout << L"����:" << endl;
	for (int i = 0; i < input_major.size(); i++)
		wcout << input_major[i] << endl;

	//cout << "����: " << endl;
	//for (int i = 0; i < input_liberal.size(); i++)
	//	cout << input_liberal[i] << endl;

	return 0;
}