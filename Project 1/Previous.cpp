#include "Previous.h"
#include <iostream>

using namespace std;
///////////////////////////////////////////////////////////////////////////
// Previous Implementations
///////////////////////////////////////////////////////////////////////////
Previous::Previous(int nRows, int nCols)
{
    m_rows = nRows;
    m_cols = nCols;
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            m_arena[i][j] = '.';
}
bool Previous::dropACrumb(int r, int c)
{
    r--;
    c--;
    if (r > m_rows || c > m_cols || r < -1 || c < -1)
    {
        return false;
    }
    if (r >= 0 && r <= m_rows && c >= 0 && c <= m_cols) {

        if (m_arena[r][c] == '.')
            m_arena[r][c] = 'A';

        else if (m_arena[r][c] != '.' && m_arena[r][c] != 'Z')
            m_arena[r][c]++;;

        return true;

    }
    else

        return true;
}



void Previous::showPreviousMoves() const
{
    clearScreen();
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++)
        {
            if (m_arena[i][j] == '.')
            {
                cout << '.';
            }
            else
                cout << m_arena[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
