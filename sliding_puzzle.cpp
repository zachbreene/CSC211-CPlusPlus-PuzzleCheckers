#include <iostream>

// Helper function to swap two integer values by reference.
void change(int &i, int &j){
    int x = i;
    i = j, j = x;
}

// Reads the initial 3x3 puzzle state from standard input.
void create(int puzzle[][3]){
    int val = 0, i = 0, j = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            std::cin >> val;
            puzzle[i][j] = val;
        }
    }
}

int main()
{
    char direction;
    // target represents the solved state of a 3x3 sliding puzzle where 0 is the empty space.
    int arr[3][3], end[9], target[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0}, a = 0, b = 0, i = 0, j = 0;
    bool correct = true;
    
    create(arr);
    
    // Locates the starting coordinates (a, b) of the empty tile '0'.
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(arr[i][j] == 0){
               a = i, b = j; 
            }
        }
    }
    
    // Continuously reads directional character inputs to shift the '0' tile.
    while(std::cin >> direction){
        if(b > 0 && direction == 'L'){ // Move left.
            change(arr[a][b], arr[a][b - 1]);
            b--;
        }
        if(b < 2 && direction == 'R'){ // Move right.
            change(arr[a][b], arr[a][b + 1]);
            b++;
        }
        if(a > 0 && direction == 'U'){ // Move up.
            change(arr[a][b], arr[a - 1][b]);
            a--;
        }
        if(a < 2 && direction == 'D'){ // Move down.
            change(arr[a][b], arr[a + 1][b]);
            a++;
        }
    }
    
    // Flattens the 2D array into a 1D array to check against the target win-state.
    for(i = 0; i < 9; i++){
        end[i] = arr[i/3][i%3];
        if(end[i] != target[i]){
            correct = false; // Mismatch found, puzzle is not solved.
        }
    }
    
    if(correct){
        std::cout << "Solution is good!" << std::endl;
    }
    else{
        std::cout << "Wrong solution!" << std::endl;
    }
}