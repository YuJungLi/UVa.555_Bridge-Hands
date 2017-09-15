#include <iostream>
#include <iomanip>
#include <string.h>
#include <algorithm>
#pragma warning( disable : 4996 )
using namespace std;

int main()
{
	freopen("Input.txt", "rt", stdin);
	freopen("Output.txt", "w+t", stdout);
	char s, card_table[104], N[13], E[13], S[13], W[13];
	char num[13] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };
	char suit[4] = { 'C','D','S','H' };
	int card[52];
	while (cin >> s)
	{
		if (s == '#')
			break;

		for (int i = 0; i < 104; i++)
			cin >> card_table[i];

		for (int i = 0; i < 52; i++)
		{
			switch (card_table[i * 2])
			{
			case 'C':	card[i] = 0;	break;
			case 'D':	card[i] = 13;	break;
			case 'S':	card[i] = 26;	break;
			default:	card[i] = 39;	break;
			}
			switch (card_table[i * 2 + 1] - '0')
			{
			case 17:	card[i] += 12;	break;
			case 36:	card[i] += 8;	break;
			case 26:	card[i] += 9;	break;
			case 33:	card[i] += 10;	break;
			case 27:	card[i] += 11;	break;
			default:	card[i] += (card_table[i * 2 + 1] - '2');	break;
			}
		}
		if (s == 'W')
			for (int i = 0; i < 13; i++)
			{
				N[i] = card[i * 4];
				E[i] = card[i * 4 + 1];
				S[i] = card[i * 4 + 2];
				W[i] = card[i * 4 + 3];
			}
		else if (s == 'N')
			for (int i = 0; i < 13; i++)
			{
				E[i] = card[i * 4];
				S[i] = card[i * 4 + 1];
				W[i] = card[i * 4 + 2];
				N[i] = card[i * 4 + 3];
			}
		else if (s == 'E')
			for (int i = 0; i < 13; i++)
			{
				S[i] = card[i * 4];
				W[i] = card[i * 4 + 1];
				N[i] = card[i * 4 + 2];
				E[i] = card[i * 4 + 3];
			}
		else
			for (int i = 0; i < 13; i++)
			{
				W[i] = card[i * 4];
				N[i] = card[i * 4 + 1];
				E[i] = card[i * 4 + 2];
				S[i] = card[i * 4 + 3];
			}

		sort(S, S + 13);
		cout << "S:";
		for (int i = 0; i < 13; i++)
			cout << " " << suit[S[i] / 13] << num[S[i] % 13];
		cout << endl;

		sort(W, W + 13);
		cout << "W:";
		for (int i = 0; i < 13; i++)
			cout << " " << suit[W[i] / 13] << num[W[i] % 13];
		cout << endl;

		sort(N, N + 13);
		cout << "N:";
		for (int i = 0; i < 13; i++)
			cout << " " << suit[N[i] / 13] << num[N[i] % 13];
		cout << endl;

		sort(E, E + 13);
		cout << "E:";
		for (int i = 0; i < 13; i++)
			cout << " " << suit[E[i] / 13] << num[E[i] % 13];
		cout << endl;
	}
	return 0;
}
