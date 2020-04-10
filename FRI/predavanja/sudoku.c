#include <stdio.h>
#include <stdlib.h>

int sudoku [9][9] = 
    { { 4, 0, 0, 0, 5, 2, 3, 0, 0 },    
      { 0, 9, 3, 0, 8, 0, 0, 0, 5 },    
      { 0, 7, 0, 0, 6, 0, 2, 0, 0 },    
      { 0, 0, 0, 8, 4, 0, 0, 0, 0 },    
      { 0, 5, 4, 9, 0, 7, 0, 3, 0 },    
      { 0, 0, 0, 5, 1, 6, 0, 0, 8 },
      { 0, 0, 0, 0, 0, 0, 8, 7, 1 },
      { 0, 0, 9, 0, 0, 4, 6, 0, 0 },
      { 7, 6, 5, 0, 0, 8, 9, 0, 0 } };
      
int solve (int i, int j)
{
    if((i == 9) && (j == 0)){
        for(int ii = 0; ii < 9; ii++){
            for(int jj = 0; jj < 9; jj++){
                printf("%2d\n", sudoku[ii][jj]);
            }
        }
        return 1;
    }
    if(sudoku[i][j] != 0){
        int new_i, new_j;
        if(i == 8){
            //skok v novo vrstico
            new_i = i + 1;
            new_j = 0;
        }else{
            new_i = i;
            new_j = j + 1;
        }
        solve(new_i, new_j);
    }else {
        for(int n = 1; n <= 9; n++){
            int found = 0;
            for(int ii = 0; ii < 9; ii++)
                found = found || (sudoku[ii][j] == n);
            for(int jj = 0; jj < 9; jj++)
                found = found || (sudoku[jj][j] == n);
            for(int ii = 0; ii < 3; ii++){
                for(int jj = 0; jj < 3; jj++){
                    found = found || 
                            (sudoku[(i/3 * 3 + ii)][(j/3) * 3 + jj] == n);
                }        
            }
            if(!found){
                //n je veljavna vrednost za celici (i, j)
                sudoku[i][j] = n;
                if(solve ((j == 8) ? i + 1 : i, (j == 8) ? 0 : j + 1) != 0)
                    return 1;
                //tu se nekaj manka
                sudoku[i][j] = 0;
            }
        }
    }
    return 0;
}

int main ()
{
    solve(0, 0);
    return 0;
}