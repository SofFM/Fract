#ifndef WND_HPP
#define WND_HPP


#include<cstddef>
#include<ostream>

namespace wn{
	
	class Common{
		friend class Window;
        
		std::size_t step;
        std::size_t owners;
        bool* data;
		
		Common();
		
		Common(std::size_t h_, std::size_t w_);
		
		Common(Window& window, std::size_t x, std::size_t y, std::size_t w); 
		
		
		Common (const Common& info);
		Common (Common&& info);
		
		Common& operator = (const Common& info);
		Common& operator = (Common&& info);
		
		
		~Common()
	}

    class Window{
		    friend class Common;
            
			std::size_t h;
            std::size_t w;
			Common& info;
			bool* start;
        
		public:
            Window();
            Window(std::size_t h_, std::size_t w_);

            Window (const Window& window);
            Window (Window&& window);
			
            Window (Window& window, std::size_t x, std::size_t y, std::size_t h_, std::size_t w_);


            ~Window();

            friend std::ostream& operator << (std::ostream& os, const Window& window);

            Window& operator = (const Window& window);

            Window& operator = (Window&& window);

            std::ostream& operator << (std::ostream& s);

            bool operator == (const Window& window) const;

            bool operator () (std::size_t x, std::size_t y) const;

            bool& operator () (std::size_t x, std::size_t y);

            explicit operator bool() const;

            std::size_t get_width() const;
            std::size_t get_height() const;
            std::size_t check_owners() const;
    };



}
#endif // WND_HPP
