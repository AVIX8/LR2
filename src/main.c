#include "SDL2/SDL.h"
#include "Window.h"
#include "Vector2.h"

static int GREEN[3] = {0, 255, 0};
static int RED[3] = {255, 0, 0};
static int WHITE[3] = {255, 255, 255};

static int Script(void *window)
{
    while (1)
    {
        WindowClear(window);

        // статическиая переменная
        Vector2 v1;
        Vector2Read(&v1);
        printf("v1 = ");
        Display(&v1);
        v1.color = GREEN;
        DrawVector2(window, &v1);

        // динамическая переменная
        Vector2 *v2 = Vector2Init(0, 0, WHITE);
        Vector2Read(v2);
        printf("v2 = ");
        Display(v2);
        v2->color = GREEN;
        DrawVector2(window, v2);

        printf("Angle between v1 and v2: %f\n", Angle(&v1, v2));

        Vector2 sum = Add(&v1, v2);
        printf("v1 + v2 = ");
        Display(&sum);
        sum.color = RED;
        DrawVector2(window, &sum);

        printf("\n");
        system("pause");
        system("cls");
    }
    return 0;
}

int main(int argc, char *argv[])
{
    SDL_Window *window = WindowInit();
    SDL_Thread *thread = SDL_CreateThread(Script, "Script", (void *)window);

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