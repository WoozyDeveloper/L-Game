/**
    This is the implementation for the User Interface layer.
    The User Interface layer is responsible with the visual side of the application.
**/

#include "User_Interface.h"
#include "Player_Versus_Environment.h"
#include "Player_Versus_Player.h"

#include <graphics.h> // for graphics
#include <Windows.h> // for the mouse cursor position inside the window
#include <cstring> // for the "strcpy" function



/**
    Runs the graphical user interface.
    Input:
        - none
    Output:
        - runs the graphical user interface
**/
void runGUI ()
{
    // Exclude the C functions for higher speed.
    std::ios::sync_with_stdio(false);

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Draw the application window.
    initwindow(screenWidth, screenHeight);

    // Draw the main menu's buttons.
    drawMainMenuButtons();

    // Search for a click and see where the user clicked.
    scanMousePosition();

    // Close the application.
    closeApplication();
}



/**
    Draws a button.
    Input:
        - "left": the left margin of the button
        - "up": the up margin of the button
        - "right": the right margin of the button
        - "down": the down margin of the button
        - "depth": the depth of the button
        - "drawDetails": specifies if it should draw more details
        - "textXCoordinate": the starting X position of the text
        - "textYCoordinate": the starting Y position of the text
        - "text": the text of the button
    Output:
        - draws a button on the screen
**/
void drawButton (USI left, USI up, USI right, USI down, USI depth, bool drawDetails, USI textXCoordinate, USI textYCoordinate, char text[])
{
    // Draw the button.
    bar3d(left, up, right, down, depth, drawDetails);

    // Set the font characteristics.
    settextstyle(BOLD_FONT, HORIZ_DIR, FONT_SIZE);

    // Write the text.
    outtextxy(textXCoordinate, textYCoordinate, text);
}



