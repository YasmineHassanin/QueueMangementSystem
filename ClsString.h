#pragma once
#include<iostream>
#include<vector>
using namespace std;
class ClsString
{
private:
    string _Value;
   /* int _Number;*/
public:
  
    ///*Default Constructor*/
    ClsString()
    {
        _Value = "";
    }
    /*Paramaterized Constructor*/
    ClsString(string Value)
    {
        _Value = Value;
    }
    /*Set Property value*/
    void SetValue(string Value)
    {
        _Value = Value;
    }
    /*Get Property value*/
    string GetValue()
    {
        return _Value;
    }
    /*Instead of get/set properties and using Value when me calling them*/
    __declspec(property(get=GetValue,put=SetValue))string Value;
  

    ////////////////////////////////1-the first function///////////////////////////////////////////////////////////////////
    static vector<string>SplitString(string Line, string Separator)
    {
        string SwordThatSeparated;
        short position=0;
        vector <string> Vstring;
        ///serach about the separetor
        while ((position = Line.find(Separator)) != std::string::npos)
        {
            //if you found the position of delimter ,cut the string from 0 to the position of delimter and save it in string
            SwordThatSeparated = Line.substr(0, position);
            //check if the string not equal space ,push the all words in vector 
            if (SwordThatSeparated != "")
            {
                Vstring.push_back(SwordThatSeparated);
            }
            //erase the part of string and it's delimter that saved already
            Line.erase(0, position + Separator.length());
        }
        //store the last word in vector 
        if (Line != "")
        {
            Vstring.push_back(Line);
        }
        return Vstring;
    }
 
    vector<string>SplitString(string Delimter)
    {
        return SplitString(_Value, Delimter);
    }
    /////////////////////////////////////the second function//////////////////////////////////////////////
    static short CountWords(string S1)
    {

        string delim = " "; // delimiter  
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;
    }
    /*The OverLoading Function*/
    short CountWords()
    {
        return CountWords(_Value);
    };
    //////////////////////////////3-third function/////////////////////////////////////////////////////////
  static  string  TrimLeft(string name)
    {
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] != ' ')
            {
                return name.substr(i, name.length() - 1);
            }
        }
    }
    string  TrimLeft()
    {
        return TrimLeft(_Value);
    }
    //////////////////////////////4-the fourth function/////////////////////////////////
  static  string TrimRight(string name)
    {
      int i;
        for ( i= name.length() - 1; i >= 0; i--)
        {
            if (name[i] != ' ')
            {
                return name.substr(0, i + 1);
            }
        }
    }
    string  TrimRight()
    {
        return TrimRight(_Value);
    }
    ///////////////////////////////////5-the fifth function//////////////////////////////////////////
   static string Trim(string name)
    {
        return TrimLeft(TrimRight(name));
    }
    string Trim()
    {
        return Trim(_Value);
    }
    ///////////////////////////////////////6-////////////////////////////////////////////////////////////
   static string Join_fun(vector<string>VjoinString, string delimter)
    {
        string s1;
        for (string& s : VjoinString)
        {
            s1 = s1 + s + delimter;
        }
        return s1.substr(0, s1.length() - delimter.length());
    }
   /////////////////////////////////////////7-///////////////////////////////////////////////////////////
   static string Join_fun(string arr[], int length, string delimter)
    {
        string s1;
        for (int i = 0; i < length; i++)
        {
            s1 = s1 + arr[i] + delimter;
        }
        return s1.substr(0, s1.length() - delimter.length());
    }
   ////////////////////////////////////8-//////////////////////////////////////////////////////////
  static string reversestring(string s1)
   {
       vector <string>vString;
       string s2 = "";
       vString = SplitString(s1, " ");
       vector<string>::iterator iter = vString.end();
       while (iter != vString.begin())
       {
           --iter;
           s2 += *iter + " ";//s2=s2+*iter;
       }
       s2 = s2.substr(0, s2.length() - 1);
       return s2;
   }
   string reversestring()
   {
       return reversestring(_Value);
   }
   ////////////////////////////////////11-//////////////////////////////////////
   string replacethestringtoanotheroneUsingbuildinfunction(string s1, string replaceword, string replaceto)
   {
       short pos = 0;
      pos = s1.find(replaceword);
       while (pos != std::string::npos)
       {
           s1 = s1.replace(pos, replaceword.length(), replaceto);
           pos = s1.find(replaceword);//find next
       }
       return s1;
   }
 static  string ReplaceFunctionUsingSplitFunction(string s1, string StringToReplace, string NewStringReplaced, bool matchcase = true)
   {
       int pos = s1.find(StringToReplace);
       while (pos != std::string::npos)
       {
           vector<string> vString = SplitString(s1, " ");
           for (string& str : vString)
           {
               if (matchcase)
               {
                   if (str == StringToReplace)
                   {
                       str = NewStringReplaced;
                   }
               }
               else
               {
                   if (LowerAllString(str) == LowerAllString(StringToReplace))
                   {
                       str = NewStringReplaced;
                   }
               }

           }

           return Join_fun(vString, " ");
       }
   }

   ////////////////////////////////////////12-//////////////////////////////////////
  static string  LowerAllString(string S1)
   {
       for (short i = 0; i < S1.length(); i++)
       {
           S1[i] = tolower(S1[i]);
       }
       return S1;
   }
  string  LowerAllString()
  {
      return LowerAllString(_Value);
  }
  //////////////////////////////////////////////////////////////////////
  static string  UpperAllString(string S1)
  {
      for (short i = 0; i < S1.length(); i++)
      {
          S1[i] = toupper(S1[i]);
      }
      return S1;
  }

  void  UpperAllString()
  {
      _Value = UpperAllString(_Value);
  }

  /////////////////////////////////////////13-/////////////////////////////////////////
