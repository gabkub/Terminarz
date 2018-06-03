#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define ch '-'



extern year, month, day, days_num, dates_i[3][7], weekday_nr, size;
extern char dates_s[7][12];

typedef struct
{
	char date[13];
	char opis[256];
} tasks;

void start();
void line(); //wypisuje znak przez ca³¹ linijkê
void get_date(); //pobiera datê od u¿ytkownika
void pl(); //polskie znaki
void print_calendar(); //wyœwietlenie kalendarza
int days_in_month(int m); //zwraca iloœæ dni w miesi¹cu
boolean leap_year(); //czy rok jest przestêpny
int weekday(int d, int m, int y); //algorytm na wyznaczenie dnia tygodnia dowolnej daty
void if_mon();
void if_tue();
void if_wed();
void if_thu();
void if_fri();
void if_sat();
void if_sun();
void print_tasks(); //wypisuje zadania na danym tygodniu
void service();






