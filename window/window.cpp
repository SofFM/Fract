#include "window.hpp"

namespace wn{                                                                  
	
	
	COmmon::Common():
		step(),
		owners(),
		data(nullptr)
	{}
	
	
	Common::~Common(){  
		delete data;
	}
	
	
	Common::Common(std::size_t h_, std::size_t w_):
		step(w),
		owners(1),
		data(nullptr)
	{
		data= new bool[h_*w_]{};
	}	
	
	
		
	Common::Common (const Common& info):
		step(info.step),
		owners(1),
		data(nullptr)
	{}	
		
		
	Common::Common (Common&& info):
		step(info.step),
		owners(info.owners),
		data(info.data)
	{
		info.data=nullptr;
	}
		
	Common& Common::operator = (const Common& info){
		step=info.step;
		owners=1;
		delete data;
		data=nullptr;
	}
	
	Common& Common::operator = (Common&& info){
		step=info.step;
		owners=info.owners;
		delete data; 
		data = info.data;
		info.data= nullptr;
	}

	Common::Common(Window& window, std::size_t x, std::size_t y, std::size_t w): 
		step(w),
		owners(),
		data(window.start+y+x*window.info.step)
	{
		 owners=window.inc_owners();
    }
	
	
	Window::Window():
        h(),
        w(),
        info(),
		start(info.data)
    {}


   Window::Window(std::size_t h_, std::size_t w_):
        h(h_),
        w(w_),
        info(h_,w_)
    {}
	
	

    Window::Window(Window& window, std::size_t x, std::size_t y, std::size_t h_, std::size_t w_):
        h(h_),
        w(w_),
        info(window,x,y,w)
		start(info.data)
    {}
    
	Window::Window (const Window& window):  
		h(window.h),
        w(window.w),
        info(window.info),
        start(nullptr)
    {
		info.data= new bool[h*w]{};
		for (std::size_t i=0; i <h*w; ++i){
			info.data[i]=window.info.data[i];
		}
		start=info.data;
	}


    Window::Window(Window&& window):
        h(window.h),
        w(window.w),
        info(static_cast<Common&&>(window.info)),
		start(window.start)
    {
        window.data=nullptr;
		window.stat=nullptr;
    }


    Window& Window::operator =(const Window& window){
        if (this!=&window){
            h=window.h;
			w=window.w;
			info=window.info;
			data= new bool[h*w]{};
			for (std::size_t i=0; i< h*w; ++i){
				info.data[i]=window.info.data[i];
			}
			
			start=info.data;
			
        }
		return *this;
	}

    Window& Window::operator = (Window&& window){
        if (this!=&window){
            h=window.h;
			w=window.w;
			info=static_cast<Common&&>(window.info);
			statr=window.start;
			window.start=nullptr;
        }
        
		return *this;
    }

    Window::~Window(){           // step owners bool* data // h,w, info , bool *start 
		if (info.owners==1){
			info.~Common();
		}
		start = nullptr;
	}

    //Сравнивание двух окон на идентичность
    bool Window::operator == (const Window& window) const{
        if ((h != window.h) || (w != window.w)) {
            return false;
        } else {
            for (std::size_t i = 0; i < h; ++i) {
                for (std::size_t j = 0; j < w; ++j) {
                    if (this->info.data[j + i * this->info.step] !=
                        window.info.data[j + i * window.info.step]) {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    std::ostream& operator << (std::ostream& s, const Window& window)
    {
        for (std::size_t i = 0; i < window.h; ++i) {
            for (std::size_t j = 0; j < window.w; ++j) {
                 s << (window.info.data[j + i * window.info.step] ? "# " : "  ");
            }
            s << '\n';
        }
        s << '\n';
        return s;
    }


    bool Window::operator () (std::size_t x, std::size_t y) const {
        return this->info.data[y+x*this->info.step];

    }

    bool& Window::operator () (std::size_t x, std::size_t y){
        bool& value=this->info.data[y+x*this->info.step];
        return value;

    }

    Window::operator bool() const{
        return info.data!=nullptr;
    }

    std::size_t Window::get_height() const {
        return  h;
    }

    std::size_t Window::get_width() const {
        return w;
    }

    std::size_t Window::check_owners() const{
        return info.owners;
    }


    void Window::dec_owners(){
        --info.owners;
        return;
    }
    
	void Window::inc_owners(){
        ++info.owners;
        return;
    }


}



