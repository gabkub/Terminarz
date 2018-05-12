#include "Header.h"

void start()
{
	pl();
	print_calendar();
	getchar();
}

void pl()
{
	system("chcp 1250"); system("cls");
}

void print_calendar()
{
	int day = 0, month = 0, year = 0;
	get_date(day, month, year);

	char *weekdays[] = { "Poniedzia³ek", "Wtorek", "Œroda", "Czwartek", "Pi¹tek", "Sobota", "Niedziela" };

	for (int i = 0; i < 7; i++)
	{
		printf_s("%15s", weekdays[i]);
	}
	printf_s("\n");
	print_dates(day, month, year);
}

void get_date(int year_get, int month_get, int day_get)
{
	printf_s("PODAJ DATÊ:\n");
	do
	{
		year_get = 0;
		printf_s("Rok: ");
		scanf_s("%i", &year_get);
	} while (year_get <= 1500 || year_get >= 5000);
	do
	{
		month_get = 0;
		printf_s("Miesi¹c: ");
		scanf_s("%i", &month_get);
	} while (month_get <= 0 || month_get > 12);

	do
	{
		day_get = 0;
		printf_s("Dzieñ: ");
		scanf_s("%i", &day_get);
	} while (day_get <= 0 || day_get > days_in_month(month_get, year_get));
}

int days_in_month(int month_days, int year_days)
{
	switch (month_days)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
	case 4: case 6: case 9: case 11: return 30;
	case 2:
	{
		if (leap_year(year_days) == 1) return 29;
		else return 28;
	}
	default:printf_s("B³¹d!"); break;
	}
	return 0;
}

boolean leap_year(int year_leap)
{
	return ((year_leap % 4 == 0 && year_leap % 100 != 0) || (year_leap % 400 == 0));
}

void print_dates(int day_print, int month_print, int year_print)
{
	switch ( zeller(day_print, month_print, year_print) )
	{
	case 1:if_mon(day_print, month_print, year_print); break;
	/*case 2:if_tue(day_print, month_print, year_print); break;
		case 3:if_wed(day_pd, month_pd, year_pd); break;
		case 4:if_thu(day_pd, month_pd, year_pd); break;
		case 5:if_fri(day_pd, month_pd, year_pd); break;
		case 6:if_sat(day_pd, month_pd, year_pd); break;
		case 0:if_sun(day_pd, month_pd, year_pd); break;*/
	default:printf_s("B³¹d!"); break;
	}
}

int zeller(int day_zeller, int month_zeller, int year_zeller)
{
	int number_of_days[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
	int day_year, yy, c, g, z;

	day_year = day_zeller + number_of_days[month_zeller];
	if ((month_zeller > 2) && (leap_year(year_zeller) == 1)) day_year++;

	yy = (year_zeller - 1) % 100;
	c = year_zeller - 1 - yy;
	g = yy + (yy / 4);

	z = ((((c / 100) % 4) * 5) + g) % 7;
	z += day_year - 1;
	z %= 7;

	printf("%i", z);
	getchar();

	return z;
}

void if_mon(int day_mon, int month_mon, int year_mon)
{
	int days_num = days_in_month(month_mon, year_mon);
	int dates_i[3][7];
	char dates_s[7][12];

	for (int i = 0; i < 7; i++)
	{
		if (day_mon + i <= days_num)
		{
			dates_i[0][i] = day_mon + i;
			dates_i[1][i] = month_mon;
			dates_i[2][i] = year_mon;
		}
		else
		{
			dates_i[0][i] = (day_mon + i) - days_num;
			if (month_mon + 1 <= 12)
			{
				dates_i[1][i] = month_mon + 1;
				dates_i[2][i] = year_mon;
			}
			else
			{
				dates_i[1][i] = 1;
				dates_i[1][i] = year_mon + 1;
			}
		}
		sprintf_s(dates_s[i], 12, "%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
		printf_s("%15s", dates_s[i]);
	}
	system("pause");
}

/*void if_tue(int day_weekday, int month_weekday, int year_weekday)
{
	int days_num = days_in_month(month_weekday, year_weekday);
	int dates_i[3][7];
	char dates_s[7][12];

	if (days_num == 1)
	{
		dates_i[0][0] = days_in_month((month_weekday - 1), year_weekday);
		dates_i[1][0] = month_weekday;
		dates_i[2][0] = year_weekday;
		sprintf_s(dates_s[0], 12, "%i/%i/%i", dates_i[0][0], dates_i[1][0], dates_i[2][0]);
		printf_s("%15s", dates_s[0]);
	}


	for (int i = 1; i < 7; i++)
	{
		if (day_weekday + (i-1) <= days_num)
		{
			dates_i[0][i] = day_weekday + (i-1);
			dates_i[1][i] = month_weekday;
			dates_i[2][i] = year_weekday;
			sprintf_s(dates_s[i], 12, "%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
			printf_s("%15s", dates_s[i]);
		}
		else
		{
			dates_i[0][i] = (day_weekday + (i-1)) - days_num;
			if (month_weekday + 1 <= 12)
			{
				dates_i[1][i] = month_weekday + 1;
				dates_i[2][i] = year_weekday;
			}
			else
			{
				dates_i[1][i] = 1;
				dates_i[1][i] = year_weekday + 1;
			}
		}
	}
}

void if_wed(int day_weekday, int month_weekday, int year_weekday)
{
	int days_num = days_in_month(month_weekday, year_weekday);
	int dates_i[3][7];
	char dates_s[7][12];

	for (int i = 0; i >= 0; i--)
	{
		if (day_weekday - i >= 0)
		{
			dates_i[0][i] = day_weekday;
			dates_i[1][i] = month_weekday;
			dates_i[2][i] = year_weekday;
		}
		else
		{
			dates_i[0][i] = days_num;
			if (month_weekday - 1 >= 0)
			{
				dates_i[1][i] = month_weekday - 1;
				dates_i[2][i] = year_weekday;
			}
			else
			{
				dates_i[1][i] = 12;
				dates_i[2][i] = year_weekday - 1;
			}
		}
		sprintf_s(dates_s[i], 12, "%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
		printf_s("%15s", dates_s[i]);
	}

	for (int i = 1; i < 7; i++)
	{
		if (day_weekday + i <= days_num)
		{
			dates_i[0][i] = day_weekday + i;
			dates_i[1][i] = month_weekday;
			dates_i[2][i] = year_weekday;

		}
		else
		{
			dates_i[0][i] = (day_weekday + i) - days_num;
			if (month_weekday + 1 <= 12)
			{
				dates_i[1][i] = month_weekday + 1;
				dates_i[2][i] = year_weekday;
			}
			else
			{
				dates_i[1][i] = 1;
				dates_i[2][i] = year_weekday + 1;
			}
		}
		sprintf_s(dates_s[i], 12, "%i/%i/%i", dates_i[0][i], dates_i[1][i], dates_i[2][i]);
		printf_s("%15s", dates_s[i]);
	}

}*/



