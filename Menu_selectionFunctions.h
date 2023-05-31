#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>

using namespace std;
using namespace sf;



//window displayed when new game button is selected.
void Newgame(){
    RenderWindow window{{600,600},"Difficulty"};
     Font font;
    if(!font.loadFromFile("arial.ttf")){
        cout<<"couldn't load font!";
    }
    Texture texture;
if(!texture.loadFromFile("bg.png")){
   cout<<"couldn't load background image!";
}
Sprite background{texture};
background.setPosition({0.f,0.f});
    //Menu selection buttons.
    Text easyButton("Easy",font,50);
    easyButton.setPosition(255,220);
    easyButton.setFillColor(Color::Black);
    Text mediumButton("Medium",font,50);
    mediumButton.setPosition(255,270);
    mediumButton.setFillColor(Color::Black);
    Text hardButton("Hard",font,50);
    hardButton.setPosition(250,320);
    hardButton.setFillColor(Color::Black);
    Text backButton("Back",font,30);
    backButton.setPosition(3,3);
    backButton.setFillColor(Color::Black);
     while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {if(event.type==Event::Closed){ window.close();}
         else if(event.type==Event::MouseMoved){
            //getting its location(location of button text).
            FloatRect location=easyButton.getGlobalBounds();
            FloatRect location1=mediumButton.getGlobalBounds();
            FloatRect location2=hardButton.getGlobalBounds();
            FloatRect location3=backButton.getGlobalBounds();
            //Changing colour if button is bieng hovered over.
            if(location.contains(event.mouseMove.x,event.mouseMove.y)){
                easyButton.setFillColor(Color::Yellow);}
               else if(location1.contains(event.mouseMove.x,event.mouseMove.y)){
                mediumButton.setFillColor(Color::Yellow);}
               else if(location2.contains(event.mouseMove.x,event.mouseMove.y)){
                hardButton.setFillColor(Color::Yellow);}
                else if(location3.contains(event.mouseMove.x,event.mouseMove.y)){
                backButton.setFillColor(Color::Yellow);}
            else{
             easyButton.setFillColor(Color::Black);
             mediumButton.setFillColor(Color::Black);
             hardButton.setFillColor(Color::Black);
             backButton.setFillColor(Color::Black);
            }}else if(event.type==Event::MouseButtonPressed){
                //again retrieving position of text.
            FloatRect location=easyButton.getGlobalBounds();
            FloatRect location1=mediumButton.getGlobalBounds();
            FloatRect location2=hardButton.getGlobalBounds();
            FloatRect location3=backButton.getGlobalBounds();
            //Changes colour if button is bieng pressed.
            if(location.contains(event.mouseButton.x,event.mouseButton.y)){
                easyButton.setFillColor(Color::Green);
                window.close();                
                easyMode();}
               else if(location1.contains(event.mouseButton.x,event.mouseButton.y)){
                mediumButton.setFillColor(Color::Green);
                window.close();
                mediumMode();
              }
               else if(location2.contains(event.mouseButton.x,event.mouseButton.y)){
                hardButton.setFillColor(Color::Green);
                window.close();
                hardMode();
            }else if(location3.contains(event.mouseButton.x,event.mouseButton.y)){
                backButton.setFillColor(Color::Green);
                window.close();
                  
            }
            
      }

     window.draw(background);
     window.draw(easyButton);
     window.draw(mediumButton);
     window.draw(hardButton);
     window.draw(backButton);
        window.display();}
    }}
    


void Tutorial(){
    RenderWindow window{{1200,675},"Tutorial"};
     Font font;
 if(!font.loadFromFile("arial.ttf")){
        cout<<"couldn't load font!";
    }
    Texture texture;
if(!texture.loadFromFile("bg.png")){
   cout<<"couldn't load background image!";
}
Sprite background{texture};
background.setPosition({0.f,0.f});     
 
 Texture tutorialimage;
 tutorialimage.loadFromFile("sudoku-instructions1.png");
 Sprite instructions{tutorialimage};
     while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))

        {if(event.type==Event::Closed){
            window.close();
        }
        window.draw(background);
        window.draw(instructions);
      
        window.display();
    }}}

 
void loadGame(int solvedgrid[][9]){
  int grid[9][9];
    ifstream in("saved game.txt",ios::in);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int x;
            while(in>>x){
               grid[i][j]=x;
            }
        }
    }
    // Create the game window
    RenderWindow window(VideoMode(600, 600), "Loaded game");
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
                                savedGrid[i][j]=savedgrid2[i][j];
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
                                 save(grid);
                               }
                           else{
            Vector2i mousePos = Mouse::getPosition(window);


                // Determining which cell was clicked.
                int row = mousePos.y / 50;
                int col = mousePos.x / 50;
                
                // Checking if the cell is empty.
                if (grid[row][col] == 0)
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
                        
                        grid[row][col] = num;
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
                if (savedGrid[i][j] !=0)
                {
                    text.setString(to_string(grid[i][j]));//fill  cells.
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
    }
    }

