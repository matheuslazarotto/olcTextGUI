#include "Application.h"

bool olcApplication::OnUserCreate()
{
    return true;
}

bool olcApplication::OnUserUpdate(float fElapsedTime)
{
    Clear(olc::VERY_DARK_GREY);
    olc::vi2d vMousePos = {GetMouseX(), GetMouseY()};

    // Select sext size
         if (GetKey(olc::Key::K1).bPressed) { vCharSize = 1 * GetTextSize(" "); }
    else if (GetKey(olc::Key::K2).bPressed) { vCharSize = 2 * GetTextSize(" "); }
    else if (GetKey(olc::Key::K3).bPressed) { vCharSize = 3 * GetTextSize(" "); }
    else if (GetKey(olc::Key::K4).bPressed) { vCharSize = 4 * GetTextSize(" "); }
    else if (GetKey(olc::Key::K5).bPressed) { vCharSize = 5 * GetTextSize(" "); }
    else if (GetKey(olc::Key::K6).bPressed) { vCharSize = 6 * GetTextSize(" "); }
    else if (GetKey(olc::Key::K7).bPressed) { vCharSize = 7 * GetTextSize(" "); }
    else if (GetKey(olc::Key::K8).bPressed) { vCharSize = 8 * GetTextSize(" "); }
    else if (GetKey(olc::Key::K9).bPressed) { vCharSize = 9 * GetTextSize(" "); }

    // Display Info
    DrawString({5, 5}, "Right click to create box", olc::WHITE, 2);
    DrawString({5, 5 + 1 + 2 * GetTextSize(" ").y}, "Text scale: " + std::to_string(vCharSize.x / 8), olc::WHITE, 2);
    DrawString({ScreenWidth() - GetTextSize("ABNT2 format").x - 5, ScreenHeight() - GetTextSize(" ").y - 5}, 
                "ABNT2 key format", olc::WHITE, 1);

    // Draw boxes and Handle input
    for (auto &text : vTextBoxes)
    {
        // Update CapsLock state
        if (GetKey(olc::CAPS_LOCK).bPressed)
        {
            text.bCapsLockOn = !text.bCapsLockOn;
        }

        // Draw and Handle events
        text.OnTextUpdate((*this), vMousePos, fElapsedTime);

        // Return selected box text
        if (text.bBoxActive && GetKey(olc::ENTER).bPressed)
        {
            sTextSelected = text.GetText();
        }
    }

    // Click to create
    if (GetMouse(1).bPressed)
    {
        bCreateBox = true;
        vNewBoxOffset = vMousePos;
    }
    else if (bCreateBox && !GetMouse(0).bPressed)
    {
        //                                                                                 Char + pad(5 + 5)
        vNewBoxSize = {vCharSize.x * (int)((vMousePos.x - vNewBoxOffset.x) / vCharSize.x), vCharSize.y + 10};
        DrawRect(vNewBoxOffset, vNewBoxSize, olc::BLUE);
    }
    else if (bCreateBox && GetMouse(0).bPressed)
    {
        vNewBoxSize = {vCharSize.x * (int)((vMousePos.x - vNewBoxOffset.x) / vCharSize.x), vCharSize.y};
        if (vNewBoxSize.x < 0) 
        { 
            vNewBoxOffset.x = vNewBoxOffset.x + vNewBoxSize.x;
            vNewBoxSize.x = abs(vNewBoxSize.x);
        }
        
        olcTextGUI NewTextBox(vNewBoxOffset, vNewBoxSize, vCharSize.x / 8, olc::WHITE);
        vTextBoxes.push_back(NewTextBox);
        
        vNewBoxOffset = {0, 0};
        vNewBoxSize = {0, 0};
        bCreateBox = false;
    }
    
    // Print last returned text
    DrawString({5, ScreenHeight() - 2 * GetTextSize(sTextSelected).y - 5}, "Last Entered text: " + sTextSelected, olc::WHITE, 2);
    
    return true;
}