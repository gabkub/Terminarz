#include "Header.h"

int day, month, year;
int days_num;
int dates_i[3][7];
char dates_s[7][12];
int weekday_nr;
int size;

void start()
{
	pl();
	SetConsoleCP(CP_UTF8);
	get_date();
	print_calendar();
}


void get_date()
{
	printf_s("PODAJ DATÊ:\n");
	do
	{
		year = 0;
		printf_s("Rok: ");
		scanf_s("%i", &year);
	} while (year <= 1500 || year >= 5000);
	do
	{
		month = 0;
		printf_s("Miesi¹c: ");
		scanf_s("%i", &month);
	} while (month <= 0 || month > 12);

	do
	{
		day = 0;
		printf_s("Dzieñ: ");
		scanf_s("%i", &day);
	} while (day <= 0 || day > days_in_month(month));
}

void pl()
{
	system("chcp 1250"); system("cls");
}

void line()
{
	printf_s("\n");
	for (int i = 1; i <= 112; i++)
	{
		printf_s("%c", ch);
	}
	printf_s("\n");
}

void print_calendar()
{
	system("cls");
	char *weekdays[] = { "Poniedzia³ek", "Wtorek", "Œroda", "Czwartek", "Pi¹tek", "Sobota", "Niedziela" };
	weekday_nr = weekday(day, month, year);
	days_num = days_in_month(month);

	line();

	for (int i = 0; i < 7; i++)
	{
		if (i == weekday_nr)
		{
			printf_s("\x1b[32m%14s \x1b[0m|", weekdays[i]);
		}
		else
		{
			printf_s("%14s |", weekdays[i]);
		}
	}
	printf_s("\n");

	switch (weekday_nr)
	{
	case 0: if_mon(); break;
	case 1: if_tue(); break;
	case 2: if_wed(); break;
	case 3: if_thu(); break;
	case 4: if_fri(); break;
	case 5: if_sat(); break;
	case 6: if_sun(); break;
	default:printf_s("B³¹d!"); break;
	}

	line();
	line();
	service();
}

int days_in_month(int m)
{
	switch (m)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
	case 4: case 6: case 9: case 11: return 30;
	case 2:
	{
		if (leap_year() == 1) return 29;
		else return 28;
	}
	default:printf_s("B³¹d!"); break;
	}
	return 0;
}

boolean leap_year()
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int weekday(int d, int m, int y)
{
	int a = (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
	switch (a)
	{
	case 1: case 2: case 3: case 4: case 5: case 6: return a - 1;
	case 0: return 6;
	default: printf_s("B³¹d!"); break;
	}
	return 0;
}

void if_mon()
{
	

	for (int i = 0; i < 7; i++)
	{
		if (day + i <= days_num)
		{
			dates_i[0][i] = day + i;
			dates_i[1][i] = month;
			dates_i[2][i] = year;
		}
		else
		{
			dates_i[0][i] = day + i - days_num;
			if (month + 1 <= 12)
			{
				dates_i[1][i] = month + 1;
				dates_i[2][i] = year;
			}
			else
			{
				dates_i[1][i] = 1;
				dates_i[2][i] = year + 1;
			}
		}
		if (dates_i[0][i] < 10)
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "0%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "0%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}
		else
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}
		if (i == 0)
		{
			printf_s("\x1b[32m%14s \x1b[0m|", dates_s[i]);
		}
		else
		{
			printf_s("%14s |", dates_s[i]);
		}
	}
	line();
	print_tasks();
}

