# Chess
Text Based Chess Program Made in C

![image](https://github.com/matthewduffy33/Chess/assets/105711454/30db6ac0-cb18-44f1-9882-9d55e22ce1ea)

Features:
Move a Piece: Select a starting space and a destination space.

![image](https://github.com/matthewduffy33/Chess/assets/105711454/8b3800ae-02e2-41a6-9bf9-77252d0527bd)

View a Piece: Select a piece and see the moves it can make.

![image](https://github.com/matthewduffy33/Chess/assets/105711454/7659bcfe-3979-44e0-9e73-7bd70fdeba9f)
![image](https://github.com/matthewduffy33/Chess/assets/105711454/b4acac4b-55bf-4aec-afeb-98bbf03159ef)


Castling: Select a side to castle on (if any are possible).

![image](https://github.com/matthewduffy33/Chess/assets/105711454/d71e8ebb-61e7-4ee2-b8c3-16e283513181)

![image](https://github.com/matthewduffy33/Chess/assets/105711454/8527a8ac-02ab-4501-92eb-c217540008c3)

![image](https://github.com/matthewduffy33/Chess/assets/105711454/8c8fb991-438a-4b06-a158-78473bba713e)

History: See a previous move play out again.

![image](https://github.com/matthewduffy33/Chess/assets/105711454/0460a200-4d34-4550-80e0-0d008a955ef0)


Hist List: List of previously made moves.

![image](https://github.com/matthewduffy33/Chess/assets/105711454/a5b6488a-53fd-42e6-920f-16bcd11a17e8)

Resigining is simply forfeiting the win
Saving is Saving and quiting so you can return later
Quitting is for when both players wish to quit

I ran and compiled in Cygwin using 
gcc -g chess.c makeMoves.c checkChecker.c list.c fileHandling.c viewMoves.c -o chess `pkg-config --cflags --libs check`

