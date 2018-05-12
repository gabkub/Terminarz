#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

void start();
void pl(); //polskie znaki
void print_calendar(); //wyœwietlenie kalendarza
void get_date(int year_get, int month_get, int day_get); //data podana przez u¿ytkownika
int days_in_month(int month_days, int year_days); //zwraca iloœæ dni w miesi¹cu
boolean leap_year(int year_leap); //czy rok jest przestêpny
void print_dates(int day_print, int month_print, int year_print); //wypisanie dat w ca³ym tygodniu
int zeller(int day_zeller, int month_zeller, int year_zeller); //algorytm Zellera na wyznaczenie dnia tygodnia dowolnej daty
void if_mon(int day_mon, int month_mon, int year_mon);
/*void if_tue(int day_weekday, int month_weekday, int year_weekday);
void if_wed(int day_mon, int month_mon, int year_mon);
void if_thu(int day_mon, int month_mon, int year_mon);
void if_fri(int day_mon, int month_mon, int year_mon);
void if_sat(int day_mon, int month_mon, int year_mon);
void if_sun(int day_mon, int month_mon, int year_mon);*/





