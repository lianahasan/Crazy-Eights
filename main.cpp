// Liana Hasan, Intro to CS Project
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

// Card Class:
class Card {
    private:
        string _suit;
        string _face;
    public:
        Card(string suit, string face = "") {
            _suit = suit;
            _face = face;
        }
        
        void setSuit(string suit) {
           _suit = suit; 
        }
        
        void setFace(string face) {
            _face = face;
        }
        
        string getSuit() {
            return _suit;
        }
        
        string getFace() {
            return _face;
        }
        
        void card_print() {
            cout << _suit << _face;
        }
};

const int Deck_vals = 52;
const int s_size = 4;
const int f_size = 13;

// Deck Class:
class Deck {
    private:
        vector<Card> theDeck;
        vector<string> Suits;
        vector<string> Faces;
        
    public:
        Deck() {
            Suits.push_back("H");
            Suits.push_back("D");
            Suits.push_back("C");
            Suits.push_back("S");

            Faces.push_back("1");
            Faces.push_back("2");
            Faces.push_back("3");
            Faces.push_back("4");
            Faces.push_back("5");
            Faces.push_back("6");
            Faces.push_back("7");
            Faces.push_back("8");
            Faces.push_back("9");
            Faces.push_back("10");
            Faces.push_back("J");
            Faces.push_back("Q");
            Faces.push_back("K");
            for (int i = 0; i < s_size; i++) {
                for (int j = 0; j < f_size; j++) {
                    Card card = Card(Suits.at(i),Faces.at(j)); 
                    theDeck.push_back(card);
                }
            }
        }
        
        vector<Card> ddeck() {
            vector<Card> ddeck;
            for (int i = 0; i < s_size; i++) {
                for (int j = 0; j < f_size; j++) {
                    Card card = Card(Suits.at(i),Faces.at(j)); 
                    ddeck.push_back(card);
                }
            }
            return ddeck;
        }
        
        void deck_print() {
            for(int i = 0; i < Deck_vals; i++) {
                theDeck.at(i).card_print(); 
                cout << " ";
            }
        }
        
        vector<Card> shuffle_vect(vector<Card> shuff) {
            int shuff_vals = shuff.size();
            srand(100); //changes shuffle if you change number
            for(int i = 0; i < shuff_vals; i++) {
                int j = rand()% shuff_vals;
                Card temp = shuff.at(i);
                shuff.at(i) = shuff.at(j);
                shuff.at(j) = temp;
            }
            return shuff;
        }
        
        Card drawCard(vector<Card> no) {
            return no.at(0);
        }
        
        Card newSuit(string h) {
            Card l = Card(h);
            return l;
        }
 
        vector<Card> erasevect(vector<Card> erased_cards, int ind) {
            erased_cards.erase(erased_cards.begin() + ind);
            return erased_cards;
        }
        
        void displayHand(vector<Card> disp_1) {
            char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
            cout << endl;
            for(int i = 0; i < disp_1.size(); i++) {
                    cout << "  (" << alphabet[i] << ") ";
                    disp_1.at(i).card_print();
                }
            cout << "  (" << alphabet[disp_1.size()] << ") ";
            cout << "draw";
            cout << endl;
        }
        
        void displayHand2(vector<Card> disp_2) { //without spaces
            char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
            for(int i = 0; i < disp_2.size(); i++) {
                    cout << " (" << alphabet[i] << ") ";
                    disp_2.at(i).card_print();
                }
        }
        
        int getAlphabetIndex(vector<Card> alpha_c, char the_input){
            char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
            int index;
            for(int j = 0; j < alpha_c.size(); j++) { //make function getalphabetindex
                if(the_input == alphabet[j]) {
                    index = j;
                }
            }
            return index;
        }
        
        int playerChoice(vector<Card> the_cards, string su, string fa) {
            int index;
            for(int i = 0; i < the_cards.size(); i++) {
                if(the_cards.at(i).getSuit() == su) {
                   index = i; 
                   break;
                } else if (the_cards.at(i).getFace() == fa) {
                    index = i;
                    break;
                } else {
                    index = the_cards.size();
                }
            }
            return index;
        }
        
        string declareSuit(vector<Card> ca) { //goes through vector and finds suit that appears most
            string s = "";
            int count = 0;
            for(int i = 0; i < ca.size(); i++) {
                string temp_s = ca.at(i).getSuit();
                int temp_c = 0;
                for(int j = 0; j < ca.size(); j++) {
                    if(ca.at(j).getSuit() == temp_s)
                        temp_c++;
                }
                    if(temp_c > count) {
                        s = temp_s;
                        count = temp_c;
                    }
            }
            return s;
        }
         
};

    void print(vector<Card> print_cards) {
        int vals = print_cards.size();
        for(int i = 0; i < vals; i++) {
            print_cards.at(i).card_print(); 
            cout << " ";
        }
    }


