class Tablero {
protected:
    int tab[7][6];
public:
    Tablero() {
        for(int i = 0; i < 7; i++)
            for(int j = 0; j < 6; j++)
                tab[i][j] = 0;
    }
    // Métodos para manipular el tablero
};