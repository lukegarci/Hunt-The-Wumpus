# Hunt-The-Wumpus

The goal of this project is to start working with polymorphism and C++ template classes from the STL.

The Hunt the Wumpus game
The object of Hunt the Wumpus is to guide an adventurer to kill the Wumpus, find its hidden gold, and escape alive. The Wumpus lives in a large cave of rooms arranged in a grid, where each room at has four tunnels leading to the rooms to the north, east, south, and west.

The adventurer starts the game in a random empty room in the Wumpus’ cave. The starting position is also the location of the escape rope that the player must use to escape after all completed tasks.

Each room may be empty, or it may contain one (and only one) of four "events" (all described below): two kinds of dangerous hazards, the terrifying Wumpus, and the gold treasure. When the adventurer is in a room that’s adjacent to a room containing an one of these "events", the player will receive a percept (a message) to inform them about the event the adventurer is close to.

If the adventurer perishes while searching for the Wumpus, the player should be presented with the option to start the game over with the same cave configuration, start the game over with a new random cave configuration, or quit the game entirely.

The player wins the game if they can safely guide the adventurer through the cave to kill the Wumpus, pick up the gold, and make it back to the escape rope unharmed!
Game elements
The adventurer

Each turn you may take one of two actions to guide the adventurer:

    Move: You can move through a tunnel to an adjacent room.

    Fire an Arrow: The adventurer has three arrows. You can aim each arrow by firing it into an adjacent room in a direction the user selects. The arrow continues flying in the same direction until it hits a wall or travels through three rooms. If the arrow enters the Wumpus’ room, it pierces the Wumpus’ heart and kills the monster. If the adventurer runs out of arrows without having killed the Wumpus, you lose.

The Wumpus

Usually, the Wumpus is peacefully asleep in his cave. Two things wake the Wumpus up, however: the adventurer entering his room or shooting an arrow and missing him. If the Wumpus wakes up while in the same room as the adventurer, the Wumpus will angrily eat the adventurer, ending the game. If the Wumpus just wakes up from hearing an arrow being fired, though, there’s a 75% chance he will move to a random empty room in the cave to avoid being found.
Hazards

There are two kinds of hazards in the Wumpus' cave:

    Stalactites: Two of the rooms have stalactites in them. If the adventurer enters a room with a stalactites, it will fall on the player, and the player loses.

    Super bats: Two rooms have super bats. If the adventurer enters a room that contains super bats, an angry bat grabs her and takes her to some other room at random (which could be dangerous!).

The gold

The gold is a treasure sitting in a room that contains neither a hazard nor the wumpus. If the adventurer is in a room containing the gold, she automatically picks it up and takes it with her.
Percepts

When the adventurer is in a room directly adjacent to to a room containing an "event", the player receives the following messages:

    Wumpus: "You smell a terrible stench."
    Super bats: "You hear wings flapping."
    Stalactites: "You hear dripping."
    Gold: "You see a glimmer nearby."

Notice that there’s no percept for the escape rope! That means the player will have to remember where they started and find their way back to that tile after they’ve completed their task.

As an example of how the percepts work, if the adventurer is standing in an empty room with the Wumpus one room to the North, the Gold one room to the East, and Bats two rooms to the South, they would receive the following messages at the beginning of their turn:

You smell a terrible stench.
You see a glimmer nearby.

Remember, the percepts don’t tell you where the hazard or gold is, just that it’s somewhere close!
Program requirements

    Your program should allow the user to play Hunt the Wumpus, as described above.

    The Wumpus' cave is represented by a square grid. The size of the grid (i.e. the numbner of rooms on one side of the square) should be specified as a command line parameter to your program. Caves smaller than four rooms on a side aren't allowed.

    Your code must have the following classes: Room, Event, Wumpus, Bats, Stalactites, and Gold. You may create more classes if they would be helpful.

    The Event class must be abstract (i.e. it must contain purely virtual functions), and the Wumpus, Bats, Stalactites, and Gold classes should all be derived from Event. Remember, any event does something when the adventurer enters the same room as the event, and will display a message when the adventurer is nearby. Your design of the Event class should reflect this.

    You must use the Event classes polymorphically. In other words, your Room class may only contain a member of the Event class but not members of the Wumpus, Bats, Pit, or Gold classes.

    Each Room contains at most one Event, but it may not contain any Event. The design of your Room class should reflect this.

    The grid representing your cave should be implemented using the std::vector class.

