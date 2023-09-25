# :checkered_flag: Chess
This repository is home to my chess engine.

## :thought_balloon: Design Decisions
I have designed all squares for a board and all pieces for the board to be
strictly singletons in the program.  This is done using shared memory (i.e.
squares point and pieces and vice versa).  This allows for no garbage collection
during the execution of the program until the user chooses to terminate it.

## Future Plans
The following are ideas that I have for this engine:
  - Grahpical Inteface Using OpenGL/Raylib or the Like.
  - Stockfish Integration/Communication.
    - Ability to Get Live Analysis While Studying a Line Using Stockfish.
  - Study Document Generator (i.e. LaTeX Based Output Files for a Given Study).
  - PGN and FEN Parsers
  - Opening Analysis Study Aid
    - Using PGN/FEN/My Custom Study Note Format Test the User on a Given Study.
  - Endgame Practice Study Aid
    - Using a Combination of Stockfish and TableBase to Allow the Use to Prove
      Draws/Wins.
