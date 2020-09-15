#include "SDL2/SDL.h"
#include "Window.h"
#include "Vector2.h"

static const int GREEN[3] = {0, 255, 0};

static void Loop(void *window)
{
    while (1)
    {
        WindowClear(window);

        Vector2 v1 = Vector2Read();
        printf("v1 = ");
        Display(v1);
        DrawVector2(window, v1);

        Vector2 v2 = Vector2Read();
        printf("v2 = ");
        Display(v2);
        DrawVector2(window, v2);

        printf("Angle between v1 and v2: %f\n", Angle(v1, v2));

        Vector2 sum = Add(v1, v2);
        printf("v1 + v2 = ");
        Display(sum);
        sum.color = GREEN;
        DrawVector2(window, sum);

        printf("\n");
        system("pause");
        system("cls");
    }
}

int main(int argc, char *argv[])
{
    SDL_Window *window = WindowInit();
    SDL_Thread *thread = SDL_CreateThread(Loop, "TestThread", (void *)window);

    SDL_Event event;
    while (SDL_WaitEvent(&event) >= 0)
    {
        switch (event.type)
        {
        case SDL_QUIT:
        {
            Quit(window);
            exit(0);
        }
        break;
        }
    }
    return 0;
}