/****************************************
    Project Name: Tic Tac Toe Game
    Author:       Dhrubo Roy Partho
    Date:         15/09/2022
    Version:      1.0v
****************************************/

#include<bits/stdc++.h>
using namespace std;

char cell[3][3]={'1', '2', '3',
                 '4', '5', '6',
                 '7', '8', '9'};        // Initializing Game Board Data

int check_result()          // For check the result
{
    // Cross check start
    if(cell[0][0] == cell[1][1] && cell[1][1] == cell[2][2]){
        cout<<"\'"<<cell[0][0]<<"\' is winner......\n"<<endl;
        return 1;
    }
    else if(cell[0][2] == cell[1][1] && cell[1][1] == cell[2][0]){
        cout<<"\'"<<cell[0][2]<<"\' is winner......\n"<<endl;
        return 1;
    }
    //Cross check end


    // Horizontal check start
    else if(cell[0][0] == cell[0][1] && cell[0][1] == cell[0][2]){
        cout<<"\'"<<cell[0][0]<<"\' is winner......\n"<<endl;
        return 1;
    }
    else if(cell[1][0] == cell[1][1] && cell[1][1] == cell[1][2]){
        cout<<"\'"<<cell[1][0]<<"\' is winner......\n"<<endl;
        return 1;
    }
    else if(cell[2][0] == cell[2][1] && cell[2][1] == cell[2][2]){
        cout<<"\'"<<cell[2][0]<<"\' is winner......\n"<<endl;
        return 1;
    }
    //Horizontal check end


    //Vertical check start
    else if(cell[0][0] == cell[1][0] && cell[1][0] == cell[2][0]){
        cout<<"\'"<<cell[0][0]<<"\' is winner......\n"<<endl;
        return 1;
    }
    else if(cell[0][1] == cell[1][1] && cell[1][1] == cell[2][1]){
        cout<<"\'"<<cell[0][1]<<"\' is winner......\n"<<endl;
        return 1;
    }
    else if(cell[0][2] == cell[1][2] && cell[1][2] == cell[2][2]){
        cout<<"\'"<<cell[0][2]<<"\' is winner......\n"<<endl;
        return 1;
    }
    //Vertical check end

    else return -1;     // If result is not defined
}

void draw_lines()           // For drawing the lines
{
    cout<<"Tic Tac Toe\n-----------\n\n";
    cout<<cell[0][0]<<" | "<<cell[0][1]<<" | "<<cell[0][2]<<endl;
    cout<<"---------"<<endl;
    cout<<cell[1][0]<<" | "<<cell[1][1]<<" | "<<cell[1][2]<<endl;
    cout<<"---------"<<endl;
    cout<<cell[2][0]<<" | "<<cell[2][1]<<" | "<<cell[2][2]<<endl;
    cout<<endl;
}

void take_input_A()         // For take input of player A
{
    char data;
    cout<<endl;
    cout<<"Player A (Enter 1-9) - ";
    cin>>data;
    int x,y,num = data - '0';   // Converting character to integer
    num--;      // Decreasing number
    x = num/3;          // Cell position calculating
    y = num%3;
    if(cell[x][y] == 'X' || cell[x][y] == 'O'){
        system("CLS");
        cout<<data<<" is not a valid number. Please, enter a valid number.";
        draw_lines();
        take_input_A();
    }
    else{
        cell[x][y] = 'X';
        system("CLS");
        draw_lines();
    }
}

void take_input_B()         // For take input of player B
{
    char data;
    cout<<endl;
    cout<<"Player B (Enter 1-9) - ";
    cin>>data;
    int x,y,num = data - '0';       // Converting character to integer
    num--;      // Decreasing number
    x = num/3;          // Cell position calculating
    y = num%3;
    if(cell[x][y] == 'X' || cell[x][y] == 'O'){
        system("CLS");
        cout<<data<<" is not a valid number. Please, enter a valid number.";
        draw_lines();
        take_input_B();
    }
    else{
        cell[x][y] = 'O';
        system("CLS");
        draw_lines();
    }
}

int main()
{
    int t=0;    // Initializing test case number
    system("CLS");      // Screen clearing
    draw_lines();       // Drawing Game Board
    while(1){       // Infinity loop
        if(t%2 == 0){       // This system for take input successively
            take_input_A();
            int res = check_result();
            if(res == 1) return 0;
        }
        else{
            take_input_B();
            int res = check_result();
            if(res == 1) return 0;
        }
        t++;        // Test case increasing
        if(t == 9){
            cout<<"Match is draw...\n"<<endl;
            return 0;
        }
    }
    return 0;
}