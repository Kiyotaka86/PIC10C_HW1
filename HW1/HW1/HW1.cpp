//
//  HW1.cpp
//  HW1
//
//  Created by Kio on 10/14/16.
//  Copyright © 2016 Kio. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
#include <iomanip>
#include <algorithm>


/* *************************************************
 Card class
 ************************************************* */

/*
 Default constructor for the Card class.
 It could give repeated cards. This is OK.
 Most variations of Blackjack are played with
 several decks of cards at the same time.
 */
Card::Card(){
    int r = 1 + rand() % 4;
    switch (r) {
        case 1: suit = OROS; break;
        case 2: suit = COPAS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = BASTOS; break;
        default: break;
    }
    
    r = 1 + rand() % 10;
    switch (r) {
        case  1: rank = AS; break;
        case  2: rank = DOS; break;
        case  3: rank = TRES; break;
        case  4: rank = CUATRO; break;
        case  5: rank = CINCO; break;
        case  6: rank = SEIS; break;
        case  7: rank = SIETE; break;
        case  8: rank = SOTA; break;
        case  9: rank = CABALLO; break;
        case 10: rank = REY; break;
        default: break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break;
        case REY:
            rankName = "Rey";
            break;
        default: break;
    }
    return rankName;
}



// Accessor: returns a string with the suit of the card in English
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
        string suitName;
        switch (suit) {
            case OROS:
                suitName = "coins";
                break;
            case COPAS:
                suitName = "cups";
                break;
            case ESPADAS:
                suitName = "spades";
                break;
            case BASTOS:
                suitName = "clubs";
                break;
            default: break;
        }
        return suitName;
}

// Accessor: returns a string with the rank of the card in English
string Card::get_english_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "Ace";
            break;
        case DOS:
            rankName = "Two";
            break;
        case TRES:
            rankName = "Three";
            break;
        case CUATRO:
            rankName = "Four";
            break;
        case CINCO:
            rankName = "Five";
            break;
        case SEIS:
            rankName = "Six";
            break;
        case SIETE:
            rankName = "Seven";
            break;
        case SOTA:
            rankName = "Jack";
            break;
        case CABALLO:
            rankName = "Knight";
            break;
        case REY:
            rankName = "King";
            break;
        default: break;
    }
    return rankName;

}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}



/* *************************************************
 Hand class
 ************************************************* */
Hand::Hand(){
    vector<Card> han;
    
}

void Hand::add_card(Card a){
    han.push_back(a);
}

double Hand::get_val(){
    double val;
    for(auto i:han){
        if(i.get_rank()<=7)
            val+=i.get_rank();
        else
            val+=0.5;
    }
        
    
        return val;
}

string Hand::get_spanish_rank(int n) const{
    return  han[n].get_spanish_rank();
}

string Hand::get_spanish_suit(int n) const{
    return han[n].get_spanish_suit();
}

string Hand::get_english_suit(int n) const{
    return han[n].get_english_suit();
}
string Hand::get_english_rank(int n) const{
    return han[n].get_english_rank();
}
int Hand::get_rank(int n){
    return han[n].get_rank();
}
/* *************************************************
 Player class
 ************************************************* */
Player::Player(int m){
    money = m;
}




int main() {
    int bet=0;
    Player you(100);
    Hand your_h, d_hand;
    
    int game_num=1;
    
//Player's turn
    
    while(you.get_money()>0 || you.get_money()<=900){
    
        char extra='r';

        do{
            std::cout<<"You have $" <<you.get_money() <<". Enter bet ";
            std::cin>>bet;
        }while(bet > you.get_money() || bet < 0);


        Card your_card;
        your_h.add_card(your_card);

        do{
            std::cout<<"Your cards:" << std::endl;
            for(int i=0; i< your_h.get_size(); ++i){
                std::cout<<your_h.get_spanish_rank(i) <<" de " <<your_h.get_spanish_suit(i)<< "  (" << your_h.get_english_rank(i)<<" of " << your_h.get_english_suit(i) <<")\n";
            }

            std::cout<<"Your total is " << your_h.get_val() <<". Do you want another card (y/n)?" <<std::endl;
            std::cin>>extra;
            
            if (extra =='y'||extra=='Y'){
                Card ncard;
                your_h.add_card(ncard);
                std::cout<<"New Card:\n";
                std::cout<< ncard.get_spanish_rank() <<" de " <<ncard.get_spanish_suit()<< "  (" << ncard.get_english_rank()<<" of " << ncard.get_english_suit() <<")\n";
            }
            
            if (your_h.get_val()>7.5){
                std::cout<<"Your total is"<< your_h.get_val();
                break;
            }
            
        }while(extra != 'n'&&extra != 'N');

//the dealer's turn
        
        do{
            Card d_card;
            d_hand.add_card(d_card);
        }while(d_hand.get_val()<5.5);
               
        std::cout<<"Dealer's cards" << std::endl;
        for(int i=0; i< d_hand.get_size(); ++i){
            std::cout<<d_hand.get_spanish_rank(i) <<" de " <<d_hand.get_spanish_suit(i)<< "  (" << d_hand.get_english_rank(i) <<" of " << d_hand.get_english_suit(i) <<")\n";
        }
        
        std::cout<<"Dealer's total is " << d_hand.get_val() <<std::endl;
        
        
        
        game_num++;
        
    }
    return 0;
    
}