/**
    Draws all the buttons of the main menu.
    Input:
        - none
    Output:
        - draws all the buttons of the main menu on the screen
**/
void drawMainMenuButtons ()
{
    // Clear the window.
    cleardevice();

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Get the parameters for drawing the "START" button.
    unsigned short int distanceFromCenter = 100;
    unsigned short int left = screenWidth / 2 - distanceFromCenter;
    unsigned short int right = screenWidth / 2 + distanceFromCenter;
    unsigned short int up = 200 + screenHeight - 1080;
    unsigned short int down = 300 + screenHeight - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = screenWidth / 2 - 50;
    unsigned short int textYCoordinate = 250 + screenHeight - 1080;
    char text[] = "START";

    // Draw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for drawing the "RULES" button.
    up = 400;
    down = 500;
    textYCoordinate = 450;
    strcpy(text, "RULES");

    // Draw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for drawing the "EXIT" button.
    up = 600;
    down = 700;
    textXCoordinate += 10;
    textYCoordinate = 650;
    strcpy(text, "EXIT");

    // Draw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Determines where the user clicked on the screen.
    Input:
        - "xCoordinate": the x coordinate for the click
        - "yCoordinate": the y coordinate for the click
    Output:
        - 0: the user clicked outside the buttons
        - 1: the user clicked on the "START" button
        - 2: the user clicked on the "RULES" button
        - 3: the user clicked on the "EXIT" button
*/
unsigned short int checkMouseLocation (double xCoordinate, double yCoordinate)
{
    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    if (xCoordinate >= screenWidth / 2 - 100 && xCoordinate <= screenWidth / 2 + 100)

        // The user clicked on the "START" button.
        if(yCoordinate >= 200 + screenHeight - 1080 && yCoordinate <= 300 + screenHeight - 1080)
            return 1;

        // The user clicked on the "RULES" button.
        else if (yCoordinate >= 400 + screenHeight - 1080 && yCoordinate <= 500 + screenHeight - 1080)
            return 2;

        // The user clicked on the "EXIT" button.
        else if (yCoordinate >= 600 + screenHeight - 1080 && yCoordinate <= 700 + screenHeight - 1080)
            return 3;

    // The user clicked outside the buttons.
    return 0;
}



/**
    Redraws the "START" button with the hover effect on it.
    Input:
        - none
    Output:
        - redraws all the buttons with the hover effect on the "START" button
**/
void hoverStart ()
{
    // Clear the window.
    cleardevice();

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Get the new parameters for redrawing the "START" button.
    unsigned short int distanceFromCenter = 80;
    unsigned short int left = screenWidth / 2 - distanceFromCenter;
    unsigned short int right = screenWidth / 2 + distanceFromCenter + 40;
    unsigned short int up = 180 + screenHeight - 1080;
    unsigned short int down = 280 + screenHeight - 1080;
    unsigned short int depth = 10;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = screenWidth / 2 - 30;
    unsigned short int textYCoordinate = 230 + screenHeight - 1080;
    char text[] = "START";

    // Redraw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "RULES" button.
    distanceFromCenter = 100;
    left = screenWidth / 2 - distanceFromCenter;
    right = screenWidth / 2 + distanceFromCenter;
    up = 400 + screenHeight - 1080;
    down = 500 + screenHeight - 1080;
    depth = 25;
    textXCoordinate = screenWidth / 2 - 50;
    textYCoordinate = 450;
    strcpy(text, "RULES");

    // Redraw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "EXIT" button.
    up = 600 + screenHeight - 1080;
    down = 700 + screenHeight - 1080;
    textXCoordinate += 10;
    textYCoordinate = 650;
    strcpy(text, "EXIT");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Redraws the "RULES" button with the hover effect on it.
    Input:
        - none
    Output:
        - redraws all the buttons with the hover effect on the "RULES" button
**/
void hoverRules ()
{
    // Clear the window.
    cleardevice();

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Get the new parameters for redrawing the "START" button.
    unsigned short int distanceFromCenter = 100;
    unsigned short int left = screenWidth / 2 - distanceFromCenter;
    unsigned short int right = screenWidth / 2 + distanceFromCenter;
    unsigned short int up = 200 + screenHeight - 1080;
    unsigned short int down = 300 + screenHeight - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = screenWidth / 2 - 50;
    unsigned short int textYCoordinate = 250 + screenHeight - 1080;
    char text[] = "START";

    // Redraw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "RULES" button.
    distanceFromCenter = 80;
    left = screenWidth / 2 - distanceFromCenter;
    right = screenWidth / 2 + distanceFromCenter + 40;
    up = 380 + screenHeight - 1080;
    down = 480 + screenHeight - 1080;
    depth = 10;
    textXCoordinate = screenWidth / 2 - 30;
    textYCoordinate = 430 + screenHeight - 1080;
    strcpy(text, "RULES");

    // Redraw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "EXIT" button.
    distanceFromCenter = 100;
    left = screenWidth / 2 - distanceFromCenter;
    right = screenWidth / 2 + distanceFromCenter;
    up = 600 + screenHeight - 1080;
    down = 700 + screenHeight - 1080;
    depth = 25;
    textXCoordinate -= 10;
    textYCoordinate = 650 + screenHeight - 1080;
    strcpy(text, "EXIT");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Redraws the "EXIT" button with the hover effect on it.
    Input:
        - none
    Output:
        - redraws all the buttons with the hover effect on the "EXIT" button
**/
void hoverExit ()
{
    // Clear the window.
    cleardevice();

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Get the new parameters for redrawing the "START" button.
    unsigned short int distanceFromCenter = 100;
    unsigned short int left = screenWidth / 2 - distanceFromCenter;
    unsigned short int right = screenWidth / 2 + distanceFromCenter;
    unsigned short int up = 200 + screenHeight - 1080;
    unsigned short int down = 300 + screenHeight - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = screenWidth / 2 - 50;
    unsigned short int textYCoordinate = 250 + screenHeight - 1080;
    char text[] = "START";

    // Redraw the "START" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "RULES" button.
    up = 400 + screenHeight - 1080;
    down = 500 + screenHeight - 1080;
    textYCoordinate = 450 + screenHeight - 1080;
    strcpy(text, "RULES");

    // Redraw the "RULES" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    // Update the parameters for redrawing the "EXIT" button.
    distanceFromCenter = 80;
    left = screenWidth / 2 - distanceFromCenter;
    right = screenWidth / 2 + distanceFromCenter + 40;
    up = 580 + screenHeight - 1080;
    down = 680 + screenHeight - 1080;
    depth = 10;
    textXCoordinate = screenWidth / 2 - 20;
    textYCoordinate = 630 + screenHeight - 1080;
    strcpy(text, "EXIT");

    // Redraw the "EXIT" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Redraws the "BACK" button with the hover effect on it.
    Input:
        - none
    Output:
        - redraws the "RULES" page with the hover effect on the "BACK" button
**/
void hoverBack ()
{
    // Clears the window.
    cleardevice();

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    unsigned short horizontalPosition = screenWidth / 2;
    unsigned short int fontSize = 4;
    unsigned short int verticalPosition = 100 + screenHeight - 1080;

    // Write the title.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize);
    outtextxy(horizontalPosition - 200, verticalPosition, "!!!RULES OF THE GAME!!!");

    horizontalPosition -= 50;

    // Write the rules.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize / 2);
    outtextxy(horizontalPosition - 200, verticalPosition += 150, "The board has 2 'L' shaped objects and 2 coins");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "You can move your 'L' object and, if you wish,");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "you can move at your choice one of the coins on");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "a free position. You have to move your objects");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "in such a way that you block the other player.");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "The player who runs out of moves loses!!!");

    unsigned short int left = horizontalPosition - 80;
    unsigned short int right = horizontalPosition + 120;
    unsigned short int up = 780 + screenHeight - 1080;
    unsigned short int down = 880 + screenHeight - 1080;
    unsigned short int depth = 10;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 20;
    unsigned short int textYCoordinate = 830 + screenHeight - 1080;
    char text[] = "BACK";

    // Draw the "BACK" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Redraws the "PLAYER vs COMPUTER" button with the hover effect on it.
    Input:
        - none
    Output:
        - redraws the "PLAYER vs COMPUTER" button with the hover effect on it
