#include "OneCard.h"
/*----------------------------------------------------------------------------------------------
* 함    수 : void userprint(Card you[])
* 목    적 : 플레이어의 카드를 하단에 출력.
* 참    고 : 예시 출력
*  5.♠─┐
*    │ A│여기서 5.는 index 변수가 나타냅니다.
*    └─┘나머지는 Location 위치를 잡기 위한 변수들.
*   또한, 이 CardPrint.c는 별로 어려운 알고리즘이 없으며,
*   단순 출력을 위한 함수임.
*----------------------------------------------------------------------------------------------*/
void userprint(const Card you[], int max){
	int				cnt=0, cvalue=0, line=0, index=1;
	register int	n=0;

	Location( 2, 18 );	puts("USER");
	
	while(n != max){
		Location( 1+cvalue, 19+line );
		printf("%2d.", index++);
		
		switch(you[n].cardpattern){
		case spade:
			puts("♠─┐"); break;
		case diamond:
			puts("◆─┐"); break;
		case heart:
			puts("♥─┐"); break;
		case clover:
			puts("♣─┐"); break;
		default:
			puts("┌JOKE");
		}
		Location( 4+cvalue, 20+line );
		if(you[n].cardcode>10 || you[n].cardcode == 1){
			switch(you[n].cardcode){
			case 1:
				puts("│ A│"); break;
			case 11:
				puts("│ J│"); break;
			case 12:
				puts("│ Q│"); break;
			case 13:
				puts("│ K│"); break;
			case 512:
				puts("│BL│"); break;
			default:
				puts("│RD│");
			}
		}
		else
			printf("│%2d│", you[n].cardcode);
		Location( 4+cvalue, 21+line );
		puts("└─┘");
		n++;
		cvalue += 10;
		if(!(n%8)){
			cvalue = 0;
			line += 3;
		}
	}
}
/*----------------------------------------------------------------------------------------------
* 함    수 : void com1print(int max)
* 목    적 : com1의 카드를 하단에 출력.
*----------------------------------------------------------------------------------------------*/
void com1print(int max){
	
	system("cls");
	puts("Computer1");
	printf("Rest : %2d", max);
	
	switch(max){
	case 15:
		Location(52, 1); puts("■");
		Location(52, 2); puts("■");
		Location(52, 3); puts("■");
		Location(52, 4); puts("■");
	case 14:
		Location(50, 1); puts("□");
		Location(50, 2); puts("□");
		Location(50, 3); puts("□");
		Location(50, 4); puts("□");		
	case 13:
		Location(48, 1); puts("■");
		Location(48, 2); puts("■");
		Location(48, 3); puts("■");
		Location(48, 4); puts("■");
	case 12:
		Location(46, 1); puts("□");
		Location(46, 2); puts("□");
		Location(46, 3); puts("□");
		Location(46, 4); puts("□");
	case 11:
		Location(44, 1); puts("■");
		Location(44, 2); puts("■");
		Location(44, 3); puts("■");
		Location(44, 4); puts("■");
	case 10:
		Location(42, 1); puts("□");
		Location(42, 2); puts("□");
		Location(42, 3); puts("□");
		Location(42, 4); puts("□");
	case 9:
		Location(40, 1); puts("■");
		Location(40, 2); puts("■");
		Location(40, 3); puts("■");
		Location(40, 4); puts("■");
	case 8:
		Location(38, 1); puts("□");
		Location(38, 2); puts("□");
		Location(38, 3); puts("□");
		Location(38, 4); puts("□");
	case 7:
		Location(36, 1); puts("■");
		Location(36, 2); puts("■");
		Location(36, 3); puts("■");
		Location(36, 4); puts("■");
	case 6:
		Location(34, 1); puts("□");
		Location(34, 2); puts("□");
		Location(34, 3); puts("□");
		Location(34, 4); puts("□");
	case 5:
		Location(32, 1); puts("■");
		Location(32, 2); puts("■");
		Location(32, 3); puts("■");
		Location(32, 4); puts("■");
	case 4:
		Location(30, 1); puts("□");
		Location(30, 2); puts("□");
		Location(30, 3); puts("□");
		Location(30, 4); puts("□");
	case 3:
		Location(28, 1); puts("■");
		Location(28, 2); puts("■");
		Location(28, 3); puts("■");
		Location(28, 4); puts("■");
	case 2:
		Location(26, 1); puts("□");
		Location(26, 2); puts("□");
		Location(26, 3); puts("□");
		Location(26, 4); puts("□");
	case 1:
		Location(20, 1); puts("■■■");
		Location(20, 2); puts("■■■");
		Location(20, 3); puts("■■■");
		Location(20, 4); puts("■■■"); break;
	default:
		Location(30, 2); puts("Hoola!");
	}
	
}
/*----------------------------------------------------------------------------------------------
* 함    수 : void com2print(Card com[], int max)
*----------------------------------------------------------------------------------------------*/
void com2print(int max){

	switch(max){
	case 15:
	case 14:
	case 13:
	case 12:
	case 11:
	case 10:
	case 9:
	case 8:
	case 7:
	case 6:
	case 5:
	case 4:
		Location( 11, 7 ); puts("│");
		Location( 11, 8 ); puts("│");
		Location( 11, 9 ); puts("│");
		Location( 11, 10 ); puts("│");
		Location( 5, 11 ); puts("───┘");
	case 3:
		Location( 9, 7 ); puts("■");
		Location( 9, 8 ); puts("■");
		Location( 9, 9 ); puts("■");
		Location( 5, 10 ); puts("■■■");
	case 2:
		Location( 7, 6 ); puts("□");
		Location( 7, 7 ); puts("□");
		Location( 7, 8 ); puts("□");
		Location( 3, 9 ); puts("□□□");
	case 1:
		Location( 1, 5 ); puts("■■■\n■■■\n■■■\n■■■\n"); break;
	default:
		Location( 1, 12 ); puts("ㅉㅉㅉ"); break;
	}
	Location(1, 12); printf("Rest : %2d\n", max);
	puts("Computer2");
}
/*----------------------------------------------------------------------------------------------
* 함    수 : void com3print(int max)
*----------------------------------------------------------------------------------------------*/
void com3print(int max){
	Location(59, 8); printf("Rest : %2d\n", max);
	switch(max){
	case 15:
	case 14:
	case 13:
	case 12:
	case 11:
	case 10:
	case 9:
	case 8:
	case 7:
	case 6:
	case 5:
	case 4:
		Location( 69, 3 ); puts("│");
		Location( 69, 4 ); puts("│");
		Location( 69, 5 ); puts("│");
		Location( 69, 6 ); puts("│");
		Location( 63, 7 ); puts("───┘");
	case 3:
		Location( 67, 3 ); puts("■");
		Location( 67, 4 ); puts("■");
		Location( 67, 5 ); puts("■");
		Location( 63, 6 ); puts("■■■");
	case 2:
		Location( 65, 2 ); puts("□");
		Location( 65, 3 ); puts("□");
		Location( 65, 4 ); puts("□");
		Location( 61, 5 ); puts("□□□");
	case 1:
		Location(59, 1); puts("■■■");
		Location(59, 2); puts("■■■");
		Location(59, 3); puts("■■■");
		Location(59, 4); puts("■■■"); break;
	default:
		Location(59, 7); puts("ㅅㄱㅇ"); break;
	}
	Location(59, 9);	puts("Computer3");
}
/*----------------------------------------------------------------------------------------------
* 함    수 : unsigned GetDeckprint(int max)
* 목    적 : 먹는 카드 무더기를 중앙에 출력.
* 리 턴 값 : 남은 카드 장수(Rest).
*----------------------------------------------------------------------------------------------*/
void GetDeckprint(int max){

	Location(20, 8); printf("Rest:%2d", max);
	Location(20, 9);
	if(max){
		if(max>1){
			puts("■■■");
			Location(20, 10); puts("■■■");
			Location(20, 11); puts("■■■");
			Location(20, 12); puts("■■■");
		}
		Location(26, 9); puts("│");
		Location(26, 10); puts("│");
		Location(26, 11); puts("│");
		Location(26, 12); puts("│");
		Location(20, 13); puts("───┘");
	}
	else
		puts("Empty!");
}
/*----------------------------------------------------------------------------------------------
* 함    수 : void PutDeckprint(Card top)
* 목    적 : 내는 카드 무더기를 중앙에 출력.
*----------------------------------------------------------------------------------------------*/
void PutDeckprint(Card top){
	
	Location(28, 9); puts("┌──┐");
	Location(28, 10); printf("│");

	switch(top.cardpattern){
	case spade: printf(" ♠ "); break;
	case diamond: printf(" ◆ "); break;
	case heart: printf(" ♥ "); break;
	case clover: printf(" ♣ "); break;
	default: printf(" JK "); break;
	}
	puts("│");
	Location(28, 11); printf("│");

	switch(top.cardcode){
	case 512: printf(" BL "); break;
	case 1024: printf(" RD "); break;
	case 13: printf(" K  "); break;
	case 12: printf(" Q  "); break;
	case 11: printf(" J  "); break;
	case 1: printf(" A  "); break;
	default: printf(" %2d ", top.cardcode);
	}

	puts("│");
	Location(28, 12); puts("│    │");
	Location(28, 13); puts("└──┘");
}
/*----------------------------------------------------------------------------------------------
* 함    수 : statBar()
* 목    적 : 상황판을 출력.
*----------------------------------------------------------------------------------------------*/
void statBar(){
	Location(36, 10);
	printf("┌────────────────────┐");
	Location(36, 11);
	printf("│　　　　　　　　　　　　　　　　　　　　│");
	Location(36,12);
	printf("│　　　　　　　　　　　　　　　　　　　　│");
	Location(36,13);
	printf("│　　　　　　　　　　　　　　　　　　　　│");
	Location(36,14);
	printf("│　　　　　　　　　　　　　　　　　　　　│");
	Location(36,15);
	printf("│　　　　　　　　　　　　　　　　　　　　│");
	Location(36,16);
	printf("│　　　　　　　　　　　　　　　　　　　　│");
	Location(36,17);
	printf("└────────────────────┘");
}
/*----------------------------------------------------------------------------------------------
* 함    수 : statprn(char **s, int key)
* 목    적 : 상황판을 출력.
*----------------------------------------------------------------------------------------------*/
void statprn(char s[][30], int key){
	int y=11;
	int i;

	for(i=0; i<6; i++){
		if(key>=6)
			key%=6;
		Location(38, y++);
		puts(s[key]);
		Sleep(500);
		key++;
	}
}