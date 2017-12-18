#include <iostream>
#include <taskThree/window.hpp>
#include <cassert>

int main(){
    using namespace wn;

    {
        Window win(3,4);
        Window empty_win;

        std::cout << "Checking window size...\n";
        assert ((win.get_height()==3)&&(win.get_width()==4));

        std::cout << "Writing values in window...\n";
        for (std::size_t i=0; i<win.get_height(); ++i){
            for (std::size_t j=0; j<win.get_width(); ++j){
                win(i,j)=1;
                assert(win(i,j)==1);
            }
        }

        std::cout << "Checking empty window...\n";
        assert (static_cast<bool>(empty_win) ==0);
    }

    {
        Window win(2,2);
        win(0,0)=1;
        win(1,1)=1;
        Window win2(win);

        std::cout << "Checking copy constructor...\n";
        assert (win==win2);
        Window win3(static_cast<Window &&>(win));

        std::cout << "Checking move constructor...\n";
        assert (win2==win3);
        assert(static_cast<bool>(win)==0);

    }

    {
        Window win(2,2);
        win(0,0)=1;
        win(1,1)=1;
        Window win2;
        win2=win;

        std::cout << "Checking copy operator...\n";
        assert(win==win2);
        Window win3;

        win3=static_cast<Window&&>(win);

        std::cout << "Checking move operator...\n";
        assert(win2==win3);
        assert(static_cast<bool>(win)==0);
    }
    return 0;
}

