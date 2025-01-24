// To run on Linux, after Raylib is configured and Raygui.h is on the same folder:
// g++ main.cpp -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 && ./main

#define RAYGUI_IMPLEMENTATION

#include "raylib.h"
#include "raygui.h"

#include <iostream>
#include <vector>
#include <string>
#include <iostream>


int main()
{

    int32_t screenWidth = 1280;
    int32_t screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "TODO List");

    SetTargetFPS(60);
    
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

    char active_input_buffer[255] = {0};
    std::vector<std::string> tasks;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawFPS(10, screenHeight - 20);

        int32_t label_width = MeasureText("TODO App", 50);
        GuiLabel({5, 0, (float)label_width, 50}, "TODO App");

        const char* title = "Enter a task";
        const char* text = "Task";
        const char* buttons = "Add Task";
        bool secret_view = true;

        int32_t result = GuiTextInputBox({20, 50, 600, 300}, title, text, buttons, active_input_buffer, 255, &secret_view);

        if( result == 1 )
        {
            // tasks.push_back(active_input_buffer);
            tasks.insert(tasks.begin(), active_input_buffer);
            memset(active_input_buffer, 0, 255);
        }

        for( int32_t i = 0; i < tasks.size(); i++ )
        {
            int32_t task_width = MeasureText(tasks[i].c_str(), 30);
            GuiLabel({650, 15.0f + (i * 40), (float)task_width, 100}, tasks[i].c_str());

            if( GuiButton({screenWidth - 120.0f, 50.0f + (i * 40), 100, 30}, "Del") )
            {
                tasks.erase(tasks.begin() + i);
            }
        }

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
