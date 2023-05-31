#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;
using namespace sf;

void startGame(){
    RenderWindow window{{600,600}, "Sudoku"};
    //giving a font to load from arial.ttf.
   
    Font font;
    if(!font.loadFromFile("arial.ttf")){
        cout<<"couldn't load font!";
    }
    //Menu selection buttons.
    Text newGamebutton("New game",font,40);
    newGamebutton.setPosition(200,150);
    newGamebutton.setFillColor(Color::Black);
    Text tutorialButton("Tutorial",font,40);
    tutorialButton.setPosition(200,190);
    tutorialButton.setFillColor(Color::Black);
    Text loadGameButton("Load Game",font,40);
    loadGameButton.setPosition(200,230);
    loadGameButton.setFillColor(Color::Black);
    Text exitbutton("Exit",font,40);
   exitbutton.setPosition(200,270);
   exitbutton.setFillColor(Color::Black);

Texture texture;
if(!texture.loadFromFile("bg.png")){
   cout<<"couldn't load background image!";
}
Sprite background{texture};
background.setPosition({0.f,0.f});
//loop to handle events.
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
         if (event.type == Event::Closed){window.close();}
        else if(event.type==Event::MouseMoved){
            //getting its location(location of button text).
            FloatRect location=newGamebutton.getGlobalBounds();
            FloatRect location1=tutorialButton.getGlobalBounds();
            FloatRect location2=loadGameButton.getGlobalBounds();
            FloatRect location3=exitbutton.getGlobalBounds();
            //Changing colour if button is bieng hovered over.
            if(location.contains(event.mouseMove.x,event.mouseMove.y)){
                newGamebutton.setFillColor(Color::Yellow);}
               else if(location1.contains(event.mouseMove.x,event.mouseMove.y)){
                tutorialButton.setFillColor(Color::Yellow);}
               else if(location2.contains(event.mouseMove.x,event.mouseMove.y)){
                loadGameButton.setFillColor(Color::Yellow);}
               else if(location3.contains(event.mouseMove.x,event.mouseMove.y)){
               exitbutton.setFillColor(Color::Yellow);}
            else{
             newGamebutton.setFillColor(Color::Black);
             tutorialButton.setFillColor(Color::Black);
             loadGameButton.setFillColor(Color::Black);
            exitbutton.setFillColor(Color::Black);
            }}else if(event.type==Event::MouseButtonPressed){
                //again retrieving position of text.
                FloatRect location=newGamebutton.getGlobalBounds();
                FloatRect location1=tutorialButton.getGlobalBounds();
                FloatRect location2=loadGameButton.getGlobalBounds();
                FloatRect location3=exitbutton.getGlobalBounds();
            //Changes colour if button is bieng pressed.
            if(location.contains(event.mouseButton.x,event.mouseButton.y)){
                newGamebutton.setFillColor(Color::Green);
                window.close();                
                Newgame();}
               else if(location1.contains(event.mouseButton.x,event.mouseButton.y)){
                tutorialButton.setFillColor(Color::Green);
                window.close();
                Tutorial();}
               else if(location2.contains(event.mouseButton.x,event.mouseButton.y)){
                loadGameButton.setFillColor(Color::Green);
                window.close();
               // loadGame();
            } else if(location3.contains(event.mouseButton.x,event.mouseButton.y)){
               exitbutton.setFillColor(Color::Green);
                window.close();
            }
            }
        
     window.draw(background);
     window.draw(newGamebutton);
     window.draw(tutorialButton);
     window.draw(loadGameButton);
     window.draw(exitbutton);
        window.display();
        }}
}