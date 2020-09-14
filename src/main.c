#include "SDL2/SDL.h"
#include "Window.h"
#include "Vector2.h"

static const GREEN[3] = {0, 255, 0};

static void Loop(void *window)
{
    Vector2 prev;
    
    for (int i = 1; 1; i++)
    {
        printf("%d: ", i);
        Vector2 cur = Vector2Read();
        Display(cur);
        DrawVector2(window, cur);
        if (i > 1)
        {
            printf("Angle between %d and %d: %f\n", i - 1, i, Angle(cur, prev));
            
            Vector2 sum = Add(cur, prev);
            printf("Vector %d + %d = ", i - 1, i);
            Display(sum);
            sum.color = GREEN;
            DrawVector2(window, sum);
        }
        prev = cur;
    }
}

int main(int argc, char *argv[])
{
    SDL_Window *window = WindowInit();
    SDL_Thread *thread = SDL_CreateThread(Loop, "TestThread", (void *)window);
    WindowClear(window);

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