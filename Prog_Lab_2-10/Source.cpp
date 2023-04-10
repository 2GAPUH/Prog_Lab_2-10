#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ARRAY_SIZE 300




char GetRandomChar()
{
	return rand() % (126 - 31 + 1) + 31;
}

void GetText(char textArray[])
{
	printf_s("Enter your massege: ");
	while (getchar() != '\n');
	gets_s(textArray, 300);
}

bool CheckBuffer(char buffer[], int wordLen)
{
	if (wordLen < 3 || wordLen % 2 == 0 )
		return 0;
	for (int i = 0; i < wordLen / 2; i++)
	{
		if (buffer[i] != buffer[wordLen - i - 1])
			return 0;
	}
	return 1;
}


//Удалить из текста все слова, которые являются палиндромами.
void DeletePalindrom(char textArray[], char newArray[])
{
	if (textArray[0] == 0)
	{
		newArray[0] = 0;
		return;
	}

	char* buffer;

	buffer = (char*)malloc(sizeof(char) * ARRAY_SIZE);

	for (int i = 0, n = 0, z = 0, wordLen = 0; ; i++)
	{

		if (textArray[i] != 32)
		{
			buffer[z++] = textArray[i];
			wordLen++;
		}

		if (textArray[i+1] == 32 || textArray[i + 1] == 0)
		{
			if (!CheckBuffer(buffer, wordLen))
			{
				z = 0;
				while (z < wordLen)
				{
					newArray[n++] = buffer[z++];
				}
				z = 0;
			}

			newArray[n++] = 32;
			wordLen = 0;
			z = 0;
		}
			

		if (textArray[i] == 0)
		{
			newArray[n-1] = 0;
			break;
		}
	}

	

	free(buffer);
}


/*Дана строка. Определить, какой символ в ней встречается
раньше: 'x' или 'w'. Если какого-то из символов нет, вывести
сообщение об этом.*/
void ChechXW(char textArray[])
{
	for (int i = 0; textArray[i] != 0; i++)
	{
		if (textArray[i] == 'w')
		{
			printf_s("'w' is Detected!\n");
			return;
		}
		else if(textArray[i] == 'x')
		{
			printf_s("'x' is Detected!\n");
			return;
		}
	}

	printf_s("No w or x found.\n");
}

/*Дана строка. Вставить после каждого символа два случайных
символа.*/
void AddRandomChar(char textArray[], char newArray[])
{
	for (int i = 0, n = 0; textArray[i] != 0; i++, n+=3)
	{
		newArray[n ] = textArray[i];
		newArray[n + 1] = GetRandomChar();
		newArray[n + 2] = GetRandomChar();
		if (textArray[i + 1] == 0)
		{
			newArray[n + 3] = 0;
			return;
		}
	}
	newArray[0] = 0;
}

int main()
{
	system("chcp 1251");
	system("cls");

	int seed = time(NULL);
	srand(seed);

	int type;

	char textArray[ARRAY_SIZE];
	char newArray[ARRAY_SIZE*3];

	do
	{
		printf_s("Enter ex number: ");
		scanf_s("%d", &type);
		if (type >= 1 && type <= 3)
			break;
		printf_s("Invalid value. Try again.\n");
	} while (true);

	GetText(textArray);

	switch (type)
	{
	case 1:
		DeletePalindrom(textArray, newArray);
		printf_s("%s", newArray);
		break;
	case 2:
		ChechXW(textArray);
		break;
	case 3:
		AddRandomChar(textArray, newArray);
		printf_s("%s", newArray);
		break;
	}


	return 0;
}