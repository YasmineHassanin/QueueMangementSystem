#pragma warning(disable:4996)
#pragma once
#include<iostream>
#include<string>
#include "ClsString.h"
using namespace std;
class ClsDateLibrary
{

private:
	short _Days = 1;
    short _Months = 1;
    short _Year = 1900;

public:
    ClsDateLibrary()
    {
        /*Initiate the private memebers system time*/
        time_t t = time(0);
        tm* now = localtime(&t);
        _Days = now->tm_mday;
        _Months = now->tm_mon+1;
        _Year = now->tm_year+1900;
    }
    ClsDateLibrary(string SDate)
    {
        /*Initiate the private memebers by elemnts of vector*/
        vector<string>Vdate;
        Vdate = ClsString::SplitString(SDate, "/");
        _Days = stoi(Vdate[0]);
        _Months = stoi(Vdate[1]);
        _Year = stoi(Vdate[2]);
    }
    ClsDateLibrary(short Day, short month, short year)
    {
        /*Initiate the private memebers by paramters of function*/
        _Days = Day;
        _Months = month;
        _Year = year;
    }
    ClsDateLibrary(short numberofdays, short year)
    {
        /*Initiate the private memebers by members in struct*/
     ClsDateLibrary date= ConverTotalDaysToDateFromBeginningTheYear(numberofdays,year);
       _Days = date.days;
       _Months = date.months;
       _Year = date.year;
    }
    void SetDays(short days)
    {
        _Days = days;
    }
    short GetDays()
    {
        return _Days;
    }
    __declspec(property(get = GetDays, put = SetDays)) short days;
    void SetMonth(short Month)
    {
        _Months = Month;
    }
    short GetMonth()
    {
        return _Months;
    }
    __declspec(property(get = GetMonth, put = SetMonth)) short months;
    void SetYear(short Year)
    {
        _Year = Year;
    }
  short GetYear()
    {
        return _Year;
    }
  __declspec(property(get = GetYear, put = SetYear)) short year;
  /*If Called from main*/
 static  string DateToString(ClsDateLibrary date)
    {
        return  to_string(date.days) + "/" + to_string(date.months) + "/" + to_string(date.year);
    }
  /*If called from ant object*/
 string DateToString()
    {
       return DateToString(*this);
    }
 void Print()
    {
        cout << DateToString()<<endl;
    }
 static string PrintTheDay(short TheDayOfTheWeakorder)
    {
        string NameOfTheOrder[] = { "sun","mon","tus","wen","thurs","fri","sat" };
        return NameOfTheOrder[TheDayOfTheWeakorder];
    }
 string PrintTheDay()
 {
     return PrintTheDay(_Days);
 }
 static string PrintTheMonth(short TheMonthOfYearorder)
    {
        string NameOfTheOrder[12] = { "Jan","Feb","Mar","April","May","June","July","Aug","Sep","Oct","Nov","Dec" };
        return (NameOfTheOrder[TheMonthOfYearorder - 1]);
    }
 string PrintTheMonth()
 {
     return PrintTheMonth(_Months);
 }
 static  bool IsLeapYear(short Year)
    {
        return  (Year % 4 == 0) && (Year % 100 != 0) || (Year % 400 == 0);
    }
 bool IsLeapYear()
  {
      return IsLeapYear(_Year);
  }
 static short NumberOfDaysInAMonthOfAYear(short month, short year)
    {
        short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : (NumberOfDays[month - 1]);
    }
 short NumberOfDaysInAMonthOfAYear()
 {
     return NumberOfDaysInAMonthOfAYear(_Months, _Year);
 }
    static   int NumberOfHours(int month, int year)
    {
        return NumberOfDaysInAMonthOfAYear(month, year) * 24;
    }
    int NumberOfHours()
    {
        return NumberOfHours(_Months, _Year);
    }
    static    int numberofMuintes(int month, int year)
    {
        return NumberOfHours(month, year) * 60;
    }
    int numberofMuintes()
    {
        return numberofMuintes(_Months, _Year);
    }