void if_tue()
{
	for (int i = 0; i < 6; i++)
	{
		if (day + i <= days_num)
		{
			dates_i[0][i + 1] = day + i;
			dates_i[1][i + 1] = month;
			dates_i[2][i + 1] = year;
		}
		else
		{
			dates_i[0][i + 1] = i;
			if (month + 1 <= 12)
			{
				dates_i[1][i + 1] = month + 1;
				dates_i[2][i + 1] = year;
			}
			else
			{
				dates_i[1][i + 1] = 1;
				dates_i[1][i + 1] = year + 1;
			}
		}
	}

	if (day - 1 > 0)
	{
		dates_i[0][0] = day - 1;
		dates_i[1][0] = month;
		dates_i[2][0] = year;
	}
	else
	{
		dates_i[0][0] = days_in_month(month - 1);
		if (month - 1 > 0)
		{
			dates_i[1][0] = month - 1;
			dates_i[2][0] = year;
		}
		else
		{
			dates_i[1][0] = 12;
			dates_i[1][0] = year - 1;
		}
	}

	for (int i = 0; i < 7; i++)
	{
		if (dates_i[0][i] < 10)
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "0%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "0%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}
		else
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}		if (i == 1)
		{
			printf_s("\x1b[32m%14s \x1b[0m|", dates_s[i]);
		}
		else
		{
			printf_s("%14s |", dates_s[i]);
		}
	}
	line();
	print_tasks();
}

void if_wed()
{

	for (int i = 0; i < 5; i++)
	{
		if (day + i <= days_num)
		{
			dates_i[0][i + 2] = day + i;
			dates_i[1][i + 2] = month;
			dates_i[2][i + 2] = year;
		}
		else
		{
			dates_i[0][i + 2] = i;
			if (month + 1 <= 12)
			{
				dates_i[1][i + 2] = month + 1;
				dates_i[2][i + 2] = year;
			}
			else
			{
				dates_i[1][i + 2] = 1;
				dates_i[1][i + 2] = year + 1;
			}
		}
	}

	for (int i = -2; i < 0; i++)
	{
		if (day + i > 0)
		{
			dates_i[0][i + 2] = day + i;
			dates_i[1][i + 2] = month;
			dates_i[2][i + 2] = year;
		}
		else
		{
			dates_i[0][i + 2] = days_in_month(month - 1) + i + 1;
			if (month - 1 > 0)
			{
				dates_i[1][i + 2] = month - 1;
				dates_i[2][i + 2] = year;
			}
			else
			{
				dates_i[1][i + 2] = 12;
				dates_i[1][i + 2] = year - 1;
			}
		}
	}
	

	for (int i = 0; i < 7; i++)
	{
		if (dates_i[0][i] < 10)
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "0%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "0%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}
		else
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}		if (i == 2)
		{
			printf_s("\x1b[32m%14s \x1b[0m|", dates_s[i]);
		}
		else
		{
			printf_s("%14s |", dates_s[i]);
		}
	}
	line();
	print_tasks();
}

void if_thu()
{
	for (int i = 0; i < 4; i++)
	{
		if (day + i <= days_num)
		{
			dates_i[0][i + 3] = day + i;
			dates_i[1][i + 3] = month;
			dates_i[2][i + 3] = year;
		}
		else
		{
			dates_i[0][i + 3] = i;
			if (month + 1 <= 12)
			{
				dates_i[1][i + 3] = month + 1;
				dates_i[2][i + 3] = year;
			}
			else
			{
				dates_i[1][i + 3] = 1;
				dates_i[1][i + 3] = year + 1;
			}
		}
	}

	for (int i = -3; i < 0; i++)
	{
		if (day + i > 0)
		{
			dates_i[0][i + 3] = day + i;
			dates_i[1][i + 3] = month;
			dates_i[2][i + 3] = year;
		}
		else
		{
			dates_i[0][i + 3] = days_in_month(month - 1) + i + 1;
			if (month - 1 > 0)
			{
				dates_i[1][i + 3] = month - 1;
				dates_i[2][i + 3] = year;
			}
			else
			{
				dates_i[1][i + 3] = 12;
				dates_i[1][i + 3] = year - 1;
			}
		}
	}


	for (int i = 0; i < 7; i++)
	{
		if (dates_i[0][i] < 10)
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "0%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "0%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}
		else
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}		if (i == 3)
		{
			printf_s("\x1b[32m%14s \x1b[0m|", dates_s[i]);
		}
		else
		{
			printf_s("%14s |", dates_s[i]);
		}
	}
	line();
	print_tasks();
}

