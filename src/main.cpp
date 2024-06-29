#include <stdio.h>
#include <iostream>
#include <vector>

#include "FileReader.hpp"
#include "EarClipper.hpp"

// #include <SDL2/SDL.h>  // For Linux and Windows
#include <SDL.h>

// On linux compile with:
// g++ -std=c++17 main.cpp -o prog -lSDL2 -ldl
// On windows compile with (if using mingw)
// g++ main.cpp -o prog.exe -lmingw32 -lSDL2main -lSDL2
// On Mac compile with:
// clang++ main.cpp -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2


int main()
{
    FileReader fr("./shape_files/s1.txt");
    std::vector<Point2D> points = fr.extractPoints();
    
    EarClipper ec(points);
    std::vector<Triangle> triangles = ec.triangulate();

    SDL_Window* window=nullptr;

    // Initialize the video subsystem.
    // iF it returns less than 1, then an
    // error code will be received.
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
    }else{
        std::cout << "SDL video system is ready to go\n";
    }
    // Request a window to be created for our platform
    // The parameters are for the title, x and y position,
    // and the width and height of the window.
    window = SDL_CreateWindow("C++ SDL2 Window",20, 20, 640,480,SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = nullptr;
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // Infinite loop for our application
    bool gameIsRunning = true;
    // Main application loop
    while(gameIsRunning){
        SDL_Event event;

        // (1) Handle Input
        // Start our event loop
        while(SDL_PollEvent(&event)){
            // Handle each specific event
            if(event.type == SDL_QUIT){
                gameIsRunning= false;
            }
        }
        // (2) Handle Updates
        
        // (3) Clear and Draw the Screen
        // Gives us a clear "canvas"
        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

         SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
        for (Triangle t : triangles)
        {
            Point2D p0 = t._p1, p1 = t._p2, p2 = t._p3;
            SDL_RenderDrawLine(renderer, p0._x, p0._y, p1._x, p1._y);
            SDL_RenderDrawLine(renderer, p0._x, p0._y, p2._x, p2._y);
            SDL_RenderDrawLine(renderer, p2._x, p2._y, p1._x, p1._y);
        }

        // Do our drawing
        SDL_SetRenderDrawColor(renderer,255,0,0,SDL_ALPHA_OPAQUE);

        for (int i = 1; i < points.size(); ++i)
        {
            SDL_RenderDrawLine(renderer, points[i - 1]._x, points[i - 1]._y, points[i]._x, points[i]._y);
        }
        SDL_RenderDrawLine(renderer, points[points.size() - 1]._x, points[points.size() - 1]._y, points[0]._x, points[0]._y);


        // Finally show what we've drawn
        SDL_RenderPresent(renderer);

    }

    // We destroy our window. We are passing in the pointer
    // that points to the memory allocated by the 
    // 'SDL_CreateWindow' function. Remember, this is
    // a 'C-style' API, we don't have destructors.
    SDL_DestroyWindow(window);
    
    // our program.
    SDL_Quit();
}