**/
void hoverSinglePlayer ()
{
    cleardevice();

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    unsigned short int horizontalPosition = screenWidth / 2;
    unsigned short int left = horizontalPosition - 150;
    unsigned short int right = horizontalPosition + 250;
    unsigned short int up = horizontalPosition - 600 + screenHeight - 1080;
    unsigned short int down = horizontalPosition - 500 + screenHeight - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 120;
    unsigned short int textYCoordinate = screenWidth / 2 - 550 + screenHeight - 1080;
    char text[] = "PLAYER vs COMPUTER";

    // Draw the "PLAYER vs COMPUTER" button.
    drawButton(left + 20, up - 20, right + 20, down - 20, depth - 15, drawDetails, textXCoordinate + 20, textYCoordinate - 20, text);

    //Update the values.
    up += 300;
    down += 300;
    textXCoordinate += 20;
    textYCoordinate += 300;
    strcpy(text, "PLAYER vs PLAYER");

    //Draw the "PLAYER vs PLAYER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Redraws the "PLAYER vs PLAYER" button with the hover effect on it.
    Input:
        - none
    Output:
        - redraws the "PLAYER vs PLAYER" button with the hover effect on it
**/
void hoverMultiPlayer ()
{
    cleardevice();

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    unsigned short int horizontalPosition = screenWidth / 2;
    unsigned short int left = horizontalPosition - 150;
    unsigned short int right = horizontalPosition + 250;
    unsigned short int up = horizontalPosition - 600 + screenHeight - 1080;
    unsigned short int down = horizontalPosition - 500 + screenHeight - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 120;
    unsigned short int textYCoordinate = screenWidth / 2 - 550 + screenHeight - 1080;
    char text[] = "PLAYER vs COMPUTER";

    // Draw the "PLAYER vs COMPUTER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    //Update the values.
    up += 280;
    down += 280;
    left += 20;
    right +=20;
    depth = 10;
    textXCoordinate += 40;
    textYCoordinate += 280;
    strcpy(text,"PLAYER vs PLAYER");

    //Draw the "PLAYER vs PLAYER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Draws the "START" page.
    Input:
        - none
    Output:
        - draws the "START" page
**/
void drawStartPage ()
{
    // Clear the window.
    cleardevice();

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    unsigned short int horizontalPosition = screenWidth / 2;
    unsigned short int left = horizontalPosition - 150;
    unsigned short int right = horizontalPosition + 250;
    unsigned short int up = horizontalPosition - 600;
    unsigned short int down = horizontalPosition - 500;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 120;
    unsigned short int textYCoordinate = screenWidth / 2 - 550;
    char text[] = "PLAYER vs COMPUTER";

    // Draw the "SINGLE PLAYER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);

    //Update the values.
    up += 300;
    down += 300;
    textXCoordinate += 20;
    textYCoordinate += 300;
    strcpy(text,"PLAYER vs PLAYER");

    //Draw the "MULTIPLAYER" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    Draws the "RULES" page.
    Input:
        - none
    Output:
        - draws the "RULES" page
**/
void drawRulesPage ()
{
    // Clear the screen.
    cleardevice();

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    unsigned short horizontalPosition = screenWidth / 2;
    unsigned short int fontSize = 4;
    unsigned short int verticalPosition = 100 + screenHeight - 1080;

    // Write the title.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize);
    outtextxy(horizontalPosition - 200, verticalPosition, "!!!RULES OF THE GAME!!!");

    horizontalPosition -= 50;

    // Write the rules.
    settextstyle(BOLD_FONT, HORIZ_DIR, fontSize / 2);
    outtextxy(horizontalPosition - 200, verticalPosition += 150, "The board has 2 'L' shaped objects and 2 coins");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "You can move your 'L' object and, if you wish,");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "you can move at your choice one of the coins on");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "a free position. You have to move your objects");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "in such a way that you block the other player.");
    outtextxy(horizontalPosition - 200, verticalPosition += 50, "The player who runs out of moves loses!!!");

    unsigned short int left = horizontalPosition - 100;
    unsigned short int right = horizontalPosition + 100;
    unsigned short int up = 800 + screenHeight - 1080;
    unsigned short int down = 900 + screenHeight - 1080;
    unsigned short int depth = 25;
    bool drawDetails = 1;
    unsigned short int textXCoordinate = horizontalPosition - 40;
    unsigned short int textYCoordinate = 850 + screenHeight - 1080;
    char text[] = "BACK";

    // Draw the "BACK" button.
    drawButton(left, up, right, down, depth, drawDetails, textXCoordinate, textYCoordinate, text);
}



