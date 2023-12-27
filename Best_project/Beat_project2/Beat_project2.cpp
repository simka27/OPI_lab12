#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>
using namespace std;

bool gameOver;
const int width = 16;
const int height = 18;
int score;
int field[18][16] = { 0 };

int shapes[7][4][2] = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
    {{0, 1}, {1, 1}, {2, 1}, {1, 0}},
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}
};

struct Point {
    int x, y;
};

Point currentShape;
int currentShapeNum;

bool CheckCollision(int x, int y, int shape)
{
    for (int i = 0; i < 4; i++)
    {
        int newX = x + shapes[shape][i][0];
        int newY = y + shapes[shape][i][1];

        if (newX < 0 || newX >= width || newY >= height || field[newY][newX] != 0)
            return true;
    }
    return false;
}

void ClearLines()
{
    for (int i = height - 1; i >= 0; i--)
    {
        bool lineFull = true;
        for (int j = 0; j < width; j++)
        {
            if (field[i][j] == 0)
            {
                lineFull = false;
                break;
            }
        }
        if (lineFull)
        {
            for (int k = i; k > 0; k--)
            {
                for (int j = 0; j < width; j++)
                    field[k][j] = field[k - 1][j];
            }
            score += 10;
        }
    }
}

void Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";

            if (field[i][j] == 0)
            {
                bool isCurrentShapeBlock = false;
                for (int k = 0; k < 4; k++)
                {
                    int blockX = currentShape.x + shapes[currentShapeNum][k][0];
                    int blockY = currentShape.y + shapes[currentShapeNum][k][1];

                    if (blockX == j && blockY == i)
                    {
                        cout << "4";
                        isCurrentShapeBlock = true;
                        break;
                    }
                }

                if (!isCurrentShapeBlock)
                    cout << " ";
            }
            else
                cout << "4";

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}




void AddToField(int x, int y, int shape)
{
    for (int i = 0; i < 4; i++)
    {
        int newX = x + shapes[shape][i][0];
        int newY = y + shapes[shape][i][1];
        field[newY][newX] = 1;
    }
}

void RotateShape()

{
    Point oldShape[4];
    for (int i = 0; i < 4; i++)
    {
        oldShape[i].x = currentShape.x + shapes[currentShapeNum][i][0];
        oldShape[i].y = currentShape.y + shapes[currentShapeNum][i][1];
    }

    for (int i = 0; i < 4; i++)
    {
        int offsetX = oldShape[i].x - currentShape.x;
        int offsetY = oldShape[i].y - currentShape.y;

        int newX = currentShape.x - offsetY;
        int newY = currentShape.y + offsetX;

        if (newX < 0 || newX >= width || newY >= height || field[newY][newX] != 0)
        {
            return;
        }

        shapes[currentShapeNum][i][0] = newX - currentShape.x;
        shapes[currentShapeNum][i][1] = newY - currentShape.y;
    }
}



void PlaceNewShape()
{
    currentShape.x = width / 2;
    currentShape.y = 0;
    currentShapeNum = rand() % 7;
    if (CheckCollision(currentShape.x, currentShape.y, currentShapeNum))
        gameOver = true;
}

void Update()
{
    if (!CheckCollision(currentShape.x, currentShape.y + 1, currentShapeNum))
        currentShape.y++;

    if (CheckCollision(currentShape.x, currentShape.y + 1, currentShapeNum))
    {
        AddToField(currentShape.x, currentShape.y, currentShapeNum);
        ClearLines();
        PlaceNewShape();
    }
}


void Input()
{
    if (GetAsyncKeyState('A') & 0x8000)
    {
        if (!CheckCollision(currentShape.x - 1, currentShape.y, currentShapeNum))
            currentShape.x--;
    }
    else if (GetAsyncKeyState('D') & 0x8000)
    {
        if (!CheckCollision(currentShape.x + 1, currentShape.y, currentShapeNum))
            currentShape.x++;
    }
    else if (GetAsyncKeyState('S') & 0x8000)
    {
        if (!CheckCollision(currentShape.x, currentShape.y + 1, currentShapeNum))
            currentShape.y++;
    }
    else if (GetAsyncKeyState('W') & 0x8000)
    {
        RotateShape();
    }
    else if (GetAsyncKeyState('X') & 0x8000)
    {
        gameOver = true;
    }
}




int main()
{
    using namespace std::chrono;
    milliseconds frameDuration(200);

    srand(static_cast<unsigned>(time(0)));
    gameOver = false;
    score = 0;

    auto lastFrameTime = steady_clock::now();

    while (!gameOver)
    {
        Draw();
        Input();
        Update();

        auto currentTime = steady_clock::now();
        auto elapsedTime = duration_cast<milliseconds>(currentTime - lastFrameTime);

        if (elapsedTime < frameDuration)
        {
            Sleep(static_cast<DWORD>(frameDuration.count() - elapsedTime.count()));
        }

        lastFrameTime = steady_clock::now();
    }

    cout << "Game Over! Final Score: " << score << endl;

    return 0;
}