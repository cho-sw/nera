/*
* �� �� �� : Cardlib.c
* �� �� �� : �� �� ��
* ���ϸ��� : OneCard ���� ������ �ʿ��� �Լ��� �����մϴ�.
* �� �� �� : 2009.02.03
* �����Լ� : 
* ��    �� : �� ���Ͽ� ���ǵ� �Լ� ������ CardHeader.h�� �����Ͻʽÿ�. 
*----------------------------------------------------------------------------------------------*/
#include "OneCard.h"

/*----------------------------------------------------------------------------------------------
* ��    �� : void Location(unsigned, unsigned)
* ��    �� : ��ġ�� �������ش�,
*----------------------------------------------------------------------------------------------*/
void Location( unsigned _iX, unsigned _iY ){
	COORD Pos = {_iX - 1, _iY - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
/*----------------------------------------------------------------------------------------------
* ��    �� : void initialize(Card a[])
* ��    �� : �ʱ�ȭ. ī�忡 ������ �Ҵ�.
*----------------------------------------------------------------------------------------------*/
void initialize(Card a[]){
	register int	i;
	
	for(i=0; i<54; i++){
		a[i].cardcode = (i%13)+1;
		switch(a[i].cardcode){
		case 13:
			a[i].ability = replay;	break;
		case 12:
			a[i].ability = direction;	break;
		case 11:
			a[i].ability = jump;	break;
		case 7:
			a[i].ability = seven;	break;
		case 2:
			a[i].ability = nbr2;	break;
		case 1:
			a[i].ability = ace;	break;
		default:
			a[i].ability = general;
		}
		if(i<13)
			a[i].cardpattern = spade;
		else if(i>=13 && i<26)
			a[i].cardpattern = diamond;
		else if(i>=26 && i<39)
			a[i].cardpattern = heart;
		else
			a[i].cardpattern = clover;
	}
	a[0].ability = spadeAce;
	a[52].cardcode = 512;
	a[52].ability = bJoker;
	a[52].cardpattern = joker;
	a[53].cardcode = 1024;
	a[53].ability = rJoker;
	a[53].cardpattern = joker;
}
/*----------------------------------------------------------------------------------------------
* ��    �� : void shuffle(Card a[], int max)
* ��    �� : ī�� ����
*----------------------------------------------------------------------------------------------*/
void shuffle(Card a[], int max){
	register int	n;
	int				i, j;
	Card			temp;
	
	srand((unsigned)time(NULL));
	
	/* �ƹ� ��ȣ�� �ΰ� ���ؼ�
	�� �� ��ȣ�� ī�� �����͸� ���� ��ü�Ѵ�.
	�̸� 32�� ���� �ݺ��Ѵ�. */
	for(n=0; n<1024; n++){
		i = rand() % max;
		j = rand() % max;
		
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

/*----------------------------------------------------------------------------------------------
* ��    �� : void chkAll(const chk test)
* ��    �� : ������ �Լ�
*----------------------------------------------------------------------------------------------*/
void chkAll(const chk test){
	register int i;

	system("cls");
	puts("<User Card>");
	for(i=0; i<(*(test.t)); i++){
		printf("%2d : ", i+1);

		switch(((test.you)+i)->cardpattern){
		case spade:	printf("��"); break;
		case diamond: printf("��"); break;
		case heart: printf("��"); break;
		case clover: printf("��"); break;
		default: printf("JOKER ");
		}
		switch(((test.you)+i)->cardcode){
		case 1024: printf("RED\n"); break;
		case 512: printf("BLACK\n"); break;
		case 13: printf(" K\n"); break;
		case 12: printf(" Q\n"); break;
		case 11: printf(" J\n"); break;
		case 1: printf(" A\n"); break;
		default: printf("%2d\n", ((test.you)+i)->cardcode);
		}
	}
	puts("<Computer 1 Card>");
	for(i=0; i<(*((test.t)+1)); i++){
		printf("%2d : ", i+1);

		switch(((test.c1)+i)->cardpattern){
		case spade:	printf("��"); break;
		case diamond: printf("��"); break;
		case heart: printf("��"); break;
		case clover: printf("��"); break;
		default: printf("JOKER ");
		}
		switch(((test.c1)+i)->cardcode){
		case 1024: printf("RED\n"); break;
		case 512: printf("BLACK\n"); break;
		case 13: printf(" K\n"); break;
		case 12: printf(" Q\n"); break;
		case 11: printf(" J\n"); break;
		case 1: printf(" A\n"); break;
		default: printf("%2d\n", ((test.c1)+i)->cardcode);
		}
	}
	puts("<Computer 2 Card>");
	for(i=0; i<(*((test.t)+2)); i++){
		printf("%2d : ", i+1);

		switch(((test.c2)+i)->cardpattern){
		case spade:	printf("��"); break;
		case diamond: printf("��"); break;
		case heart: printf("��"); break;
		case clover: printf("��"); break;
		default: printf("JOKER ");
		}
		switch(((test.c2)+i)->cardcode){
		case 1024: printf("RED\n"); break;
		case 512: printf("BLACK\n"); break;
		case 13: printf(" K\n"); break;
		case 12: printf(" Q\n"); break;
		case 11: printf(" J\n"); break;
		case 1: printf(" A\n"); break;
		default: printf("%2d\n", ((test.c2)+i)->cardcode);
		}
	}
	puts("<Computer 3 Card>");
	for(i=0; i<(*((test.t)+3)); i++){
		printf("%2d : ", i+1);

		switch(((test.c3)+i)->cardpattern){
		case spade:	printf("��"); break;
		case diamond: printf("��"); break;
		case heart: printf("��"); break;
		case clover: printf("��"); break;
		default: printf("JOKER ");
		}
		switch(((test.c3)+i)->cardcode){
		case 1024: printf("RED\n"); break;
		case 512: printf("BLACK\n"); break;
		case 13: printf(" K\n"); break;
		case 12: printf(" Q\n"); break;
		case 11: printf(" J\n"); break;
		case 1: printf(" A\n"); break;
		default: printf("%2d\n", ((test.c3)+i)->cardcode);
		}
	}
	puts("<Deck Card>");
	for(i=0; i<(*((test.t)+4)); i++){
		printf("%2d : ", i+1);

		switch(((test.d)+i)->cardpattern){
		case spade:	printf("��"); break;
		case diamond: printf("��"); break;
		case heart: printf("��"); break;
		case clover: printf("��"); break;
		default: printf("JOKER ");
		}
		switch(((test.d)+i)->cardcode){
		case 1024: printf("RED\n"); break;
		case 512: printf("BLACK\n"); break;
		case 13: printf(" K\n"); break;
		case 12: printf(" Q\n"); break;
		case 11: printf(" J\n"); break;
		case 1: printf(" A\n"); break;
		default: printf("%2d\n", ((test.d)+i)->cardcode);
		}
	}
	puts("end");
}
/*----------------------------------------------------------------------------------------------
* ��    �� : Card userAct(Card u[], int* umax, Card d[], int* dmax, const int index)
* arguments: user �迭, user�� �ִ� ī�� ��, ����� ���� Deck�� ī��, user�� ����
* ��    �� : ī�带 PutDeck�� �ִ´�. �� ī���ϳ��� ���� ���̴�.
* ��    �� : ī��� ī�� ��� �״�� ���´�.
*            ���� ��� ������ 7���� ���� ������ 7�� ������ �迭 �ε����� 6���� ����� ��.
*----------------------------------------------------------------------------------------------*/
int userAct(Card u[], int* umax, Card d[], int* dmax, char print[]){
	char	select[5];
	char	pattern[6]={0};
	char	code[6]={0,};
	char	J[] = "J", Q[] = "Q";
	char	K[] = "K", A[] = "A";
	char	SPADE[] = "��", DIAMOND[] = "��";
	char	HEART[] = "��", CLOVER[] = "��";
	char	RED[] = "RED";
	char	BLACK[] = "BLACK";
	char	JOKER[] = "JOKER";
	int		arri;

	while(1){
		Location(10, 18);
		printf("Put your card!");
		printf("  ");

		memset(select, 0, sizeof(select));
		fgets(select, sizeof(select)-1, stdin);
		arri = atoi(select)-1;
		
		if(atoi(select)==0){
			if((*umax) >= MAXGET){			// ī�尡 15���� �Ѵ°��
				system("cls");
				Location(10, 10);
				puts("You have got too many CARDS!");
				Location(10, 11);
				puts("GAME OVER");
				exit(0);
			}
			switch(u[(*umax)].cardpattern){
			case spade:
				strcpy(pattern, SPADE); break;
			case diamond:
				strcpy(pattern, DIAMOND); break;
			case heart:
				strcpy(pattern, HEART); break;
			case clover:
				strcpy(pattern, CLOVER); break;
			default:
				strcpy(pattern, JOKER);
			}
			switch(u[(*umax)].cardcode){
			case 1024:
				strcpy(code, RED);
			case 512:
				strcpy(code, BLACK);
			case 13:
				strcpy(code, K); break;
			case 12:
				strcpy(code, Q); break;
			case 11:
				strcpy(code, J); break;
			default:
				itoa(u[(*umax)].cardcode, code, 10);
				strcat(code, "\0");
			}
			strcpy(print, "You get ");
			strcat(print, pattern);
			strcat(print, code);
			strcat(print, " from Card Deck!\n");
			memmove(&u[(*umax)], &d[(*dmax)-1], sizeof(Card));
			(*umax)++;
			(*dmax)--;
			return 0;
		}
		if((d[(*dmax)-1].cardcode==u[arri].cardcode)			// ī���ȣ�� ��ġ�ϰų�
			|| (d[(*dmax)-1].cardpattern==u[arri].cardpattern)	// ������ ��ġ�ϰų�
			|| (u[arri].cardpattern == joker)){					// ��Ŀ�� �� �����̶��
			
			switch(d[(*dmax)-1].cardpattern){
			case spade:
				strcpy(pattern, SPADE); break;
			case diamond:
				strcpy(pattern, DIAMOND); break;
			case heart:
				strcpy(pattern, HEART); break;
			case clover:
				strcpy(pattern, CLOVER); break;
			default:
				strcpy(pattern, JOKER);
			}
			switch(d[(*dmax)-1].cardcode){
			case 1024:
				strcpy(code, RED);
			case 512:
				strcpy(code, BLACK);
			case 13:
				strcpy(code, K); break;
			case 12:
				strcpy(code, Q); break;
			case 11:
				strcpy(code, J); break;
			default:
				itoa(u[(*umax)].cardcode, code, 10);
				strcat(code, "\0");
			}
			strcpy(print, "You put ");
			strcat(print, pattern);
			strcat(print, code);
			strcat(print, " to Card Deck!\n");

			memmove(&d[(*dmax)], &u[arri], sizeof(Card));
			memmove(&u[arri], &u[(*umax)-1], sizeof(Card));
			(*umax)--;
			(*dmax)++;
			
			return 0;
		}
		
		Location(59, 18);
		printf("Wrong.");
		Sleep(500);
		Location(59,18);
		printf("��������");
	}
}