// Main Program:
int main() {
    char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    vector<Card> the_hand;
    vector<Card> hand_1;
    vector<Card> hand_2;
    vector<Card> hand_3;
    
    Deck d;
    vector<Card> the_deck = d.ddeck();
    the_deck = d.shuffle_vect(the_deck);

    for(int i = 0; i < 6; i++) { //setting all the hands
        the_hand.push_back(d.drawCard(the_deck));
        the_deck = d.erasevect(the_deck, 0);
    }
    for(int i = 0; i < 6; i++) { //player 1's hand
        hand_1.push_back(d.drawCard(the_deck));
        the_deck = d.erasevect(the_deck, 0);
    }
    for(int i = 0; i < 6; i++) { //player 2's hand
        hand_2.push_back(d.drawCard(the_deck));
        the_deck = d.erasevect(the_deck, 0);
    }
    for(int i = 0; i < 6; i++) { //player 3's hand
        hand_3.push_back(d.drawCard(the_deck));
        the_deck = d.erasevect(the_deck, 0);
    }

    char input;
    char cardsuit;
    char cardface;
   
    cout << "Welcome to Crazy Eights!" << endl << endl;
    cout << "How to play:" << endl;
    cout << "Play a card that either matches the suit or the face of the card in the pile." << endl;
    cout << "All the '8' Cards are crazy, so if you play a Crazy Eight then you can choose any suit for the pile." << endl;
    cout << "If you don't have a card, then draw. The first player to finish all the cards in their hand wins." << endl;
    cout << "Note: If there are no more cards in the deck, then the game will automatically end." << endl << endl;
    Card currentCard = d.drawCard(the_deck);
    the_deck = d.erasevect(the_deck, 0);
    cout << "Pile has "; currentCard.card_print();
    cout << " <--- your turn" << endl;
    while(true) {
        d.displayHand(the_hand);
        cout << endl;
        if(the_deck.empty()) {
            cout << "There are no more cards in the deck." << endl;
            cout << "No one won!" << endl;
            break;
        } else {
            cout << "Which one to play?: ";
            cin >> input;
        }
        
        int index;
        
            if(input < alphabet[the_hand.size()] && input != '?') {
                index = d.getAlphabetIndex(the_hand, input);
                Card p = the_hand.at(index);
                if (p.getFace() == "8") {
                    string thesuit;
                    cout << "Which suit do you want? ";
                    cin >> thesuit;
                    currentCard = d.newSuit(thesuit);
                    cout << "Pile has "; currentCard.card_print(); cout << "*" << endl;
                    the_hand = d.erasevect(the_hand, index);
                } else {
                    
                    while(!(p.getSuit() == currentCard.getSuit() || p.getFace() == currentCard.getFace())) {
                        d.displayHand(the_hand);
                        cout << endl << "Try again. Which one to play? ";
                        cin >> input;
                        
                        if (input >= alphabet[the_hand.size()]){
                        if(the_deck.empty()) {
                            cout << "There are no more cards in the deck." << endl;
                            cout << "No one won!" << endl;
                            break;
                        } else {
                            the_hand.push_back(d.drawCard(the_deck));
                            the_deck = d.erasevect(the_deck, 0);
                            continue;
                        }
                    } else {
                    index = d.getAlphabetIndex(the_hand, input);
                    p = the_hand.at(index);
                    if (p.getFace() == "8") {
                        string thesuit;
                        cout << "Which suit do you want? ";
                        cin >> thesuit;
                        currentCard = d.newSuit(thesuit);
                        break;
                    } 
                    
                    }    
                    index = d.getAlphabetIndex(the_hand, input);  
                    p = the_hand.at(index);
                    
                }
                
                    if(the_deck.empty()) {
                        break;
                    } else if(p.getFace() == "8") {
                        the_hand = d.erasevect(the_hand, index);
                        cout <<  "Pile has "; currentCard.card_print(); cout << "*" << endl;
                            if(the_hand.empty()) {
                             cout << "You won!" << endl;
                             break;
                            }
                    } else {
                        currentCard = the_hand.at(index);
                        the_hand = d.erasevect(the_hand, index);
                        cout << "Pile has "; currentCard.card_print();
                        cout << endl;
                            if(the_hand.empty()) {
                                 cout << "You won!" << endl;
                                 break;
                            }
                    }
                    
                }
                
                while(d.playerChoice(hand_1, currentCard.getSuit(), currentCard.getFace()) >= hand_1.size()) {
                    cout << "        Player 1 is drawing..." << endl;
                        if(the_deck.empty()) {
                            cout << "There are no more cards in the deck." << endl;
                            cout << "No one won!" << endl;
                            break;
                        } else {
                            hand_1.push_back(d.drawCard(the_deck));
                            the_deck = d.erasevect(the_deck, 0);
                            continue;
                        }
                } 
                if (the_deck.empty()) {
                    break;
                } else {
                    int x = d.playerChoice(hand_1, currentCard.getSuit(), currentCard.getFace());
                    currentCard = hand_1.at(x);
                    hand_1 = d.erasevect(hand_1, x);
                }
                if (currentCard.getFace() == "8") {
                    cout << "        Player 1 chose "; currentCard.card_print();
                    currentCard = d.newSuit(d.declareSuit(hand_1));
                    cout << endl << "        Player 1 declared suite " << d.declareSuit(hand_1);
                    cout << endl << "Pile has "; currentCard.card_print(); cout << "*" << endl;
                    if(hand_1.empty()) {
                         cout << "Player 1 won!" << endl;
                         break;
                    }
                } else {
                    cout << "        Player 1 chose "; currentCard.card_print();
                    cout << endl << "Pile has "; currentCard.card_print();
                    cout << endl;
                    if(hand_1.empty()) {
                         cout << "Player 1 won!" << endl;
                         break;
                    }
                }
                
            
                while(d.playerChoice(hand_2, currentCard.getSuit(), currentCard.getFace()) >= hand_2.size()) {
                    cout << "        Player 2 is drawing...";
                    cout << endl;
                    if(the_deck.empty()) {
                            cout << "There are no more cards in the deck." << endl;
                            cout << "No one won!" << endl;
                            break;
                        } else {
                            hand_2.push_back(d.drawCard(the_deck));
                            the_deck = d.erasevect(the_deck, 0);
                            continue;
                        }
                } 
                if (the_deck.empty()) {
                    break;
                } else {
                    int y = d.playerChoice(hand_2, currentCard.getSuit(), currentCard.getFace());
                    currentCard = hand_2.at(y);
                    hand_2 = d.erasevect(hand_2, y);
                }
                if (currentCard.getFace() == "8") {
                    cout << "        Player 2 chose "; currentCard.card_print();
                    currentCard = d.newSuit(d.declareSuit(hand_2));
                    cout << "        Player 2 declared suite " << d.declareSuit(hand_2);
                    cout << endl << "Pile has "; currentCard.card_print(); cout << "*" << endl;
                    if(hand_2.empty()) {
                         cout << "Player 2 won!" << endl;
                         break;
                    }
                } else {
                    cout << "        Player 2 chose "; currentCard.card_print();
                    cout << endl << "Pile has "; currentCard.card_print();
                    cout << endl;
                    if(hand_2.empty()) {
                         cout << "Player 2 won!" << endl;
                         break;
                    }
                }
    
                while(d.playerChoice(hand_3, currentCard.getSuit(), currentCard.getFace()) >= hand_3.size()) {
                    cout << "        Player 3 is drawing...";
                    cout << endl;
                    if(the_deck.empty()) {
                            cout << "There are no more cards in the deck." << endl;
                            cout << "No one won!" << endl;
                            break;
                        } else {
                            hand_3.push_back(d.drawCard(the_deck));
                            the_deck = d.erasevect(the_deck, 0);
                            continue;
                        }
                }
                  
                if (the_deck.empty()) {
                    break;
                } else {
                    int z = d.playerChoice(hand_3, currentCard.getSuit(), currentCard.getFace());
                    currentCard = hand_3.at(z);
                    hand_3 = d.erasevect(hand_3, z);
                }
                    
                if (currentCard.getFace() == "8") {
                    cout << "        Player 3 chose "; currentCard.card_print();
                    currentCard = d.newSuit(d.declareSuit(hand_3));
                    cout << endl << "        Player 3 declared suite " << d.declareSuit(hand_3);
                    cout << endl << "Pile has "; currentCard.card_print(); cout << "*";
                    if(hand_3.empty()) {
                         cout << "Player 3 won!" << endl;
                         break;
                    } else {
                        cout << " <--- your turn" << endl;
                    }
                } else {
                    cout << "        Player 3 chose "; currentCard.card_print();
                    cout << endl << "Pile has "; currentCard.card_print();
                    if(hand_3.empty()) {
                         cout << "Player 3 won!" << endl;
                         break;
                    } else {
                        cout << " <--- your turn" << endl;
                    }
                }  
                continue;
            } else if (input >= alphabet[the_hand.size()] && input != '?'){
                if(the_deck.empty()) {
                    cout << "There are no more cards in the deck." << endl;
                    cout << "No one won!" << endl;
                    break;
                } else {
                    the_hand.push_back(d.drawCard(the_deck));
                    the_deck = d.erasevect(the_deck, 0);
                    continue;
                }
            } else if (input == '?') {
                cout << "Player 1: "; d.displayHand2(hand_1); cout << endl;
                cout << "Player 2: "; d.displayHand2(hand_2); cout << endl;
                cout << "Player 3: "; d.displayHand2(hand_3); cout << endl; 
                continue;
            }
        }    
    
    cout << "[ Final card distributions ]" << endl;
    cout << "Player 0: "; d.displayHand2(the_hand); cout << endl;
    cout << "Player 1: "; d.displayHand2(hand_1); cout << endl;
    cout << "Player 2: "; d.displayHand2(hand_2); cout << endl;
    cout << "Player 3: "; d.displayHand2(hand_3); cout << endl; 
    
    cout << "Thanks for playing." << endl;
}
