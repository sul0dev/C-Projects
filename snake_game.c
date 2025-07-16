#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

#define WIDTH 32
#define HEIGHT 20
#define FLOOR ' '
#define WALL '#'
#define SNAKE_HEAD 'O'
#define SNAKE_BODY 'o'
#define FOOD '@'

#define MAX_SNAKE_LENGTH 100

struct SnakeSegment {
    int x, y;
};

struct Snake {
    struct SnakeSegment segments[MAX_SNAKE_LENGTH];
    int length;
    int dx, dy;
    bool isDied;
};

char map[HEIGHT][WIDTH];
struct Snake snake;
int foodX, foodY;

void initializeGame();
void drawMap();
void update();
void spawnFood();
bool checkCollision(int x, int y);

int main() {
    initializeGame();

    while (!snake.isDied) {
        if (_kbhit()) {
            int ch = _getch();
            if (ch == 224) {
                ch = _getch();
                switch (ch) {
                    case 72: // up arrow key
                        if(snake.dy != 1){ 
                            snake.dx = 0; snake.dy = -1; 
                        }   
                        break;
                    case 80: // down arrow key
                        if(snake.dy != -1){
                            snake.dx = 0; snake.dy = 1; 
                        }   
                        break;
                    case 75: // left arrow key
                        if(snake.dx != 1){ 
                            snake.dx = -1; snake.dy = 0; 
                        } 
                        break;
                    case 77: // right arrow key
                        if(snake.dx != -1){ 
                            snake.dx = 1; snake.dy = 0; 
                        } 
                        break;
                }
            }
        }

        update();
        drawMap();
        Sleep(100);
    }

    printf("Game Over! Final Score: %d\n", snake.length - 1);
    return 0;
}

void initializeGame() {
    snake.length = 1;
    snake.segments[0].x = WIDTH / 2;
    snake.segments[0].y = HEIGHT / 2;
    snake.dx = 1;
    snake.dy = 0;
    snake.isDied = false;
    spawnFood();
}

void spawnFood() {
    do {
        foodX = rand() % (WIDTH - 2) + 1;
        foodY = rand() % (HEIGHT - 2) + 1;
    } while (checkCollision(foodX, foodY));
}

bool checkCollision(int x, int y) {
    for (int i = 0; i < snake.length; i++) {
        if (snake.segments[i].x == x && snake.segments[i].y == y)
            return true;
    }
    return false;
}

void update() {
    int newX = snake.segments[0].x + snake.dx;
    int newY = snake.segments[0].y + snake.dy;

    if (newX <= 0 || newX >= WIDTH - 1 || newY <= 0 || newY >= HEIGHT - 1 || checkCollision(newX, newY)) {
        snake.isDied = true;
        return;
    }

    if (newX == foodX && newY == foodY) {
        if (snake.length < MAX_SNAKE_LENGTH)
            snake.length++;
        spawnFood();
    }

    for (int i = snake.length - 1; i > 0; i--) {
        snake.segments[i] = snake.segments[i - 1];
    }
    snake.segments[0].x = newX;
    snake.segments[0].y = newY;
}

void drawMap() {
    system("cls");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1) {
                map[y][x] = WALL;
            } else {
                map[y][x] = FLOOR;
            }
        }
    }

    for (int i = 1; i < snake.length; i++) {
        map[snake.segments[i].y][snake.segments[i].x] = SNAKE_BODY;
    }
    map[snake.segments[0].y][snake.segments[0].x] = SNAKE_HEAD;

    map[foodY][foodX] = FOOD;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(map[y][x]);
        }
        putchar('\n');
    }
    
    printf("Score: %d\n", snake.length - 1);
    printf("-- MADE BY sul0 --\n");
}
