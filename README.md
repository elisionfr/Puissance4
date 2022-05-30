 # STUFF - Sparkling Thundering Unanimously Fabulous Framework
The Big Picture here is to build several programs around a similar homemade framework called STUFF.
That framework is based on SFML, but everything else will be homemade:
- GUI
- Network abilities (uses SFML network classes)
- Launcher
- Image processing
- Sound Processing
- Application overhaul architecture
- Patterns
- etc...

 # What will this look like ?
Each program will be compiled seperately.
A Launcher program will allow to choose which program to launch, even if each program will be able to be launched seperately.
Each program will be placed in a category.

 # What architecture will be used ?
The framework will be compiled seperately and linked synamically to SFML.
Each program will then link to the framework statically or dynamically.

 # List of programs :
- Launcher : Can launch other programs
- 4Chain : A game copyinh the Connect4 game
- StuffGUI : A program to show off the homemade GUI system