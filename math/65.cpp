//
// Created by 成翔昊 on 2022/11/5.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    enum CharType {
        CHAR_SIGN,
        CHAR_NUMBER,
        CHAR_POINT,
        CHAR_EXP,
        CHAR_END,
        CHAR_ILLEGAL,
    };
    enum State {
        STATE_INIT,
        STATE_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_LEFT_NONE,
        STATE_DECIMAL,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_INTEGER,
        STATE_END,
        STATE_ERROR
    };
    unordered_map<State, unordered_map<CharType, State>> transferMap = {
            {STATE_INIT,            {
                                            {CHAR_SIGN,   STATE_SIGN},
                                            {CHAR_NUMBER, STATE_INTEGER},
                                            {CHAR_POINT, STATE_POINT_LEFT_NONE}
                                    }
            },
            {STATE_SIGN,            {
                                            {CHAR_NUMBER, STATE_INTEGER},
                                            {CHAR_POINT,  STATE_POINT_LEFT_NONE}
                                    }
            },
            {STATE_INTEGER,         {
                                            {CHAR_NUMBER, STATE_INTEGER},
                                            {CHAR_POINT,  STATE_POINT},
                                            {CHAR_EXP,    STATE_EXP},
                                            {CHAR_END,   STATE_END}
                                    }
            },
            {STATE_POINT,           {
                                            {CHAR_NUMBER, STATE_DECIMAL},
                                            {CHAR_EXP,    STATE_EXP},
                                            {CHAR_END,   STATE_END}

                                    }
            },
            {STATE_POINT_LEFT_NONE, {
                                            {CHAR_NUMBER, STATE_DECIMAL},
                                    }
            },
            {STATE_DECIMAL,         {
                                            {CHAR_NUMBER, STATE_DECIMAL},
                                            {CHAR_EXP,    STATE_EXP},
                                            {CHAR_END,    STATE_END}
                                    }
            },
            {STATE_EXP,             {
                                            {CHAR_SIGN,   STATE_EXP_SIGN},
                                            {CHAR_NUMBER, STATE_EXP_INTEGER}
                                    }
            },
            {STATE_EXP_SIGN,        {
                                            {CHAR_NUMBER, STATE_EXP_INTEGER}
                                    }
            },
            {STATE_EXP_INTEGER,     {
                                            {CHAR_NUMBER, STATE_EXP_INTEGER},
                                            {CHAR_END,    STATE_END}
                                    }
            },
    };
public:
    bool isNumber(string s) {
        State state = STATE_INIT;
        for (auto ch: s) {
            CharType charType = toCharType(ch);
            if (charType == CHAR_ILLEGAL) return false;

            unordered_map<CharType, State> stateMap = transferMap[state];
            if (stateMap.find(charType) == stateMap.end()) return false;

            state = stateMap[charType];
        }

        unordered_map<CharType, State> stateMap = transferMap[state];
        if (stateMap.find(CHAR_END) == stateMap.end()) return false;

        return true;
    }

private:
    CharType toCharType(char ch) {
        if (ch == '+' || ch == '-') return CHAR_SIGN;
        if (ch >= '0' && ch <= '9') return CHAR_NUMBER;
        if (ch == '.') return CHAR_POINT;
        if (ch == 'e' || ch == 'E') return CHAR_EXP;
        return CHAR_ILLEGAL;
    }
};

int main() {
    Solution s;
    cout << s.isNumber(".0e7") << endl;
}