#include "style.h"

using namespace std;

// Static Style
void Style::display_green(char c)
{
    string s = "\033[1;32m";
    s.push_back(c);
    s += "\033[0m";
    cout << s;
}
void Style::display_yellow(char c)
{
    string s = "\033[1;33m";
    s.push_back(c);
    s += "\033[0m";
    cout << s;
}
void Style::display_red(char c)
{
    string s = "\033[1;31m";
    s.push_back(c);
    s += "\033[0m";
    cout << s;
}