/*
 * 파 일 명 : OneCard.h
 * 제 작 자 : 조성우
 * 파일목적 : OneCard 게임 구현에 필요한 데이터 타입을 정의하고 함수 선언
 * 제 작 일 : 2009.02.03
 * 선언함수 : 
 * 참    고 : 함수 선언에 대한 정의는 Cardlib.c를 참고하십시오. 
 *----------------------------------------------------------------------------------------------*/


/* Header files */
#include <stdio.h>
#include <conio.h>				// getch()
#include <stdlib.h>				// srand(), rand()
#include <windows.h>			// system(), Sleep()
#include <time.h>				// time()

#define FALSE 0
#define TRUE 1

#define MAXGET 15
#define CARDSIZE 54

/*--------------------------------------------ADT-----------------------------------------------*/

typedef enum status{			/* 카드의 기능을 정의 */
	general,
	jump, direction, replay,			// 순서대로 J, Q, K
	ace, nbr2,							// A: 벌카드 3장, 2: 벌카드 2장.
	seven,								// 문양 변경
	spadeAce,							// ♠A. 벌카드 3장, 조커방어
	rJoker,	bJoker						// 방어불능, 빨간조커: 7장, 까만조커 : 5장
}status;

typedef enum pattern{			/* 카드의 문양을 정의 */
	spade,
	diamond,
	heart,
	clover,
	joker
}pattern;

typedef struct Card{			/* 카드 ADT */
	unsigned cardcode;			// 카드 고유의 번호
	status ability;				// 특수 카드의 경우 능력치 설정
	pattern cardpattern;		// 문양
}Card;

typedef struct test{			/* 디버깅용 ADT */
	Card *you;
	Card *c1;
	Card *c2;
	Card *c3;
	Card *d;
	int *t;
}chk;



/*--------------------------------------------Fuctions-----------------------------------------*/

void	Location( unsigned , unsigned );			// gotoxy
void	statBar();
void	initialize(Card a[]);
void	shuffle(Card a[], int max);				// 카드셔플
void	userprint(const Card you[], int max);			// 유저 출력
void	com1print(int max);						// 컴퓨터 출력
void	com2print(int max);
void	com3print(int max);
void	GetDeckprint(int max);						// 먹는 카드(CardDeck) 출력.
void	PutDeckprint(Card top);					// 내는 카드 출력.
void	chkAll(const chk);
int	userAct(Card u[], int* umax, Card d[], int* dmax, char print[]);
void	statprn(char s[][30], int key);
/*----------------------------------------------------------------------------------------------*/