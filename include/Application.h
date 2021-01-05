#include "olcPixelGameEngine.h"
#include "TextGUI.h"

class olcApplication : public olc::PixelGameEngine
{
public:
    olcApplication() { sAppName = "Application"; }

private:
    std::vector<olcTextGUI> vTextBoxes;
    olc::vi2d vNewBoxSize;
    olc::vi2d vNewBoxOffset;
    olc::vi2d vCharSize = 2 * GetTextSize(" ");
    std::string sTextSelected;
    bool bCreateBox = false;

protected:  
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
};