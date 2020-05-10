#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

enum CardType {
    SINGLE = 0,
    COUPLE,
    TRIPLE,
    STREAM,
    BOMB
};

typedef pair<CardType, int> CARD;

int cardToNumber(string card)
{
    if (1 != card.size())
    {
        if (card == "10") return 10;
        if (card == "joker") return 16;
        if (card == "JOKER") return 17;
    } else {
        char c = card[0];
        if ('3' <= c && c <= '9') return c - '0';
        if (c == 'J') return 11;
        if (c == 'Q') return 12;
        if (c == 'K') return 13;
        if (c == 'A') return 14;
        if (c == '2') return 15;
    }
}

CARD parseCards(const vector<string>& card) {
    switch (card.size()) {
        case 1:
            return make_pair(SINGLE, cardToNumber(card[0]));
        case 2:
            if (card[0] == "joker" || card[0] == "JOKER") return make_pair(BOMB, cardToNumber(card[1]));
            else return make_pair(COUPLE, cardToNumber(card[0]));
        case 3:
            return make_pair(TRIPLE, cardToNumber(card[0]));
        case 4:
            return make_pair(BOMB, cardToNumber(card[0]));
        case 5:
            return make_pair(STREAM, cardToNumber(card[0]));
    }
}

vector<string> toArray(const string& card)
{
    vector<string> result;
    istringstream iss(card);
    for(std::string s; iss >> s; )
        result.push_back(s);
    return result;
}

int main() {
    string line;
    while (std::getline(std::cin, line)) {
        auto index = line.find('-');
        string A = line.substr(0, index);
        string B = line.substr(index + 1);
        CARD typeA = parseCards(toArray(A));
        CARD typeB = parseCards(toArray(B));
        if (typeA.first != typeB.first)
        {
            if (typeA.first == BOMB) cout << A << endl;
            else if (typeB.first == BOMB) cout << B << endl;
            else cout << "ERROR" << endl;
        } else {
            cout << ((typeA.second < typeB.second) ? B : A) << endl;
        }
    }
    return 0;
}
