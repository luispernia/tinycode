#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class TicTac
{
private:
    int rows;
    int columns;

    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> moves;
    std::string square_line = " * * * * * ";
    std::string square_fill = " *       * ";


public:
    TicTac(int columns, int rows)
    {
        this->rows = rows;
        this->columns = columns;
        this->matrix.resize(rows, std::vector<int>(columns));
        this->moves.resize(2, std::vector<int>(columns * rows));
        /* 0 = direct acess */
        /* >0 = 5 * 4 + 1 + n */
    }

    void Print()
    {
        if (this->matrix.size() < 1)
            return;

        for (int i = 0; i < this->rows; i++)
        {
            std::string square = "";
            for (int j = 0; j < 5; j++)
            {
                this->DrawSquare(j, i, square);
            }
            std::cout << square << std::endl;
        }
    }

    void DrawSquare(int j, int i, std::string &square)
    {
        for (int l = 0; l < this->columns; l++)
        {
            std::string spacing = (l == 0 ? " *" : "  *");
            square.append(((j < 1) || (j == 4)) ? this->square_line : (j == 2 ? (std::string(spacing  + "   ").append(std::to_string(i) + std::to_string(l)).append("  *")) : this->square_fill));

        }

        square.append("\n");
    }

    void Mark(int m, int n, int player) {
        this->GetIndex(m,n);
    }

    // get index by entering a real location
    int GetIndex(int m, int n) {
 /* (3 * 2 - 1) = last of 2 row = 5 - (2 - 1) */
 /*    if(3 == 3) = last of 2 row */
 /*    if(3 > 2 */
        int index = 0;
        int lastElementOfRow = (this->columns * m -1);
        index = (lastElementOfRow - this->columns) + n;

        if(n == this->columns)
            index = lastElementOfRow;



        printf("Row=%dColumn=%d Index=%di LastElementRow=%d", m,n, index, lastElementOfRow);
        return 0;
    }

    bool CheckMoves() {
       // check vectically both
       // check horizontally both
       // check curved both
       return true;

    }

    int GetRows() { return this->rows; }

    int GetColumns() { return this->columns; }
};

int main()
{

    int columns = 0;
    int rows = 0;

    while (rows < 3)
    {
        std::cout << "Please enter the rows min=3 " << std::endl;
        std::cin >> rows;
    }

    while (columns < 3)
    {
        std::cout << "Please enter the columns min=3 " << std::endl;
        std::cin >> columns;
    }


    TicTac *tictac = new TicTac(columns, rows);
    int player1 = 0;
    int player2 = 1;

    while(tictac->CheckMoves()) {
        int move1 = 0;
        int move2 = 1;
        tictac->Print();
        printf("%s", "Player 1 turn's\n");
        printf("%s", "Select row position\n");
        scanf("%d", &move1);
        printf("%s", "Select column position\n");
        scanf("%d", &move2);

        tictac->Mark(move1, move2, player1);
    }

    return 0;
}
