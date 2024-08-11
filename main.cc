#include <bits/stdc++.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

char bl=215, d=177, pd=188, pg=187, lg=201, ld=200, poz=205, pio=186;
char pole[10][30];
int Xd=3, Yd=9, Xs, Ys;
float wynik=0, highscore=0, oldhighscore=0;
int losuj, klawisz;
bool wyjdz=true;

/*

void gotoxy( int column, int line )
{
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

*/

void ramka()
{
    cout<<lg;
    for(int i=0; i<30; i++)
    {
        cout<<poz<<poz;
    }
    cout<<pg<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<pio;
        for(int j=0; j<30; j++)
        {
            if(pole[i][j]=='p')
                cout<<"  ";
            else if(pole[i][j]=='d')
                cout<<d<<d;
            else if(pole[i][j]=='l')
            {
                //pole[i+1][j]='l';
                cout<<"| ";

            }


        }
        cout<<pio<<endl;;
    }
    cout<<ld;
    for(int i=0; i<30; i++)
    {
        cout<<poz<<poz;
    }
    cout<<pd;

    cout<<endl<<endl<<"wynik: "<<wynik<<endl;

    if(wynik>highscore)
    {
        highscore=wynik;
    }
    cout<<"rekord: "<<highscore;

}


void ruszajl()
{
    for(int i=0; i<30; i++)
    {
        if(pole[9][i]=='l')
        {
            pole[9][i]='p';
            pole[9][i-1]='l';
        }
    }
}

void skacze()
{
    for(int i=0; i<3; i++)
    {

        Ys=Yd;
        Yd--;
        pole[Yd][Xd]='d';
        pole[Ys][Xd]='p';
        system("cls");
        ramka();
        Sleep(30/(i+1)^2);

        if(i==1)
        {
            ruszajl();
        }

    }


    for(int i=0; i<3; i++)
    {
        Ys=Yd;
        Yd++;
        pole[Yd][Xd]='d';
        pole[Ys][Xd]='p';
        system("cls");
        ramka();
        Sleep(30/(i+1)^2);

        if(i==1)
        {
            ruszajl();
        }
    }


}

void lampa()
{

    losuj=rand()%7;
    if(losuj==1)
    {
        pole[9][29]='l';
    }
}

void end()
{


    system("cls");

    cout<<"1 - restart"<<endl;
    cout<<"2 - exit"<<endl;

    unsigned char znak = getch();
    switch( znak )
    {
        case '1':
            {
                system("cls");
                pole[Yd][Xd]='d';
                wynik=0;
                break;
            }


        case '2':
            {
                system( "cls" );
                cout<<endl<<"Na razie :("<<endl;
                system("pause");
                wyjdz=false;
                break;
            }
        default:
            {
                system("cls");
                end();
            }

        }




}


void menu()
{
    cout<<"1 - gra"<<endl;
    cout<<"2 - instrukcja"<<endl;
    cout<<"3 - exit"<<endl;

    unsigned char znak = getch();
    switch( znak )
    {
        case '1':
            {
                system("cls");
                break;
            }

        case '2':
            {
                system("cls");
                cout<<"                   DINOZAUR Z CHROME'A"<<endl;
                cout<<"Drogi Graczu,"<<endl;
                cout<<"Zapewne kiedys, siedzac przy komputerze, miales problem ze swoim"<<endl;
                cout<<"polaczeniem internetowym."<<endl;
                cout<<"Ucieczka od nudy byl wtedy dinozaur unikajacy drzewek."<<endl;
                cout<<"Twoim dinozaurem jest tutaj ta ikonka:"<<endl<<endl;
                cout<<"                                  "<<d<<d<<endl<<endl;
                cout<<"Musisz unikac drzewek, ktore wygladaja tak:"<<endl<<endl;
                cout<<"                                  "<<"| "<<endl<<endl;
                cout<<"Jezeli przeskoczysz je calkowicie dostajesz punkt, jednak gdy dinozaur"<<endl;
                cout<<"naskoczy na drzewko, przewraca sie i co prawda, gra sie nie konczy,"<<endl;
                cout<<"ale punkt nie jest naliczany. Gdy wpadniesz na przeszkode, przegrywasz."<<endl;
                cout<<"Dinozaur skacze po nacisnieciu spacji"<<endl;
                cout<<"Tak jak jest w oryginalnej grze, rekord zanika po zamknieciu programu."<<endl<<endl;
                cout<<"                    MILEJ GRY! :) "<<endl;
                system("pause");
                system("cls");
                menu();

                break;

            }

        case '3':
            {
                system( "cls" );
                cout<<endl<<"Na razie :("<<endl;
                system("pause");
                wyjdz=false;
                break;
            }
        default:
            {
                system("cls");
                menu();
            }

        }
}

void sup()
{
    for(int i=0; i<5; i++)
    {
        cout<<". ";
        Sleep(200);
        system("cls");
        cout<<" .";
        Sleep(200);
        system("cls");
        cout<<"  .";
        Sleep(200);
        system("cls");
    }

    menu();


}



int main()
{
    srand(time(NULL));

    sup();

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<30; j++)
        {
            pole[i][j]='p';
        }
    }

    pole[Yd][Xd]='d';

    for(;;)
    {
        if(wyjdz==false)
        {
            break;
        }

        pole[8][29]='p';

        ramka();

        if(kbhit())
        {
            klawisz=getch();

            if(klawisz==32)
            {
                skacze();
            }

        }

        if(pole[9][29]=='p'&&pole[9][28]=='p'&&pole[9][27]=='p'&&pole[9][26]=='p'&&pole[9][25]=='p')
        {
            lampa();
        }

        ruszajl();

        if(pole[Yd][Xd+1]=='l')
        {
            wynik++;
        }

        if(pole[Yd][Xd]=='l')
        {
            if(wynik>0)
                wynik--;

            system("cls");

            if(highscore>wynik&&highscore>oldhighscore)
            {
                highscore--;
                oldhighscore=highscore;
            }

            ramka();
            system("pause");
            system("cls");

            cout<<"wynik: "<<wynik<<endl;
            cout<<"rekord: "<<highscore<<endl;

            Sleep(2000);
            end();

        }


        Sleep(100);
        system("cls");
    }



}