#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.h"

class util {
public:
    template <typename T>
    static int getIndex(std::vector<T*> v, sf::Drawable* K)
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
    template <typename T>
    static std::string to_str(const T& param)
    {
        std::stringstream sstream;
        sstream << param;
        return sstream.str();
    }

    static float to_float(const std::string& str)
    {
        return std::stof(str);
    }

    static int to_int(const std::string& str)
    {
        return std::stoi(str);
    }

    static bool to_bool(const std::string& str)
    {
        if (str == "true" || str == "True" || str == "TRUE")
            return true;
        return false;
    }

};

