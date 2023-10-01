#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class TicTac {
private:
    int rows;
    int columns;

    std::vector<std::vector<int>> matrix;
    std::string square_line = " * * * * * ";
    std::string square_fill = " *       * ";

public:
    TicTac(int columns, int rows) {
        this->rows = rows;
        this->columns = columns;
        this->matrix.resize(rows, std::vector<int>(columns));
    }

    void Print() {
        if(this->matrix.size() < 1)
            return;

        for(int i = 0; i < this->rows; i++) {
            std::string square = "";
            for(int j = 0; j < 5; j++) {
                this->DrawSquare(j, i, square);
            }
            std::cout << square << std::endl;
        }
    }

    void DrawSquare(int j, int i, std::string &square) {
        for(int l = 0; l < this->columns; l++) {
            square.append(((j < 1) || (j == 4))? this->square_line : (j == 2 ? (std::string (" *   ").append(std::to_string(i) + std::to_string(l)).append("   * ")) : this->square_fill));
        }

        square.append("\n");
    }

    void Mark(int m, int n, int player) {}

    void CheckMoves() {}

    int GetRows() {return this->rows;}

    int GetColumns() {return this->columns;}
};

int main() {

    int columns = 0;
    int rows = 0;

    while(rows < 3) {
        std::cout << "Please enter the rows min=3 " << std::endl;
        std::cin >> rows;
    }

    while(columns < 3) {
        std::cout << "Please enter the columns min=3 " << std::endl;
        std::cin >> columns;
    }

    TicTac * tictac = new TicTac(columns, rows);

    tictac->Print();

    return 0;
}
