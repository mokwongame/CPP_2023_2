// MyMovieInfo.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 영화 정보 저장 및 검색
// 클래스명: MyMovieInfo
// 10개의 영화 데이터를 저장: 영화명, 개봉연도, 장르, 평점, 러닝타임,출연진, 감독 -> 필요한 정보는 다음 영화(https://movie.daum.net) 검색
// 영화 데이터용 클래스: MovieData
// 데이터는 vector<MovieData>로 저장
// 검색 기능: 최고 평점, 출연진, 감독
// 영화 정보 출력: 모든 영화 데이터의 모든 항목을 순서대로 출력

#include <iostream>
#include "MyMovieInfo.h"

int main()
{
	using namespace std;
	MyMovieInfo myMovieInfo; // MyMovieInfo는 클래스(설계도) 이름, myMovieInfo는 인스턴스(실체) 이름

	cout << "Hello World!\n";
}
