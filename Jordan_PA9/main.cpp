#include "Screen.h"
#include "Ships.h"



int main()
{
	// creates window
	sf::RenderWindow window(sf::VideoMode(1000, 700), "Battleship");

	srand((unsigned)time(0));

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
				while (finish != 1)
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
					rules.setString("The object of Battleship is to try and sink all of the super computer's before they sink all of your ships. All of the computer's ships are somewhere\non the super computer's board.  You try and hit them by hovering your mouse over the cell on the opponent's board and clicking that cell (make\nsure to release the mouse button immediately after clicking). The super computer also tries to hit your\nships by with its complex randomization algorithm.");
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
					newGame.setString("Your ships as well as the super computer's ships will be randomly placed on the board using another different even more complex randomization\nalgorithm.");
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
					playingGame.setString("You and the super computer take turns guessing the coordinates. Both player's boards are marked:\nred for hit, white for miss. When all the cells on your ship or the super computer's ship have been hit, the ship will be sunk. You will see on the screen\n which ship has been sunk. As soon as all of one player's\nships have been sunk, the game ends.");
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

					if (sf::Mouse::getPosition(window).y >= 600 && sf::Mouse::getPosition(window).y <= 650)
					{

						exitRules.setColor(sf::Color::Red);
						window.draw(exitRules);
						window.display();

						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (sf::Mouse::getPosition(window).y >= 600 && sf::Mouse::getPosition(window).y <= 650))
						{
							finish = 1;
						}
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

				int finish = 0;

				while (finish != 1)
				{

					int computerTurn = 0;
					// clear window to white
					//window.clear(sf::Color::White);

					


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

					computerTurn = mouseHover(window, computer, player, compText, playerText, carrierC, battleshipC, cruiserC, subC, destroyerC);

					if (carrierC.isDestroyed() == true)
					{

						sf::Text computerCarrier;
						computerCarrier.setFont(font);
						computerCarrier.setString("Carrier Sunk");
						computerCarrier.setCharacterSize(30);
						computerCarrier.setColor(sf::Color::Green);
						computerCarrier.setPosition(sf::Vector2f(110, 450));
						window.draw(computerCarrier);

					}

					if (battleshipC.isDestroyed() == true)
					{

						sf::Text computerBattleship;
						computerBattleship.setFont(font);
						computerBattleship.setString("Battleship Sunk");
						computerBattleship.setCharacterSize(30);
						computerBattleship.setColor(sf::Color::Green);
						computerBattleship.setPosition(sf::Vector2f(110, 490));
						window.draw(computerBattleship);

					}

					if (cruiserC.isDestroyed() == true)
					{

						sf::Text computerCruiser;
						computerCruiser.setFont(font);
						computerCruiser.setString("Cruiser Sunk");
						computerCruiser.setCharacterSize(30);
						computerCruiser.setColor(sf::Color::Green);
						computerCruiser.setPosition(sf::Vector2f(110, 530));
						window.draw(computerCruiser);

					}

					if (subC.isDestroyed() == true)
					{

						sf::Text computerSub;
						computerSub.setFont(font);
						computerSub.setString("Submarine Sunk");
						computerSub.setCharacterSize(30);
						computerSub.setColor(sf::Color::Green);
						computerSub.setPosition(sf::Vector2f(110, 570));
						window.draw(computerSub);

					}

					if (destroyerC.isDestroyed() == true)
					{

						sf::Text computerDestroyer;
						computerDestroyer.setFont(font);
						computerDestroyer.setString("Destroyer Sunk");
						computerDestroyer.setCharacterSize(30);
						computerDestroyer.setColor(sf::Color::Green);
						computerDestroyer.setPosition(sf::Vector2f(110, 610));
						window.draw(computerDestroyer);

					}

					if (carrierC.isDestroyed() == true && battleshipC.isDestroyed() == true && cruiserC.isDestroyed() == true && subC.isDestroyed() == true && destroyerC.isDestroyed() == true)

					{

						finish = 1;

					}

					if (carrierP.isDestroyed() == true)
					{

						sf::Text playerCarrier;
						playerCarrier.setFont(font);
						playerCarrier.setString("Carrier Sunk");
						playerCarrier.setCharacterSize(30);
						playerCarrier.setColor(sf::Color::Red);
						playerCarrier.setPosition(sf::Vector2f(640, 450));
						window.draw(playerCarrier);

					}

					if (battleshipP.isDestroyed() == true)
					{

						sf::Text playerBattleship;
						playerBattleship.setFont(font);
						playerBattleship.setString("Battleship Sunk");
						playerBattleship.setCharacterSize(30);
						playerBattleship.setColor(sf::Color::Red);
						playerBattleship.setPosition(sf::Vector2f(640, 490));
						window.draw(playerBattleship);

					}

					if (cruiserP.isDestroyed() == true)
					{

						sf::Text playerCruiser;
						playerCruiser.setFont(font);
						playerCruiser.setString("Cruiser Sunk");
						playerCruiser.setCharacterSize(30);
						playerCruiser.setColor(sf::Color::Red);
						playerCruiser.setPosition(sf::Vector2f(640, 530));
						window.draw(playerCruiser);

					}

					if (subP.isDestroyed() == true)
					{

						sf::Text playerSub;
						playerSub.setFont(font);
						playerSub.setString("Submarine Sunk");
						playerSub.setCharacterSize(30);
						playerSub.setColor(sf::Color::Red);
						playerSub.setPosition(sf::Vector2f(640, 570));
						window.draw(playerSub);

					}

					if (destroyerP.isDestroyed() == true)
					{

						sf::Text playerDestroyer;
						playerDestroyer.setFont(font);
						playerDestroyer.setString("Destroyer Sunk");
						playerDestroyer.setCharacterSize(30);
						playerDestroyer.setColor(sf::Color::Red);
						playerDestroyer.setPosition(sf::Vector2f(640, 610));
						window.draw(playerDestroyer);

					}

					if (carrierP.isDestroyed() == true && battleshipP.isDestroyed() == true && cruiserP.isDestroyed() == true && subP.isDestroyed() == true && destroyerP.isDestroyed() == true)

					{

						finish = 1;

					}

					window.display();

					if (computerTurn == 1)
					{
						int j = 0;
						int k = 0;

						while (j != 100000000)
						{
							while (k != 10000000)
							{
								k += 1;
							}
							j += 1;
						}



						int randX;
						int randY;

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

						randX = rand() % 10;
						randY = rand() % 10;
						while (player.getNode(randX, randY).getHitMiss() != "None")
						{

							randX = rand() % 10;
							randY = rand() % 10;

						}

						if (player.getNode(randX, randY).getOccupied() == true)
						{

							if (player.getNode(randX, randY).getShip() == "Carrier")
							{
								carrierP.setHits(carrierP.getHits() + 1);
							}
							else if (player.getNode(randX, randY).getShip() == "Battleship")
							{
								battleshipP.setHits(battleshipP.getHits() + 1);
							}
							else if (player.getNode(randX, randY).getShip() == "Cruiser")
							{
								cruiserP.setHits(cruiserP.getHits() + 1);
							}
							else if (player.getNode(randX, randY).getShip() == "Submarine")
							{
								subP.setHits(subP.getHits() + 1);
							}
							else if (player.getNode(randX, randY).getShip() == "Destroyer")
							{
								destroyerP.setHits(destroyerP.getHits() + 1);
							}

							player.setNodeHitMiss(randX, randY, "Hit");
							player.setNodeColor(randX, randY, sf::Color::Red);

							computerTurn = 0;

						}

						else
						{

							player.setNodeHitMiss(randX, randY, "Miss");
							player.setNodeColor(randX, randY, sf::Color::White);

							computerTurn = 0;

						}

						window.display();
						computerTurn = 0;

					}

				}

				if (carrierC.isDestroyed() == true && battleshipC.isDestroyed() == true && cruiserC.isDestroyed() == true && subC.isDestroyed() == true && destroyerC.isDestroyed() == true)

				{

					// creates the computer's and the player's screen
					computer = Screen();
					player = Screen(550, 50);

					player.playerShipSetup();
					computer.computerShipSetup();

					// creates ships for both the player and the computer
					carrierP = AircraftCarrier();
					carrierC = AircraftCarrier();
					battleshipP = Battleship();
					battleshipC = Battleship();
					cruiserP = Cruiser();
					cruiserC = Cruiser();
					subP = Submarine();
					subC = Submarine();
					destroyerP = Destroyer();
					destroyerC = Destroyer();

					int j = 0;
					int k = 0;

					while (j != 100000000)
					{
						while (k != 100000000)
						{
							k += 1;
						}
						j += 1;
					}

					int finish = 0;
					while (finish != 1)
					{

						window.clear(sf::Color::White);

						sf::Text playerWin;
						playerWin.setFont(font);
						playerWin.setString("You win!");
						playerWin.setCharacterSize(75);
						playerWin.setColor(sf::Color::Black);
						playerWin.setPosition(sf::Vector2f(350, 200));
						window.draw(playerWin);

						sf::Text exitGame;
						exitGame.setFont(font);
						exitGame.setString("Press here to go back");
						exitGame.setCharacterSize(50);
						exitGame.setColor(sf::Color::Black);
						exitGame.setPosition(sf::Vector2f(250, 600));
						window.draw(exitGame);

						window.display();

						if (sf::Mouse::getPosition(window).y >= 600 && sf::Mouse::getPosition(window).y <= 650)
						{

							exitGame.setColor(sf::Color::Red);
							window.draw(exitGame);
							window.display();

							if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (sf::Mouse::getPosition(window).y >= 600 && sf::Mouse::getPosition(window).y <= 650))
							{
								finish = 1;
							}
						}

					}

				}

				if (carrierP.isDestroyed() == true && battleshipP.isDestroyed() == true && cruiserP.isDestroyed() == true && subP.isDestroyed() == true && destroyerP.isDestroyed() == true)

				{

					// creates the computer's and the player's screen
					computer = Screen();
					player = Screen(550, 50);

					player.playerShipSetup();
					computer.computerShipSetup();

					// creates ships for both the player and the computer
					carrierP = AircraftCarrier();
					carrierC = AircraftCarrier();
					battleshipP = Battleship();
					battleshipC = Battleship();
					cruiserP = Cruiser();
					cruiserC = Cruiser();
					subP = Submarine();
					subC = Submarine();
					destroyerP = Destroyer();
					destroyerC = Destroyer();

					int j = 0;
					int k = 0;

					while (j != 100000000)
					{
						while (k != 100000000)
						{
							k += 1;
						}
						j += 1;
					}

					int finish = 0;
					while (finish != 1)
					{

						window.clear(sf::Color::White);

						sf::Text playerLose;
						playerLose.setFont(font);
						playerLose.setString("You lose.");
						playerLose.setCharacterSize(75);
						playerLose.setColor(sf::Color::Black);
						playerLose.setPosition(sf::Vector2f(350, 200));
						window.draw(playerLose);

						sf::Text exitGame;
						exitGame.setFont(font);
						exitGame.setString("Press here to go back");
						exitGame.setCharacterSize(50);
						exitGame.setColor(sf::Color::Black);
						exitGame.setPosition(sf::Vector2f(250, 600));
						window.draw(exitGame);

						window.display();

						if (sf::Mouse::getPosition(window).y >= 600 && sf::Mouse::getPosition(window).y <= 650)
						{

							exitGame.setColor(sf::Color::Red);
							window.draw(exitGame);
							window.display();

							if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (sf::Mouse::getPosition(window).y >= 600 && sf::Mouse::getPosition(window).y <= 650))
							{
								finish = 1;
							}
						}

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