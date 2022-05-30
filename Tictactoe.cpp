#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;
string user1 = "X";
string user2 = "O";
char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
char player = 'X';
int turns, score1, score2, rounds;
int delay = 1000;

void singlePlayer();
void ttt_computer();
void twoPlayers();
void twoP_option();
void oneP_option();
void display();
void scoreboard();
void playerswitch();
void input();
void clearboard();
char checkwin();

void about();
void reg_entry();
void close();


int main(){
    char choice;
    system("cls");
    cout << "[Main Menu]" << endl;
    cout << "1. Two Players" << endl;
    cout << "2. Versus computer" << endl;
    cout << "3. Register" << endl;
    cout << "4. About" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == '1'){
        twoPlayers();
    }
    else if (choice == '2'){
        player = 'X';
        user2 = "Computer";
        singlePlayer();
    }
    else if (choice == '3'){
        reg_entry();
    } 
    else if (choice == '4'){
        about();
    }
    else if (choice == '5'){
        close();
    } 
    else if (choice != '1' && choice != '2' && choice != '3'){
        cout << "Option not available. Terminating process..." << endl;
        system("Pause");
        main();
    }

    return 0;
}
void playerswitch(){
    if (player == 'X'){
        player = 'O'; 
    } else {
        player = 'X';
    }
}
void twoPlayers(){
    while (1){
        turns++;
        display();
        input();
        if (checkwin() == 'X'){
            score1++;
            rounds++;
            display();
            cout << "\t\t" << user1 << " wins!" << endl;
            system("Pause");
            clearboard();
        }
        else if (checkwin() == 'O'){
            score2++;
            rounds++;
            display();
            cout << "\t\t" << user2 << " wins!" << endl;
            system("Pause");
            clearboard();
        }
        else if (checkwin() == '-' && turns == 9){
            rounds++;
            display();
            cout << "Game Draw!" << endl;
            system("Pause");
            clearboard();
        }
        if (rounds == 5){
            twoP_option();
        } 
        playerswitch();
    }
}
void twoP_option(){
    char option;
    turns = 0;
    rounds = 0;
    if (score1 > score2 ){
        cout << user1 << " won the match!" << endl;
    }
    else if (score2 > score1){
        cout << user2 << " won the match!" << endl;
    }
    else if (score1 == score2){
        cout << "Match-up ended as draw." << endl;
    }
    cout << "[1] Rematch | [2] Main menu" << endl;
    cout << "Select options: ";
    cin >> option;
    if (option == '1'){
        score1 = 0;
        score2 = 0;
        twoPlayers();
    } 
    else if (option == '2'){
        cout << "Saving data ..." << endl;
        system("Pause");
        main();
    }
    else if (option != '1' && option != '2'){
        score1 = 0;
        score2 = 0;
        user1 = "X";
        user1 = "O";
        main();
    }
}
void oneP_option(){
    char option;
    turns = 0;
    rounds = 0;
    if (score1 > score2 ){
        cout << user1 << " won the match!" << endl;
    }
    else if (score2 > score1){
        cout << "The " << user2 << " won the match!" << endl;
    }
    else if (score1 == score2){
        cout << "Match-up ended as draw." << endl;
    }
    cout << "[1] Rematch | [2] Main menu" << endl;
    cout << "Select options: ";
    cin >> option;
    if (option == '1'){
        score1 = 0;
        score2 = 0;
        singlePlayer();
    } 
    else if (option == '2'){
        cout << "Saving data ..." << endl;
        system("Pause");
        main();
    }
    else if (option != '1' && option != '2'){
        score1 = 0;
        score2 = 0;
        user1 = "X";
        main();
    }
}
void display(){
    system("cls");
    cout <<"Player 1: " << user1 << " vs " << "Player 2: " << user2 << endl;
    scoreboard();
    cout <<"-------------" << "\t\t-------------" << endl;
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << 
        "\t\t| " << "1" << " | " << "2" << " | " << "3" << " |" << endl;
    cout << "|---|---|---|" << "\t\t|---|---|---|" << endl;
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << 
        "\t\t| " << "4" << " | " << "5" << " | " << "6" << " |" << endl;
    cout << "|---|---|---|" << "\t\t|---|---|---|" << endl;
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << 
        "\t\t| " << "7" << " | " << "8" << " | " << "9" << " |" << endl;
    cout <<"-------------" << "\t\t-------------" << endl;
    cout <<"    BOARD  " << "\t\t PLACEMENTS" << endl;
}
void scoreboard(){
    cout <<"\t  ================" << endl;
    cout << "\t  | Player 1 [" << score1 << "] |" << endl;
    cout << "\t  | Player 2 [" << score2 << "] |" << endl;
    cout <<"\t  ================" << endl;
}
void clearboard(){
    turns = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = '-';
        }
    }
}
void input(){
    char placement;
    if (player == 'O'){
        cout << user2 << "'s turn. ";
    } else cout << user1 << "'s turn. ";
    cout << "Enter placement: ";
    cin >> placement;

    if (placement == '1'){
        if (board[0][0] == '-'){
            board[0][0] = player;
        } else {
            display();
            cout << "Placement occupied!" << endl;
            input();
        }
    }
    else if (placement == '2'){
        if (board[0][1] == '-'){
            board[0][1] = player;
        } else {
            display();
            cout << "Placement occupied!" << endl;
            input();
        }
    }
    else if (placement == '3'){
        if (board[0][2] == '-'){
            board[0][2] = player;
        } else {
            display();
            cout << "Placement occupied!" << endl;
            input();
        }
    }
    else if (placement == '4'){
        if (board[1][0] == '-'){
            board[1][0] = player;
        } else {
            display();
            cout << "Placement occupied!" << endl;
            input();
        }
    }
    else if (placement == '5'){
        if (board[1][1] == '-'){
            board[1][1] = player;
        } else {
            display();
            cout << "Placement occupied!" << endl;
            input();
        }
    }
    else if (placement == '6'){
        if (board[1][2] == '-'){
            board[1][2] = player;
        } else {
            display();
            cout << "Placement occupied!" << endl;
            input();
        }
    }
    else if (placement == '7'){
        if (board[2][0] == '-'){
            board[2][0] = player;
        } else {
            display();
            cout << "Placement occupied!" << endl;
            input();
        }
    }
    else if (placement == '8'){
        if (board[2][1] == '-'){
            board[2][1] = player;
        } else {
            display();
            cout << "Placement occupied!" << endl;
            input();
        }
    }
    else if (placement == '9'){
        if (board[2][2] == '-'){
            board[2][2] = player;
        } else {
            display();
            cout << "Placement occupied!" << endl;
            input();
        }
    }
    else if (placement != '1' && placement != '2' && placement != '3' && placement != '4' && placement != '5' && placement != '6' && placement != '7' && placement != '8' && placement != '9'){
        display();
        cout << "Incorrect placement." << endl;
        input();
    }
}
char checkwin(){
    //horizontal
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'){
        return 'X';
    }
    else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){
        return 'X';
    }
    else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){
        return 'X';
    }
    //vetrical
    if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){
        return 'X';
    }
    else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){
        return 'X';
    }
    else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){
        return 'X';
    }
    //diagonal
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
        return 'X';
    }
    else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
        return 'X';
    }

    //horizontal
    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'){
        return 'O';
    }
    else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
        return 'O';
    }
    else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
        return 'O';
    }
    //vetrical
    if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){
        return 'O';
    }
    else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
        return 'O';
    }
    else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
        return 'O';
    }
    //diagonal
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
        return 'O';
    }
    else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
        return 'O';
    }

    return '-';
}
void close(){
    char x;
    int seconds;
    cout << "Menu > Exit" << endl;
    system("cls");
    cout << "Are you sure you want to quit?" << endl;
    cout << "[y] yes | [n] no" << endl;
    cin >> x;
    if (x == 'y'){
        cout << "\t\t\t\t\tThank you!" << endl;
        exit(EXIT_SUCCESS);
    } else if (x == 'n'){
        cout << "Returning to main menu. Please wait..." << endl;
        system("Pause");
        main();
    } else {
        system("cls");
        cout << "Warning! Explotion will occur in..." << endl;
        for (seconds = 3; seconds >= 1; seconds--){
            cout << seconds << endl;
            Sleep(delay);
        }
        cout << "Joke, binuang ra bitaw to -- UwU " << endl;

        system("Pause");
        main();
    }
}
void reg_entry(){
    system("cls");
    cout << "Menu > Register " << endl;
    cout << "Enter player 1 username: ";
    cin >> user1;
    cout << "Enter player 2 username: ";
    cin >> user2;

    cout << "Saving data ..." << endl;
    system("Pause");
    main();
}
void singlePlayer(){
    while (1){
        turns++;
        display();
        input();
        if (checkwin() == 'X'){
            score1++;
            rounds++;
            display();
            cout << "\t\t" << user1 << " wins!" << endl;
            system("Pause");
            clearboard();
            if (rounds == 5){
                oneP_option();
            } 
            singlePlayer();
        }
        else if (checkwin() == '-' && turns == 9){
            rounds++;
            display();
            cout << "Game Draw!" << endl;
            system("Pause");
            clearboard();
            if (rounds == 5){
                oneP_option();
            } 
            singlePlayer();
        }
        ttt_computer();
        if (checkwin() == 'O'){
            score2++;
            rounds++;
            display();
            cout << "\t\t" << user2 << " wins!" << endl;
            system("Pause");
            clearboard();
            if (rounds == 5){
                oneP_option();
            } 
            singlePlayer();
        }
        else if (checkwin() == '-' && turns == 9){
            rounds++;
            display();
            cout << "Game Draw!" << endl;
            system("Pause");
            clearboard();
            if (rounds == 5){
                oneP_option();
            } 
            singlePlayer();
        }
    }
}
void ttt_computer(){
    int row, col;
    while(1){
        row = (rand() % 4);
        col = (rand() % 4);

        if(board[row][col] == 'X'){
            continue;
        }
        else if (board[row][col] == 'O'){
            continue;
        }
        else if (board[row][col] == '-'){
            board[row][col] = 'O';
            break;
        }
    }
}
void about(){
    system("cls");
    cout << "Menu > About" << endl;
    cout << "\t\t\t\t\t ===========================" << endl;
    cout << "\t\t\t\t\t| Tic-Tac-Toe [Console Game] |" << endl;
    cout << "\t\t\t\t\t ===========================" << endl;
    cout << "\t\t\t\t\tProgrammer: Paolo Angelo E. Porlas" << endl;
    cout << "\t\t\t\t\tProject: Midterm Exam" << endl;
    cout << "\t\t\t\t\tProfessor: David Matthew Derit" << endl;
    cout << "\t\t\t\t\tCourse: Programming Logic and Design 2" << endl;
    cout << "\t\t\t\t\tSub Date: 09/04/2022" << endl;

    system("Pause");
    main();
}