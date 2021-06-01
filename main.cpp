#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include "Lecture.h"
#include "MajorFunction.h"

using namespace std;

int main() {

	// 한글 유니코드 사용을 위해 wstring을 사용
	// cin -> wcin, cout -> wcout 사용
	locale::global(locale("ko_KR.UTF-8"));		

	// 전공
	Major M1(L"기초프로그래밍", 3, L"", true, false);	// L"~"의 형태로 사용
	Major M2(L"계산적사고법", 3, L"", true, false);
	Major M3(L"창의적공학설계", 3, L"", true, false);
	Major M4(L"이산구조", 3, L"", true, false);
	Major M5(L"심화프로그래밍", 3, L"기초프로그래밍", false, false);
	Major M6(L"객체지향언어와실습", 3, L"기초프로그래밍", false, false);
	Major M7(L"자료구조와실습", 3, L"기초프로그래밍", true, false);
	Major M11(L"컴퓨터구성", 3, L"이산구조", true, false);
	Major M8(L"웹프로그래밍", 3, L"객체지향언어와실습", false, false);
	Major M9(L"객체지향윈도우즈프로그래밍", 3, L"객체지향언어와실습", false, false);
	Major M10(L"프로그래밍언어개념", 3, L"기초프로그래밍", false, false);
	Major M12(L"시스템소프트웨어와실습", 3, L"자료구조와실습", true, false);
	Major M13(L"공개SW프로젝트", 3, L"창의적공학설계", true, false);
	Major M14(L"인간컴퓨터상호작용시스템", 3, L"자료구조와실습", false, false);
	Major M15(L"컴퓨터그래픽스입문", 3, L"자료구조와실습", false, false);
	Major M16(L"데이터베이스시스템", 3, L"자료구조와실습", false, false);
	Major M17(L"형식언어", 3, L"이산구조", false, false);
	Major M18(L"운영체제", 3, L"시스템소프트웨어와실습", false, false);
	Major M20(L"컴퓨터알고리즘과실습", 3, L"자료구조와실습", false, false);
	Major M21(L"소프트웨어공학개론", 3, L"객체지향언어와실습", false, false);
	Major M22(L"데이터통신입문", 3, L"기초프로그래밍", false, false);
	Major M23(L"데이터베이스프로그래밍", 3, L"자료구조와실습", false, false);
	Major M24(L"컴퓨터구조", 3, L"컴퓨터구성", false, false);
	Major M25(L"컴파일러구성", 3, L"형식언어", false, false);
	Major M26(L"임베디드소프트웨어입문", 3, L"운영체제", false, false);
	Major M27(L"인공지능", 3, L"자료구조와실습", false, false);
	Major M28(L"객체지향설계와패턴", 3, L"객체지향언어와실습", false, false);
	Major M29(L"S/W품질관리및테스팅", 3, L"", false, false);
	Major M30(L"컴퓨터보안", 3, L"", false, false);
	Major M31(L"컴퓨터네트워킹", 3, L"", false, false);
	Major M32(L"현장실습", 3, L"자료구조와실습", false, false);
	Major M33(L"바이오빅데이터분석특론", 3, L"", false, false);
	Major M34(L"블록체인보인", 3, L"", false, false);
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
	Major M54(L"창업캡스톤디자인2", 3, L"", false, false);
	Major M55(L"기업사회맞춤형프로젝트1", 3, L"", false, false);
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

	// 필수교양
	/*Liberal L1("나의삶나의비전", 1, true, false);
	Liberal L2("불교와인간", 2, true, false);
	Liberal L3("기술보고서작성및발표", 3, true, false);
	Liberal L4("자아와명상1", 1, true, false);
	Liberal L5("자아와명상2", 1, true, false);
	Liberal L6("EAS1", 3, true, false);
	Liberal L8("EAS2", 3, true, false);
	Liberal L9("소셜앙트레프레너십과리더십", 2, false, false);
	Liberal L10("글로벌앙트레프레너십과리더십", 2, false, false);
	Liberal L11("테크노앙트레프레너십과리더십", 2, false, false);*/

	// MSC
	Liberal L12("미적분학및연습1", 3, true, false);
	Liberal L13("확률및통계학", 3, true, false);
	Liberal L14("공학선형대수학", 3, true, false);
	Liberal L15("미적분학및연습2", 3, false, false);
	Liberal L16("공학수학1", 3, false, false);
	Liberal L17("수치해석및실습", 3, false, false);
	Liberal L18("산업수학", 3, false, false);
	Liberal L19("일반물리학및실험1", 4, false, false);
	Liberal L20("일반물리학및실험2", 4, false, false);
	Liberal L21("일반화학및실험1", 4, false, false);
	Liberal L22("일반화학및실험2", 4, false, false);
	Liberal L23("일반생물학및실험1", 4, false, false);
	Liberal L24("일반생물학및실험2", 4, false, false);
	Liberal L25("물리학개론", 3, false, false);
	Liberal L26("화학개론", 3, false, false);
	Liberal L27("생물학개론", 3, false, false);
	Liberal L28("지구환경과학", 3, false, false);

	// 기본소양
	Liberal L29("기술창조와특허", 3, false, false);
	Liberal L30("공학경제", 3, false, false);
	Liberal L31("공학윤리", 3, false, false);
	Liberal L32("기술과사회", 3, false, false);
	Liberal L33("지속가능한발전과인간", 3, false, false);

	// 파일 입력
	wifstream fmajor("input_major.txt"); // 수강한 전공과목이 담긴 txt
	//ifstream fliberal("input_liberal.txt"); // 수강한 교양과목이 담긴 txt

	// 파일 입력 에러
	if (fmajor.fail()) {
		cerr << "파일을 불러올 수 없습니다." << endl;
	}
	//if (fliberal.fail()) {
	//	cerr << "파일을 불러올 수 없습니다." << endl;
	//}

	//string line;

	wstring line_m;		// wstring 형태의 임시 파일 읽기 변수 사용
	//string line_l;		

	vector <wstring> input_major; // 수강한 전공 과목들을 담는 벡터
	//vector <string> input_liberal; // 수강한 교양 과목들을 담는 벡터

	//while (fmajor.peek() != EOF) {
	//	getline(fmajor, line);
	//	input_major.push_back(line);
	//}

	while (getline(fmajor, line_m))	// wstring형으로 파일을 읽어야 해서 바꿈
	{
		input_major.push_back(line_m);
	}

	//while (fliberal.peek() != EOF) {
	//	getline(fliberal, line_l);
	//	input_liberal.push_back(line_l);
	//}

	// 순차 탐색 후 test print까지
	//linearSearch(majorList, input_major);
	//for (int i = 0; i < majorList.size(); i++)
	//{
	//	if (majorList[i].getCompleted() == true)		// 들은 과목만 출력
	//		wcout << majorList[i].getName() << endl;
	//}

	// 이진 탐색 후 test print까지
	//BinarySearch(majorList, input_major);
	//for (int i = 0; i < majorList.size(); i++)
	//{
	//	if (majorList[i].getCompleted() == true)		// 들은 과목만 출력
	//		wcout << majorList[i].getName() << endl;
	//}

	// test print
	wcout << L"전공:" << endl;
	for (int i = 0; i < input_major.size(); i++)
		wcout << input_major[i] << endl;

	//cout << "교양: " << endl;
	//for (int i = 0; i < input_liberal.size(); i++)
	//	cout << input_liberal[i] << endl;

	return 0;
}