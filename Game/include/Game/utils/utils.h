#pragma once
#define EQUALS ==
#include <vector>
#include <SFML/Graphics.hpp>
#include <Game/Game.h>

class util {
public:
    template <typename T>
    static int getIndex(std::vector<T*> v, T* K)
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
    static inline std::vector<int> genLevel(const int x, const int y) {
        /* deprecated -- values are now dynamically allocated by util::genLevel() itself
        if (false) {
            outl("level_gen: designated size of (" << x << " * " << y << " = " << x*y << " is smaller than " << arr_size);
        }
        */
        std::vector<int> array;
        int total = x*y, xc = 0, yc = 0;

        for (size_t i = 0; i < total; i++) {

            if (xc < x) {
                xc++;
            } else {
                yc++;
            }
           // seed to the most random sht ever 

            srand(  rand() * time(0) % (rand() * time(0)) + 1937);
            
            // random
            short random = rand() % 16;

            if (random == 0) {
               array[i] = 0;
            } else {
               array[i] = 1;
            }
            
        }

        return array;
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
        if (str == "true" || str == "True" || str == "TRUE" || str == "tru" || str == "trueeeee")
            return true;
        return false;
    }

};