void if_fri()
{

	for (int i = 0; i < 3; i++)
	{
		if (day + i <= days_num)
		{
			dates_i[0][i + 4] = day + i;
			dates_i[1][i + 4] = month;
			dates_i[2][i + 4] = year;
		}
		else
		{
			dates_i[0][i + 4] = i;
			if (month + 1 <= 12)
			{
				dates_i[1][i + 4] = month + 1;
				dates_i[2][i + 4] = year;
			}
			else
			{
				dates_i[1][i + 4] = 1;
				dates_i[1][i + 4] = year + 1;
			}
		}
	}

	for (int i = -4; i < 0; i++)
	{
		if (day + i > 0)
		{
			dates_i[0][i + 4] = day + i;
			dates_i[1][i + 4] = month;
			dates_i[2][i + 4] = year;
		}
		else
		{
			dates_i[0][i + 4] = days_in_month(month - 1) + i + 1;
			if (month - 1 > 0)
			{
				dates_i[1][i + 4] = month - 1;
				dates_i[2][i + 4] = year;
			}
			else
			{
				dates_i[1][i + 4] = 12;
				dates_i[1][i + 4] = year - 1;
			}
		}
	}

	for (int i = 0; i < 7; i++)
	{
		if (dates_i[0][i] < 10)
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "0%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "0%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}
		else
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}		if (i == 4)
		{
			printf_s("\x1b[32m%14s \x1b[0m|", dates_s[i]);
		}
		else
		{
			printf_s("%14s |", dates_s[i]);
		}
	}
	line();
	print_tasks();
}

void if_sat()
{

	for (int i = 0; i < 2; i++)
	{
		if (day + i <= days_num)
		{
			dates_i[0][i + 5] = day + i;
			dates_i[1][i + 5] = month;
			dates_i[2][i + 5] = year;
		}
		else
		{
			dates_i[0][i + 5] = i;
			if (month + 1 <= 12)
			{
				dates_i[1][i + 5] = month + 1;
				dates_i[2][i + 5] = year;
			}
			else
			{
				dates_i[1][i + 5] = 1;
				dates_i[1][i + 5] = year + 1;
			}
		}
	}

	for (int i = -5; i < 0; i++)
	{
		if (day + i > 0)
		{
			dates_i[0][i + 5] = day + i;
			dates_i[1][i + 5] = month;
			dates_i[2][i + 5] = year;
		}
		else
		{
			dates_i[0][i + 5] = days_in_month(month - 1) + i + 1;
			if (month - 1 > 0)
			{
				dates_i[1][i + 5] = month - 1;
				dates_i[2][i + 5] = year;
			}
			else
			{
				dates_i[1][i + 5] = 12;
				dates_i[1][i + 5] = year - 1;
			}
		}
	}


	for (int i = 0; i < 7; i++)
	{
		if (dates_i[0][i] < 10)
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "0%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "0%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}
		else
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}		if (i == 5)
		{
			printf_s("\x1b[32m%14s \x1b[0m|", dates_s[i]);
		}
		else
		{
			printf_s("%14s |", dates_s[i]);
		}
	}
	line();
	print_tasks();
}

