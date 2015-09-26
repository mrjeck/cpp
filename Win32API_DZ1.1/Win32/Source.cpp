#include <windows.h>
#include <iostream>
#include <tchar.h>
//#define _UNICODE

using namespace std;

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    TCHAR text_1[]=TEXT("Семашко Виктор Сергеевич\nДата Рождения: 07.01.1981\nАдрес: место проживания: г. Минск, ул.\nКирова  д. 68 кв.27\nКонтактная информация:\nТел. +375-29-963-23-71\nE-mail: SVS@tut.by");
    TCHAR text_2[]=TEXT("Профессиональные навыки:\nC,C++\nПрофессиональные цели:\nСтать профессионалом в своем деле.\nОпыт работы:\niTechArt, Минск, www.techart.com.\nОбразование:\nБелорусский государственный университет информатики и радиоэлектроники,\nПрограммное обеспечение информационных технологий, Инженер-программист.");
    TCHAR text_3[]=TEXT("Дополнительные особенности:\nУмение качественно работать. Добросовестность в работе.\nУмение быстро освоить новый программный продукт, технологию.\nОбладание творческими способностями.\nПрисутствие желания работать и зарабатывать.");
    int len=(_tcslen(text_1)+_tcslen(text_2)+_tcslen(text_3))/3;
	TCHAR str[5];
	_itow(len, str, 10);
    MessageBox(0,text_1,TEXT ("Окно-1"),MB_OK|MB_ICONINFORMATION);
    MessageBox(0,text_2,TEXT ("Окно-2"),MB_OK|MB_ICONINFORMATION);
    MessageBox(0,text_3,str,MB_OK|MB_ICONINFORMATION);
    return 0;
}
