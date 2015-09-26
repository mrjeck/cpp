#include <windows.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

int WINAPI WinMain (HINSTANCE hThisInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpszArgument,
					int nCmdShow)
{
	wchar_t window[]=L"Игра";
	wchar_t text[15]=L"Это число ";
	wchar_t text_2[25]=L"Количество попыток ";
	wchar_t _number[4];
	wchar_t _counter[4];
	int userReply;
	int number;
	int counter;
	vector<int> numbers;
	vector<int>::iterator it;
	srand(time(NULL));
	do
	{
		MessageBox(0,TEXT ("Загадайте число от 1 до 100"),window,MB_OK|MB_ICONWARNING);
		counter=0;
		do
		{
			if(counter==100)
			{
				MessageBox(0,TEXT ("Вы выбрали число не из того диапазона"),window,MB_OK|MB_ICONWARNING);
				break;
			}
			if(numbers.size())
			{
				do
				{	
					number=1+rand()%100;
					it=find(numbers.begin(), numbers.end(), number);
				}while(numbers.end()!=it);
			}
			else
			{
				number=1+rand()%100;
			}
			numbers.push_back(number);
			_itow(number, _number, 10);
			wcscat(text,_number);
			userReply = MessageBox(0,text,window,MB_YESNO|MB_ICONQUESTION);
			text[10]='\0';
			++counter;
		}while(IDNO == userReply);
		_itow(counter,  _counter, 10);
		wcscat(text_2, _counter);
		MessageBox(0,text_2,window,MB_OK|MB_ICONASTERISK);
		text_2[19]='\0';
		userReply=MessageBox(0,TEXT ("Сыграть еще раз?"),window,MB_YESNO|MB_ICONQUESTION);

	}while(IDYES == userReply);

	return 0;
}
