#include "Player.hpp"

Player::Player(const std::string & name, float maxLife, Direction dir, float speed, const sf::Vector2f & pos)
 : Character(PLAYER, name, maxLife, dir, speed, pos)
{
    c_Shape.setFillColor(sf::Color(0, 120, 0));
}

void Player::setShortCut(const Item * item, sf::Keyboard::Key key)
{
    if(c_Bag->findItem(item) >= 0)
    {
        c_Shortcuts[key] = item;
    }
}

const Item * Player::getItemShortCut(sf::Keyboard::Key key)
{
    int16_t itemIndex = c_Bag->findItem(c_Shortcuts[key]);
    if(itemIndex != -1)
        return c_Bag->getItem(itemIndex);
    return NULL;
}
int16_t Player::getItemIndexShortCut(sf::Keyboard::Key key)
{
    return c_Bag->findItem(c_Shortcuts[key]);
}