    static int numberofSecondsinMonth(int month, int year)
    {
        return numberofMuintes(month, year) * 60;
    }
    int numberofSecondsinMonth()
    {
        return numberofSecondsinMonth(_Months, _Year);
    }
  static  bool IsTheDateIsValidOrNot(ClsDateLibrary date)
    {
        if (date.days < 1 || date.days>31)
            return false;

        if (date.months < 1 || date.months>12)
            return false;
        if (date.months == 2)
        {
            if (IsLeapYear(date.year))
            {
                if (date.days > 29)
                    return false;
            }
            else
                if (date.days > 28)
                    return false;
        }
        short numberofDays = NumberOfDaysInAMonthOfAYear(date.months, date.year);
        if (date.days > numberofDays)
            return false;
        return true;
    }
  bool IsTheDateIsValidOrNot()
  {
      return IsTheDateIsValidOrNot(*this);
  }
  
  static ClsDateLibrary GetSystemDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        short year, months, days;
        year = now->tm_year + 1900;
        months = now->tm_mon + 1;
        days = now->tm_mday;
        return ClsDateLibrary(days,months,year);
    }
  static string GetSystemDateTimeString()
  {
      //system datetime string
      time_t t = time(0);
      tm* now = localtime(&t);

      short Day, Month, Year, Hour, Minute, Second;

      Year = now->tm_year + 1900;
      Month = now->tm_mon + 1;
      Day = now->tm_mday;
      Hour = now->tm_hour;
      Minute = now->tm_min;
      Second = now->tm_sec;

      return (to_string(Day) + "/" + to_string(Month) + "/"
          + to_string(Year) + " - "
          + to_string(Hour) + ":" + to_string(Minute)
          + ":" + to_string(Second));

  }
  
   static short DayOfWeakOrder(short day, short month, short year)
    {
        short a, m, y, d;
        a = (14 - month) / 12;
        y = year - a;
        m = month + (12 * a) - 2;
        d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
        return d;
    }
   short DayOfWeakOrder()
   {
       return DayOfWeakOrder(_Days, _Months, _Year);
   }
  static  short DayOfWeakOrder(ClsDateLibrary date)
    {
        return  DayOfWeakOrder(date.days, date.months, date.year);
    }
   /* short DayOfWeakOrder()
    {
        return DayOfWeakOrder();
    }*/
    static ClsDateLibrary ConverTotalDaysToDateFromBeginningTheYear(short OrderofDays,short year)
{
    short RemainingDays = OrderofDays;
    //short currentday;
    short DaysInAmonth = 0;
    ClsDateLibrary Date;
    Date.year = year;
    Date.months = 1;
    while (true)
    {
        DaysInAmonth = NumberOfDaysInAMonthOfAYear(Date.months, year);
        if (RemainingDays > DaysInAmonth)
        {
            RemainingDays -= DaysInAmonth;
            Date.months++;
        }
        else
        {
            Date.days = RemainingDays;
            break;
        }
    }
    return Date;
}
    ClsDateLibrary ConverTotalDaysToDateFromBeginningTheYear(short OrderofDays)
    {
        return ConverTotalDaysToDateFromBeginningTheYear(OrderofDays, _Year);
    }
    static bool IsEndOfWeak(ClsDateLibrary date)
    {
        return  (DayOfWeakOrder(date) == 6);
    }
    bool IsEndOfWeak()
    {
        return IsEndOfWeak(*this);
    }
    static bool IsWeakendOfWeak(ClsDateLibrary date)
    {
        short IndexOfDay = DayOfWeakOrder(date);
        return (IndexOfDay == 5 || IndexOfDay == 6);
    }
    bool IsWeakendOfWeak()
    {
        return IsWeakendOfWeak(*this);
    }
  static  bool IsBuisnessOfWeak(ClsDateLibrary date)
    {
        return (!IsWeakendOfWeak(date));
    }
  bool IsBuisnessOfWeak()
  {
      return IsBuisnessOfWeak(*this);
  }
  static  short DaysUntilEndOfTheWeak(ClsDateLibrary date)
    {
        return 6 - DayOfWeakOrder(date);
    }
  short DaysUntilEndOfTheWeak()
  {
      return DaysUntilEndOfTheWeak(*this);
  }
  static  bool IsLastDayInAMonth(ClsDateLibrary date)
    {
        return (date.days == NumberOfDaysInAMonthOfAYear(date.months, date.year));
    }
  bool IsLastDayInAMonth()
  {
      return IsLastDayInAMonth(*this);
  }
   static bool IsLastMonthInAYear(short month)
    {
        return (month == 12);
    }
   bool IsLastMonthInAYear()
   {
       return IsLastMonthInAYear(_Months);
   }
   static ClsDateLibrary IncreaseDateByOneDay(ClsDateLibrary &date)
    {
        if (IsLastDayInAMonth(date))
        {
            if (IsLastMonthInAYear(date.months))
            {
                date.days = 1;
                date.months = 1;
                date.year++;
            }
            else
            {
                date.days = 1;
                date.months++;
            }
        }
        else
        {
            date.days++;
        }
        return date;
    }
   void IncreaseDateByOneDay()
   {
        IncreaseDateByOneDay(*this);
   }
  static  void SwapTwoDates(ClsDateLibrary& date1, ClsDateLibrary& date2)
    {
    ClsDateLibrary TempDate;
        TempDate.days = date1.days;
        TempDate.months = date1.months;
        TempDate.year = date1.year;

        date1.days = date2.days;
        date1.months = date2.months;
        date1.year = date2.year;

        date2.days = TempDate.days;
        date2.months = TempDate.months;
        date2.year = TempDate.year;
    }
     ClsDateLibrary StringToDate(string DateString)
    {
        ClsDateLibrary date;
        /*string to date :
        1-using split function
        2-using stoi:string to integer
        */
        /*we need vector  to store split string in it*/
        vector<string>Vdate;
        Vdate = ClsString::SplitString(DateString,"/");
        /*Store elements of vector after convert them from string to integer in date strucure */
        date.days = stoi(Vdate[0]);
        date.months = stoi(Vdate[1]);
        date.year = stoi(Vdate[2]);
        return date;
    }
    static bool IsDate1BeforeDate2(ClsDateLibrary date1, ClsDateLibrary date2)
     {
         return (date2.year > date1.year) ? true : ((date2.year == date1.year) ? (date2.months > date1.months ? true : (date2.months == date1.months ? (date2.days > date1.days) : false)) : false);
     }
    bool IsDate1BeforeDate2(ClsDateLibrary date2)
    {
        return IsDate1BeforeDate2(*this);
    }
  static   bool IsDate1EqualDate2(ClsDateLibrary date1, ClsDateLibrary date2)
     {
         return (date1.year == date2.year ? (date1.months == date2.months ? (date1.days == date2.days ? true : false) : false) : false);
     }
  bool IsDate1EqualDate2(ClsDateLibrary date2)
  {
      return IsDate1EqualDate2(*this);
  }
     enum enReturnDate
     {
         before = -1, equal = 0, after = 1
     };
     static bool IsDate1AfterDate2(ClsDateLibrary Date1, ClsDateLibrary Date2)
     {
         return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
     }
     bool IsDate1AfterDate2(ClsDateLibrary Date2)
     {
         return IsDate1AfterDate2(*this, Date2);
     }
   static  enReturnDate CompareTwoDate(ClsDateLibrary date1, ClsDateLibrary date2)
     {
         if (IsDate1BeforeDate2(date1, date2))
             return enReturnDate::before;
         else if (IsDate1EqualDate2(date1, date2))
             return enReturnDate::equal;
         return enReturnDate::after;

     }
   enReturnDate CompareTwoDate(ClsDateLibrary date2)
   {
       return CompareTwoDate(*this);
   }
  static  short TheDifferanceBetweenTwoDates(ClsDateLibrary date1, ClsDateLibrary date2, bool IsIncludindEndDay = false)
     {
         short days = 0;
         short swapFlag = 1;
         while (!IsDate1BeforeDate2(date1, date2))
         {
             SwapTwoDates(date1, date2);
             swapFlag = -1;
         }
         while (IsDate1BeforeDate2(date1, date2))
         {
             days++;
             date1 = IncreaseDateByOneDay(date1);
         }
         return IsIncludindEndDay ? ++days * swapFlag : days * swapFlag;
     }
  short TheDifferanceBetweenTwoDates(ClsDateLibrary date2, bool IsIncludindEndDay = false)
  {
      return TheDifferanceBetweenTwoDates(*this,date2,true);
  }
   static  short DaysUntilTheEndOfMonth(ClsDateLibrary date1)
     {
         /*short numberofdays = NumberOfDaysInAMonthOfAYear(date1.month, date1.year);
         return  numberofdays- date1.day ;*/
         ClsDateLibrary EndDaysToMonth;
         EndDaysToMonth.days = NumberOfDaysInAMonthOfAYear(date1.months, date1.year);
         EndDaysToMonth.months = date1.months;
         EndDaysToMonth.year = date1.year;
         return TheDifferanceBetweenTwoDates(date1, EndDaysToMonth, true);
     }
   short DaysUntilTheEndOfMonth()
   {
       return DaysUntilTheEndOfMonth(*this);
   }
  static   short daysUntilTheEndOfAYear(ClsDateLibrary date)
     {
         ClsDateLibrary EndDaysToYear;
         EndDaysToYear.days = 31;
         EndDaysToYear.months = 12;
         EndDaysToYear.year = date.year;
         return TheDifferanceBetweenTwoDates(date, EndDaysToYear, true);
     }
  short daysUntilTheEndOfAYear()
  {
      return daysUntilTheEndOfAYear(*this);
  }
      static short NumberOfDaysFromBeginningOfTheYear(short day, short month, short year)
     {
         short TotalDays = 0;
         for (short i = 1; i <= month - 1; i++)
         {
             TotalDays += NumberOfDaysInAMonthOfAYear(i, year);
         }
         TotalDays += day;
         return TotalDays;
     }
      short NumberOfDaysFromBeginningOfTheYear()
      {
          return NumberOfDaysFromBeginningOfTheYear(_Days, _Months, _Year);
      }
    static ClsDateLibrary AddDaysToDate(short DaysToAdd, ClsDateLibrary & Date)
     {

         short RemainingDays = DaysToAdd + NumberOfDaysFromBeginningOfTheYear(Date.days ,Date.months, Date.year);
         short DaysInAMonth = 0;
         Date.months = 1;
         while (1)
         {
             DaysInAMonth = NumberOfDaysInAMonthOfAYear(Date.months, Date.year);
             if (RemainingDays > DaysInAMonth)
             {
                 RemainingDays -= DaysInAMonth;
                 Date.months++;
                 if (Date.months > 12)
                 {
                     Date.months = 1;
                     Date.year++;
                 }
             }
             else
             {
                 Date.days = RemainingDays;
                 break;
             }

         }
         return Date;
     }
    void AddDaysToDate(short DaysToAdd)
    {
         AddDaysToDate(DaysToAdd, *this);
    }
  
     static string FormateDate(ClsDateLibrary& date, string FormateString = "dd/mm/yyyy")
     {
         string NewFormateOfStringOfDate;
         NewFormateOfStringOfDate = ClsString::ReplaceFunctionUsingSplitFunction(FormateString, "dd", to_string(date.days));
         NewFormateOfStringOfDate = ClsString::ReplaceFunctionUsingSplitFunction(NewFormateOfStringOfDate, "mm", to_string(date.months));
         NewFormateOfStringOfDate = ClsString::ReplaceFunctionUsingSplitFunction(NewFormateOfStringOfDate, "yyyy", to_string(date.year));
         return NewFormateOfStringOfDate;
     }
     string FormateDate(string FormateString = "dd/mm/yyyy")
     {
         return FormateDate(*this, FormateString);
     }
    static  ClsDateLibrary DecreaseDateByOneDay(ClsDateLibrary &date)
     {
         if (date.days == 1)
         {
             if (date.months == 1)
             {

                 date.days = 31;
                 date.months = 12;
                 date.year--;
             }
             else
             {
                 date.months--;
                 date.days = NumberOfDaysInAMonthOfAYear(date.months, date.year);
             }
         }
         else
         {
             date.days--;
         }
         return date;
     }
    void DecreaseDateByOneDay()
    {
        DecreaseDateByOneDay(*this);
    }
   static  ClsDateLibrary DecreaseDateByXDay(short numberofDays, ClsDateLibrary &date)
     {
         for (int i = 1; i <= numberofDays; i++)
         {
             date = DecreaseDateByOneDay(date);
         }
         return date;
     }
   void DecreaseDateByXDay(short numberofDays)
   {
        DecreaseDateByXDay(numberofDays, *this);
   }
    static ClsDateLibrary DecreaseDateByOneWeak(ClsDateLibrary &date)
     {
         for (int i = 1; i <= 7; i++)
         {
             date = DecreaseDateByOneDay(date);
         }
         return date;
     }
    void DecreaseDateByOneWeak()
    {
        DecreaseDateByOneWeak(*this);
    }
   static  ClsDateLibrary DecreaseDateByXWeak(short NumberOfweaks, ClsDateLibrary &date)
     {
         for (int i = 1; i <= NumberOfweaks; i++)
         {
             date = DecreaseDateByOneWeak(date);
         }
         return date;
     }
   void DecreaseDateByXWeak(short NumberOfweaks)
   {
       DecreaseDateByXWeak(NumberOfweaks,*this);
   }
    static ClsDateLibrary DecreaseDateByOneMonth(ClsDateLibrary& date)
     {
         if (date.months == 1)
         {
             date.months = 12;
             date.year--;
         }
         else
         {
             date.months--;
         }
         short NumberOfDaysInAmonth = NumberOfDaysInAMonthOfAYear(date.months, date.year);
         if (date.days > NumberOfDaysInAmonth)
         {
             date.days = NumberOfDaysInAmonth;
         }
         return date;
     }
    void DecreaseDateByOneMonth()
    {
         DecreaseDateByOneMonth(*this);
    }
   static  ClsDateLibrary DecreaseDateByXMonth(short numberOfMonths, ClsDateLibrary & date)
     {
         for (int i = 1; i <= numberOfMonths; i++)
         {
             date = DecreaseDateByOneMonth(date);
         }
         return date;
     }
   void DecreaseDateByXMonth(short numberOfMonths)
   {
        DecreaseDateByXMonth(numberOfMonths, *this);
   }
    static ClsDateLibrary DecreaseDateByOneYear(ClsDateLibrary &date)
     {
         date.year--;
         return date;
     }
    void DecreaseDateByOneYear()
    {
         DecreaseDateByOneYear(*this);
     }
  static   ClsDateLibrary DecreaseDateByXYears(short numberofyears, ClsDateLibrary &date)
     {
         date.year -= numberofyears;
         return date;
     }
  void DecreaseDateByXYears(short numberofyears)
  {
       DecreaseDateByXYears(numberofyears, *this);
  }
    static ClsDateLibrary DecreaseDateByOneCentury(ClsDateLibrary &date)
     {
         date.year -= 10;
         return date;
     }
    void DecreaseDateByOneCentury()
    {
         DecreaseDateByOneCentury(*this);
    }
   static  ClsDateLibrary DecreaseDateByXCenturies(short numberofCentures, ClsDateLibrary & date)
     {
         date.year -= numberofCentures * 10;
         return date;
     }
   void DecreaseDateByXCenturies(short numberofCentures)
   {
        DecreaseDateByXCenturies(numberofCentures, *this);
   }
 static    ClsDateLibrary DecreaseDateByonedecade(ClsDateLibrary &date)
     {
         date.year -= 100;
         return date;
     }
 void DecreaseDateByonedecade()
 {
      DecreaseDateByonedecade(*this);
 }
   static  ClsDateLibrary DecreaseDateByonedecade(short numberofdecades, ClsDateLibrary &date)
     {
         date.year -= numberofdecades * 100;
         return date;
     }
   void DecreaseDateByonedecade(short numberofdecades)
   {
        DecreaseDateByonedecade(numberofdecades, *this);
   }
    static ClsDateLibrary DecreaseDateByMilinuim(ClsDateLibrary &date)
     {
         date.year -= 1000;
         return date;
     }
    void DecreaseDateByMilinuim()
    {
       DecreaseDateByMilinuim(*this);
    }
  static   void PrintMonthCalender(short Year, short Month)
     {
         int NumberOfDays;
         int current = DayOfWeakOrder(1, Month, Year);
         NumberOfDays = NumberOfDaysInAMonthOfAYear(Year, Month);
         //print the name of current month
         printf("\n______________%s______________\n\n", PrintTheMonth(Month).c_str());
         //print the coloumns
         printf(" Sun  Mon  Tuse  Wend  Thurs  Fri  Sat\n");
         //print the spaces to reach the date of the day 
         int i;
         for (i = 0; i < current; i++)
             printf("     ");

         for (int j = 1; j <= NumberOfDays; j++)
         {
             printf("%5d", j);

             if (++i == 7)
             {
                 i = 0;
                 printf("\n");
             }
         }
         printf("\n___________________________________");

     }
 static    void printYearCalender(short Year)
     {
         printf("\n___________________________________\n\n");
         printf("         Calender - %d\n", Year);
         printf("\n____________________________________\n");
         for (int i = 1; i <= 12; i++)
         {
             PrintMonthCalender(Year, i);
         }
         return;
     }

 static ClsDateLibrary AddOneDay(ClsDateLibrary Date)
 {
     if (IsLastDayInAMonth(Date))
     {
         if (IsLastMonthInAYear(Date.months))
         {
             Date.months = 1;
             Date.days = 1;
             Date.year++;
         }
         else
         {
             Date.days = 1;
             Date.months++;
         }
     }
     else
     {
         Date.days++;
     }

     return Date;
 }

 void AddOneDay()

 {
     *this = AddOneDay(*this);
 }
 static short CalculateMyAgeInDays(ClsDateLibrary DateOfBirth)
 {
     return TheDifferanceBetweenTwoDates(DateOfBirth, ClsDateLibrary::GetSystemDate(), true);
 }
 static ClsDateLibrary IncreaseDateByOneWeek(ClsDateLibrary& Date)
 {

     for (int i = 1; i <= 7; i++)
     {
         Date = AddOneDay(Date);
     }

     return Date;
 }

 void IncreaseDateByOneWeek()
 {
     IncreaseDateByOneWeek(*this);
 }

 ClsDateLibrary IncreaseDateByXWeeks(short Weeks, ClsDateLibrary& Date)
 {

     for (short i = 1; i <= Weeks; i++)
     {
         Date = IncreaseDateByOneWeek(Date);
     }
     return Date;
 }

 void IncreaseDateByXWeeks(short Weeks)
 {
     IncreaseDateByXWeeks(Weeks, *this);
 }

 ClsDateLibrary IncreaseDateByOneMonth(ClsDateLibrary& Date)
 {

     if (Date.months == 12)
     {
         Date.months = 1;
         Date.year++;
     }
     else
     {
         Date.months++;
     }

     //last check day in date should not exceed max days in the current month
     // example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
     // be 28/2/2022
     short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonthOfAYear(Date.months, Date.year);
     if (Date.days > NumberOfDaysInCurrentMonth)
     {
         Date.days = NumberOfDaysInCurrentMonth;
     }

     return Date;
 }

 void IncreaseDateByOneMonth()
 {

     IncreaseDateByOneMonth(*this);

 }

 ClsDateLibrary IncreaseDateByXDays(short Days, ClsDateLibrary& Date)
 {

     for (short i = 1; i <= Days; i++)
     {
         Date = AddOneDay(Date);
     }
     return Date;
 }

 void IncreaseDateByXDays(short Days)
 {

     IncreaseDateByXDays(Days, *this);
 }

 ClsDateLibrary IncreaseDateByXMonths(short Months, ClsDateLibrary& Date)
 {

     for (short i = 1; i <= Months; i++)
     {
         Date = IncreaseDateByOneMonth(Date);
     }
     return Date;
 }

 void IncreaseDateByXMonths(short Months)
 {
     IncreaseDateByXMonths(Months, *this);
 }

 static ClsDateLibrary IncreaseDateByOneYear(ClsDateLibrary& Date)
 {
     Date.year++;
     return Date;
 }

 void IncreaseDateByOneYear()
 {
     IncreaseDateByOneYear(*this);
 }

 ClsDateLibrary IncreaseDateByXYears(short Years, ClsDateLibrary& Date)
 {
     Date.year += Years;
     return Date;

 }

 void IncreaseDateByXYears(short Years)
 {
     IncreaseDateByXYears(Years);
 }

 ClsDateLibrary IncreaseDateByOneDecade(ClsDateLibrary& Date)
 {
     //Period of 10 years
     Date.year += 10;
     return Date;
 }

 void IncreaseDateByOneDecade()
 {
     IncreaseDateByOneDecade(*this);
 }

 ClsDateLibrary IncreaseDateByXDecades(short Decade, ClsDateLibrary& Date)
 {
     Date.year += Decade * 10;
     return Date;
 }

 void IncreaseDateByXDecades(short Decade)
 {
     IncreaseDateByXDecades(Decade, *this);
 }

 ClsDateLibrary IncreaseDateByOneCentury(ClsDateLibrary& Date)
 {
     //Period of 100 years
     Date.year += 100;
     return Date;
 }

 void IncreaseDateByOneCentury()
 {
     IncreaseDateByOneCentury(*this);
 }

 ClsDateLibrary IncreaseDateByOneMillennium(ClsDateLibrary& Date)
 {
     //Period of 1000 years
     Date.year += 1000;
     return Date;
 }

 ClsDateLibrary IncreaseDateByOneMillennium()
 {
     IncreaseDateByOneMillennium(*this);
 }
 static short CalculateBusinessDays(ClsDateLibrary DateFrom, ClsDateLibrary DateTo)
 {

     short Days = 0;
     while (IsDate1BeforeDate2(DateFrom, DateTo))
     {
         if (IsBuisnessOfWeak(DateFrom))
             Days++;

         DateFrom = AddOneDay(DateFrom);
     }

     return Days;

 }

 static short CalculateVacationDays(ClsDateLibrary DateFrom, ClsDateLibrary DateTo)
 {
     /*short Days = 0;
     while (IsDate1BeforeDate2(DateFrom, DateTo))
     {
         if (IsBusinessDay(DateFrom))
             Days++;

         DateFrom = AddOneDay(DateFrom);
     }*/

     return CalculateBusinessDays(DateFrom, DateTo);

 }
 //above method is eough , no need to have method for the object

 static ClsDateLibrary CalculateVacationReturnDate(ClsDateLibrary DateFrom, short VacationDays)
 {

     short WeekEndCounter = 0;

     for (short i = 1; i <= VacationDays; i++)
     {

         if (IsEndOfWeak(DateFrom))
             WeekEndCounter++;

         DateFrom = AddOneDay(DateFrom);
     }
     //to add weekends 
     for (short i = 1; i <= WeekEndCounter; i++)
         DateFrom = AddOneDay(DateFrom);

     return DateFrom;
 }
};