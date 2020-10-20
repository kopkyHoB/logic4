#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;
int i, j, m;
bool* visited = new bool[m];
int** graph;

void DFS(int st)
{
	int r;
	printf("%d ", st + 1);
	visited[st] = true; //������� ��������
	for (r = 0; r <= m; r++)
		if ((graph[st][r] != 0) && (!visited[r]))
			DFS(r);
}

void DFS_main()
{
	setlocale(LC_ALL, "Rus");
	printf("������� ���������� ������ �����: ");
	scanf_s("%d", &m);

	graph = new int* [m];
	for (int i = 0; i < m; i++) {
		graph[i] = new int[m];
	}

	int start;
	printf("������� ��������� �����:\n");
	srand(time(NULL));
	for (i = 0; i < m; ++i)
		for (j = i; j < m; ++j)
			graph[i][j] = graph[j][i] = rand() % 2;
	printf("  ");
	for (j = 0; j < m; j++)
	{
		printf("v%d ", j+1);
	}
	printf("\n");
	for (i = 0; i < m; ++i)
	{
		printf("v%d ", i+1);
		visited[i] = false;
		for (j = 0; j < m; ++j)
			printf("%d  ", graph[i][j]);
		printf("\n\n");
	}

	for (i = 0; i < m; i++)
	{
		printf("\n%d - ", i+1);
		for (j = 0; j < m; j++) {
			if (graph[i][j] == 1) printf("%d ", j+1);
		}
	}
	printf("\n����� �������, � ������� ������ ����� � �������: ");
	scanf_s("%d", &start);
	while (start > m) {
		printf("\n������� �� ����������!\n");
		printf("\n����� �������, � ������� ������ ����� � �������: ");
		scanf_s("%d", &start);
	}

	bool* vis = new bool[m];
	printf("������� ������: ");
	DFS(start - 1);

	_getch();
}

int Menu(void)
{
	system("CLS");
	int c = 0;
	setlocale(LC_ALL, "Rus");
	while (c < '0' || c > '1')
	{
		printf(
			"::=================================::\n"
			"|| 1 : ����� � �������             ||\n"
			"|| 0 : ����� �� ���������          ||\n"
			"::=================================::\n"
			"> ");
		c = _getch();
		system("cls");
	}
	return c;
}

void main(void)
{
	int Select;
	while ((Select = Menu()) != '0' && Select != 27)
		switch (Select)
		{
		case '1':
			DFS_main();
			break;
		}
}