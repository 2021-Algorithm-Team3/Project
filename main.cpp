#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include "Lecture.h"
#include "MajorFunction.h"
#include "LiberalFunction.h"

#define HASH_SIZE 100
#define HASH_SIZE_2 50

using namespace std;

int main() {

	locale::global(locale("ko_KR.UTF-8"));
	setlocale(LC_ALL, "korean");

	// 전공
	Major M1(L"기초프로그래밍", 3, L"", false, false);
	Major M2(L"계산적사고법", 3, L"", true, false);
	Major M3(L"창의적공학설계", 3, L"", true, false);
	Major M4(L"이산구조", 3, L"", true, false);
	Major M5(L"심화프로그래밍", 3, L"기초프로그래밍", false, false);
	Major M6(L"객체지향언어와실습", 3, L"기초프로그래밍", false, false);
	Major M7(L"자료구조와실습", 3, L"기초프로그래밍", true, false);
	Major M8(L"컴퓨터구성", 3, L"이산구조", true, false);
	Major M9(L"웹프로그래밍", 3, L"객체지향언어와실습", false, false);
	Major M10(L"객체지향윈도우즈프로그래밍", 3, L"객체지향언어와실습", false, false);
	Major M11(L"프로그래밍언어개념", 3, L"기초프로그래밍", false, false);
	Major M12(L"시스템소프트웨어와실습", 3, L"자료구조와실습", true, false);
	Major M13(L"공개SW프로젝트", 3, L"창의적공학설계", true, false);
	Major M14(L"인간컴퓨터상호작용시스템", 3, L"자료구조와실습", false, false);
	Major M15(L"컴퓨터그래픽스입문", 3, L"자료구조와실습", false, false);
	Major M16(L"데이터베이스시스템", 3, L"자료구조와실습", false, false);
	Major M17(L"형식언어", 3, L"이산구조", false, false);
	Major M18(L"운영체제", 3, L"시스템소프트웨어와실습", false, false);
	Major M19(L"컴퓨터알고리즘과실습", 3, L"자료구조와실습", false, false);
	Major M20(L"소프트웨어공학개론", 3, L"객체지향언어와실습", false, false);
	Major M21(L"데이터통신입문", 3, L"기초프로그래밍", false, false);
	Major M22(L"데이터베이스프로그래밍", 3, L"자료구조와실습", false, false);
	Major M23(L"컴퓨터구조", 3, L"컴퓨터구성", false, false);
	Major M24(L"컴파일러구성", 3, L"형식언어", false, false);
	Major M25(L"임베디드소프트웨어입문", 3, L"운영체제", false, false);
	Major M26(L"인공지능", 3, L"자료구조와실습", false, false);
	Major M27(L"객체지향설계와패턴", 3, L"객체지향언어와실습", false, false);
	Major M28(L"S/W품질관리및테스팅", 3, L"", false, false);
	Major M29(L"컴퓨터보안", 3, L"", false, false);
	Major M30(L"동시성프로그래밍", 3, L"", false, false);
	Major M31(L"컴퓨터네트워킹", 3, L"", false, false);
	Major M32(L"현장실습", 3, L"자료구조와실습", false, false);
	Major M33(L"바이오빅데이터분석특론", 3, L"", false, false);
	Major M34(L"블록체인보안", 3, L"", false, false);
	Major M35(L"사물인터넷", 3, L"임베디드소프트웨어입문", false, false);
	Major M36(L"머신러닝", 3, L"인공지능", false, false);
	Major M37(L"모바일컴퓨팅", 3, L"", false, false);
	Major M38(L"암호학과네트워크보안", 3, L"", false, false);
	Major M39(L"SW비지니스와창업", 3, L"", false, false);
	Major M40(L"테크니컬프리젠테이션", 3, L"", false, false);
	Major M41(L"클라우드컴퓨팅", 3, L"", false, false);
	Major M42(L"로봇프로그래밍", 3, L"", false, false);
	Major M43(L"바이오빅데이터분석알고리즘", 3, L"", false, false);
	Major M44(L"시큐어코딩", 3, L"", false, false);
	Major M45(L"빅데이터분석", 3, L"", false, false);
	Major M46(L"컴퓨터공학종합설계1", 3, L"공개SW프로젝트", true, false);
	Major M47(L"컴퓨터공학종합설계2", 3, L"공개SW컴퓨터공학종합설계1", true, false);
	Major M48(L"개별연구1", 1, L"", true, false);
	Major M49(L"개별연구2", 1, L"", true, false);
	Major M50(L"개별연구3", 1, L"", false, false);
	Major M51(L"커리어멘토링", 3, L"", false, false);
	Major M52(L"다학제캡스톤디자인", 3, L"", false, false);
	Major M53(L"창업캡스톤디자인1", 3, L"", false, false);
	Major M54(L"기업사회맞춤형프로젝트1", 3, L"", false, false);
	Major M55(L"창업캡스톤디자인2", 3, L"", false, false);
	Major M56(L"기업사회맞춤형프로젝트2", 3, L"", false, false);

	// 모든 전공 객체를 담은 벡터를 생성(탐색에 쓰일 함수의 파라미터로 쓰임)
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
	vector<Major> sophomore2 = { M9, M10, M11, M12 };
	vector<Major> junior1 = { M13, M14, M15, M16, M17, M18, M19 };
	vector<Major> junior2 = { M20, M21, M22, M23, M24, M25, M26 };
	vector<Major> senior1 = { M46, M27, M28, M29, M30, M31, M32, M33, M34, M35, M36 };
	vector<Major> senior2 = { M47, M37, M38, M39, M40, M41, M42, M43, M44, M45, M46, M47 };
	vector<Major> engineering = { M48, M49, M50, M51, M52, M53, M54, M55, M56 };

	vector<vector<Major>> tempInfo;

	tempInfo.push_back(freshman1); tempInfo.push_back(freshman2);
	tempInfo.push_back(sophomore1); tempInfo.push_back(sophomore2);
	tempInfo.push_back(junior1); tempInfo.push_back(junior2);
	tempInfo.push_back(senior1); tempInfo.push_back(senior2);
	tempInfo.push_back(engineering);

	// 필수교양
	Liberal L1(L"나의삶나의비전", 1, true, false);
	Liberal L2(L"불교와인간", 2, true, false);
	Liberal L3(L"기술보고서작성및발표", 3, true, false);
	Liberal L4(L"자아와명상1", 1, true, false);
	Liberal L5(L"자아와명상2", 1, true, false);
	Liberal L6(L"EAS1", 3, true, false);
	Liberal L7(L"EAS2", 3, true, false);
	Liberal L8(L"소셜앙트레프레너십과리더십", 2, false, false);
	Liberal L9(L"글로벌앙트레프레너십과리더십", 2, false, false);
	Liberal L10(L"테크노앙트레프레너십과리더십", 2, false, false);

	// MSC
	Liberal L11(L"미적분학및연습1", 3, true, false);
	Liberal L12(L"확률및통계학", 3, true, false);
	Liberal L13(L"공학선형대수학", 3, true, false);
	Liberal L14(L"미적분학및연습2", 3, false, false);
	Liberal L15(L"공학수학1", 3, false, false);
	Liberal L16(L"수치해석및실습", 3, false, false);
	Liberal L17(L"산업수학", 3, false, false);
	Liberal L18(L"일반물리학및실험1", 4, false, false);
	Liberal L19(L"일반물리학및실험2", 4, false, false);
	Liberal L20(L"일반화학및실험1", 4, false, false);
	Liberal L21(L"일반화학및실험2", 4, false, false);
	Liberal L22(L"일반생물학및실험1", 4, false, false);
	Liberal L23(L"일반생물학및실험2", 4, false, false);
	Liberal L24(L"물리학개론", 3, false, false);
	Liberal L25(L"화학개론", 3, false, false);
	Liberal L26(L"생물학개론", 3, false, false);
	Liberal L27(L"지구환경과학", 3, false, false);

	// 기본소양
	Liberal L28(L"기술창조와특허", 3, false, false);
	Liberal L29(L"공학경제", 3, false, false);
	Liberal L30(L"공학법제", 3, false, false);
	Liberal L31(L"기술과사회", 3, false, false);
	Liberal L32(L"지속가능한발전과인간", 3, false, false);

	vector<Liberal> liberalList;
	liberalList.push_back(L1);
	liberalList.push_back(L2);
	liberalList.push_back(L3);
	liberalList.push_back(L4);
	liberalList.push_back(L5);
	liberalList.push_back(L6);
	liberalList.push_back(L7);
	liberalList.push_back(L8);
	liberalList.push_back(L9);
	liberalList.push_back(L10);
	liberalList.push_back(L11);
	liberalList.push_back(L12);
	liberalList.push_back(L13);
	liberalList.push_back(L14);
	liberalList.push_back(L15);
	liberalList.push_back(L16);
	liberalList.push_back(L17);
	liberalList.push_back(L18);
	liberalList.push_back(L19);
	liberalList.push_back(L20);
	liberalList.push_back(L21);
	liberalList.push_back(L22);
	liberalList.push_back(L23);
	liberalList.push_back(L24);
	liberalList.push_back(L25);
	liberalList.push_back(L26);
	liberalList.push_back(L27);
	liberalList.push_back(L28);
	liberalList.push_back(L29);
	liberalList.push_back(L30);
	liberalList.push_back(L31);
	liberalList.push_back(L32);

	int year, semester;
	// 파일 입력
	wifstream fin("input.txt"); // 수강한 전체과목이 담긴 txt

	// 파일 입력 에러
	if (fin.fail()) {
		cerr << L"파일을 불러올 수 없습니다." << endl;
		exit(100);
	}

	wstring line_m;		// wstring 형태의 임시 파일 읽기 변수 사용		
	vector <wstring> input_major; // 수강한 전공 과목들을 담는 벡터
	vector <wstring> input_liberal; // 수강한 교양 과목들을 담는 벡터

	vector<vector<Major>> majorInfo[3]; // 탐색을 통해 만들어진 벡터를 토대로 2차원 벡터 생성
	vector<Major> output_major[3]; // 수강할 전공 과목들을 담는 벡터
	vector<Major> replace_major[3]; // 대체 가능 과목들을 담는 벡터


	fin >> year >> semester;
	int flag = 0;

	while (getline(fin, line_m))	// wstring형으로 파일을 읽어야 해서 바꿈
	{
		if (line_m == L"") continue;
		else if (line_m == L"전공:") { flag = 1; continue; }
		else if (line_m == L"교양:") { flag = 2; continue; }
		if (flag == 1) {
			input_major.push_back(line_m);
		}
		else if (flag == 2) {
			input_liberal.push_back(line_m);
		}
	}

	// 전공
	// [1] 순차 탐색 후 추천과목 리스트 추출
	linearSearch(majorList, input_major);
	make2Dvector(majorList, tempInfo, majorInfo[0]);
	subjectExtraction(year, semester, majorInfo[0], input_major, output_major[0], replace_major[0]);

	// [2] 이진 탐색 후 추천과목 리스트 추출
	// BinarySearch(majorList, input_major);
	//make2Dvector(majorList, tempInfo, majorInfo[1]);
	//subjectExtraction(year, semester, majorInfo[1], input_major, output_major[1], replace_major[1]);

	// [3] 입력 받은 과목을 hash탐색하여 추천과목 리스트 추출
	// 모든 전공 객체를 담은 해쉬 테이블 생성
	//vector<Major*> majorHash[HASH_SIZE];
	//make_HT(majorHash, majorList);
	//set_Complete_Hash(majorHash, input_major);

	//make2Dvector(majorList, tempInfo, majorInfo[2]);
	//subjectExtraction(year, semester, majorInfo[2], input_major, output_major[2], replace_major[2]);


	// 교양
	vector<Liberal> liberalCommon, liberalCommon_cyber;
	vector<wstring> liberalNormal;
	vector<Liberal> liberalExperiment, liberalTheory;
	vector<Liberal> liberalMath_must, liberalMath;

	int n_common, n_normal, n_math;
	int n_science[2];

	// [1] 순차 탐색 후 추천과목 리스트 추출
	linearSearch(liberalList, input_liberal);
	extractCommon(liberalList, liberalCommon, liberalCommon_cyber, semester, year, n_common);
	extractMath(year, liberalList, liberalMath_must, liberalMath, n_math);
	extractScience(liberalList, liberalExperiment, liberalTheory, n_science);
	extractNormal(liberalList, liberalNormal, n_normal);

	//// [2] 이진 탐색 후 추천과목 리스트 추출
	//BinarySearch(liberalList, input_liberal);
	//extractScience(liberalList, liberalExperiment, liberalTheroy, n_science);
	//extractNormal(liberalList, liberalNormal, n_normal);
	//extractCommon(liberalList, liberalCommon, semester, year);
	//extrachMath(year, liberalList, liberalMath_must, liberalMath, n_math);

	//// [3] 입력 받은 과목을 hash탐색하여 추천과목 리스트 추출
	//// 모든 전공 객체를 담은 해쉬 테이블 생성
	//vector<Liberal*> liberalHash[HASH_SIZE_2];
	//make_HT(liberalHash, liberalList);
	//set_Complete_Hash(liberalHash, input_liberal);
	//extractScience(liberalList, liberalExperiment, liberalTheroy, n_science);
	//extractNormal(liberalList, liberalNormal, n_normal);
	//extractCommon(liberalList, liberalCommon, semester, year);
	//extrachMath(year, liberalList, liberalMath_must, liberalMath, n_math);


	// 파일 출력
	wofstream fout("output.txt"); // 수강한 전체과목이 담긴 txt

	// 파일 입력 에러
	if (fout.fail()) {
		cerr << L"파일을 불러올 수 없습니다." << endl;
		exit(100);
	}

	// 출력 결과 확인([1])
	fout << L"[전공]";

	fout << endl << L"> 추천" << endl;
	for (int i = 0; i < output_major[0].size(); i++) {
		fout << output_major[0][i].getName() << endl;
	}

	fout << endl << L"> 대체가능" << endl;
	for (int i = 0; i < replace_major[0].size(); i++) {
		fout << replace_major[0][i].getName() << endl;
	}


	fout << endl << L"----------------------------" << endl;
	fout << endl << L"[교양]" << endl;

	fout << L"> 공통교양" << endl;
	for (int i = 0; i < liberalCommon.size(); i++) {
		fout << liberalCommon[i].getName() << ' ';
	}
	
	if (n_common > 0) {
		fout << endl <<L"> 공통교양(리더십)" << endl;
		for (int i = 0; i < liberalCommon_cyber.size(); i++) {
			fout << liberalCommon_cyber[i].getName() << ' ';
		}
		fout << L"중 " << n_common << endl;
	}

	fout << endl << L"> 수학" << endl;
	fout << L"> 수학(필수)" << endl;
	for (int i = 0; i < liberalMath_must.size(); i++) {
		fout << liberalMath_must[i].getName() << ' ';
	}
	fout << endl;
	fout << L"> 수학(선택)" << endl;
	for (int i = 0; i < liberalMath.size(); i++) {
		fout << liberalMath[i].getName() << ' ';
	}
	if (n_math > 0)
		fout << L"중 " << n_math << endl;


	fout << endl << L"> 과학" << endl;
	fout << L"> 과학(실험)" << endl;
	for (int i = 0; i < liberalExperiment.size(); i++) {
		fout << liberalExperiment[i].getName() << ' ';
	}
	if(n_science[0]>0)
		fout << L"중 " << n_science[0] << endl;
	fout << L"> 과학(이론)" << endl;
	for (int i = 0; i < liberalTheory.size(); i++) {
		fout << liberalTheory[i].getName() << ' ';
	}
	if(n_science[1]>0)
		fout << L"중 " << n_science[1] << endl;

	fout << endl << L"> 기본소양" << endl;
	for (int i = 0; i < liberalNormal.size(); i++) {
		fout << liberalNormal[i] << ' ';
	}
	if (n_normal > 0)
		fout << L"중 " << n_normal << endl;

	fout.close();


	return 0;
}