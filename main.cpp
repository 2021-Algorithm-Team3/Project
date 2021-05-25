#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Lecture.h"
using namespace std;

int main() {
	// 전공
	Major M1("기초프로그래밍", 3, "", true, false);
	Major M2("계산적사고법", 3, "", true, false);
	Major M3("창의적공학설계", 3, "", true, false);
	Major M4("이산구조", 3, "", true, false);
	Major M5("심화프로그래밍", 3, "기초프로그래밍", false, false);
	Major M6("객체지향언어와실습", 3, "기초프로그래밍", false, false);
	Major M7("자료구조와실습", 3, "기초프로그래밍", true, false);
	Major M11("컴퓨터구성", 3, "이산구조", true, false);
	Major M8("웹프로그래밍", 3, "객체지향언어와실습", false, false);
	Major M9("객체지향윈도우즈프로그래밍", 3, "객체지향언어와실습", false, false);
	Major M10("프로그래밍언어개념", 3, "기초프로그래밍", false, false);
	Major M12("시스템소프트웨어와실습", 3, "자료구조와실습", true, false);
	Major M13("공개SW프로젝트", 3, "창의적공학설계", true, false);
	Major M14("인간컴퓨터상호작용시스템", 3, "자료구조와실습", false, false);
	Major M15("컴퓨터그래픽스입문", 3, "자료구조와실습", false, false);
	Major M16("데이터베이스시스템", 3, "자료구조와실습", false, false);
	Major M17("형식언어", 3, "이산구조", false, false);
	Major M18("운영체제", 3, "시스템소프트웨어와실습", false, false);
	Major M20("컴퓨터알고리즘과실습", 3, "자료구조와실습", false, false);
	Major M21("소프트웨어공학개론", 3, "객체지향언어와실습", false, false);
	Major M22("데이터통신입문", 3, "기초프로그래밍", false, false);
	Major M23("데이터베이스프로그래밍", 3, "자료구조와실습", false, false);
	Major M24("컴퓨터구조", 3, "컴퓨터구성", false, false);
	Major M25("컴파일러구성", 3, "형식언어", false, false);
	Major M26("임베디드소프트웨어입문", 3, "운영체제", false, false);
	Major M27("인공지능", 3, "자료구조와실습", false, false);
	Major M28("객체지향설계와패턴", 3, "객체지향언어와실습", false, false);
	Major M29("S/W품질관리및테스팅", 3, "", false, false);
	Major M30("컴퓨터보안", 3, "", false, false);
	Major M31("컴퓨터네트워킹", 3, "", false, false);
	Major M32("현장실습", 3, "자료구조와실습", false, false);
	Major M33("바이오빅데이터분석특론", 3, "", false, false);
	Major M34("블록체인보인", 3, "", false, false);
	Major M35("사물인터넷", 3, "임베디드소프트웨어입문", false, false);
	Major M36("머신러닝", 3, "인공지능", false, false);
	Major M37("모바일컴퓨팅", 3, "", false, false);
	Major M38("암호학과네트워크보안", 3, "", false, false);
	Major M39("SW비지니스와창업", 3, "", false, false);
	Major M40("테크니컬프리젠테이션", 3, "", false, false);
	Major M41("클라우드컴퓨팅", 3, "", false, false);
	Major M42("로봇프로그래밍", 3, "", false, false);
	Major M43("바이오빅데이터분석알고리즘", 3, "", false, false);
	Major M44("시큐어코딩", 3, "", false, false);
	Major M45("빅데이터분석", 3, "", false, false);
	Major M46("컴퓨터공학종합설계1", 3, "공개SW프로젝트", true, false);
	Major M47("컴퓨터공학종합설계2", 3, "공개SW컴퓨터공학종합설계1", true, false);
	Major M48("개별연구1", 1, "", true, false);
	Major M49("개별연구2", 1, "", true, false);
	Major M50("개별연구3", 1, "", false, false);
	Major M51("커리어멘토링", 3, "", false, false);
	Major M52("다학제캡스톤디자인", 3, "", false, false);
	Major M53("창업캡스톤디자인1", 3, "", false, false);
	Major M54("창업캡스톤디자인2", 3, "", false, false);
	Major M55("기업사회맞춤형프로젝트1", 3, "", false, false);
	Major M56("기업사회맞춤형프로젝트2", 3, "", false, false);

	// 필수교양
	Liberal L1("나의삶나의비전", 1, true, false);
	Liberal L2("불교와인간", 2, true, false);
	Liberal L3("기술보고서작성및발표", 3, true, false);
	Liberal L4("자아와명상1", 1, true, false);
	Liberal L5("자아와명상2", 1, true, false);
	Liberal L6("EAS1", 3, true, false);
	Liberal L8("EAS2", 3, true, false);
	Liberal L9("소셜앙트레프레너십과리더십", 2, false, false);
	Liberal L10("글로벌앙트레프레너십과리더십", 2, false, false);
	Liberal L11("테크노앙트레프레너십과리더십", 2, false, false);

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
	ifstream fmajor("input_major.txt"); // 수강한 전공과목이 담긴 txt
	ifstream fliberal("input_liberal.txt"); // 수강한 교양과목이 담긴 txt

	// 파일 입력 에러
	if (fmajor.fail()) {
		cerr << "파일을 불러올 수 없습니다." << endl;
	}
	if (fliberal.fail()) {
		cerr << "파일을 불러올 수 없습니다." << endl;
	}

	string line;

	vector <string> input_major; // 수강한 전공 과목들을 담는 벡터
	vector <string> input_liberal; // 수강한 교양 과목들을 담는 벡터

	while (fmajor.peek() != EOF) {
		getline(fmajor, line);
		input_major.push_back(line);
	}

	while (fliberal.peek() != EOF) {
		getline(fliberal, line);
		input_liberal.push_back(line);
	}

	// test print
	cout << "전공:" << endl;
	for (int i = 0; i < input_major.size(); i++)
		cout << input_major[i] << endl;

	cout << "교양: " << endl;
	for (int i = 0; i < input_liberal.size(); i++)
		cout << input_liberal[i]<<endl;

	return 0;
}