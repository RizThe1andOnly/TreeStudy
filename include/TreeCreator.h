/**
 * @file TreeCreator.h
 * @author Rizwan Chowdhury
 * @brief Interface to read in data and convert to a tree data structure.
 * @version 0.1
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 * Define an abstract class(es) which can read tree structures from a file. There will be different implementations of the abstract class 
 * based on what type of file is being read.
 * 
 * Classes will be defined for reading as well as parsing.
 * 
 * Current plan will be to read in all bytes at once and then pass it to parser.
 */


// includes
#include <vector>
#include <string>


/**
 * @brief Abstract class for parsing read bytes into tree structures.
 * 
 * Will implemente a system which iterates through read bytes and triggers a method call upon hitting a delimiter.
 * Each child class will construct its own delimiter list and concrete delimiter processing methods.
 * 
 */
class TreeParser{
    public:
        TreeParser();
        void parseReadBytes(std::vector<int> bytes);
    
    private:
        std::vector<int> localBytes;
        // pick between one of the two following:
        std::string delimiters_regex;
        std::vector<char> delimiters;
        // pick between one of the two above.
        void iterateThroughBytes();
        void delimiterEvent();

};
