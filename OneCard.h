/*
 * �� �� �� : OneCard.h
 * �� �� �� : ������
 * ���ϸ��� : OneCard ���� ������ �ʿ��� ������ Ÿ���� �����ϰ� �Լ� ����
 * �� �� �� : 2009.02.03
 * �����Լ� : 
 * ��    �� : �Լ� ���� ���� ���Ǵ� Cardlib.c�� �����Ͻʽÿ�. 
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

typedef enum status{			/* ī���� ����� ���� */
	general,
	jump, direction, replay,			// ������� J, Q, K
	ace, nbr2,							// A: ��ī�� 3��, 2: ��ī�� 2��.
	seven,								// ���� ����
	spadeAce,							// ��A. ��ī�� 3��, ��Ŀ���
	rJoker,	bJoker						// ���Ҵ�, ������Ŀ: 7��, ���Ŀ : 5��
}status;

typedef enum pattern{			/* ī���� ������ ���� */
	spade,
	diamond,
	heart,
	clover,
	joker
}pattern;

typedef struct Card{			/* ī�� ADT */
	unsigned cardcode;			// ī�� ������ ��ȣ
	status ability;				// Ư�� ī���� ��� �ɷ�ġ ����
	pattern cardpattern;		// ����
}Card;

typedef struct test{			/* ������ ADT */
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
void	shuffle(Card a[], int max);				// ī�����
void	userprint(const Card you[], int max);			// ���� ���
void	com1print(int max);						// ��ǻ�� ���
void	com2print(int max);
void	com3print(int max);
void	GetDeckprint(int max);						// �Դ� ī��(CardDeck) ���.
void	PutDeckprint(Card top);					// ���� ī�� ���.
void	chkAll(const chk);
int	userAct(Card u[], int* umax, Card d[], int* dmax, char print[]);
void	statprn(char s[][30], int key);
/*----------------------------------------------------------------------------------------------*/