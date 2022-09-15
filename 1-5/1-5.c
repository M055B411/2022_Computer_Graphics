#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct list
{
	int x;
	int y;
	int z;
	bool havdata;
};

int main() {
	struct list List[10];

	for (int i = 0; i < 10; i++)List[i].havdata = false;



	char input;
	int x, y, z;
	int cnt =0;
	int point = 0;
	bool sucess = true;
	while (true)
	{
		system("cls");
		for (int i = 0; i < 10; i++) {
			printf("%2d", i + 1);
			if (List[i].havdata) {
				printf(" %2d\t%2d\t%2d", List[i].x, List[i].y, List[i].z);
			}
			printf("\n");
		}
		if (cnt > 0)printf("점 %2d 개", cnt);
		if (sucess == false) printf("실패");


		sucess = false;
		input = getch();
		switch (input)
		{
		case '+':
			for (int i = 0; i < 10; i++) {
				if (List[i].havdata == false) {
					printf("number : ");
					scanf("%d %d %d", &List[i].x, &List[i].y, &List[i].z);
					List[i].havdata = true;
					sucess = true;
					break;
				}
			}
			break;
		case '-':
			for (int i = 0; i < 10; i++) {
				if (List[i].havdata) {
					List[i].havdata = false;
					sucess = true;
					break;
				}
			}
			break;
		case 'e':
			for (int i = 9; i >= 0; i--) {
				if (List[i].havdata == false) {
					printf("number : ");
					scanf("%d %d %d", &List[i].x, &List[i].y, &List[i].z);
					List[i].havdata = true;
					sucess = true;
					break;
				}
			}
			break;
		case 'd':
			for (int i = 9; i >= 0; i--) {
				if (List[i].havdata) {
					List[i].havdata = false;
						sucess = true;
					break;
				}
			}
			break;
		case 'l':
			for (int i = 0; i < 10; i++) {
				if (List[i].havdata) {
					cnt++;
				}
			}
			if (cnt > 0) sucess = true;
			break;
		case 'c':
			for (int i = 0; i < 10; i++) {
				List[i].havdata = false;
			}
			sucess = true;
			break;
		case 'm':
			break;
		case 'n':
			break;
		case 's':
			break;
		case 'q':
			return 0;
			break;
		default:
			break;
		}
	}
}