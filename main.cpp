#include <iostream>
using namespace std;

int tab[7][6];
int eleccion, player;
bool fin = false;
int a=0;

void check(int x)
{
    if(tab[x-1][a]!=0 && a<6)
    {
        a++;
        check(x);
    }   else if (player==1 && a<6)
            {
            tab[x-1][a]=1;
            a=0;
            }
        else if (player==2 && a<6)
            {
            tab[x-1][a]=2;
            a=0;
            }
        else
        {
        std::cout << "WRONG!" << std::endl;
        a=0;
        player++;
        }
}

int draw()
{
    system("clear");
    for(int i = 0; i<9; i++)
    {
        if(i<2)
        {
        cout<<"-";
        } else if(i>7)
        {
        cout<<i-1<<"--"<<endl;
        } else {
        cout<<i-1<<"----";
        }
    }
    for(int i = 0; i<6; i++)
    {
        for(int j = 0; j<7; j++)
        {
            if(tab[j][i]!=0)
            {
                if(tab[j][i]==1)
                {
                cout<<"| X |";
                }else cout<<"| O |";
            }
            else cout<<"|   |";
        } cout<< endl;
    }
    for(int i = 0; i<35; i++)
    {
        cout<<"=";
    } cout<<endl;
}

int win_check()
{
    for(int i = 0; i<6; i++)
    {
        for(int j = 0; j<7; j++)
        {
        if(tab[j][i]==1 && tab[j+1][i+1]==1 && tab[j+2][i+2]==1 && tab[j+3][i+3]==1)
            {
            fin = true;
            cout << "\nPLAYER 1 WIN!" << endl;
            }
        if(tab[j][i]==1 && tab[j+1][i-1]==1 && tab[j+2][i-2]==1 && tab[j+3][i-3]==1)
            {
            cout << "\nPLAYER 1 WIN!" << endl;
            fin = true;
            }
        if(tab[j][i]==2 && tab[j+1][i-1]==2 && tab[j+2][i-2]==2 && tab[j+3][i-3]==2)
            {
            cout << "\nPLAYER 2 WIN!" << endl;
            fin=true;
            }
        else if(tab[j][i]==2 && tab[j-1][i-1]==2 && tab[j-2][i-2]==2 && tab[j-3][i-3]==2)
            {
            fin = true;
            cout << "\nPLAYER 2 WIN!" << endl;
            }
        else if(tab[j][i]==1 && tab[j][i-1]==1 && tab[j][i-2]==1 && tab[j][i-3]==1)
            {
            cout << "\nPLAYER 1 WIN!" << endl;
            fin = true;
            }
        else if(tab[j][i]==1 && tab[j-1][i]==1 && tab[j-2][i]==1 && tab[j-3][i]==1)
            {
            cout << "\nPLAYER 1 WIN!" << endl;
            fin = true;
            }
        else if(tab[j][i]==2 && tab[j][i-1]==2 && tab[j][i-2]==2 && tab[j][i-3]==2)
            {
            cout << "\nPLAYER 2 WIN!" << endl;
            fin = true;
            }
        else if(tab[j][i]==2 && tab[j-1][i]==2 && tab[j-2][i]==2 && tab[j-3][i]==2)
            {
            cout << "\nPLAYER 2 WIN!" << endl;
            fin = true;
            }
        }
    }
}
int ai_choice()
{
    return rand() % 7 + 1; // Random column between 1 and 7
}

int p_choice()
{
    player = 1;
    while(fin!=true)
    {
        if (player == 1)
        {
            cout << "PLAYER " << player << ": ";
            cin >> eleccion;
        }
        else
        {
            eleccion = ai_choice();
            cout << "AI chooses column " << eleccion << endl;
        }

        if (eleccion>0 && eleccion<8)
        {
            check(eleccion);
            draw();
            if (player == 1)
            {
                player++;
            }
            else
            {
                player--;
            }
        }
        else
        {
            cout << "Eleccion equivocada!" << endl;
        }
        win_check();
    }
}

int main()
{
    srand(time(0)); // Seed for random number generator

    system("clear");
    cout<<"Bienvenido a conecta 4"<<endl;
   
    draw();
    p_choice();

    return 0;
}