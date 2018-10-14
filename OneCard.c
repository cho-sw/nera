#include "OneCard.h"

int main(void){
	Card	Deck[CARDSIZE];
	Card	Player[MAXGET];
	Card	Com1[MAXGET];
	Card	Com2[MAXGET];
	Card	Com3[MAXGET];
	char	stat[6][30]={0,};
	int		statkey=0;
	chk		currentData;

	
	int		i;


	/*
	top[0] : the number of player cards
	top[1] : com1
	top[2] : com2
	top[3] : com3
	top[4] : Deck
	���� : ī�� ������ �ǹ��ϴ� ������,
	�迭 �������δ� top[4]-1�� ����ϴ� ������ ���.
	*/
	int		top[5] = {0,0,0,0,CARDSIZE};
	
	currentData.you = Player;
	currentData.c1 = Com1;
	currentData.c2 = Com2;
	currentData.c3 = Com3;
	currentData.d = Deck;
	currentData.t = top;

	initialize(Deck);				// ī�忡 ������ �ֱ�
	
	shuffle(Deck, CARDSIZE);		// ī�� ����
	top[4]--;
	
	for(i=0; i<5; i++){
		memmove(&Player[top[0]], &Deck[top[4]], sizeof(Card));
		top[0]++;
		memset(&Deck[top[4]], 0, sizeof(Card));
		top[4]--;
	}
	for(i=0; i<5; i++){
		memmove(&Com1[top[1]], &Deck[top[4]], sizeof(Card));
		top[1]++;
		memset(&Deck[top[4]], 0, sizeof(Card));
		top[4]--;
	}
	for(i=0; i<5; i++){
		memmove(&Com2[top[2]], &Deck[top[4]], sizeof(Card));
		top[2]++;
		memset(&Deck[top[4]], 0, sizeof(Card));
		top[4]--;
	}
	
	for(i=0; i<5; i++){
		memmove(&Com3[top[3]], &Deck[top[4]], sizeof(Card));
		top[3]++;
		memset(&Deck[top[4]], 0, sizeof(Card));
		top[4]--;
	}

	top[4]++;
		
	
	while(1){
		com1print(top[1]);
		com2print(top[2]);
		GetDeckprint(top[4]);
		PutDeckprint(Deck[top[4]-1]);		// �ִ� �迭 ������ �翬�� top[4]-1�̴�.
		com3print(top[3]);
		statBar();
		userprint(Player, top[0]);		
		while(userAct(Player, &top[0], Deck, &top[4], stat[statkey])){;}
		statprn(stat, statkey);

	}
	getch();
	return 0;
}