/**
    ???
**/
void clickOnStart ()
{
    // Clear the window.
    cleardevice();

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Draws the "RULES" page.
    drawStartPage();

    bool onStartPage = true;
    bool changer = false;

    // Horizontal left position for the "RULES" button.
    unsigned short int startPosition = screenWidth / 2;

    while (onStartPage == true)
    {
        HWND hwnd = GetForegroundWindow();  /// ?????
        POINT cursorPosition;

        // Get the mouse position.
        GetCursorPos(&cursorPosition);
        // Get the mouse position on the window.
        ScreenToClient(hwnd,&cursorPosition);

        double xCoordinate = cursorPosition.x;
        double yCoordinate = cursorPosition.y;

        // First we check if the usScreenToClient(hwnd, &p)er clicked somewhere on the screen, then we check the position.
        // After this, we check if we can apply the hover animation on the button.
        if (GetAsyncKeyState(VK_LBUTTON))

            // Check if the click is inside the "SINGLE PLAYER" button.
            if (xCoordinate >= startPosition - 150 && xCoordinate <= startPosition + 150)
                if (yCoordinate >= 300 + screenHeight - 1080 && yCoordinate <= 400 + screenHeight - 1080)
                {
                    ///Action if user clicks on Single player
                    onStartPage = false;
                }
                else if(yCoordinate >=600 + screenHeight - 1080 && yCoordinate <= 700 + screenHeight - 1080)
                {
                    ///Action if user clicks on Multiplayer
                    onStartPage = false;
                    startMultiplayerGame();
                }

        if (xCoordinate >= startPosition - 150 && xCoordinate <= startPosition + 150)
            if (yCoordinate >= 300 + screenHeight - 1080 && yCoordinate <= 400 + screenHeight - 1080)
            {
                 if (changer == false)
                 {
                    changer = true;
                    cleardevice();
                    hoverSinglePlayer();
                 }
            }
            else if(yCoordinate >= 600 + screenHeight - 1080 && yCoordinate <= 700 + screenHeight - 1080)
            {
                if(changer == false)
                {
                    changer = true;
                    cleardevice();
                    hoverMultiPlayer();
                }
            }
            else
            {
                if (changer == true)
                {
                    changer = false;
                    drawStartPage();
                }
            }
        else if (changer == true)
        {
            changer = false;
            drawStartPage();
        }
    }

    // Redraw the main window.
    drawMainMenuButtons();

    // Look for the mouse position.
    scanMousePosition();
}



