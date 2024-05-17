<div align="center">
    <img src="https://imgur.com/AhSVJu2.png" />
    <p>An *unbeatable* tictactoe bot written in C++.</p>
</div>

## About
This program uses the [Minimax Algorithm](https://en.wikipedia.org/wiki/Minimax) to figure out the best possible move even in the worst positions. The program also has a CUI written using [ncurses](https://en.wikipedia.org/wiki/Ncurses), so it's ready to play!

## How to use?

### Installing

1. Clone this repository and CD into it
    ```
    git clone https://github.com/goodboyneon/tictactoe.git
    cd tictactoe
    ```
1. Compile the program
    ```
    make # If you do not want to use make, run build command from Makefile
    ```
1. Run the program
    ```
    ./main
    ```

### Usage

This is the rendered image you should see on your screen after you run the program
<img src="https://imgur.com/hxwxiYo.png" />

* To make a move, simply press the number corresponding to the specific square
    > Tip: If your keyboard has a numpad, you might realize that the positions of the number keys on the numpad are the same as the numbers for each of the square. For example, you can press the top left key on the numpad (i.e. 7) to play the top left square on the tic-tac-toe grid!
    
* The program randomly assigns you a token (either X or O) at the start of each game. Therefore, you have a 50-50 change or getting either token
* Whoever gets the X token is the one who plays the first move.

## Contributing
I am very thankful that you decided to invest time and energy into this project. To contribute,
1. clone this repository and make a new branch: `git checkout https://github.com/goodboyneon/tictactoe -b replace_with_branch_name`.
1. You can make your changes on that branch and submit a Pull Request. Please make sure your code prioritizes readability and that your PR's content is descriptive and straight-to-point.

## License
[MIT](https://choosealicense.com/licenses/mit/)
