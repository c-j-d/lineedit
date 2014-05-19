#ifndef UTILS_H
#define	UTILS_H

#include <string>
#include <cctype>

class LineEditUtils {
public:

    static std::string reverseString(std::string s) {
        std::string result = "";
        for (int i = 0; i < s.length(); i++) {
            result = s[ i ] + result;
        }
        return result;
    }

    static unsigned int charLen(const char* buf) { // must be a null terminated char pointer
        std::string s(buf);
        return s.size();
    }

    static bool contains(char c, const char* buf) {
        std::string s(buf);        
        for (unsigned int i = 0; i < s.size(); i++) {
            if (s.at(i) == c) {
                return true;
            }
        }
        return false;
    }

    static bool lastCharContains(const char* buf, const char* test) {
        if (charLen(buf) <= 0) {
            return false;
        }
        return contains(buf[charLen(buf) - 1], test);
    }
    
    static const char* popChar(const char* buf){
        std::string s(buf);
        if(s.size() <= 1){
            return s.c_str();
        }
        return s.substr(0, s.size()-1).c_str();
    }
    
    /**
     * Get last char
     * @param buf
     * @return 
     */
    static const char getTail(const char* buf){
        std::string s(buf);
        return s.at(s.size()-1);
    }

    static const char* getTail(const char* buf, int fromPosition) {
        std::string tmp;
        for (int i = fromPosition; i < charLen(buf); i++) {
            tmp += buf[i];
        }

        return tmp.c_str();
    }

    static const char* extractSubject(const char* cmd) {
        std::string s = "";
        bool foundStart = false;

        for (int i = charLen(cmd) - 1; i >= 0; i--) {
            char c = cmd[i];
            if (!foundStart && isalpha(c)) {
                foundStart = true;
            }

            if (foundStart) {
                if (isalnum(c)) {
                    s += c;
                } else {
                    break;
                }
            }
        }
        return reverseString(s).c_str();
    }


};
#endif	/* UTILS_H */

