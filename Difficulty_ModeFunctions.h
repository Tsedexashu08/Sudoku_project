#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

void CheckGameEnd(){
    RenderWindow window(VideoMode(300,100),"Checker");
    Font font;
    font.loadFromFile("arial.ttf");
    Text message("Congrats! you have solved the puzzle.",font,20);
    message.setPosition({10.f,10.f});
    while(window.isOpen()){
          Event event;
          while(window.pollEvent(event)){
            if(event.type==Event::Closed){ window.close();}
          }
        window.draw(message);
        window.display();
    }
}  

//small window to display error message.
void Check(){
    RenderWindow window(VideoMode(300,100),"Checker");
    Font font;
    font.loadFromFile("arial.ttf");
    Text message("Incorrect entry,try again!",font,20);
    message.setPosition({10.f,10.f});
    while(window.isOpen()){
          Event event;
          while(window.pollEvent(event)){
            if(event.type==Event::Closed){ window.close();}
          }
        window.draw(message);
        window.display();
    }
}  

 void Solve(int solvedGrid[][9]){
    // Create the game window
    RenderWindow window(VideoMode(600, 600), "Sudoku");

   Texture background;
   background.loadFromFile("bg.png");
   Sprite backgroundimage{background};
   backgroundimage.setPosition({0.f,0.f});
    // Define the solved Sudoku table.
   
    // Define the font to be used for text
    Font font;
    font.loadFromFile("arial.ttf");

    // Define the text to be displayed in the cells
    Text text;
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(Color::Black);

    Text backButton("Back",font,40);
    backButton.setFillColor(Color::Black);
    backButton.setPosition({475.f,150.f});

    // Main game loop
    while (window.isOpen())
    {
        // Handle events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        // Drawing the Sudoku table
        window.clear(Color::White);
        window.draw(backgroundimage);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // Draw the cell
                RectangleShape cell(Vector2f(50, 50));
                cell.setPosition(j * 50, i * 50);
                cell.setOutlineThickness(4.f);
                cell.setOutlineColor(Color::Black);
                window.draw(cell);
                // Draw the number in the cell if it is not zero
                if (solvedGrid[i][j] !=0)
                {
                    text.setString(to_string(solvedGrid[i][j]));//fill  cells.
                    text.setPosition(j * 50 + 15, i * 50 + 5);
                    window.draw(text);
                    window.draw(backButton);
                }
            }
        }
        window.display();
     }
      
}      


