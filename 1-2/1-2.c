#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main() {
	char word[10][50] = {NULL};
	char input;
	char read;
	int l = 0;
	int w = 0;
	FILE* open;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 50; j++) {
			word[i][j] = NULL;
		}
	}
	//���� �Է�
	open = fopen("line.txt", "r");
	if (open == NULL) {
		printf("������ �Էµ��� �ʾҽ��ϴ�. ��θ� �ٽ� Ȯ���ϼ���\n");
	}
	else {
		for(l= 0;l<10;l++) {
			fgets(word[l], sizeof(word[l]), open);
			printf("%s", word[l]);
		}
	}

	int cnt, capital;
	int num = 0;
	cnt = 0;
	capital = 0;

	for (l = 0; l < 10; l++) {
		for (w = 0; w < 50; w++) {
			if (word[l][w] == ' ') {
				if ((w-1 >= 0)&&(word[l][w - 1] >= '0') && (word[l][w - 1] <= '9')) num++;
				else cnt++;
			}
			else if ((word[l][w] <= 'Z') && (word[l][w] >= 'A')) capital++;
			else if (word[l][w] == '\n') {
				cnt++;
				break;
			}
		}
	}

	printf("\n�ܾ� �� : %d��\t���� �� : %d��\t�빮�� �� : %d��",cnt,num,capital);

	while (1)
	{
		input = getch();
		switch (input)
		{
		case 'q':
			return 0;
			break;
		default:
			break;
		}
	}
}