void if_sun()
{
		dates_i[0][6] = day;
		dates_i[1][6] = month;
		dates_i[2][6] = year;

	for (int i = -6; i < 0; i++)
	{
		if (day + i > 0)
		{
			dates_i[0][i + 6] = day + i;
			dates_i[1][i + 6] = month;
			dates_i[2][i + 6] = year;
		}
		else
		{
			dates_i[0][i + 6] = days_in_month(month - 1) + i + 1;
			if (month - 1 > 0)
			{
				dates_i[1][i + 6] = month - 1;
				dates_i[2][i + 6] = year;
			}
			else
			{
				dates_i[1][i + 6] = 12;
				dates_i[1][i + 6] = year - 1;
			}
		}
	}


	for (int i = 0; i < 7; i++)
	{
		if (dates_i[0][i] < 10)
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "0%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "0%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}
		else
		{
			if (dates_i[1][i] < 10)
			{
				sprintf(dates_s[i], "%i/0%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			}
			else
			{
				sprintf(dates_s[i], "%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);

			}
		}		if (i == 6)
		{
			printf_s("\x1b[32m%14s \x1b[0m|", dates_s[i]);
		}
		else
		{
			printf_s("%14s |", dates_s[i]);
		}
	}
	line();
	print_tasks();
}

void print_tasks()
{
	tasks* t = malloc(sizeof(tasks));
	FILE* fp;
	int lines = 0;
	fp = fopen("Notes.txt", "r");
	if (fp == NULL)
	{
		printf_s("\n\nB£¥D OTWIERANIA PLIKU!");
	}
	else
	{
		char today[12];
		memcpy(today, dates_s[weekday_nr], 12);
		strcat(today, "\n"); //fgets dodaje znacznik \n do odczytanej zmiennej
		while (fgets(t, sizeof(t), fp) != NULL)
		{
			fread(t->date, 10, 1, fp);
			int cmp = strncmp(t->date, today, 10);
			if (cmp == 0)
			{
				lines++;
			}
		}
		rewind(fp);
		while (fgets(t, sizeof(t), fp) != NULL)
		{
			fread(t->date, 10, 1, fp);
			int cmp = strncmp(t->date, today, 10);
			if (cmp == 0)
			{
				fgets(t->opis, sizeof(t->opis), fp);
				printf("%s\n", t->opis);
			}
		}
	}
	fclose(fp);
}

void service()
{
	printf_s("Opcje: \n[a] = dodaj wpis \n[d] = usuñ wpisy\n[/] = kolejny dzieñ \n[\\] = poprzedni dzieñ \n[>] = kolejny tydzieñ \n[<] = poprzedni tydzieñ \n[n] = nowa data \n[x] = koniec\n");
	char key = 'z';
	printf_s("Twój wybór:\n");
	do
	{
		key = getchar();
		switch (key)
		{
		case 'a':
		{
			FILE* fp;
			fp = fopen("Notes.txt", "a");
			if (fp == NULL)
			{
				printf_s("\nB£¥D OTWIERANIA PLIKU!");
			}
			else
			{
				char descr[251], hour[6], all[256];
				printf_s("Wpisz godzinê:\n");
				scanf_s("%s", &hour, 6);
				printf_s("Napisz opis:\n");
				scanf_s("%s", &descr, 250);
				sprintf_s(all, 256, "%s : %s", hour, descr);
				fprintf_s(fp, "%s %s\n", dates_s[weekday_nr], all);
				printf_s("Wpis zosta³ dodany!\n");
				fclose(fp);
			}
		}; break;
		case 'd':
		{
			FILE* fp;
			fp = fopen("Notes.txt", "w");
			if (fp == NULL)
			{
				printf_s("\nB£¥D OTWIERANIA PLIKU!");
			}
			else
			{
				printf_s("Usuniêto.\n");
				fclose(fp);
			}
		}; break;
		case 'n': start(); break;
		case '/':
		{
			if (day + 1 < days_num)
			{
				day++;
			}
			else
			{
				day = 1;
				if (month + 1 <= 12)
				{
					month++;
				}
				else
				{
					month = 1;
					year++;
				}
			}
			print_calendar();
		}; break;
		case '\\':
		{
			if (day - 1 > 0)
			{
				day--;
			}
			else
			{
				day = days_in_month(month - 1);
				if (month - 1 > 0)
				{
					month = month--;
				}
				else
				{
					month = 12;
					year--;
				}
			}
			print_calendar();
		}; break;
		case '>':
		{
			if (day + 7 <= days_num)
			{
				day += 7;
			}
			else
			{
				day = day + 7 - days_num;
				if (month + 1 <= 12)
				{
					month++;
				}
				else
				{
					month = 1;
					year++;
				}
			}
			print_calendar();
		}; break;
		case '<':
		{
			if (day - 7 > 0)
			{
				day -= 7;
			}
			else
			{
				if (month - 1 > 0)
				{
					day = day - 7 + days_in_month(month - 1);
					month--;
				}
				else
				{
					day = day - 7 + 31;
					month = 12;
					year--;
				}
			}
			print_calendar();
		}; break;
		case 'x':exit(0);
		}
	} while (key != 'x');
}