void draw(int table[][9], int solvedGrid[][9],int savedGrid[][9]){
    // Create the game window.
    RenderWindow window(VideoMode(600, 600), "Sudoku");
   Texture background;
   background.loadFromFile("bg.png");
   Sprite backgroundimage{background};
   backgroundimage.setPosition({0.f,0.f});

    // Define the font to be used for text
    Font font;
    font.loadFromFile("arial.ttf");
    Text solve("solve",font,40);
    solve.setFillColor(Color::Black);
    solve.setPosition({475.f,155.f});
     
    // Define the text to be displayed in the cells
    Text text;
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(Color::Black);

    Text backButton("Back",font,40);
    backButton.setFillColor(Color::Black);
    backButton.setPosition({475.f,100.f});
     Text saveGame("Save",font,40);
     saveGame.setPosition(475.f,210.f);
     saveGame.setFillColor(Color::Black);

     Text instruction1("Instructions",font,35);
     instruction1.setFillColor(Color::Yellow);
     instruction1.setPosition(15.f,470.f);
    
     Text instruction2("1.Select a Grid then enter a number.",font,35);
     instruction2.setFillColor(Color::Yellow);
     instruction2.setPosition(15.f,515.f);
    
     Text instruction3("2.Solve the puzzle.",font,35);
     instruction3.setFillColor(Color::Yellow);
     instruction3.setPosition(15.f,555.f);
     for(int i=0;i<9;i++){
            for(int j=0;i<9;i++){
                                savedGrid[i][j]=table[i][j];
                        }
                    }//giving saved grid all the tables first  elements.

    // Main game loop
    while (window.isOpen())
    {
        // Handle events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }else if(event.type==Event::MouseMoved){
                FloatRect solvebutton=solve.getGlobalBounds();
                        FloatRect Gobackbutton=backButton.getGlobalBounds();
                             FloatRect saveButton=saveGame.getGlobalBounds();
                        if(solvebutton.contains(event.mouseMove.x,event.mouseMove.y)){
                            solve.setFillColor(Color::Yellow);
                        }else if(Gobackbutton.contains(event.mouseMove.x,event.mouseMove.y)){
                            backButton.setFillColor(Color::Yellow);
                        }else if(saveButton.contains(event.mouseMove.x,event.mouseMove.y)){
                            saveGame.setFillColor(Color::Yellow);
                        }else{
                            backButton.setFillColor(Color::Black);
                            solve.setFillColor(Color::Black);
                            saveGame.setFillColor(Color::Black);
                        }
            }
            
            else if(event.type==Event::MouseButtonPressed){
                  FloatRect solvebutton=solve.getGlobalBounds();
                           FloatRect Gobackbutton=backButton.getGlobalBounds();
                            FloatRect saveButton=saveGame.getGlobalBounds();
                           if(solvebutton.contains(event.mouseButton.x,event.mouseButton.y)){
                                  window.close();
                                  Solve(solvedGrid);
                           }else if(Gobackbutton.contains(event.mouseButton.x,event.mouseButton.y)){
                                 window.close();
                            //back to menu.
                           }else if(saveButton.contains(event.mouseButton.x,event.mouseButton.y)){
                                 //save function
                                 save(table);
                               }
                           else{
            Vector2i mousePos = Mouse::getPosition(window);


                // Determining which cell was clicked.
                int row = mousePos.y / 50;
                int col = mousePos.x / 50;
                
                // Checking if the cell is empty.
                if (table[row][col] == 0)
                {
                    // Get the number input from the player.
                    int num;
                    cout << "Enter a number: ";
                    cin >> num;

                    // Validate the input
                    if ((num >= 1 && num <= 9)){
                            //checking if input is correct.
                        while(num!=solvedGrid[row][col]){
                            Check();
                             cout << "Enter a number: ";
                             cin >> num;
                         
                           
                            }
                        
                        // Update the table with the user's input
                        
                        table[row][col] = num;
                        savedGrid[row][col]=num;//updating the saved grid array.
                        break;
                    }
                }
            }  
        }
        
        // Drawing the Sudoku table
        window.clear(Color::White);
        window.draw(backgroundimage);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // Draw the cell
                RectangleShape cell(Vector2f(50, 50));
                cell.setPosition(j * 50, i * 50);
                cell.setOutlineThickness(4.f);
                cell.setOutlineColor(Color::Black);
                window.draw(cell);
                // Draw the number in the cell if it is not zero
                if (table[i][j] !=0)
                {
                    text.setString(to_string(table[i][j]));//fill  cells.
                    text.setPosition(j * 50 + 15, i * 50 + 5);
                    window.draw(text);
                    window.draw(solve);
                    window.draw(backButton);
                    window.draw(saveGame);
                    window.draw(instruction1);
                    window.draw(instruction2);
                    window.draw(instruction3);
                }
            }
        }
        window.display();
        }
    }int x=0;
      for(int i=0;i<9;i++){
        for(int j=0;j<9;i++){
            if(table[i][j]==0){
                   x=0;
            }else{x=1;};
            
        }
      }
      if(x=1){
            CheckGameEnd();
      }
    }


 
 
