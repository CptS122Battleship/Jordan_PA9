#include "Screen.h"
#include "Ships.h"



int main()
{
	// creates window
	sf::RenderWindow window(sf::VideoMode(1000, 700), "Battleship");

	srand((unsigned)time(0));

	int playerSunkShips = 0;
	int computerSunkShips = 0;

	ScreenNode temp;

	// creates the computer's and the player's screen
	Screen computer = Screen();
	Screen player = Screen(550, 50);

	player.playerShipSetup();
	computer.computerShipSetup();

	// creates ships for both the player and the computer
	AircraftCarrier carrierP;
	AircraftCarrier carrierC;
	Battleship battleshipP;
	Battleship battleshipC;
	Cruiser cruiserP;
	Cruiser cruiserC;
	Submarine subP;
	Submarine subC;
	Destroyer destroyerP;
	Destroyer destroyerC;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		////////////////////////////////////////////////////////
		//                    TITLE SCREEN                    //     
		////////////////////////////////////////////////////////

		// clear window to white
		window.clear(sf::Color::White);

		// Font
		sf::Font font;
		font.loadFromFile("arial.ttf");

		// Creates the title screen of the game
		// Title text
		sf::Text title;
		title.setFont(font);
		title.setString("Welcome to Battleship!");
		title.setCharacterSize(50);
		title.setColor(sf::Color::Black);
		title.setPosition(sf::Vector2f(225, 100));
		window.draw(title);

		// Game Instructions
		sf::Text option1;
		option1.setFont(font);
		option1.setString("1. Game Instructions");
		option1.setCharacterSize(50);
		option1.setColor(sf::Color::Black);
		option1.setPosition(sf::Vector2f(245, 175));
		window.draw(option1);

		// Play Game
		sf::Text option2;
		option2.setFont(font);
		option2.setString("2. Play Game");
		option2.setCharacterSize(50);
		option2.setColor(sf::Color::Black);
		option2.setPosition(sf::Vector2f(245, 250));
		window.draw(option2);

		// Exit Game
		sf::Text option3;
		option3.setFont(font);
		option3.setString("3. Exit Game");
		option3.setCharacterSize(50);
		option3.setColor(sf::Color::Black);
		option3.setPosition(sf::Vector2f(245, 325));
		window.draw(option3);

		

		/////////////////////////////////////////////////////////////
		//                    GAME INSTRUCTIONS                    //     
		/////////////////////////////////////////////////////////////

	
		if (sf::Mouse::getPosition(window).y >= 175 && sf::Mouse::getPosition(window).y <= 225)
		{
			window.clear(sf::Color::White);
			option1.setColor(sf::Color::Red);
			window.draw(title);
			window.draw(option1);
			window.draw(option2);
			window.draw(option3);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				int finish = 0;
				while (finish == 0)
				{
					window.clear(sf::Color::White);
					sf::Text rulesTitle;
					rulesTitle.setFont(font);
					rulesTitle.setString("Rules of Battleship");
					rulesTitle.setCharacterSize(50);
					rulesTitle.setColor(sf::Color::Black);
					rulesTitle.setPosition(sf::Vector2f(0, 0));
					window.draw(rulesTitle);

					sf::Text rules;
					rules.setFont(font);
					rules.setString("The object of Battleship is to try and sink all of the other player's before they sink all of your ships. All of the other player's ships are somewhere\non his/her board.  You try and hit them by calling out the coordinates of one of the squares on the board.  The other player also tries to hit your\nships by calling out coordinates.  Neither you nor the other player can see the other's board so you must try to guess where they are.  Each board\nin the physical game has two grids:  the lower (horizontal) section for the player's ships and the upper part (vertical during play) for recording the\nplayer's guesses.");
					rules.setCharacterSize(15);
					rules.setColor(sf::Color::Black);
					rules.setPosition(sf::Vector2f(0, 75));
					window.draw(rules);

					sf::Text newGameTitle;
					newGameTitle.setFont(font);
					newGameTitle.setString("Starting a New Game");
					newGameTitle.setCharacterSize(50);
					newGameTitle.setColor(sf::Color::Black);
					newGameTitle.setPosition(sf::Vector2f(0, 175));
					window.draw(newGameTitle);

					sf::Text newGame;
					newGame.setFont(font);
					newGame.setString("Each player places the 5 ships somewhere on their board.  The ships can only be placed vertically or horizontally. Diagonal placement is not allowed.\nNo part of a ship may hang off the edge of the board.  Ships may not overlap each other.  No ships may be placed on another ship. Once the\nguessing begins, the players may not move the ships. The 5 ships are:  Carrier (occupies 5 spaces), Battleship (4), Cruiser (3), Submarine (3), and\nDestroyer (2).");
					newGame.setCharacterSize(15);
					newGame.setColor(sf::Color::Black);
					newGame.setPosition(sf::Vector2f(0, 250));
					window.draw(newGame);

					sf::Text playingGameTitle;
					playingGameTitle.setFont(font);
					playingGameTitle.setString("Playing the Game");
					playingGameTitle.setCharacterSize(50);
					playingGameTitle.setColor(sf::Color::Black);
					playingGameTitle.setPosition(sf::Vector2f(0, 325));
					window.draw(playingGameTitle);

					sf::Text playingGame;
					playingGame.setFont(font);
					playingGame.setString("Player's take turns guessing by calling out the coordinates. The opponent responds with \"hit\" or \"miss\" as appropriate.  Both players should mark\ntheir board with pegs:  red for hit, white for miss. For example, if you call out F6 and your opponent does not have any ship located at F6, your\nopponent would respond with \"miss\".  You record the miss F6 by placing a white peg on the lower part of your board at F6.  Your opponent records\nthe miss by placing. When all of the squares that one your ships occupies have been hit, the ship will be sunk.   You should announce\n\"hit and sunk\".  In the physical game, a red peg is placed on the top edge of the vertical board to indicate a sunk ship. As soon as all of one player's\nships have been sunk, the game ends.");
					playingGame.setCharacterSize(15);
					playingGame.setColor(sf::Color::Black);
					playingGame.setPosition(sf::Vector2f(0, 400));
					window.draw(playingGame);

					sf::Text exitRules;
					exitRules.setFont(font);
					exitRules.setString("Press here to go back");
					exitRules.setCharacterSize(50);
					exitRules.setColor(sf::Color::Black);
					exitRules.setPosition(sf::Vector2f(200, 600));
					window.draw(exitRules);

					window.display();

					


					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						finish = 1;
					}
				}
				
			}
		}

		////////////////////////////////////////////////////////////
		//                    PLAYING THE GAME                    //     
		////////////////////////////////////////////////////////////

		if (sf::Mouse::getPosition(window).y >= 250 && sf::Mouse::getPosition(window).y <= 300)
		{
			window.clear(sf::Color::White);
			option2.setColor(sf::Color::Red);
			window.draw(title);
			window.draw(option1);
			window.draw(option2);
			window.draw(option3);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				int playerTurn = 0;
				int computerTurn = 0;
				// clear window to white
				//window.clear(sf::Color::White);
				while (playerSunkShips != 5 && computerSunkShips != 5)
				{

					while (playerTurn == 0)

					{

						// clear window to white
						window.clear(sf::Color::White);
						sf::Text compText;
						compText.setFont(font);
						compText.setString("Computer Screen");
						compText.setCharacterSize(35);
						compText.setColor(sf::Color::Black);
						compText.setPosition(sf::Vector2f(110, 5));
						window.draw(compText);

						sf::Text playerText;
						playerText.setFont(font);
						playerText.setString("Player Screen");
						playerText.setCharacterSize(35);
						playerText.setColor(sf::Color::Black);
						playerText.setPosition(sf::Vector2f(640, 5));
						window.draw(playerText);

						// draws both the computer's and player's screen
						int x = 0;
						int y = 0;
						while (x != 10)
						{

							while (y != 10)
							{
								if (computer.getNode(x, y).getHitMiss() == "None")
								{
									computer.setNodeColor(x, y, sf::Color::Cyan);
								}
								window.draw(computer.getNode(x, y));
								window.draw(player.getNode(x, y));
								y += 1;

							}
							y = 0;
							x += 1;

						}

						playerTurn = mouseHover(window, computer, player, compText, playerText, carrierC, battleshipC, cruiserC, subC, destroyerC);
						
						window.display();

						playerTurn = 0;

					}

				}

			}
		}

		////////////////////////////////////////////////////////
		//                    EXIT GAME                       //     
		////////////////////////////////////////////////////////

		if (sf::Mouse::getPosition(window).y >= 325 && sf::Mouse::getPosition(window).y <= 375)
		{
			window.clear(sf::Color::White);
			option3.setColor(sf::Color::Red);
			window.draw(title);
			window.draw(option1);
			window.draw(option2);
			window.draw(option3);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				window.close();
			}

		}

		// displays the screens
		window.display();

	}

	return 0;
}