/**
    Redirects to the "RULES" page.
    Input:
        - none
    Output:
        - redirects to the "RULES" page
**/
void clickOnRules ()
{
    // Clears the screen.
    cleardevice();

    // Get the size of the screen.
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Draws the "RULES" page.
    drawRulesPage();

    bool onRulesPage = true;
    bool changer = false;

    // Horizontal left position for the "RULES" button.
    unsigned short int startPosition = screenWidth / 2;

    while (onRulesPage == true)
    {
        HWND hwnd = GetForegroundWindow();
        POINT cursorPosition;

        // Get the mouse position.
        GetCursorPos(&cursorPosition);
        // Get the mouse position on the window.
        ScreenToClient(hwnd,&cursorPosition);

        double xCoordinate = cursorPosition.x;
        double yCoordinate = cursorPosition.y;

        // First we check if the usScreenToClient(hwnd, &p)er clicked somewhere on the screen, then we check the position.
        // After this, we check if we can apply the hover animation on the button.
        if (GetAsyncKeyState(VK_LBUTTON))

            // Check if the click is inside the "BACK" button.
            if (xCoordinate >= startPosition  - 100 && xCoordinate <= startPosition + 100)
                if (yCoordinate >= 800 + screenHeight - 1080 && yCoordinate <= 900 + screenHeight - 1080)
                {
                    xCoordinate = cursorPosition.x;
                    yCoordinate = cursorPosition.y;
                    onRulesPage = false;
                }

        if (xCoordinate >= startPosition - 100 && xCoordinate <= startPosition + 100)
            if (yCoordinate >= 800 + screenHeight - 1080 && yCoordinate <= 900 + screenHeight - 1080)
            {
                 if (changer == false)
                 {
                    changer = true;
                    cleardevice();
                    hoverBack();
                 }
            }
            else
            {
                if (changer == true)
                {
                    changer = false;
                    drawRulesPage();
                }
            }
        else if (changer == true)
        {
            changer = false;
            drawRulesPage();
        }
    }

    // Redraw the main window.
    drawMainMenuButtons();

    // Look for the mouse position.
    scanMousePosition();
}



/**
    Permanently scans the mouse position.
    Input:
        - none
    Output:
        - none
**/
void scanMousePosition ()
{
    HWND hwnd = GetForegroundWindow();
    POINT cursorPosition;
    bool buttonPressed = false;
    bool changer = false;

    while (buttonPressed == false)
    {
        // Get the mouse position.
        GetCursorPos(&cursorPosition);
        // Get the mouse position on the screen.
        ScreenToClient(hwnd,&cursorPosition);
        double xCoordinate = cursorPosition.x;
        double yCoordinate = cursorPosition.y;

        // Check if the click is on a button.
        unsigned short int button = checkMouseLocation(xCoordinate, yCoordinate);

        switch (button)
        {
            // The "START" button
            case 1:
                if (changer == false)
                    hoverStart();
                changer = true;
                break;

            // The "RULES" button
            case 2:
                if (changer == false)
                    hoverRules();
                changer = true;
                break;

            // The "EXIT" button
            case 3:
                if (changer == false)
                    hoverExit();
                changer = true;
                break;

            // The click is outside the buttons.
            default:
                if (changer == true)
                {
                    cleardevice();
                    drawMainMenuButtons();
                }
                changer = false;
        }

        // If you pressed left click
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            // Get the position of the cursor.
            int button = checkMouseLocation(xCoordinate, yCoordinate);

            switch (button)
            {
                // The "START" button
                case 1:
                    buttonPressed = true;
                    clickOnStart();
                    break;

                // The "RULES" button
                case 2:
                    buttonPressed = true;
                    clickOnRules();
                    break;

                case 3:
                    exit(0);
            }
        }

        // Wait 30 milliseconds for performance reasons. (we don t want to scan the mouse position every millisecond)
        delay(30);
    }
}



/**
    Closes the application.
    Input:
        - none
    Output:
        - closes the application
**/
void closeApplication ()
{
    closegraph();
    getch();
}
