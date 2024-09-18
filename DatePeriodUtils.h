#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include "þþ_strings - äÓÎÉ.h"

namespace DatePeriodUtils {
	enum enDateCompare {
		Before = -1, Equal = 0, After
		= 1
	};
	int ReadInt(string message) {
		if (message != "")
			cout << message << endl;
		int _;
		cin >> _;
		return _;
	}
	struct stDate {
		unsigned short day, month, year;
	};
	stDate ReadDate() {
		stDate date;
		date.day = ReadInt("Enter The Day ");
		date.month = ReadInt("Enter The Month ");
		date.year = ReadInt("Enter The Year ");
		return date;
	}
	struct stPeriod {
		stDate startDate;
		stDate endDate;
	};
	stPeriod ReadPeriod(string message) {
		stPeriod period;
		if (message != "")
			cout << message << endl;

		cout << "Enter The Start Date " << endl;
		period.startDate = ReadDate();

		cout << "Enter The End Date " << endl;
		period.endDate = ReadDate();

		return period;
	}
	string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One" , "Two" ,
			"Three" , "Four" , "Five" , "Six" , "Seven" ,
			"Eight" , "Nine" , "Ten" , "Eleven" , "Twelve" ,
			"Thirteen" , "Fourteen" , "Fifteen" , "Sixteen" ,
			"Seventeen" , "Nineteen" };
			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "" , "" , "Twenty" , "Thirty" , "Forty" , "Fifty" ,
			"Sixty", "Seventy" , "Eighty" , "Ninety" };
			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " +
				NumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousands " +
				NumberToText(Number % 1000);
		}if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "Millions " +
				NumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return NumberToText(Number / 1000000000) + "Billions " +
				NumberToText(Number % 1000000000);
		}

	}
	bool IsLeapYear(short Year)
	{
			return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}
	int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}
	int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}
	short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		if (Month == 2)
		{
			return IsLeapYear(Year) ? 29 : 28;
		}
		short arr31Days[7] = { 1,3,5,7,8,10,12 };
		for (short i = 1; i <= 7; i++)
		{
			if (arr31Days[i - 1] == Month)
				return 31;
		}
		//if you reach here then its 30 days.
		return 30;
	}
	short NumberOfHoursInAMonth(short Month, short Year)
	{
		return NumberOfDaysInAMonth(Month, Year) *	24;
	}
	int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return NumberOfHoursInAMonth(Month, Year) * 60;
	}
	int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return NumberOfMinutesInAMonth(Month, Year)	* 60;
	}
	
	short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		// Gregorian:
		//0:sun, 1:Mon, 2:Tue...etc.
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder];
	}
	string MonthShortName(short MonthNumber)
	{
		string Months[12] =
		{
		"Jan", "Feb", "Mar",
		"Apr", "May", "Jun",
		"Jul", "Aug", "Sep",
		"Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}
	void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;
		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(1, Month, Year);
		NumberOfDays = NumberOfDaysInAMonth(Month, Year);

		printf("\n _______________%s__________________\n\n", MonthShortName(Month).c_str()); 
		printf(" Sun Mon Tue Wed Thu Fri Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf(" ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n ____________________________________\n");
	}
	void PrintYearCalendar(short Year)
	{
		printf("\n _________________________________\n\n");
		printf(" Calendar - %d\n", Year);
		printf(" _________________________________\n");
		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}
	short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;
		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;
	}
	stDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		stDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date.year = Year;
		Date.month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.month, Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.month;
			}
			else
			{
				Date.day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	stDate DateAddDays(short Days, stDate Date)
	{
		short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.day, Date.month, Date.year);
		short MonthDays = 0;
		Date.month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.month, Date.year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.month++;
				if (Date.month > 12)
				{
					Date.month = 1;
					Date.year++;
				}
			}
			else
			{
				Date.day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
	{
		return (Date1.year < Date2.year) ? true :
	((Date1.year == Date2.year) ?
				(Date1.month < Date2.month ? true :
					(Date1.month == Date2.month ?
						Date1.day < Date2.day : false))
				: false);
	}
	bool IsDate1EqualDate2(stDate Date1, stDate Date2)
	{
		return (Date1.year == Date2.year) ? ((
			Date1.month == Date2.month) ? ((Date1.day ==
				Date2.day) ? true : false) : false) : false;
	}
	bool IsLastDayInMonth(stDate Date)
	{
		return (Date.day == NumberOfDaysInAMonth(Date.month, Date.year));
	}
	bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}
	stDate IncreaseDateByOneDay(stDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.month))
			{
				Date.month = 1;
				Date.day = 1;
				Date.year++;
			}
			else
			{
				Date.day = 1;
				Date.month++;
			}
		}
		else
		{
			Date.day++;
		}
		return Date;
	}
	stDate GetSystemDate()
	{
		stDate Date;
		time_t t = time(0);
		tm* now = localtime(&t);
		Date.year = now->tm_year + 1900;
		Date.month = now->tm_mon + 1;
		Date.day = now->tm_mday;
		return Date;
	}
	void SwapDates(stDate& Date1, stDate& Date2)
	{
		stDate TempDate;
		TempDate.year = Date1.year;
		TempDate.month = Date1.month;
		TempDate.day = Date1.day;

		Date1.year = Date2.year;
		Date1.month = Date2.month;
		Date1.day = Date2.day;

		Date2.year = TempDate.year;
		Date2.month = TempDate.month;
		Date2.day = TempDate.day;
	}
	int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;
		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}
	stDate IncreaseDateByXDays(short Days, stDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate IncreaseDateByOneWeek(stDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	stDate IncreaseDateByOneMonth(stDate Date)
	{
		if (Date.month == 12)
		{
			Date.month = 1;
			Date.year++;
		}
		else
		{
			Date.month++;
		}
		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be
	    short NumberOfDaysInCurrentMonth =
	    NumberOfDaysInAMonth(Date.month, Date.year);
		if (Date.day > NumberOfDaysInCurrentMonth)
		{
			Date.day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	stDate IncreaseDateByXMonths(short Months, stDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	stDate IncreaseDateByOneYear(stDate Date)
	{
		Date.year++;
		return Date;
	}
	stDate IncreaseDateByXYears(short Years, stDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	stDate IncreaseDateByXYearsFaster(short Years, stDate Date)
	{
		Date.year += Years;
		return Date;
	}
	stDate IncreaseDateByOneDecade(stDate Date)
	{
		//Period of 10 years
		Date.year += 10;
		return Date;
	}
	stDate IncreaseDateByXDecades(short Decade, stDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date)
	{
		Date.year += Decade * 10;
		return Date;
	}
	stDate IncreaseDateByOneCentury(stDate Date)
	{
		//Period of 100 years
		Date.year += 100;
		return Date;
	}
	stDate IncreaseDateByOneMillennium(stDate Date)
	{
		//Period of 1000 years
		Date.year += 1000;
		return Date;
	}
	stDate DecreaseDateByOneDay(stDate Date)
	{
		if (Date.day == 1)
		{
			if (Date.month == 1)
			{
				Date.month = 12;
				Date.day = 31;
				Date.year--;
			}
			else
			{
				Date.month--;
				Date.day = NumberOfDaysInAMonth(Date.month, Date.year);
			}
		}
		else
		{
			Date.day--;
		}
		return Date;
	}
	stDate DecreaseDateByXDays(short Days, stDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate DecreaseDateByOneWeek(stDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	stDate DecreaseDateByOneMonth(stDate Date)
	{
		if (Date.month == 1)
		{
			Date.month = 12;
			Date.year--;
		}
		else
		{
			Date.month--;
		}
		short NumberOfDaysInCurrentMonth =
			NumberOfDaysInAMonth(Date.month, Date.year);
		if (Date.day > NumberOfDaysInCurrentMonth)
		{
			Date.day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	stDate DecreaseDateByXMonths(short Months, stDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	stDate DecreaseDateByOneYear(stDate Date)
	{
		Date.year--;
		return Date;
	}
	stDate DecreaseDateByXYears(short Years, stDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
	{
		Date.year -= Years;
		return Date;
	}
	stDate DecreaseDateByOneDecade(stDate Date)
	{
		//Period of 10 years
		Date.year -= 10;
		return Date;
	}
	stDate DecreaseDateByXDecades(short Decade, stDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date)
	{
		Date.year -= Decade * 10;
		return Date;
	}
	stDate DecreaseDateByOneCentury(stDate Date)
	{
		//Period of 100 years
		Date.year -= 100;
		return Date;
	}
	stDate DecreaseDateByOneMillennium(stDate Date)
	{
		//Period of 1000 years
		Date.year -= 1000;
		return Date;
	}
	bool IsEndOfWeek(stDate Date)
	{
		return DayOfWeekOrder(Date.day, Date.month, Date.year) == 6;
	}
	bool IsWeekend(stDate Date)
	{
		// Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date.day , Date.month , Date.year);
		return (DayIndex == 6 || DayIndex == 5);
	}
	bool IsBusinessDay(stDate Date)
	{
		return !IsWeekend(Date);
	}
	short DaysUntilTheEndOfWeek(stDate Date)
	{
		return 6 - DayOfWeekOrder(Date.day , Date.month , Date.year);
	}
	short DaysUntilTheEndOfMonth(stDate Date)
	{
		stDate EndOfMonthDate;
		EndOfMonthDate.day = NumberOfDaysInAMonth(Date.month, Date.year);
		EndOfMonthDate.month = Date.month;
		EndOfMonthDate.year = Date.year;
		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}
	short DaysUntilTheEndOfYear(stDate Date)
	{
		stDate EndOfMonthDate;
		EndOfMonthDate.day = 31;
		EndOfMonthDate.month = 12;
		EndOfMonthDate.year = Date.year;
		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}
	short CalculateVacationDays(stDate DateFrom, stDate DateTo)
	{
		short DaysCount = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DaysCount;
	}
	stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		while (IsWeekend(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		//here we increase the vacation dates to add all weekends to it.
		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{
			if (IsWeekend(DateFrom))
				WeekEndCounter++;
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}


 		while (IsWeekend(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DateFrom;
	}
	bool IsDate1AfterDate2(stDate Date1, stDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2)
			&& !IsDate1EqualDate2(Date1, Date2));
	}
	enDateCompare CompareDates(stDate Date1, stDate	Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;
		/* if (IsDate1AfterDate2(Date1,Date2))
		return enDateCompare::After;*/
		//this is faster
		return enDateCompare::After;
	}
	bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
	{
		if (CompareDates(Period2.endDate,Period1.startDate) == enDateCompare::Before || 
			CompareDates(Period2.startDate,	Period1.endDate) == enDateCompare::After)
			return false;
		else
			return true;
	}
	int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false)
	{
		return GetDifferenceInDays(Period.startDate, Period.endDate,IncludeEndDate);
	}
	bool isDateInPeriod(stDate Date, stPeriod Period)
	{
		return !(CompareDates(Date, Period.startDate) == enDateCompare::Before	|| CompareDates(Date, Period.endDate) == enDateCompare::After);
	}
	int CountOverlapDays(stPeriod Period1, stPeriod Period2)
	{
		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);
		int OverlapDays = 0;
		if (!IsOverlapPeriods(Period1, Period2))
			return 0;
		if (Period1Length < Period2Length)
		{
			while (IsDate1BeforeDate2(Period1.startDate, Period1.endDate))
			{
				if (isDateInPeriod(Period1.startDate, Period2))
					OverlapDays++;
				Period1.startDate = IncreaseDateByOneDay(Period1.startDate);
			}
		}
		else
		{
			while (IsDate1BeforeDate2(Period2.startDate, Period2.endDate))
			{
				if (isDateInPeriod(Period2.startDate, Period1))
					OverlapDays++;
				Period2.startDate = IncreaseDateByOneDay(Period2.startDate);
			}
		}
		return OverlapDays;
	}
	bool IsValidDate(stDate Date)
	{
		if (Date.day < 1 || Date.day > 31)
			return false;
		if (Date.month < 1 || Date.month>12)
			return false;
		if (Date.month == 2)
		{
			if(IsLeapYear(Date.year))
			{
				if (Date.day > 29)
					return false;
			}
			else
			{
				if (Date.day > 28)
					return false;
			}

			short DaysInMonth = NumberOfDaysInAMonth(Date.month, Date.year);
			if (Date.day > DaysInMonth)
				return false;




			return true;
		}
	}
	string ReadStringDate(string Message)
	{
		string DateString;

		if(Message != "")
		cout << Message;

		getline(cin >> ws, DateString);
		return DateString;
	}
	stDate StringToDate(string DateString)
	{
		stDate Date;
		vector <string> vDate;
		vDate = _strings::SplitString(DateString, "/");
		Date.day = stoi(vDate[0]);
		Date.month = stoi(vDate[1]);
		Date.year = stoi(vDate[2]);
		return Date;
	}
	string FormatDate(stDate date , string delimiter) {

		return to_string(date.day) + delimiter + to_string(date.month) + delimiter + to_string(date.year);
	}
}