static string REmovePuncfromString(string s1)
  {
      string s2 = "";
      for (short i = 0; i < s1.length(); i++)
      {
          if (!ispunct(s1[i]))
          {
              s2 += s1[i];
          }
      }
      return s2;
  }
  string REmovePuncfromString()
  {
      return REmovePuncfromString(_Value);
  }
  ///////////////////////////////////////////////14-/////////////////////////////////////////////
   static short Length(string S1)
  {
      return S1.length();
  };
  short Length()
  {
      return Length(_Value);
  }
  ///////////////////////////////////////////15-///////////////////////////////////////////////
  static string  UpperFirstLetterOfEachWord(string S1)
  {
      bool isFirstLetter = true;
      short i;
      for (i = 0; i < S1.length(); i++)
      {
          if (S1[i] != ' ' && isFirstLetter)
          {
              S1[i] = toupper(S1[i]);
          }
          isFirstLetter = (S1[i] == ' ' ? true : false);
      }
      return S1;
  }
  void UpperFirstLetterOfEachWord()
  {
      _Value= UpperFirstLetterOfEachWord(_Value);
  }
  ///////////////////////////////////////////////////////////////
  static string  LowerFirstLetterOfEachWord(string S1)
  {
      bool isFirstLetter = true;
      short i;
      for (i = 0; i < S1.length(); i++)
      {

          if (S1[i] != ' ' && isFirstLetter)
          {
              S1[i] = tolower(S1[i]);

          }

          isFirstLetter = (S1[i] == ' ' ? true : false);

      }

      return S1;
  }
  void  LowerFirstLetterOfEachWord()
  {
      // no need to return value , this function will directly update the object value  
      _Value = LowerFirstLetterOfEachWord(_Value);
  }
  /////////////////////////////////////////////////////////////////////////////////
  static bool IsVowel(char Ch1)
  {
      Ch1 = tolower(Ch1);

      return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

  }
  static short  CountVowels(string S1)
  {

      short Counter = 0;

      for (short i = 0; i < S1.length(); i++)
      {

          if (IsVowel(S1[i]))
              Counter++;
      }
      return Counter;
  }

  short  CountVowels()
  {
      return CountVowels(_Value);
  }
/////////////////////////////////////////////////////////////
  static char  InvertLetterCase(char char1)
  {
      return isupper(char1) ? tolower(char1) : toupper(char1);
  }
  /// /////////////////////////////////////////////////////////
 
  static string  InvertAllLettersCase(string S1)
  {
      for (short i = 0; i < S1.length(); i++)
      {
          S1[i] = InvertLetterCase(S1[i]);
      }
      return S1;
  }
  ////////////////////////////////////////////////////
  void  InvertAllLettersCase()
  {
      _Value = InvertAllLettersCase(_Value);
  }

  /// ////////////////////////////////////////////////
  enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

  static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
  {


      if (WhatToCount == enWhatToCount::All)
      {
          return S1.length();
      }

      short Counter = 0;

      for (short i = 0; i < S1.length(); i++)
      {

          if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
              Counter++;


          if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
              Counter++;


      }

      return Counter;

  }
 
  /// ////////////////////////////////////////////////////////////////////////////////////

  static short  CountCapitalLetters(string S1)
  {

      short Counter = 0;

      for (short i = 0; i < S1.length(); i++)
      {

          if (isupper(S1[i]))
              Counter++;

      }

      return Counter;
  }

  short  CountCapitalLetters()
  {
      return CountCapitalLetters(_Value);
  }

  static short  CountSmallLetters(string S1)
  {

      short Counter = 0;

      for (short i = 0; i < S1.length(); i++)
      {

          if (islower(S1[i]))
              Counter++;
      }
      return Counter;
  }
  short  CountSmallLetters()
  {
      return CountSmallLetters(_Value);
  }
  static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
  {
      short Counter = 0;
      for (short i = 0; i < S1.length(); i++)
      {
          if (MatchCase)
          {
              if (S1[i] == Letter)
                  Counter++;
          }
          else
          {
              if (tolower(S1[i]) == tolower(Letter))
                  Counter++;
          }
      }
      return Counter;
  }
  short  CountSpecificLetter(char Letter, bool MatchCase = true)
  {
      return CountSpecificLetter(_Value, Letter, MatchCase);
  }
 /////////////////////////////////////////////////////////////
};

