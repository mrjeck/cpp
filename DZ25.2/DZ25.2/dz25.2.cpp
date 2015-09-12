#include <iostream>
#include<stdlib.h>
#include <time.h>
# include <conio.h>
# include <stdio.h>

using namespace std;

class Carts;
class Cgame
{
private:
	short player_score;
	short pc_score;
public:
	Cgame ()
	{
		player_score=pc_score=NULL;
	}
	bool play (Carts *pack)
	{
		short i = 0;
		for (; player_score<=21; i++)
		{
			cout<<"get the cart ? (y/n): ";
			fflush(stdin);
			if(getchar() == 'n')
				break;
			print_pack(pack, i);
			player_score+=get_value(pack, i);
		}
		cout<<endl<<endl;
		for (;pc_score<=17; i++)
		{
			print_pack(pack, i);
			pc_score+=get_value(pack, i);
		}

		if ((player_score>21)||((player_score<pc_score)&&(pc_score<=21)))
			return false;
		else
			return true;
	}
	friend short get_value (Carts *pack, short i);
	friend void print_pack(Carts *pack, short i);
};
class Carts
{
private:
	short card;
	short value;
	char suit;
public:
	Carts()
	{
		card=value=NULL;
		suit=NULL;
	}
	void set_card(short c, short v, char s)
	{
		card = c; value = v; suit = s;
	}
	void create (Carts *pack)
	{
		for (short quant_of_pack = 0; quant_of_pack < 1; quant_of_pack++)
		for (short i = 2, m = 0; i < 15; i++)
			for (char j = 3; j < 7; j++, m++)
			{
				short _card = i;
				short _value = i;
				char _suit = j;
				if (i > 10)
					_value = 10;
				if (i==14)
					_value = 11;
				pack[m].set_card (_card, _value, _suit);
			}
	}
		Carts operator[] (short &m)
	{
		return *this;
	}
	void random_mix (Carts *pack)
	{
		short a = 5+rand()%6;
		for (short i = 0 ; i < a; i++)
			for (short j = 0; j < 52; j++)
			{
				Carts tmp_mas[1];
				short tmp = 0;
				short a = rand()%52;
				short b = rand()%52;
				tmp_mas[tmp] = pack[a];
				pack[a] = pack[b];
				pack[b] = tmp_mas[tmp];
			}
	}
	friend short get_value (Carts *pack, short i);
	friend void print_pack(Carts *pack, short i);
};
	short get_value (Carts *pack, short i)
	{
		return pack[i].value;
	}
	void print_pack(Carts *pack, short i)
	{
		if (pack[i].card==11)
		{
			cout<<(char) (pack[i].card + 63);
			cout<<pack[i].suit<<" ";
		}
		if (pack[i].card==12)
		{
			cout<<(char) (pack[i].card + 69);
			cout<<pack[i].suit<<" ";
		}
		if (pack[i].card==13)
		{
			cout<<(char) (pack[i].card + 62);
			cout<<pack[i].suit<<" ";
		}
		if (pack[i].card==14)
		{
			cout<<(char) (pack[i].card + 51);
			cout<<pack[i].suit<<" ";
		}
		if (pack[i].card < 11)
		{
			cout<<pack[i].card;
			cout<<pack[i].suit<<" ";
		}
	}
int main()
{
	srand(time(NULL));
	const short a=52;
	Carts pack[a];
	pack[a].create(pack);
	pack[a].random_mix (pack);
	cout<<endl<<endl;
	Cgame game;
	if(!(game.play (pack)))
		cout<<"\npc win\n\n\n";
	else
		cout<<"\nplaer win\n\n\n";
	return NULL;
}