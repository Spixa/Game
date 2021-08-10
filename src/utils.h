#include <vector>
#include <SFML/Graphics.hpp>

class util {
public:
    static int getIndex(std::vector<sf::Drawable*> v, sf::Drawable* K)
    {
        auto it = find(v.begin(), v.end(), K);
    
        // If element was found
        if (it != v.end())
        {
        
            // calculating the index
            // of K
            int index = it - v.begin();
            return index;
        }
        else {
            // If the element is not
            // present in the vector
            return -1;
        }
    }

};