//renders a window with sudoku table for each mode of difficulty.
void easyMode(){
   int table[9][9] = {
        {2, 4, 0, 6, 0, 5, 3, 8, 7},
        {0, 3, 5, 4, 2, 8, 0, 0, 9},
        {0, 6, 0, 7, 0, 1, 4, 2, 5},
        {4, 1, 3, 8, 0, 9, 0, 5, 6},
        {6, 9, 0, 5, 0, 3, 7, 4, 8},
        {5, 0, 7, 0, 4, 6, 9, 0, 1},
        {0, 7, 0, 3, 6, 0, 0, 9, 0},
        {9, 0, 4, 0, 8, 0, 6, 7, 0},
        {3, 2, 6, 0, 5, 0, 8, 0, 4}};
    int solvedGrid[9][9]={
        {2, 4, 1, 6, 9, 5, 3, 8, 7},
        {7, 3, 5, 4, 2, 8, 1, 6, 9},
        {8, 6, 9, 7, 3, 1, 4, 2, 5},
        {4, 1, 3, 8, 7, 9, 2, 5, 6},
        {6, 9, 2, 5, 1, 3, 7, 4, 8},
        {5, 8, 7, 2, 4, 6, 9, 3, 1},
        {1, 7, 8, 3, 6, 4, 5, 9, 2},
        {9, 5, 4, 1, 8, 2, 6, 7, 3},
        {3, 2, 6, 9, 5, 7, 8, 1, 4}};
        int savedgrid[9][9];
   draw(table,solvedGrid,savedgrid);
}
void mediumMode(){
    int solvedGrid[9][9]={
        {8, 7, 6, 4, 9, 3, 2, 5, 1},
        {3, 4, 5, 7, 1, 2, 9, 6, 8},
        {2, 9, 1, 5, 6, 8, 4, 7, 3},
        {9, 8, 2, 1, 3, 5, 7, 4, 6},
        {7, 5, 4, 8, 2, 6, 3, 1, 9},
        {1, 6, 3, 9, 4, 7, 8, 2, 5},
        {4, 1, 7, 3, 5, 9, 6, 8, 2},
        {6, 3, 8, 2, 7, 1, 5, 9, 4},
        {5, 2, 9, 6, 8, 4, 1, 3, 7}};
   int table[9][9]={
        {0, 0, 6, 0, 9, 0, 2, 0, 1},
        {0, 0, 0, 7, 0, 2, 0, 0, 0},
        {0, 9, 0, 5, 0, 8, 0, 7, 0},
        {9, 0, 0, 0, 3, 0, 0, 0, 6},
        {7, 5, 0, 0, 0, 0, 0, 1, 9},
        {1, 0, 0, 0, 4, 0, 0, 0, 5},
        {0, 1, 0, 3, 0, 9, 0, 8, 0},
        {0, 0, 0, 2, 0, 1, 0, 0, 0},
        {0, 0, 9, 0, 8, 0, 1, 0, 0}};
  int savedgrid[9][9];

    draw(table,solvedGrid,savedgrid);
    }

void hardMode(){
    int solvedGrid[9][9]={
        {1, 6, 5, 8, 4, 7, 9, 2, 3},
        {7, 8, 9, 3, 1, 2, 5, 4, 6},
        {4, 3, 2, 5, 9, 6, 1, 7, 8},
        {2, 9, 7, 4, 6, 3, 8, 5, 1},
        {5, 1, 8, 7, 2, 9, 3, 6, 4},
        {3, 4, 6, 1, 5, 8, 2, 9, 7},
        {9, 7, 3, 2, 8, 4, 6, 1, 5},
        {8, 2, 1, 6, 7, 5, 4, 3, 9},
        {6, 5, 4, 9, 3, 1, 7, 8, 2}};
    int table[9][9]={
      {0, 0, 0, 0, 8, 0, 0, 0, 0},
      {7, 8, 9, 0, 1, 0, 0, 0, 6},
      {0, 0, 0, 0, 0, 6, 1, 0, 0},
      {0, 0, 7, 0, 0, 0, 0, 5, 0},
      {5, 0, 8, 7, 0, 9, 3, 0, 4},
      {0, 4, 0, 0, 0, 0, 2, 0, 0},
      {0, 0, 3, 2, 0, 0, 0, 0, 0},
      {8, 0, 0, 0, 7, 0, 4, 3, 9},
      {0, 0, 0, 0, 0, 1, 0, 0, 0}};
    int savedgrid[9][9];
draw(table,solvedGrid,savedgrid);
}

