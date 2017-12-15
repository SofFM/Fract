#include <iostream>
#include "window.hpp"

std::size_t bin_pow(std::size_t a, std::size_t n) {
   int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

void build_fractal(wn::Window& fractal, std::size_t N, wn::Window& pat){
	
	struct Data {
		wn:Window win;
		std::size_t level;
	};
	
	std::size_t w=pat.get_width();
	std::size_t h=pat.get_height();
	
	std::size_t count{}; //the number of windows that will be opened due to pattern
	
	for(std::size_t i = 0; i < h*w; ++i){
		if(pat(i / w, i % w){
			++count;
		}
	}
	count=bin_pow(count, N-1); // the number of windows that will be opened in N-dimensional fractal due to pattern
	Data* wins = new Data[count];
	
	std::size_t level=1; //level 1 corresponds to the opening of (N-1)-dimensional windows
	for (std::size_t j=0; j<h*w; ++j){
		while (count){
			for(std::size_t i = 0; i < h*w; ++i){
				if(pat(i / w, i % w){
					wins[i].win= sub_win(fractal,
					(i/ w) * bin_pow(h, N - level)+(j/w)*(bin_pow(h,level), // y coordinate
					(i % w ) * bin_pow(w , N - level)+(j%w)*bin_pow(w,level), // x coordinate
					bin_pow(h, N - level), bin_pow(w , N - level));
					wuns[i].level=level;
					if (level==N-1) {
						wins[i].win=pattern;
					}
					--count;
				}
			}
			++level;
		}
	}
	
    
	return;
}


void tests();

int main(){
    tests();
    std::size_t h,w,N;

    std::cout << "Input N: ";
    if(!(std::cin >> N)){
        if(N < 1){
            std::cout << "\nN must be more the 0\n";
            return 1;
        }
        std::cout << "\nWrong type\n";
        return 1;
    }

    std::cout << "Input h: ";
    if (!(std::cin >> h)){
        std::cout << "\nWrong type\n";
        return 1;
    }
    std::cout << "Input w: ";
    if (!(std::cin >> w)){
        std::cout << "\nWrong type\n";
        return 1;
    }
    wn::Window pattern(h,w);
    std::cout << "Enter the pattern:\n";
    std::cin >> std::noskipws;
    char inp{};
    if (std::cin >> inp) {
        for (std::size_t i = 0; i < h; ++i) {
            for (std::size_t j = 0; j < w + 1; ++j) {
                if (std::cin >> inp) {
                    if (inp != '\n' && j < w) {
                        pattern(i,j)=(inp=='#');
                    } else {
                        if (j < w) {
                            for (std::size_t k = j; k < w; ++k)
                                pattern(i,k)=0;
                            break;
                        } else {
                            if (inp != '\n') {
                                std::cerr << "Incorrect pattern!";
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (N==1){
        std::cout<<pattern<<'\n';
        return 0;
    } 
	else { 
		wn::Window fractal(bin_pow(h,N),bin_pow(w,N));
		build_fractal(fractal, N, pat);
		std::cout<<fractal<<'\n';
	}
    return 0;
}

