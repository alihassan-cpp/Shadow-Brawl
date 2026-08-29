//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//
//// ============================================================
//// SHADOW BRAWL
//// Console Dino Runner Prototype
//// ============================================================
////
//// Controls:
////
//// SPACE / W -> Jump
//// Q         -> Quit
////
//// ============================================================
//
//
//// ============================================================
//// CONSTANTS
//// ============================================================
//
//const int SCREEN_WIDTH = 80;
//const int SCREEN_HEIGHT = 25;
//
//const int GROUND_Y = 20;
//
//const float GRAVITY = 0.55f;
//const float JUMP_FORCE = -3.2f;
//
//
//// ============================================================
//// COLORS
//// ============================================================
//
//const int GREEN = 10;
//const int CYAN = 11;
//const int RED = 12;
//const int MAGENTA = 13;
//const int YELLOW = 14;
//const int WHITE = 15;
//
//
//// ============================================================
//// CONSOLE FUNCTIONS
//// ============================================================
//
//void setColor(int color)
//{
//    SetConsoleTextAttribute(
//        GetStdHandle(STD_OUTPUT_HANDLE),
//        color
//    );
//}
//
//
//void setCursorPosition(int x, int y)
//{
//    COORD position;
//
//    position.X = x;
//    position.Y = y;
//
//    SetConsoleCursorPosition(
//        GetStdHandle(STD_OUTPUT_HANDLE),
//        position
//    );
//}
//
//
//void hideCursor()
//{
//    HANDLE consoleHandle =
//        GetStdHandle(STD_OUTPUT_HANDLE);
//
//    CONSOLE_CURSOR_INFO info;
//
//    info.dwSize = 1;
//    info.bVisible = false;
//
//    SetConsoleCursorInfo(
//        consoleHandle,
//        &info
//    );
//}
//
//
//void clearScreen()
//{
//    system("cls");
//}
//
//
//// ============================================================
//// DINOSAUR CLASS
//// ============================================================
//
//class Dinosaur
//{
//private:
//
//    int x;
//    int y;
//
//    float velocityY;
//
//    bool jumping;
//
//public:
//
//    Dinosaur()
//    {
//        x = 8;
//
//        y = GROUND_Y;
//
//        velocityY = 0;
//
//        jumping = false;
//    }
//
//
//    // --------------------------------------------------------
//    // JUMP
//    // --------------------------------------------------------
//
//    void jump()
//    {
//        if (!jumping)
//        {
//            velocityY = JUMP_FORCE;
//
//            jumping = true;
//        }
//    }
//
//
//    // --------------------------------------------------------
//    // UPDATE
//    // --------------------------------------------------------
//
//    void update()
//    {
//        if (jumping)
//        {
//            velocityY += GRAVITY;
//
//            y += (int)velocityY;
//
//
//            if (y >= GROUND_Y)
//            {
//                y = GROUND_Y;
//
//                velocityY = 0;
//
//                jumping = false;
//            }
//        }
//    }
//
//
//    // --------------------------------------------------------
//    // DRAW
//    // --------------------------------------------------------
//
//    void draw() const
//    {
//        setColor(GREEN);
//
//        setCursorPosition(
//            x,
//            y
//        );
//
//        cout << "D";
//
//        setColor(WHITE);
//    }
//
//
//    // --------------------------------------------------------
//    // GETTERS
//    // --------------------------------------------------------
//
//    int getX() const
//    {
//        return x;
//    }
//
//
//    int getY() const
//    {
//        return y;
//    }
//
//
//    int getWidth() const
//    {
//        return 1;
//    }
//
//
//    int getHeight() const
//    {
//        return 1;
//    }
//
//
//    bool isJumping() const
//    {
//        return jumping;
//    }
//
//
//    // --------------------------------------------------------
//    // RESET
//    // --------------------------------------------------------
//
//    void reset()
//    {
//        x = 8;
//
//        y = GROUND_Y;
//
//        velocityY = 0;
//
//        jumping = false;
//    }
//};
//
//
//// ============================================================
//// OBSTACLE CLASS
//// ============================================================
//
//class Obstacle
//{
//private:
//
//    float x;
//
//    int y;
//
//    int width;
//    int height;
//
//    int type;
//
//public:
//
//    Obstacle(
//        float startX,
//        int obstacleType
//    )
//    {
//        x = startX;
//
//        type = obstacleType;
//
//
//        // ----------------------------------------------------
//        // TYPE 1
//        // SMALL CACTUS
//        // ----------------------------------------------------
//
//        if (type == 1)
//        {
//            width = 1;
//
//            height = 2;
//
//            y = GROUND_Y;
//        }
//
//
//        // ----------------------------------------------------
//        // TYPE 2
//        // MEDIUM CACTUS
//        // ----------------------------------------------------
//
//        else if (type == 2)
//        {
//            width = 2;
//
//            height = 3;
//
//            y = GROUND_Y;
//        }
//
//
//        // ----------------------------------------------------
//        // TYPE 3
//        // WIDE CACTUS
//        // ----------------------------------------------------
//
//        else if (type == 3)
//        {
//            width = 4;
//
//            height = 2;
//
//            y = GROUND_Y;
//        }
//
//
//        // ----------------------------------------------------
//        // TYPE 4
//        // TALL CACTUS
//        // ----------------------------------------------------
//
//        else if (type == 4)
//        {
//            width = 2;
//
//            height = 4;
//
//            y = GROUND_Y;
//        }
//
//
//        // ----------------------------------------------------
//        // TYPE 5
//        // LARGE BLOCK
//        // ----------------------------------------------------
//
//        else if (type == 5)
//        {
//            width = 4;
//
//            height = 2;
//
//            y = GROUND_Y;
//        }
//
//
//        // ----------------------------------------------------
//        // TYPE 6
//        // FLYING OBSTACLE
//        // ----------------------------------------------------
//
//        else
//        {
//            width = 3;
//
//            height = 2;
//
//            y = GROUND_Y - 4;
//        }
//    }
//
//
//    // --------------------------------------------------------
//    // MOVE
//    // --------------------------------------------------------
//
//    void move(float speed)
//    {
//        x -= speed;
//    }
//
//
//    // --------------------------------------------------------
//    // DRAW
//    // --------------------------------------------------------
//
//    void draw() const
//    {
//        setColor(RED);
//
//        int drawX = (int)x;
//
//
//        // ====================================================
//        // SMALL CACTUS
//        // ====================================================
//
//        if (type == 1)
//        {
//            setCursorPosition(
//                drawX,
//                y
//            );
//
//            cout << "#";
//
//
//            setCursorPosition(
//                drawX,
//                y - 1
//            );
//
//            cout << "#";
//        }
//
//
//        // ====================================================
//        // MEDIUM CACTUS
//        // ====================================================
//
//        else if (type == 2)
//        {
//            setCursorPosition(
//                drawX,
//                y
//            );
//
//            cout << "##";
//
//
//            setCursorPosition(
//                drawX,
//                y - 1
//            );
//
//            cout << "##";
//
//
//            setCursorPosition(
//                drawX,
//                y - 2
//            );
//
//            cout << "##";
//        }
//
//
//        // ====================================================
//        // WIDE CACTUS
//        // ====================================================
//
//        else if (type == 3)
//        {
//            setCursorPosition(
//                drawX,
//                y
//            );
//
//            cout << "####";
//
//
//            setCursorPosition(
//                drawX,
//                y - 1
//            );
//
//            cout << "####";
//        }
//
//
//        // ====================================================
//        // TALL CACTUS
//        // ====================================================
//
//        else if (type == 4)
//        {
//            setCursorPosition(
//                drawX,
//                y
//            );
//
//            cout << "##";
//
//
//            setCursorPosition(
//                drawX,
//                y - 1
//            );
//
//            cout << "##";
//
//
//            setCursorPosition(
//                drawX,
//                y - 2
//            );
//
//            cout << "##";
//
//
//            setCursorPosition(
//                drawX,
//                y - 3
//            );
//
//            cout << "##";
//        }
//
//
//        // ====================================================
//        // LARGE BLOCK
//        // ====================================================
//
//        else if (type == 5)
//        {
//            setCursorPosition(
//                drawX,
//                y
//            );
//
//            cout << "####";
//
//
//            setCursorPosition(
//                drawX,
//                y - 1
//            );
//
//            cout << "####";
//        }
//
//
//        // ====================================================
//        // FLYING OBSTACLE
//        // ====================================================
//
//        else
//        {
//            setCursorPosition(
//                drawX + 1,
//                y
//            );
//
//            cout << "T";
//
//
//            setCursorPosition(
//                drawX,
//                y - 1
//            );
//
//            cout << "TTT";
//        }
//
//
//        setColor(WHITE);
//    }
//
//
//    // --------------------------------------------------------
//    // GETTERS
//    // --------------------------------------------------------
//
//    int getX() const
//    {
//        return (int)x;
//    }
//
//
//    int getY() const
//    {
//        return y;
//    }
//
//
//    int getWidth() const
//    {
//        return width;
//    }
//
//
//    int getHeight() const
//    {
//        return height;
//    }
//
//
//    int getType() const
//    {
//        return type;
//    }
//
//
//    bool isOffScreen() const
//    {
//        return x + width < 0;
//    }
//};
//
//
//// ============================================================
//// GAME CLASS
//// ============================================================
//
//class Game
//{
//private:
//
//    Dinosaur dinosaur;
//
//    vector<Obstacle> obstacles;
//
//    int score;
//
//    int highScore;
//
//    int spawnTimer;
//
//    int spawnDelay;
//
//    float gameSpeed;
//
//    bool running;
//
//    bool gameOver;
//
//
//public:
//
//    Game()
//    {
//        score = 0;
//
//        highScore = 0;
//
//        spawnTimer = 0;
//
//        spawnDelay = 40;
//
//        gameSpeed = 1.5f;
//
//        running = true;
//
//        gameOver = false;
//    }
//
//
//    // ========================================================
//    // RESET GAME
//    // ========================================================
//
//    void reset()
//    {
//        dinosaur.reset();
//
//        obstacles.clear();
//
//        score = 0;
//
//        spawnTimer = 0;
//
//        spawnDelay = 40;
//
//        gameSpeed = 1.5f;
//
//        running = true;
//
//        gameOver = false;
//    }
//
//
//    // ========================================================
//    // HANDLE INPUT
//    // ========================================================
//
//    void handleInput()
//    {
//        if (!_kbhit())
//        {
//            return;
//        }
//
//
//        char key = _getch();
//
//
//        if (
//            key == ' ' ||
//            key == 'w' ||
//            key == 'W'
//            )
//        {
//            dinosaur.jump();
//        }
//
//
//        else if (
//            key == 'q' ||
//            key == 'Q'
//            )
//        {
//            running = false;
//        }
//    }
//
//
//    // ========================================================
//    // SPAWN OBSTACLE
//    // ========================================================
//
//    void spawnObstacle()
//    {
//        int obstacleType;
//
//        int randomValue =
//            rand() % 100;
//
//
//        if (randomValue < 20)
//        {
//            obstacleType = 1;
//        }
//
//        else if (randomValue < 38)
//        {
//            obstacleType = 2;
//        }
//
//        else if (randomValue < 55)
//        {
//            obstacleType = 3;
//        }
//
//        else if (randomValue < 70)
//        {
//            obstacleType = 4;
//        }
//
//        else if (randomValue < 85)
//        {
//            obstacleType = 5;
//        }
//
//        else
//        {
//            obstacleType = 6;
//        }
//
//
//        obstacles.push_back(
//            Obstacle(
//                SCREEN_WIDTH - 2,
//                obstacleType
//            )
//        );
//
//
//        spawnDelay =
//            30 + rand() % 25;
//
//
//        spawnTimer = spawnDelay;
//    }
//
//
//    // ========================================================
//    // UPDATE OBSTACLES
//    // ========================================================
//
//    void updateObstacles()
//    {
//        for (
//            int i = 0;
//            i < (int)obstacles.size();
//            i++
//            )
//        {
//            obstacles[i].move(
//                gameSpeed
//            );
//        }
//
//
//        // Remove obstacles outside screen
//
//        for (
//            int i = 0;
//            i < (int)obstacles.size();
//            i++
//            )
//        {
//            if (
//                obstacles[i].isOffScreen()
//                )
//            {
//                obstacles.erase(
//                    obstacles.begin() + i
//                );
//
//                i--;
//            }
//        }
//    }
//
//
//    // ========================================================
//    // UPDATE SPAWNING
//    // ========================================================
//
//    void updateSpawning()
//    {
//        spawnTimer--;
//
//
//        if (spawnTimer <= 0)
//        {
//            spawnObstacle();
//        }
//    }
//
//
//    // ========================================================
//    // COLLISION DETECTION
//    // ========================================================
//
//    bool checkCollision(
//        const Dinosaur& dino,
//        const Obstacle& obstacle
//    )
//    {
//        int dinoLeft =
//            dino.getX();
//
//        int dinoRight =
//            dino.getX() +
//            dino.getWidth() -
//            1;
//
//        int dinoTop =
//            dino.getY();
//
//        int dinoBottom =
//            dino.getY();
//
//
//        int obstacleLeft =
//            obstacle.getX();
//
//        int obstacleRight =
//            obstacle.getX() +
//            obstacle.getWidth() -
//            1;
//
//        int obstacleBottom =
//            obstacle.getY();
//
//        int obstacleTop =
//            obstacle.getY() -
//            obstacle.getHeight() +
//            1;
//
//
//        if (
//            dinoRight >= obstacleLeft &&
//            dinoLeft <= obstacleRight &&
//            dinoBottom >= obstacleTop &&
//            dinoTop <= obstacleBottom
//            )
//        {
//            return true;
//        }
//
//
//        return false;
//    }
//
//
//    // ========================================================
//    // CHECK COLLISIONS
//    // ========================================================
//
//    void checkCollisions()
//    {
//        for (
//            const Obstacle& obstacle :
//            obstacles
//            )
//        {
//            if (
//                checkCollision(
//                    dinosaur,
//                    obstacle
//                )
//                )
//            {
//                gameOver = true;
//
//                running = false;
//
//                break;
//            }
//        }
//    }
//
//
//    // ========================================================
//    // UPDATE SCORE
//    // ========================================================
//
//    void updateScore()
//    {
//        score++;
//
//
//        if (score > highScore)
//        {
//            highScore = score;
//        }
//
//
//        // Increase difficulty every 100 points
//
//        if (
//            score % 100 == 0
//            )
//        {
//            gameSpeed += 0.30f;
//
//
//            if (gameSpeed > 4.0f)
//            {
//                gameSpeed = 4.0f;
//            }
//        }
//    }
//
//
//    // ========================================================
//    // UPDATE GAME
//    // ========================================================
//
//    void update()
//    {
//        dinosaur.update();
//
//        updateObstacles();
//
//        updateSpawning();
//
//        checkCollisions();
//
//        updateScore();
//    }
//
//
//    // ========================================================
//    // DRAW GROUND
//    // ========================================================
//
//    void drawGround()
//    {
//        setColor(GREEN);
//
//
//        setCursorPosition(
//            0,
//            GROUND_Y + 1
//        );
//
//
//        for (
//            int i = 0;
//            i < SCREEN_WIDTH;
//            i++
//            )
//        {
//            cout << "-";
//        }
//
//
//        setColor(WHITE);
//    }
//
//
//    // ========================================================
//    // DRAW UI
//    // ========================================================
//
//    void drawUI()
//    {
//        // Top border
//
//        setColor(MAGENTA);
//
//        setCursorPosition(
//            0,
//            0
//        );
//
//
//        cout <<
//            "==============================================================";
//
//
//        // Title
//
//        setCursorPosition(
//            2,
//            1
//        );
//
//
//        setColor(GREEN);
//
//        cout <<
//            "SHADOW BRAWL";
//
//
//        // Score
//
//        setCursorPosition(
//            25,
//            1
//        );
//
//
//        setColor(GREEN);
//
//        cout <<
//            "SCORE: "
//            << score;
//
//
//        // High score
//
//        setCursorPosition(
//            45,
//            1
//        );
//
//
//        setColor(YELLOW);
//
//        cout <<
//            "HIGH SCORE: "
//            << highScore;
//
//
//        // Jump controls
//
//        setCursorPosition(
//            2,
//            2
//        );
//
//
//        setColor(CYAN);
//
//        cout <<
//            "[ SPACE / W = Jump ]";
//
//
//        // Quit controls
//
//        setCursorPosition(
//            28,
//            2
//        );
//
//
//        setColor(RED);
//
//        cout <<
//            "[ Q = Quit ]";
//
//
//        // Bottom border
//
//        setCursorPosition(
//            0,
//            3
//        );
//
//
//        setColor(MAGENTA);
//
//        cout <<
//            "==============================================================";
//
//
//        setColor(WHITE);
//    }
//
//
//    // ========================================================
//    // DRAW GAME
//    // ========================================================
//
//    void draw()
//    {
//        clearScreen();
//
//
//        drawUI();
//
//
//        drawGround();
//
//
//        dinosaur.draw();
//
//
//        for (
//            const Obstacle& obstacle :
//            obstacles
//            )
//        {
//            obstacle.draw();
//        }
//
//
//        cout.flush();
//    }
//
//
//    // ========================================================
//    // GAME OVER SCREEN
//    // ========================================================
//
//    void showGameOver()
//    {
//        clearScreen();
//
//
//        cout << endl;
//        cout << endl;
//
//
//        setColor(MAGENTA);
//
//        cout <<
//            "              ============================="
//            << endl;
//
//
//        setColor(GREEN);
//
//        cout <<
//            "                    SHADOW BRAWL"
//            << endl;
//
//
//        setColor(MAGENTA);
//
//        cout <<
//            "              ============================="
//            << endl;
//
//
//        cout << endl;
//
//
//        setColor(RED);
//
//        cout <<
//            "                    GAME OVER!"
//            << endl;
//
//
//        cout << endl;
//
//
//        setColor(GREEN);
//
//        cout <<
//            "                  SCORE: "
//            << score
//            << endl;
//
//
//        setColor(YELLOW);
//
//        cout <<
//            "               HIGH SCORE: "
//            << highScore
//            << endl;
//
//
//        cout << endl;
//
//
//        setColor(CYAN);
//
//        cout <<
//            "              Press R to restart"
//            << endl;
//
//
//        setColor(RED);
//
//        cout <<
//            "              Press Q to quit"
//            << endl;
//
//
//        setColor(WHITE);
//    }
//
//
//    // ========================================================
//    // PLAY GAME
//    // ========================================================
//
//    void play()
//    {
//        reset();
//
//        hideCursor();
//
//
//        while (running)
//        {
//            handleInput();
//
//            update();
//
//            draw();
//
//
//            // Faster gameplay
//
//            int delay =
//                65 -
//                (int)(gameSpeed * 8);
//
//
//            if (delay < 25)
//            {
//                delay = 25;
//            }
//
//
//            Sleep(delay);
//        }
//
//
//        if (gameOver)
//        {
//            showGameOver();
//        }
//    }
//
//
//    // ========================================================
//    // GAME OVER LOOP
//    // ========================================================
//
//    void gameOverLoop()
//    {
//        while (true)
//        {
//            if (_kbhit())
//            {
//                char key = _getch();
//
//
//                if (
//                    key == 'r' ||
//                    key == 'R'
//                    )
//                {
//                    play();
//
//                    return;
//                }
//
//
//                if (
//                    key == 'q' ||
//                    key == 'Q'
//                    )
//                {
//                    return;
//                }
//            }
//
//
//            Sleep(50);
//        }
//    }
//
//
//    // ========================================================
//    // MAIN MENU
//    // ========================================================
//
//    void menu()
//    {
//        bool menuRunning = true;
//
//
//        while (menuRunning)
//        {
//            clearScreen();
//
//
//            cout << endl;
//            cout << endl;
//
//
//            // ------------------------------------------------
//            // TITLE
//            // ------------------------------------------------
//
//            setColor(MAGENTA);
//
//
//            cout <<
//                "          ########################################"
//                << endl;
//
//
//            cout <<
//                "          #                                      #"
//                << endl;
//
//
//            setColor(GREEN);
//
//
//            cout <<
//                "          #            SHADOW BRAWL             #"
//                << endl;
//
//
//            setColor(MAGENTA);
//
//
//            cout <<
//                "          #                                      #"
//                << endl;
//
//
//            setColor(YELLOW);
//
//
//            cout <<
//                "          #             DINO RUNNER             #"
//                << endl;
//
//
//            setColor(MAGENTA);
//
//
//            cout <<
//                "          #                                      #"
//                << endl;
//
//
//            cout <<
//                "          ########################################"
//                << endl;
//
//
//            cout << endl;
//            cout << endl;
//
//
//            // ------------------------------------------------
//            // MENU OPTIONS
//            // ------------------------------------------------
//
//            setColor(YELLOW);
//
//
//            cout <<
//                "                    1. PLAY"
//                << endl;
//
//
//            setColor(CYAN);
//
//
//            cout <<
//                "                    2. CONTROLS"
//                << endl;
//
//
//            setColor(RED);
//
//
//            cout <<
//                "                    3. EXIT"
//                << endl;
//
//
//            cout << endl;
//
//
//            setColor(WHITE);
//
//
//            cout <<
//                "                    Select: ";
//
//
//            char choice = _getch();
//
//
//            if (choice == '1')
//            {
//                play();
//
//
//                if (gameOver)
//                {
//                    gameOverLoop();
//                }
//            }
//
//
//            else if (choice == '2')
//            {
//                showControls();
//            }
//
//
//            else if (choice == '3')
//            {
//                menuRunning = false;
//            }
//        }
//
//
//        setColor(WHITE);
//    }
//
//
//    // ========================================================
//    // CONTROLS SCREEN
//    // ========================================================
//
//    void showControls()
//    {
//        clearScreen();
//
//
//        cout << endl;
//        cout << endl;
//
//
//        setColor(MAGENTA);
//
//
//        cout <<
//            "                 ===== CONTROLS ====="
//            << endl;
//
//
//        cout << endl;
//
//
//        setColor(CYAN);
//
//
//        cout <<
//            "                 SPACE / W"
//            << endl;
//
//
//        setColor(WHITE);
//
//
//        cout <<
//            "                 Jump"
//            << endl;
//
//
//        cout << endl;
//
//
//        setColor(RED);
//
//
//        cout <<
//            "                 Q"
//            << endl;
//
//
//        setColor(WHITE);
//
//
//        cout <<
//            "                 Quit"
//            << endl;
//
//
//        cout << endl;
//
//
//        setColor(YELLOW);
//
//
//        cout <<
//            "                 Avoid the obstacles!"
//            << endl;
//
//
//        cout << endl;
//
//
//        setColor(WHITE);
//
//
//        cout <<
//            "                 Press any key..."
//            << endl;
//
//
//        _getch();
//    }
//};
//
//
//// ============================================================
//// MAIN
//// ============================================================
//
//int main()
//{
//    srand(
//        (unsigned int)
//        time(NULL)
//    );
//
//
//    setColor(WHITE);
//
//
//    Game game;
//
//
//    game.menu();
//
//
//    clearScreen();
//
//
//    setColor(GREEN);
//
//
//    cout <<
//        "Thanks for playing Shadow Brawl!"
//        << endl;
//
//
//    setColor(WHITE);
//
//
//    return 0;
//}